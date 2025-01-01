


#include "ssh_conn.h"

#include <libssh/libssh.h>
#include <iostream>

namespace ssh_utils {
    ssh_conn::ssh_conn()
        : m_session(ssh_new()) {}

    // 远程主机连接设置
    void ssh_conn::set_ssh_options(const char* host, int port, const char* user) {
        if (m_session == nullptr) return;
        
        ssh_options_set(m_session, SSH_OPTIONS_HOST, host);
        ssh_options_set(m_session, SSH_OPTIONS_PORT, &port);
        ssh_options_set(m_session, SSH_OPTIONS_USER, user);
    }

    // 检查是否能正常连接到远程主机
    bool ssh_conn::check_conn() {
        m_rc = ssh_connect(m_session);
        if (m_rc != SSH_OK) { 
            std::cout << "connect failed." << std::endl;
            return false;
        }
        std::cout << "connect successfully!" << std::endl;
        return true;
    }   

    // 用户连接密码验证
    bool ssh_conn::check_user(const char* pwd) {
        m_rc = ssh_userauth_password(m_session, nullptr, pwd);
        if (m_rc != SSH_AUTH_SUCCESS) { 
            std::cout << "User authenticate failed!" << std::endl;   
            return false;
        }
        std::cout << "Authenticate successfully!" << std::endl;
        return true;
    }

    // 打开连接通道
    bool ssh_conn::open_channel() {
        m_channel = ssh_channel_new(m_session);
        if (m_channel == nullptr) {
            std::cout << "Open channel failed!" << std::endl; 
            return false;
        }
        std::cout << "Open channel successfully!" << std::endl;
        return true;
    }

    // 打开会话
    bool ssh_conn::open_session() {
        m_rc = ssh_channel_open_session(m_channel);
        if (m_rc != SSH_OK) {
            std::cout << "Open session failed!" << std::endl; 
            return false;
        }
        std::cout << "Open Session successfully!" << std::endl;
        return true;
    }

    bool ssh_conn::exec_cmd(const char* cmd) {
        m_rc = ssh_channel_request_exec(m_channel, cmd);
        if (m_rc != SSH_OK)  {
            std::cout << "Execute command failed." << std::endl;   
            return false;
        }
        std::cout << "Execute command successfully!" << std::endl;
        return true;
    } 
}
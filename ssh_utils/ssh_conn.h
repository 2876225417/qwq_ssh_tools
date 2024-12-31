#ifndef SSH_CONN_H_
#define SSH_CONN_H_

#include <libssh/libssh.h>
#include <iostream>

namespace ssh_utils {
    
    class ssh_conn {
    public:
        explicit ssh_conn()
            : m_session(ssh_new())
            {
            
            if (m_session == nullptr) {
                std::cerr << "Error creating SSH session.\n";            
            }
            int port = 22;
            ssh_options_set(m_session, SSH_OPTIONS_HOST, "199.7.140.50");
            ssh_options_set(m_session, SSH_OPTIONS_PORT, &port);
            ssh_options_set(m_session, SSH_OPTIONS_USER, "root");

            m_rc = ssh_connect(m_session);
            if (m_rc != SSH_OK) {
                std::cerr << "SSH connector error!";
                // ssh_free(m_session);
            } else std::cout << "SSH connect successfully!\n";

            m_rc = ssh_userauth_password(m_session, nullptr, "FnMbJCn75UHnpepJ");
            if (m_rc != SSH_AUTH_SUCCESS) {
                std::cout << "SSH AUTH FAILED!\n";
                //ssh_disconnect(m_session);
                //ssh_free(m_session);
            } else std::cout << "SSH AUTH SUCCESS\n";

            m_channel = ssh_channel_new(m_session);
            if (m_channel == nullptr) {
                std::cerr << "Error creating channel.\n";
                //ssh_disconnect(m_session);
                //ssh_free(m_session);
            } else std::cout << "Create channel success!\n";

            m_rc = ssh_channel_open_session(m_channel);
            if (m_rc != SSH_OK) {
                std::cerr << "Error opening channel: "
                          << ssh_get_error(m_session) << '\n';

            }

            m_rc = ssh_channel_request_exec(m_channel, "ls -l");
            if (m_rc != SSH_OK) {
                std::cerr << "Error executing command!\n"
                          << ssh_get_error(m_session) << '\n';

                //ssh_disconnect(m_session);
                //ssh_free(m_session);
            } else std::cout << "Executing command success!\n";
        }

        void set_ssh_options(const char* host, int port, const char* user) {
            if (m_session == nullptr) {
                return;
            }
                
            ssh_options_set(m_session, SSH_OPTIONS_HOST, host);
            ssh_options_set(m_session, SSH_OPTIONS_PORT, &port);
            ssh_options_set(m_session, SSH_OPTIONS_USER, user);
        }
        
        bool check_conn() const {
            m_rc == ssh_connect(m_session); 
            if (m_rc != SSH_OK) {
                return false;
            }
            return true;
        }

        bool check_user(const char* pwd)  {
            m_rc = ssh_userauth_password(m_session, nullptr, pwd);
            if (m_rc != SSH_AUTH_SUCCESS) {
                return false;
            }
            return true;
        }

        bool open_channel() {
            m_channel = ssh_channel_new(m_session);
            if (m_channel == nullptr) {
                return false;
            }
            return true;
        }

        bool exec_cmd()  {
            m_rc = ssh_channel_request_exec(m_channel, "ls -l");
            if (m_rc != SSH_OK) {
                return false;
            }
            return true;
        }





    private:
        ssh_session m_session;
        ssh_channel m_channel;
        int         m_rc;
    };
}

#endif  // SSH_CONN_H_
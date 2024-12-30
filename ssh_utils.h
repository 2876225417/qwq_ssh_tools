

#ifndef SSH_UTILS_H
#define SSH_UTILS_H

#include <libssh/libssh.h>
#include <exception>

namespace qwq_ssh_tools {

    class ssh_exception: public std::exception {
    public:
        ssh_exception() = default;
        ssh_exception(const char* err_msg): m_err_msg(err_msg) { } 
        const char* what() const noexcept override {
            return m_err_msg == nullptr ? "SSH Exception!" : m_err_msg;
        }
    private:
        const char* m_err_msg;        
    };
    class ssh {
    public:
        ssh(): m_session(ssh_new()) {
            if (m_session == nullptr)
                throw ssh_exception("Session's initialization failed!");
        }

        void set_options(const char* host, int port = 22, const char* user) {
            ssh_options_set(m_session, SSH_OPTIONS_HOST, host);
            ssh_options_set(m_session, SSH_OPTIONS_PORT, &port);
            ssh_options_set(m_session, SSH_OPTIONS_USER, user);
        }

        bool check_ssh_connect() {
            m_rc = ssh_connect(m_session);
            if (m_rc != SSH_OK) { 
                
                ssh_free(m_session);
                return false;
            }
            return true;
        }

        void failed() {
            ssh_disconnect(m_session);
            ssh_free(m_session);
        }
        
        bool check_user_auth(const char* pwd) {
            m_rc = ssh_userauth_password(m_session, nullptr, pwd);
            if (m_rc != SSH_AUTH_SUCCESS) {
                failed();
                return false;
            }
            return true;
        }

        bool create_channel() { 
            m_channel = ssh_channel_new(m_session);
            if (m_channel == nullptr) {    
                failed();
                return false;
            }
            return true;
        }

        


    private:
        ssh_session m_session;  // session
        ssh_channel m_channel;  // channel
        int         m_rc;       // rc
    };

}

#endif  // SSH_UTILS_H
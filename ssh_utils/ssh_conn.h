#ifndef SSH_CONN_H_
#define SSH_CONN_H_

#include <libssh/libssh.h>
#include <iostream>

namespace ssh_utils {
    
    class ssh_conn {
    public:
        explicit ssh_conn();

        void set_ssh_options(const char* host, int port, const char* user);
        bool check_conn();
        bool check_user(const char* pwd);
        bool open_channel();
        bool open_session();
        bool exec_cmd();

    private:
        ssh_session m_session;
        ssh_channel m_channel;
        int         m_rc;
    };
}

#endif  // SSH_CONN_H_
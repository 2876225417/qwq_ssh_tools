


#include <libssh/libssh.h>
#include <iostream>

int main() {
    ssh_session session;
    ssh_channel channel;
    int rc;

    session = ssh_new();
    if (session == nullptr) {
        std::cerr << "Error creating SSH session.\n";
        return -1;
    }


    int port = 22;
    ssh_options_set(session, SSH_OPTIONS_HOST, "199.7.140.50");
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(session, SSH_OPTIONS_USER, "root");


    // 检查是否能正常连接到服务器
    rc = ssh_connect(session);
    if (rc != SSH_OK) {
        std::cerr << "Error connecting to remote host: " 
                  << ssh_get_error(session) << '\n';

        ssh_free(session);
        return -1;
    }

    // 进行服务器用户身份验证
    rc = ssh_userauth_password(session, nullptr, "FnMbJCn75UHnpepJ");
    if (rc != SSH_AUTH_SUCCESS) {
        std::cerr << "Authentication failed: "
                  << ssh_get_error(session) << '\n';
        ssh_disconnect(session);
        ssh_free(session);
        return -1;
    }

    // 创建通道
    channel = ssh_channel_new(session);
    if (channel == nullptr) {
        std::cerr << "Error creating channel.\n";
        ssh_disconnect(session);
        ssh_free(session);
        return -1;
    }

    // 打开会话
    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK) {
        std::cerr << "Error opening channel: "
                  << ssh_get_error(session) << '\n';
        ssh_disconnect(session);
        ssh_free(session);
        return -1;
    }
    
    // 处理命令请求
    rc = ssh_channel_request_exec(channel, "ls -l");
    if (rc != SSH_OK) { 
        std::cerr << "Error executing command: "
                  << ssh_get_error(session) << '\n';
        ssh_disconnect(session);
        ssh_free(session);
        return -1;
    }

    char buffer[256];
    int nbytes;
    while ((nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0)) > 0) {
        std::cout.write(buffer, nbytes);
    }

    if (nbytes < 0) {
        std::cerr << "Error reading output: " 
                  << ssh_get_error(session) << '\n';
    }
    ssh_channel_send_eof(channel);
    ssh_channel_free(channel);
    ssh_disconnect(session);
    ssh_free(session);

}
#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cassert>
#include <string>

#include "./http/http_conn.h"

using namespace std;

const int MAX_FD = 65536; // maximum file descriptor

class WebServer {

    public:
        WebServer();
        ~WebServer();

        void init(int port, string user, string password, string databaseName, int sql_num);

        void sql_pool();
        void eventListen();
        void eventLoop();

    private:

        int m_port;
        char *m_root;

        int m_pipefd[2];
        http_conn *users;

        // databases
        string m_dbuser;
        string m_password;
        string m_databaseName;
        int m_sql_num;
};

#endif
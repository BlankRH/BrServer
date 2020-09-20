#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H
#include <unistd.h>
#include <cstring>
#include <signal.h>
#include <cstdio>
#include <cstdlib>

class http_conn {
    
    public:
        static const int FILENAME_LEN = 200;
        static const int READ_BUFFER_SIZE = 2048;
        static const int WRITE_BUFFER_SIZE = 1024;
        enum METHOD {
            GET = 0,
            POST,
            HEAD,
            PUT,
            DELETE,
            TRACE,
            OPTIONS,
            CONNECT,
            PATH
        };
        enum CHECK_STATE {
            CHECK_STATE_REQUESTLINE = 0,
            CHECK_STATE_HEADER,
            CHECK_STATE_CONTENT
        };
        enum HTTP_CODE {
            NO_REQUEST,
            GET_REQUEST,
            BAD_REQUEST,
            NO_RESOURCE,
            FORBIDDEN_REQUEST,
            FILE_REQUEST,
            INTERNAL_ERROR,
            CLOSED_CONNECTION
        };
        enum LINE_STATUS {
            LINE_OK = 0,
            LINE_BAD,
            LINE_OPEN
        };

    public:
        http_conn() {}
        ~http_conn() {}

    public:
        void init(int sockfd, const sockaddr_in &addr, char *, int, int, string user, string passwd, string sqlname);
        void close_conn(bool real_close = true);
        void process();
        bool read_once();
        bool write();
        sockaddr_in *get_address() {
            return &m_address;
        }
        void initmysql_result(connection_pool *connPool);
        int timer_flag;
        int improv;

    private:
        void init();
        HTTP_CODE parse_request_line(string text);
        HTTP_CODE parse_headers(string text);
        HTTP_CODE parse_content(string text);
        
};

#endif
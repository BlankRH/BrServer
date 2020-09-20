#include "config.h"

int main(int argc, char *argv[])
{

    string dbuser = "root"
    string passwd = "blankrdb"
    string databasename = "mydb";

    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    server.init(config.PORT, user, passwd, databasename, config.sql_num);

    server.sql_pool();

    server.eventListen();

    server.eventLoop();

    return 0;
}
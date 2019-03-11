#include "headers.h"

void hit_server (char *srvr_addr, int port,
                 int no_of_clnts, int daemon_flag)
{
    printf("%d :: Server : %s, Port : %d, No. of clients %d and daemon_flag : %d\n",
            __LINE__, srvr_addr, port, no_of_clnts, daemon_flag);

}

#include "headers.h"

#define READWRITE_BUFF 1024
/*
typedef void (*uv_read_cb)(uv_stream_t* stream,
                           ssize_t nread,
                           const uv_buf_t* buf);

typedef void (*uv_alloc_cb)(uv_handle_t* handle,
                            size_t suggested_size,
                            uv_buf_t* buf);
*/
void read_call (,READWRITE_BUFF,buf)
{

}

void allocate_buff (,READWRITE_BUFF,)

void uv_conn_call (uv_stream_t *server, int status)
{
    if (status < 0) {
        fprintf(stderr,"uv_listen call failed : %s.\n", uv_strerror(ret)); 
        exit (EXIT_FAILURE);
    }

    uv_tcp_t *client_stream = (uv_tcp_t *)malloc (sizeof(uv_tcp_t));
    uv_tcp_init (loop, &client_stream);
    if (uv_accept ( server, (uv_stream_t *) client_stream) == 0)
        uv_read_start ((uv_stream_t *)client_stream,);
        int uv_read_start(uv_stream_t* stream,
                  uv_alloc_cb alloc_cb,
                  uv_read_cb read_cb) {


}

void hit_server (char *srvr_addr, int port,
                 int no_of_clnts, int daemon_flag)
{
    int ret;
    uv_loop_t *loop;
    uv_tcp_t tcp_stream; 
    struct sockaddr_in s_addr

    printf("%s : %d :: Server : %s, Port : %d, No. of clients %d and daemon_flag : %d\n",
            __FILE__, __LINE__, srvr_addr, port, no_of_clnts, daemon_flag);

    loop = uv_default_loop();
    uv_tcp_init (loop, &tcp_stream);

    uv_ip4_addr ( srvr_addr, port, &s_addr);

    uv_tcp_bind ( &tcp_stream, (const struct sockaddr *)&s_addr, 0);
   
    ret = uv_listen ((uv_stream_t *)&tcp_stream, DEFAULT_BACKLOG, uv_conn_call); 
    if (ret) {
        fprintf(stderr,"uv_listen call failed : %s.\n", uv_strerror(ret)); 
        exit (EXIT_FAILURE);
    }
    
    ret = uv_run (loop,UV_RUN_DEFAULT); 
}

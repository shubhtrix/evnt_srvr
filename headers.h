/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Future syslog logging for daemon. */
#include <syslog.h>

/* Event handeling library. In our case it's libuv. */
#include <uv.h>

#define OPTIONS "dh:n:p:s"

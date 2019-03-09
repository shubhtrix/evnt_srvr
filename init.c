#include "headers.h"

void usage () {

    printf("This is mosquitto based MQTT client including puablisher & subscriber.\n"); 
    printf("Usage :\n\t-d -\tDaemonize the process\n"
                   "\t-h -\tprint this help\n"
                   "\t-n -\tno of client to configure\n"
                   "\t-p -\tPort to configure, default is 1883\n"
                   "\t-s -\tServer to connect to\n");
}

int main(int argc, char **argv)
{
	int opt, daemon_flag=0;
	int port=0;
	char *server = NULL;

    while((opt = getopt(argc, argv, OPTIONS)) != -1)
	{
		switch (opt) {
		case'd':
			printf("Daemonizing this program.\n");
			daemon_flag=1;
            //daemonize ();
			break;
		case'h':
			usage ();
			exit (EXIT_FAILURE);
		case'p':
			port = atoi(optarg);
            if ( port < 1024) {
				port=1883;
			} else if ( port > 65534) {
				port=1883;
			} else
				printf("Provided port for broker : %d", port);
			break;
		case's': 
			server = strdup(optarg); 
			break;
		case'?':
			printf("Invalid option, check usage...\n");
			usage ();
			exit (EXIT_FAILURE);
        default : 
			printf("Default case, check usage...\n");
			usage ();
			exit (EXIT_FAILURE);
		}
	}

	if ( (server != NULL) && (port != 0)) {
		if (!daemon_flag) {
            printf("default client.\n");
			//default_client ( server, port);
		} else {
            printf("deamon's part\n");
			//daemonize ( server, port);
		}
	} else {
		printf("No server address provided. Exiting...\n");
		exit (EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

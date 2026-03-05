#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>

#include <poll.h>

#include "inet_socket.h"
#include "chess.h"
#include "chess_io.h"

void err_exit(const char *message) {
	perror(message);
	exit(errno);
}

int main(int argc, const char *argv[]) {
	int sockfd = 0, opt;
	const char *addr_str = "err", *port_str = "err";	
	
	struct sockaddr_in sockaddr = {0};
	
	if(argc < 3) {
		printf("missing args\n");
		exit(1);
	}
	
	addr_str = argv[1]; 
	port_str = argv[2];
	if((sockfd = inet_connect(argv[1], argv[2], SOCK_STREAM)) == -1)
		err_exit("connect");	
	
	printf("connected to socket at address %s:%s\n", addr_str, port_str);	

	char buf[8] = {0};
	ssize_t nread;

	for(;;) {
		switch(nread = read(STDIN_FILENO, buf, 8)) {
		case -1:
			err_exit("read");
			break;
		case 0:
			goto end;
			break;
		default:
			if(write(sockfd, buf, nread) == -1)
				err_exit("write");
			break;
		}	
	}

end:
	printf("closing socket\n");
	close(sockfd);
	return EXIT_SUCCESS;
}

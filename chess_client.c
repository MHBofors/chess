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
	int sockfd = 0, clientfd = 0, opt;
	const char *addr_str = "err", *port_str = "err";	
	
	struct sockaddr_in sockaddr = {0};
	
	if(argc < 3) {
		printf("missing args\n");
		exit(1);
	}
	
	printf("opening socket at address %s:%s\n", addr_str, port_str);	
	
	if((sockfd = inet_connect(argv[1], argv[2], SOCK_STREAM)) == -1)
		err_exit("connect");	
	
	char buf[8];
	while(read(STDIN_FILENO, buf, 8)) {
		if(write(sockfd, buf, 8) == -1)
			break;
	}	
	
	printf("closing socket\n");
	close(sockfd);
	return EXIT_SUCCESS;
}

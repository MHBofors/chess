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
	
	if((sockfd = inet_bind(argv[1], argv[2], SOCK_STREAM)) == -1)
		err_exit("binding");	
	
	if(listen(sockfd, 1) == -1)
	       err_exit("listen");

	struct sockaddr caddr;
	socklen_t clen;

	printf("waiting for connection\n");	
	if((clientfd = accept(clientfd, &caddr, &clen)) == -1)
		err_exit("accept");
	
	char buf[8];
	while(read(sockfd, buf, 8) > 0) {
		if(write(STDOUT_FILENO, buf, 8) == -1)
			err_exit("write");
	}	

	printf("closing socket\n");
	close(sockfd);
	return EXIT_SUCCESS;
}

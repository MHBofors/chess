#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "chess.h"
#include "chess_io.h"

extern int errno;

void err_exit(const char *message) {
	perror(message);
	exit(errno);
}

int main(int argc, const char *argv[]) {
	int sockfd = 0, clientfd = 0, opt;
	const char *addr_str = "err", *port_str = "err";	
	
	struct sockaddr_in sockaddr = {0};
	
	if(argc < 2) {
		printf("missing args\n");
		exit(1);
	}
	
	getopt(argc, argv, "i:");
	addr_str = strndup(optarg, 21);
	
	strtok(addr_str, ":");
	port_str = strtok(NULL, ":");	

	switch(inet_pton(AF_INET, addr_str, &sockaddr.sin_addr) != 0) {
	case 0:
		printf("invalid address");
		break;
	case -1:
		err_exit("address parsing failed");	
		break;
	default:
		sockaddr.sin_port = atoi(port_str);
		printf("address valid\n");
	}	
	
	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1) err_exit("server socket");
	
	if(bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) err_exit("server socket bind");		
	printf("opening socket at address %s:%s\n", addr_str, port_str);	
	
	sleep(10);

	printf("closing socket\n");
	close(sockfd);
	return EXIT_SUCCESS;
}

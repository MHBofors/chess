#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "chess.h"
#include "chess_io.h"

extern int errno;

struct move_t encode_move(const char *str);
const char *decode_move(struct move_t move);

int write_move(int fd, struct move_t move) {
	ssize_t nwritten;
	
	if((nwritten = write(fd, &move, sizeof(struct move_t)) == -1)) {
		printf("write failed: %s\n", strerror(errno));
		exit(errno);	
	}

	return 0;	
}

int read_move(int fd, struct move_t *move) {
	return 0;
}

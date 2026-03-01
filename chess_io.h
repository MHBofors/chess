#ifndef CHESS_IO_H
#include "chess.h"

struct move_t encode_move(const char *str);
const char *decode_move(struct move_t move);

int write_move(int fd, struct move_t move);
int read_move(int fd, struct move_t *move);

#endif

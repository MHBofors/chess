#ifndef CHESS_H
#define CHESS_H

struct move_t {
	uint32_t from:6;
	uint32_t to:6;
};
typedef struct bitboard_t bitboard_t;
typedef struct position_t position_t;

#endif /* CHESS_H */

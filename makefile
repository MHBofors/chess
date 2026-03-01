CC = clang

CFLAGS = -O1
LDFLAGS = -lc
SERVER_NAME = cserv

chess_server: chess_server.c chess.c chess_io.c chess_io.h chess.h
	$(CC) $(CFLAGS) chess_server.c chess.c chess_io.c -o $(SERVER_NAME) $(LDFLAGS)


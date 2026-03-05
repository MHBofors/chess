CC = clang

NWDIR = ../network
BUILD_DIR = build

CFLAGS = -I$(NWDIR) -Os
LDFLAGS = -lc
SERVER_NAME = cserver
CLIENT_NAME = cclient

chess_server: chess_server.c chess.c chess_io.c chess_io.h chess.h 
	$(CC) $(CFLAGS) chess_server.c chess.c chess_io.c $(NWDIR)/inet_socket.c -o $(BUILD_DIR)/$(SERVER_NAME) $(LDFLAGS)

chess_client: chess_client.c chess.c chess_io.c chess_io.h chess.h 
	$(CC) $(CFLAGS) chess_client.c chess.c chess_io.c $(NWDIR)/inet_socket.c -o $(BUILD_DIR)/$(CLIENT_NAME) $(LDFLAGS)

all: chess_client chess_server

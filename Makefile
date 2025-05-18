CC      = gcc
CFLAGS  = -O3 -Wall -std=c11

SRC     = os.c pt.c
BIN     = page_table

.PHONY: all clean

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

clean:
	rm -f $(BIN)

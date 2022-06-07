CC=g++
CCFLAGS=-c -g -Wall -std=c++17
BIN=main

all: $(BIN)

main.o: main.c
	$(CC) $(CCFLAGS) -o $@ $^

$(BIN): main.o
	$(CC) -o $@ $^

debug:
	gdb ./$(BIN)

run: all
	@echo "************Begin of Output**********************"
	./$(BIN)
	@echo "************End of Output************************"

clean:
	rm -rf *.o $(BIN)
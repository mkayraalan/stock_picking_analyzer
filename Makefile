CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

SRC = src/main.c src/csv.c src/strategies.c
OUT = analyzer

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

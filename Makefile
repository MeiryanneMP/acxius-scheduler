CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c src/scheduler.c src/acxius_key.c src/acxius_mail.c src/acxius_wifi.c
OBJ = $(SRC:.c=.o)
TARGET = acxius

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lcurl

clean:
	rm -f $(OBJ) $(TARGET)

CC = gcc
CXX = g++
CFLAGS = -Wall -std=c11 -Isrc/scheduler -Isrc/key -Isrc/network -Isrc/sender -Isrc/face
CXXFLAGS = -Wall -std=c++17 `pkg-config --cflags opencv4` -Isrc/face
LDFLAGS = `pkg-config --libs opencv4`

SRC_C = src/main.c \
        src/key/acxius_key.c \
        src/network/acxius_wifi.c \
        src/scheduler/scheduler.c \
        src/sender/acxius_mail.c

SRC_CPP = src/face/face_detector.cpp

OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)

TARGET = acxius

all: $(TARGET)

$(TARGET): $(OBJ_C) $(OBJ_CPP)
	$(CXX) -o $(TARGET) $(OBJ_C) $(OBJ_CPP) $(LDFLAGS) -lcurl

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_C) $(OBJ_CPP) $(TARGET)

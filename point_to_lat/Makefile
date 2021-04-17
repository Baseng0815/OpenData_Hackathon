TARGET 	:= point_to_lat

CC 	:= g++

.PHONY: all clean

CFLAGS 	:= -Wall -Werror -O2 -pipe -std=c++11

LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SOURCES := $(shell find . -type f -name "*.cpp")
OBJS 	:= $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS ) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

TARGET 		:= visualizer

CC 		:= g++

CFLAGS 		:= -Wall -O0 -pipe -ggdb

LDFLAGS 	:= -lglfw -lGLEW -lX11 -lGLU -lGL -lOpenGL

SOURCES 	:= $(shell find . -type f -name "*.cpp")
OBJS 		:= $(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

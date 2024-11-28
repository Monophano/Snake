CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -Llib -lsfml-graphics -lsfml-window -lsfml-system
INCLDFLAGS = -Iinclude
RELEASEFLAGS = -mwindows
DEBUGFLAG = -ggdb
OPTIMISATION = -O0

TARGET = bin/snake.exe
SRCS = src\main.cpp src\game.cpp src\grid.cpp src\apple.cpp src\snake.cpp src\file.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS) $(RELEASEFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLDFLAGS) $< -o $@

run:
	./$(TARGET)

clean:
	del obj\*.o

debug:
	gdb ./$(TARGET)

.PHONY: run

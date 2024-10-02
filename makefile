CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -Llib -lsfml-graphics -lsfml-window -lsfml-system
INCLDFLAGS = -Iinclude
RELEASEFLAGS = -mwindows
DEBUGFLAG = -ggdb
OPTIMISATION = -O0

TARGET = bin/snake.exe
SRCS =
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(DEBUGFLAG) $(OPTIMISATION) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $(INCLDFLAGS) $< -o $@

run:
	./$(TARGET)

clean:
	del obj\*.o

debug:
	gdb ./$(TARGET)

.PHONY: run

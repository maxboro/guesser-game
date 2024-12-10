# Compiler and flags
CC = g++
CFLAGS = -Wall -g

# Source files and output
SRC = main.cpp GameEngine.cpp GameManager.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = game

# Rule to build the final program
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

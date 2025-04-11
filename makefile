# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I cfc/headers

# Directories
SRC_DIR := cfc
BLD_DIR := build
OBJ_DIR := $(BLD_DIR)/obj
BIN := $(BLD_DIR)/main

# Find all .cpp files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Convert to .o files in obj/
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link object files into final binary
$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(BLD_DIR)

.PHONY: all clean

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wno-missing-braces -g
LDFLAGS = -L lib/
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
INCLUDES = -I include/ -I src/
STD = -std=c++20
OPT = -O0

# Profiling flags
PG = -pg
NO_OPT = -O0
NO_INLINE =  -fno-inline
PRFLAGS = $(PG) $(NO_OPT) $(NO_INLINE)

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Target executables
TARGET = $(BIN_DIR)/main.exe
PROFILE_TARGET = $(BIN_DIR)/main_profile.exe

# Default rule (normal build)
all: $(TARGET)

# Rule to link the normal executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(STD) $(OBJS) $(LDFLAGS) $(LIBS) $(INCLUDES) $(OPT) -o $@
	@echo "Normal build complete"

# Rule to link the profiling executable
profile: $(OBJS) | $(BIN_DIR)
	$(CC) $(PRFLAGS) $(CFLAGS) $(STD) $(OBJS) $(LDFLAGS) $(LIBS) $(INCLUDES) -o $(PROFILE_TARGET)
	@echo "Profiling build complete"

# Rule to compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(STD) $(INCLUDES) -c $< -o $@

# Rule for main.cpp file
$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(STD) $(INCLUDES) -c $< -o $@

# Create directories if they do not exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Test build
test:
	g++ -o test test.cpp -std=c++20

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean complete"

# Phony targets
.PHONY: all profile clean

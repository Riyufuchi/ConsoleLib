# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -O3 -std=c++20

# Directories
SRC_DIR = src
INC_DIR = src/inc
BUILD_DIR = build
LIB_DIR = lib

# Source files
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.cpp")

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Library
LIB_NAME = libConsoleLib.a
LIB_TARGET = $(BUILD_DIR)/$(LIB_NAME)

# Unit testing
TEST_SRC_FILES = $(wildcard test/*.cpp)
TEST_OBJ_FILES = $(patsubst test/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRC_FILES))
TEST_BINARY = $(BUILD_DIR)/test

# Targets
all: $(LIB_TARGET)

$(LIB_TARGET): $(OBJ_FILES)
	ar rcs $@ $^

# Create build directory structure
$(BUILD_DIR):
	mkdir -p $(foreach dir,$(sort $(dir $(OBJ_FILES))),$(dir))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(LIB_TARGET)
	
test: all $(TEST_BINARY)
	$(TEST_BINARY)

$(TEST_BINARY): $(TEST_OBJ_FILES) $(LIB_TARGET)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -Igoogletest/include \
	    -o $@ $^ -Lgoogletest/build -lgtest -lgtest_main -pthread

$(BUILD_DIR)/%.o: test/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -Igoogletest/include -c $< -o $@

.PHONY: all clean

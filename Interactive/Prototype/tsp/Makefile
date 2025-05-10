CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(SRC_DIR)/tsp.cpp $(TEST_DIR)/main.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/tsp.cpp $(TEST_DIR)/main.cpp -o $(BUILD_DIR)/main

run: all
	./$(BUILD_DIR)/main

clean:
	rm -rf $(BUILD_DIR)
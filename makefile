# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directories and files
DAYS_DIR = days
SOURCES = $(wildcard $(DAYS_DIR)/*.cpp) main.cpp
TARGET = adventofcode

# Build target
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

clean:
	rm -f $(TARGET)


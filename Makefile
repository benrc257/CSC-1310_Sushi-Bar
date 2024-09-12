# Define the compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Define the target executable
TARGET = course

# Default rule to build the target
all: $(TARGET)

# Rule to link Test.cpp into the executable
$(TARGET): driver.cpp course.cpp course.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) driver.cpp

# Clean rule to remove generated files
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean

CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = redis

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

# Clean build files
clean:
	rm -f $(TARGET)

# Run the application
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run
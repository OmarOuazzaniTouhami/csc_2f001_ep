CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

TARGET = bilbao
OBJS   = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

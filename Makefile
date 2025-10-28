CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# List all your .cpp files here
SRCS = main.cpp functions.cpp productData.cpp derivedMaps.cpp hashMap.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = program

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
# makefile
CXX = g++
# compiler Flags
CXXFLAGS = -Wall -std=c++11

# target executable
TARGET = dog

# source files
SRCS = main.cpp dog_features.cpp

# object files (derived from source files)
OBJS = $(SRCS:.cpp=.o)

# default target
all: $(TARGET)

# build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# compile .cpp files into .o files
%.o: %.cpp dog.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

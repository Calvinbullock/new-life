# Target: The name of your executable file
TARGET = newLifeEXE

# C++ compiler
CXX = g++

# C++ compiler flags (optimize for speed)
CXXFLAGS = -O2 -ansi -pedantic -Wall -Wextra -Wshadow -Weffc++

# Source files (cpp)
SRCS = item.cpp main.cpp tileMap.cpp creature.cpp

# Object files (created from source files)
OBJS = $(SRCS:.cpp=.o)

# Header files (include for compilation)
HDRS = item.h creature.h

# Linker flags (link with SFML library)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Rule to compile a source file (.cpp) into an object file (.o)
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

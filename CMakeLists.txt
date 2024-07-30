
cmake_minimum_required(VERSION 3.5)
project(newLifeEXE)

# Find SFML libraries
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Include directories for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Define source files
set(SRCS items/item.cpp main.cpp tileMap.cpp creature.cpp playerCreature.cpp)

# Generate object files from source files
add_executable(newLifeEXE ${SRCS})

# Link with SFML libraries
target_link_libraries(newLifeEXE PRIVATE -lsfml-graphics -lsfml-window -lsfml-system)


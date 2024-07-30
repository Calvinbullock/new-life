# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/calvin/Documents/new-life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/calvin/Documents/new-life

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/calvin/Documents/new-life/CMakeFiles /home/calvin/Documents/new-life//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/calvin/Documents/new-life/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named newLifeEXE

# Build rule for target.
newLifeEXE: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 newLifeEXE
.PHONY : newLifeEXE

# fast build rule for target.
newLifeEXE/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/build
.PHONY : newLifeEXE/fast

creatures/creature.o: creatures/creature.cpp.o
.PHONY : creatures/creature.o

# target to build an object file
creatures/creature.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/creatures/creature.cpp.o
.PHONY : creatures/creature.cpp.o

creatures/creature.i: creatures/creature.cpp.i
.PHONY : creatures/creature.i

# target to preprocess a source file
creatures/creature.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/creatures/creature.cpp.i
.PHONY : creatures/creature.cpp.i

creatures/creature.s: creatures/creature.cpp.s
.PHONY : creatures/creature.s

# target to generate assembly for a file
creatures/creature.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/creatures/creature.cpp.s
.PHONY : creatures/creature.cpp.s

creatures/playerCreature.o: creatures/playerCreature.cpp.o
.PHONY : creatures/playerCreature.o

# target to build an object file
creatures/playerCreature.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/creatures/playerCreature.cpp.o
.PHONY : creatures/playerCreature.cpp.o

creatures/playerCreature.i: creatures/playerCreature.cpp.i
.PHONY : creatures/playerCreature.i

# target to preprocess a source file
creatures/playerCreature.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/creatures/playerCreature.cpp.i
.PHONY : creatures/playerCreature.cpp.i

creatures/playerCreature.s: creatures/playerCreature.cpp.s
.PHONY : creatures/playerCreature.s

# target to generate assembly for a file
creatures/playerCreature.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/creatures/playerCreature.cpp.s
.PHONY : creatures/playerCreature.cpp.s

items/item.o: items/item.cpp.o
.PHONY : items/item.o

# target to build an object file
items/item.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/items/item.cpp.o
.PHONY : items/item.cpp.o

items/item.i: items/item.cpp.i
.PHONY : items/item.i

# target to preprocess a source file
items/item.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/items/item.cpp.i
.PHONY : items/item.cpp.i

items/item.s: items/item.cpp.s
.PHONY : items/item.s

# target to generate assembly for a file
items/item.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/items/item.cpp.s
.PHONY : items/item.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/main.cpp.s
.PHONY : main.cpp.s

tileMap.o: tileMap.cpp.o
.PHONY : tileMap.o

# target to build an object file
tileMap.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/tileMap.cpp.o
.PHONY : tileMap.cpp.o

tileMap.i: tileMap.cpp.i
.PHONY : tileMap.i

# target to preprocess a source file
tileMap.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/tileMap.cpp.i
.PHONY : tileMap.cpp.i

tileMap.s: tileMap.cpp.s
.PHONY : tileMap.s

# target to generate assembly for a file
tileMap.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/newLifeEXE.dir/build.make CMakeFiles/newLifeEXE.dir/tileMap.cpp.s
.PHONY : tileMap.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... newLifeEXE"
	@echo "... creatures/creature.o"
	@echo "... creatures/creature.i"
	@echo "... creatures/creature.s"
	@echo "... creatures/playerCreature.o"
	@echo "... creatures/playerCreature.i"
	@echo "... creatures/playerCreature.s"
	@echo "... items/item.o"
	@echo "... items/item.i"
	@echo "... items/item.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... tileMap.o"
	@echo "... tileMap.i"
	@echo "... tileMap.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


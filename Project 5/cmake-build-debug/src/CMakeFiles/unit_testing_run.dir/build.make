# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/salva/Documents/Programming/Data Structures/Project 5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug"

# Include any dependencies generated for this target.
include src/CMakeFiles/unit_testing_run.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/unit_testing_run.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/unit_testing_run.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/unit_testing_run.dir/flags.make

src/CMakeFiles/unit_testing_run.dir/main.cpp.o: src/CMakeFiles/unit_testing_run.dir/flags.make
src/CMakeFiles/unit_testing_run.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/unit_testing_run.dir/main.cpp.o: src/CMakeFiles/unit_testing_run.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/unit_testing_run.dir/main.cpp.o"
	cd "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/unit_testing_run.dir/main.cpp.o -MF CMakeFiles/unit_testing_run.dir/main.cpp.o.d -o CMakeFiles/unit_testing_run.dir/main.cpp.o -c "/Users/salva/Documents/Programming/Data Structures/Project 5/src/main.cpp"

src/CMakeFiles/unit_testing_run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_testing_run.dir/main.cpp.i"
	cd "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/salva/Documents/Programming/Data Structures/Project 5/src/main.cpp" > CMakeFiles/unit_testing_run.dir/main.cpp.i

src/CMakeFiles/unit_testing_run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_testing_run.dir/main.cpp.s"
	cd "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/salva/Documents/Programming/Data Structures/Project 5/src/main.cpp" -o CMakeFiles/unit_testing_run.dir/main.cpp.s

# Object files for target unit_testing_run
unit_testing_run_OBJECTS = \
"CMakeFiles/unit_testing_run.dir/main.cpp.o"

# External object files for target unit_testing_run
unit_testing_run_EXTERNAL_OBJECTS =

src/unit_testing_run: src/CMakeFiles/unit_testing_run.dir/main.cpp.o
src/unit_testing_run: src/CMakeFiles/unit_testing_run.dir/build.make
src/unit_testing_run: src/CMakeFiles/unit_testing_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit_testing_run"
	cd "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_testing_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/unit_testing_run.dir/build: src/unit_testing_run
.PHONY : src/CMakeFiles/unit_testing_run.dir/build

src/CMakeFiles/unit_testing_run.dir/clean:
	cd "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src" && $(CMAKE_COMMAND) -P CMakeFiles/unit_testing_run.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/unit_testing_run.dir/clean

src/CMakeFiles/unit_testing_run.dir/depend:
	cd "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/salva/Documents/Programming/Data Structures/Project 5" "/Users/salva/Documents/Programming/Data Structures/Project 5/src" "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug" "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src" "/Users/salva/Documents/Programming/Data Structures/Project 5/cmake-build-debug/src/CMakeFiles/unit_testing_run.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/unit_testing_run.dir/depend

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
CMAKE_SOURCE_DIR = "/Users/salva/Documents/Programming/Data Structures/unit-testing"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug"

# Include any dependencies generated for this target.
include tst/CMakeFiles/Project_5_tst.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tst/CMakeFiles/Project_5_tst.dir/compiler_depend.make

# Include the progress variables for this target.
include tst/CMakeFiles/Project_5_tst.dir/progress.make

# Include the compile flags for this target's objects.
include tst/CMakeFiles/Project_5_tst.dir/flags.make

tst/CMakeFiles/Project_5_tst.dir/tests.cpp.o: tst/CMakeFiles/Project_5_tst.dir/flags.make
tst/CMakeFiles/Project_5_tst.dir/tests.cpp.o: ../tst/tests.cpp
tst/CMakeFiles/Project_5_tst.dir/tests.cpp.o: tst/CMakeFiles/Project_5_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tst/CMakeFiles/Project_5_tst.dir/tests.cpp.o"
	cd "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/Project_5_tst.dir/tests.cpp.o -MF CMakeFiles/Project_5_tst.dir/tests.cpp.o.d -o CMakeFiles/Project_5_tst.dir/tests.cpp.o -c "/Users/salva/Documents/Programming/Data Structures/unit-testing/tst/tests.cpp"

tst/CMakeFiles/Project_5_tst.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_5_tst.dir/tests.cpp.i"
	cd "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/salva/Documents/Programming/Data Structures/unit-testing/tst/tests.cpp" > CMakeFiles/Project_5_tst.dir/tests.cpp.i

tst/CMakeFiles/Project_5_tst.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_5_tst.dir/tests.cpp.s"
	cd "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/salva/Documents/Programming/Data Structures/unit-testing/tst/tests.cpp" -o CMakeFiles/Project_5_tst.dir/tests.cpp.s

# Object files for target Project_5_tst
Project_5_tst_OBJECTS = \
"CMakeFiles/Project_5_tst.dir/tests.cpp.o"

# External object files for target Project_5_tst
Project_5_tst_EXTERNAL_OBJECTS =

tst/Project_5_tst: tst/CMakeFiles/Project_5_tst.dir/tests.cpp.o
tst/Project_5_tst: tst/CMakeFiles/Project_5_tst.dir/build.make
tst/Project_5_tst: src/libProject_5_lib.a
tst/Project_5_tst: lib/libgtest.a
tst/Project_5_tst: tst/CMakeFiles/Project_5_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project_5_tst"
	cd "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_5_tst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tst/CMakeFiles/Project_5_tst.dir/build: tst/Project_5_tst
.PHONY : tst/CMakeFiles/Project_5_tst.dir/build

tst/CMakeFiles/Project_5_tst.dir/clean:
	cd "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst" && $(CMAKE_COMMAND) -P CMakeFiles/Project_5_tst.dir/cmake_clean.cmake
.PHONY : tst/CMakeFiles/Project_5_tst.dir/clean

tst/CMakeFiles/Project_5_tst.dir/depend:
	cd "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/salva/Documents/Programming/Data Structures/unit-testing" "/Users/salva/Documents/Programming/Data Structures/unit-testing/tst" "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug" "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst" "/Users/salva/Documents/Programming/Data Structures/unit-testing/cmake-build-debug/tst/CMakeFiles/Project_5_tst.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tst/CMakeFiles/Project_5_tst.dir/depend


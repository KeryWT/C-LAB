# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build"

# Include any dependencies generated for this target.
include CMakeFiles/A2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/A2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/A2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A2.dir/flags.make

CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o: CMakeFiles/A2.dir/flags.make
CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o: /Users/luca/Documents/UniTo/Anno\ 2/SO/C-LAB/lezioniC/esA2/A2.c
CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o: CMakeFiles/A2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o -MF CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o.d -o CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o -c "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/lezioniC/esA2/A2.c"

CMakeFiles/A2.dir/lezioniC/esA2/A2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/A2.dir/lezioniC/esA2/A2.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/lezioniC/esA2/A2.c" > CMakeFiles/A2.dir/lezioniC/esA2/A2.c.i

CMakeFiles/A2.dir/lezioniC/esA2/A2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/A2.dir/lezioniC/esA2/A2.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/lezioniC/esA2/A2.c" -o CMakeFiles/A2.dir/lezioniC/esA2/A2.c.s

# Object files for target A2
A2_OBJECTS = \
"CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o"

# External object files for target A2
A2_EXTERNAL_OBJECTS =

A2: CMakeFiles/A2.dir/lezioniC/esA2/A2.c.o
A2: CMakeFiles/A2.dir/build.make
A2: CMakeFiles/A2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable A2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/A2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A2.dir/build: A2
.PHONY : CMakeFiles/A2.dir/build

CMakeFiles/A2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/A2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/A2.dir/clean

CMakeFiles/A2.dir/depend:
	cd "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles/A2.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/A2.dir/depend

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
include CMakeFiles/main_pipe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_pipe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_pipe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_pipe.dir/flags.make

CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o: CMakeFiles/main_pipe.dir/flags.make
CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o: /Users/luca/Documents/UniTo/Anno\ 2/SO/C-LAB/unix/PIPE/main_pipe.c
CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o: CMakeFiles/main_pipe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o -MF CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o.d -o CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o -c "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/unix/PIPE/main_pipe.c"

CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/unix/PIPE/main_pipe.c" > CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.i

CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/unix/PIPE/main_pipe.c" -o CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.s

# Object files for target main_pipe
main_pipe_OBJECTS = \
"CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o"

# External object files for target main_pipe
main_pipe_EXTERNAL_OBJECTS =

main_pipe: CMakeFiles/main_pipe.dir/unix/PIPE/main_pipe.c.o
main_pipe: CMakeFiles/main_pipe.dir/build.make
main_pipe: CMakeFiles/main_pipe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main_pipe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_pipe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_pipe.dir/build: main_pipe
.PHONY : CMakeFiles/main_pipe.dir/build

CMakeFiles/main_pipe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_pipe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_pipe.dir/clean

CMakeFiles/main_pipe.dir/depend:
	cd "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles/main_pipe.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/main_pipe.dir/depend


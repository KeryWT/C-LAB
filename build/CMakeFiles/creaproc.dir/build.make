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
include CMakeFiles/creaproc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/creaproc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/creaproc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/creaproc.dir/flags.make

CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o: CMakeFiles/creaproc.dir/flags.make
CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o: /Users/luca/Documents/UniTo/Anno\ 2/SO/C-LAB/unix/lez4/creaproc.c
CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o: CMakeFiles/creaproc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o -MF CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o.d -o CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o -c "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/unix/lez4/creaproc.c"

CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/unix/lez4/creaproc.c" > CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.i

CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/unix/lez4/creaproc.c" -o CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.s

# Object files for target creaproc
creaproc_OBJECTS = \
"CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o"

# External object files for target creaproc
creaproc_EXTERNAL_OBJECTS =

creaproc: CMakeFiles/creaproc.dir/unix/lez4/creaproc.c.o
creaproc: CMakeFiles/creaproc.dir/build.make
creaproc: CMakeFiles/creaproc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable creaproc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/creaproc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/creaproc.dir/build: creaproc
.PHONY : CMakeFiles/creaproc.dir/build

CMakeFiles/creaproc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/creaproc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/creaproc.dir/clean

CMakeFiles/creaproc.dir/depend:
	cd "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build" "/Users/luca/Documents/UniTo/Anno 2/SO/C-LAB/build/CMakeFiles/creaproc.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/creaproc.dir/depend


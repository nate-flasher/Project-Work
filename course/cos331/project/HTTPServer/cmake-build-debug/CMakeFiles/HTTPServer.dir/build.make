# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2020.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HTTPServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HTTPServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HTTPServer.dir/flags.make

CMakeFiles/HTTPServer.dir/listener.c.o: CMakeFiles/HTTPServer.dir/flags.make
CMakeFiles/HTTPServer.dir/listener.c.o: ../listener.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HTTPServer.dir/listener.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/HTTPServer.dir/listener.c.o   -c /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/listener.c

CMakeFiles/HTTPServer.dir/listener.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HTTPServer.dir/listener.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/listener.c > CMakeFiles/HTTPServer.dir/listener.c.i

CMakeFiles/HTTPServer.dir/listener.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HTTPServer.dir/listener.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/listener.c -o CMakeFiles/HTTPServer.dir/listener.c.s

# Object files for target HTTPServer
HTTPServer_OBJECTS = \
"CMakeFiles/HTTPServer.dir/listener.c.o"

# External object files for target HTTPServer
HTTPServer_EXTERNAL_OBJECTS =

HTTPServer: CMakeFiles/HTTPServer.dir/listener.c.o
HTTPServer: CMakeFiles/HTTPServer.dir/build.make
HTTPServer: CMakeFiles/HTTPServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable HTTPServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HTTPServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HTTPServer.dir/build: HTTPServer

.PHONY : CMakeFiles/HTTPServer.dir/build

CMakeFiles/HTTPServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HTTPServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HTTPServer.dir/clean

CMakeFiles/HTTPServer.dir/depend:
	cd /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug /home/CS/users/nflasher/.linux/nflasher/course/cos331/project/HTTPServer/cmake-build-debug/CMakeFiles/HTTPServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HTTPServer.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/suxinxin/1.Code_learn/cJSON-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suxinxin/1.Code_learn/cJSON-master/build

# Include any dependencies generated for this target.
include CMakeFiles/cjson_utils.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cjson_utils.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cjson_utils.dir/flags.make

CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o: CMakeFiles/cjson_utils.dir/flags.make
CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o: ../cJSON_Utils.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/suxinxin/1.Code_learn/cJSON-master/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o   -c /home/suxinxin/1.Code_learn/cJSON-master/cJSON_Utils.c

CMakeFiles/cjson_utils.dir/cJSON_Utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cjson_utils.dir/cJSON_Utils.c.i"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/suxinxin/1.Code_learn/cJSON-master/cJSON_Utils.c > CMakeFiles/cjson_utils.dir/cJSON_Utils.c.i

CMakeFiles/cjson_utils.dir/cJSON_Utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cjson_utils.dir/cJSON_Utils.c.s"
	/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/suxinxin/1.Code_learn/cJSON-master/cJSON_Utils.c -o CMakeFiles/cjson_utils.dir/cJSON_Utils.c.s

CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.requires:
.PHONY : CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.requires

CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.provides: CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.requires
	$(MAKE) -f CMakeFiles/cjson_utils.dir/build.make CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.provides.build
.PHONY : CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.provides

CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.provides.build: CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o

# Object files for target cjson_utils
cjson_utils_OBJECTS = \
"CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o"

# External object files for target cjson_utils
cjson_utils_EXTERNAL_OBJECTS =

libcjson_utils.so.1.7.13: CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o
libcjson_utils.so.1.7.13: CMakeFiles/cjson_utils.dir/build.make
libcjson_utils.so.1.7.13: libcjson.so.1.7.13
libcjson_utils.so.1.7.13: CMakeFiles/cjson_utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library libcjson_utils.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cjson_utils.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libcjson_utils.so.1.7.13 libcjson_utils.so.1 libcjson_utils.so

libcjson_utils.so.1: libcjson_utils.so.1.7.13

libcjson_utils.so: libcjson_utils.so.1.7.13

# Rule to build all files generated by this target.
CMakeFiles/cjson_utils.dir/build: libcjson_utils.so
.PHONY : CMakeFiles/cjson_utils.dir/build

CMakeFiles/cjson_utils.dir/requires: CMakeFiles/cjson_utils.dir/cJSON_Utils.c.o.requires
.PHONY : CMakeFiles/cjson_utils.dir/requires

CMakeFiles/cjson_utils.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cjson_utils.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cjson_utils.dir/clean

CMakeFiles/cjson_utils.dir/depend:
	cd /home/suxinxin/1.Code_learn/cJSON-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suxinxin/1.Code_learn/cJSON-master /home/suxinxin/1.Code_learn/cJSON-master /home/suxinxin/1.Code_learn/cJSON-master/build /home/suxinxin/1.Code_learn/cJSON-master/build /home/suxinxin/1.Code_learn/cJSON-master/build/CMakeFiles/cjson_utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cjson_utils.dir/depend

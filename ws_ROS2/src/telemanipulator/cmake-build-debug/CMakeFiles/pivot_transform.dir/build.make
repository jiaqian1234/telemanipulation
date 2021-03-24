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
CMAKE_COMMAND = /home/lijiaqian/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lijiaqian/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lijiaqian/prak_ws/src/telemanipulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pivot_transform.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pivot_transform.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pivot_transform.dir/flags.make

CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.o: CMakeFiles/pivot_transform.dir/flags.make
CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.o: ../src/homogeneous_matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.o -c /home/lijiaqian/prak_ws/src/telemanipulator/src/homogeneous_matrix.cpp

CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lijiaqian/prak_ws/src/telemanipulator/src/homogeneous_matrix.cpp > CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.i

CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lijiaqian/prak_ws/src/telemanipulator/src/homogeneous_matrix.cpp -o CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.s

CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.o: CMakeFiles/pivot_transform.dir/flags.make
CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.o: ../src/pivot_transformation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.o -c /home/lijiaqian/prak_ws/src/telemanipulator/src/pivot_transformation.cpp

CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lijiaqian/prak_ws/src/telemanipulator/src/pivot_transformation.cpp > CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.i

CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lijiaqian/prak_ws/src/telemanipulator/src/pivot_transformation.cpp -o CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.s

# Object files for target pivot_transform
pivot_transform_OBJECTS = \
"CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.o" \
"CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.o"

# External object files for target pivot_transform
pivot_transform_EXTERNAL_OBJECTS =

libpivot_transform.so: CMakeFiles/pivot_transform.dir/src/homogeneous_matrix.cpp.o
libpivot_transform.so: CMakeFiles/pivot_transform.dir/src/pivot_transformation.cpp.o
libpivot_transform.so: CMakeFiles/pivot_transform.dir/build.make
libpivot_transform.so: CMakeFiles/pivot_transform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libpivot_transform.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pivot_transform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pivot_transform.dir/build: libpivot_transform.so

.PHONY : CMakeFiles/pivot_transform.dir/build

CMakeFiles/pivot_transform.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pivot_transform.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pivot_transform.dir/clean

CMakeFiles/pivot_transform.dir/depend:
	cd /home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lijiaqian/prak_ws/src/telemanipulator /home/lijiaqian/prak_ws/src/telemanipulator /home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug /home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug /home/lijiaqian/prak_ws/src/telemanipulator/cmake-build-debug/CMakeFiles/pivot_transform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pivot_transform.dir/depend


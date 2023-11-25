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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build

# Include any dependencies generated for this target.
include _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/flags.make

_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/flags.make
_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: _deps/box2d-src/extern/glad/src/gl.c
_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.o"
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.o -MF CMakeFiles/glad.dir/src/gl.c.o.d -o CMakeFiles/glad.dir/src/gl.c.o -c /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-src/extern/glad/src/gl.c

_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glad.dir/src/gl.c.i"
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-src/extern/glad/src/gl.c > CMakeFiles/glad.dir/src/gl.c.i

_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glad.dir/src/gl.c.s"
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-src/extern/glad/src/gl.c -o CMakeFiles/glad.dir/src/gl.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/gl.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

_deps/box2d-build/bin/libglad.a: _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/src/gl.c.o
_deps/box2d-build/bin/libglad.a: _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/build.make
_deps/box2d-build/bin/libglad.a: _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../bin/libglad.a"
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/build: _deps/box2d-build/bin/libglad.a
.PHONY : _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/build

_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/clean:
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/clean

_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/depend:
	cd /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-src/extern/glad /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad /home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build/extern/glad/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/box2d-build/extern/glad/CMakeFiles/glad.dir/depend


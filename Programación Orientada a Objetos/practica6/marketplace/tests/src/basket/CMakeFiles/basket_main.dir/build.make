# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests"

# Include any dependencies generated for this target.
include src/basket/CMakeFiles/basket_main.dir/depend.make

# Include the progress variables for this target.
include src/basket/CMakeFiles/basket_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/basket/CMakeFiles/basket_main.dir/flags.make

src/basket/CMakeFiles/basket_main.dir/basket_main.cc.o: src/basket/CMakeFiles/basket_main.dir/flags.make
src/basket/CMakeFiles/basket_main.dir/basket_main.cc.o: ../src/basket/basket_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/basket/CMakeFiles/basket_main.dir/basket_main.cc.o"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basket_main.dir/basket_main.cc.o -c "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/basket/basket_main.cc"

src/basket/CMakeFiles/basket_main.dir/basket_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basket_main.dir/basket_main.cc.i"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/basket/basket_main.cc" > CMakeFiles/basket_main.dir/basket_main.cc.i

src/basket/CMakeFiles/basket_main.dir/basket_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basket_main.dir/basket_main.cc.s"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/basket/basket_main.cc" -o CMakeFiles/basket_main.dir/basket_main.cc.s

# Object files for target basket_main
basket_main_OBJECTS = \
"CMakeFiles/basket_main.dir/basket_main.cc.o"

# External object files for target basket_main
basket_main_EXTERNAL_OBJECTS =

src/basket/basket_main: src/basket/CMakeFiles/basket_main.dir/basket_main.cc.o
src/basket/basket_main: src/basket/CMakeFiles/basket_main.dir/build.make
src/basket/basket_main: src/basket/libbasket.a
src/basket/basket_main: src/basket/CMakeFiles/basket_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basket_main"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basket_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/basket/CMakeFiles/basket_main.dir/build: src/basket/basket_main

.PHONY : src/basket/CMakeFiles/basket_main.dir/build

src/basket/CMakeFiles/basket_main.dir/clean:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket" && $(CMAKE_COMMAND) -P CMakeFiles/basket_main.dir/cmake_clean.cmake
.PHONY : src/basket/CMakeFiles/basket_main.dir/clean

src/basket/CMakeFiles/basket_main.dir/depend:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/basket" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/basket/CMakeFiles/basket_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/basket/CMakeFiles/basket_main.dir/depend


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
include src/market/CMakeFiles/market_main.dir/depend.make

# Include the progress variables for this target.
include src/market/CMakeFiles/market_main.dir/progress.make

# Include the compile flags for this target's objects.
include src/market/CMakeFiles/market_main.dir/flags.make

src/market/CMakeFiles/market_main.dir/market_main.cc.o: src/market/CMakeFiles/market_main.dir/flags.make
src/market/CMakeFiles/market_main.dir/market_main.cc.o: ../src/market/market_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/market/CMakeFiles/market_main.dir/market_main.cc.o"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/market_main.dir/market_main.cc.o -c "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/market/market_main.cc"

src/market/CMakeFiles/market_main.dir/market_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/market_main.dir/market_main.cc.i"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/market/market_main.cc" > CMakeFiles/market_main.dir/market_main.cc.i

src/market/CMakeFiles/market_main.dir/market_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/market_main.dir/market_main.cc.s"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/market/market_main.cc" -o CMakeFiles/market_main.dir/market_main.cc.s

# Object files for target market_main
market_main_OBJECTS = \
"CMakeFiles/market_main.dir/market_main.cc.o"

# External object files for target market_main
market_main_EXTERNAL_OBJECTS =

src/market/market_main: src/market/CMakeFiles/market_main.dir/market_main.cc.o
src/market/market_main: src/market/CMakeFiles/market_main.dir/build.make
src/market/market_main: src/market/libmarket.a
src/market/market_main: src/client/libclient.a
src/market/market_main: src/person/libperson.a
src/market/market_main: src/basket/libbasket.a
src/market/market_main: src/market/CMakeFiles/market_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable market_main"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/market_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/market/CMakeFiles/market_main.dir/build: src/market/market_main

.PHONY : src/market/CMakeFiles/market_main.dir/build

src/market/CMakeFiles/market_main.dir/clean:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market" && $(CMAKE_COMMAND) -P CMakeFiles/market_main.dir/cmake_clean.cmake
.PHONY : src/market/CMakeFiles/market_main.dir/clean

src/market/CMakeFiles/market_main.dir/depend:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/market" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/src/market/CMakeFiles/market_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/market/CMakeFiles/market_main.dir/depend


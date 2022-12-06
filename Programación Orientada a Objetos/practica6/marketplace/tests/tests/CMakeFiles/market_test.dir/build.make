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
include tests/CMakeFiles/market_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/market_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/market_test.dir/flags.make

tests/CMakeFiles/market_test.dir/market_test.cc.o: tests/CMakeFiles/market_test.dir/flags.make
tests/CMakeFiles/market_test.dir/market_test.cc.o: market_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/market_test.dir/market_test.cc.o"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/market_test.dir/market_test.cc.o -c "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/market_test.cc"

tests/CMakeFiles/market_test.dir/market_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/market_test.dir/market_test.cc.i"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/market_test.cc" > CMakeFiles/market_test.dir/market_test.cc.i

tests/CMakeFiles/market_test.dir/market_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/market_test.dir/market_test.cc.s"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/market_test.cc" -o CMakeFiles/market_test.dir/market_test.cc.s

# Object files for target market_test
market_test_OBJECTS = \
"CMakeFiles/market_test.dir/market_test.cc.o"

# External object files for target market_test
market_test_EXTERNAL_OBJECTS =

tests/market_test: tests/CMakeFiles/market_test.dir/market_test.cc.o
tests/market_test: tests/CMakeFiles/market_test.dir/build.make
tests/market_test: src/market/libmarket.a
tests/market_test: src/basket/libbasket.a
tests/market_test: lib/libgtest_main.a
tests/market_test: lib/libgtest.a
tests/market_test: src/client/libclient.a
tests/market_test: src/basket/libbasket.a
tests/market_test: src/person/libperson.a
tests/market_test: tests/CMakeFiles/market_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable market_test"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/market_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/market_test.dir/build: tests/market_test

.PHONY : tests/CMakeFiles/market_test.dir/build

tests/CMakeFiles/market_test.dir/clean:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests" && $(CMAKE_COMMAND) -P CMakeFiles/market_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/market_test.dir/clean

tests/CMakeFiles/market_test.dir/depend:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/tests/CMakeFiles/market_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/market_test.dir/depend


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
CMAKE_SOURCE_DIR = "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build"

# Include any dependencies generated for this target.
include tests/CMakeFiles/basket_test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/basket_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/basket_test.dir/flags.make

tests/CMakeFiles/basket_test.dir/basket_test.cc.o: tests/CMakeFiles/basket_test.dir/flags.make
tests/CMakeFiles/basket_test.dir/basket_test.cc.o: ../tests/basket_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/basket_test.dir/basket_test.cc.o"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basket_test.dir/basket_test.cc.o -c "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/basket_test.cc"

tests/CMakeFiles/basket_test.dir/basket_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basket_test.dir/basket_test.cc.i"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/basket_test.cc" > CMakeFiles/basket_test.dir/basket_test.cc.i

tests/CMakeFiles/basket_test.dir/basket_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basket_test.dir/basket_test.cc.s"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/basket_test.cc" -o CMakeFiles/basket_test.dir/basket_test.cc.s

# Object files for target basket_test
basket_test_OBJECTS = \
"CMakeFiles/basket_test.dir/basket_test.cc.o"

# External object files for target basket_test
basket_test_EXTERNAL_OBJECTS =

tests/basket_test: tests/CMakeFiles/basket_test.dir/basket_test.cc.o
tests/basket_test: tests/CMakeFiles/basket_test.dir/build.make
tests/basket_test: src/basket/libbasket.a
tests/basket_test: lib/libgtest_main.a
tests/basket_test: lib/libgtest.a
tests/basket_test: tests/CMakeFiles/basket_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basket_test"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basket_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/basket_test.dir/build: tests/basket_test

.PHONY : tests/CMakeFiles/basket_test.dir/build

tests/CMakeFiles/basket_test.dir/clean:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/basket_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/basket_test.dir/clean

tests/CMakeFiles/basket_test.dir/depend:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests/CMakeFiles/basket_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/basket_test.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src"

# Include any dependencies generated for this target.
include tests/CMakeFiles/product_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/product_test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/product_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/product_test.dir/flags.make

tests/CMakeFiles/product_test.dir/product_test.cc.o: tests/CMakeFiles/product_test.dir/flags.make
tests/CMakeFiles/product_test.dir/product_test.cc.o: ../tests/product_test.cc
tests/CMakeFiles/product_test.dir/product_test.cc.o: tests/CMakeFiles/product_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/product_test.dir/product_test.cc.o"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/product_test.dir/product_test.cc.o -MF CMakeFiles/product_test.dir/product_test.cc.o.d -o CMakeFiles/product_test.dir/product_test.cc.o -c "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/product_test.cc"

tests/CMakeFiles/product_test.dir/product_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/product_test.dir/product_test.cc.i"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/product_test.cc" > CMakeFiles/product_test.dir/product_test.cc.i

tests/CMakeFiles/product_test.dir/product_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/product_test.dir/product_test.cc.s"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests/product_test.cc" -o CMakeFiles/product_test.dir/product_test.cc.s

# Object files for target product_test
product_test_OBJECTS = \
"CMakeFiles/product_test.dir/product_test.cc.o"

# External object files for target product_test
product_test_EXTERNAL_OBJECTS =

tests/product_test: tests/CMakeFiles/product_test.dir/product_test.cc.o
tests/product_test: tests/CMakeFiles/product_test.dir/build.make
tests/product_test: src/product/libproduct.a
tests/product_test: lib/libgtest_main.a
tests/product_test: lib/libgtest.a
tests/product_test: tests/CMakeFiles/product_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable product_test"
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/product_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/product_test.dir/build: tests/product_test
.PHONY : tests/CMakeFiles/product_test.dir/build

tests/CMakeFiles/product_test.dir/clean:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests" && $(CMAKE_COMMAND) -P CMakeFiles/product_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/product_test.dir/clean

tests/CMakeFiles/product_test.dir/depend:
	cd "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests" "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica6/marketplace/src/tests/CMakeFiles/product_test.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/product_test.dir/depend


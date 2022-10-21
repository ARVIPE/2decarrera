# CMake generated Testfile for 
# Source directory: /home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests
# Build directory: /home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(person_gtests "person_test")
set_tests_properties(person_gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/CMakeLists.txt;18;add_test;/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/CMakeLists.txt;0;")
add_test(product_gtests "product_test")
set_tests_properties(product_gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/CMakeLists.txt;24;add_test;/home/arturo/Documentos/GitHub/2decarrera/Programación Orientada a Objetos/practica4/marketplace/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")

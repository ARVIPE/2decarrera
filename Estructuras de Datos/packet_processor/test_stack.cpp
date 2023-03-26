/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "stack.hpp"

int
main(int argc, const char* argv[])
{
    int exit_code = EXIT_SUCCESS;
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: test_stack test_case" << std::endl;
            return EXIT_FAILURE;
        }
        std::string filename = argv[1];

        std::ifstream input (argv[1]);
        if (!input)
        {
            std::cerr << "Error: could not open input filename '" << argv[1] << "'." << std::endl;
            return EXIT_FAILURE;
        }

        Stack<int> stack;

        while(input)
        {
            std::string operation;
            input >> operation;
            if (input)
            {
                if (operation == "PUSH")
                {
                    int value;
                    input >> value;
                    std::cout << "Pushing " << value << std::endl;
                    stack.push(value);
                } else if (operation == "POP")
                {
                    std::cout << "Popping" << std::endl;
                    stack.pop();
                } else if (operation == "TOP")
                {
                    std::cout << "Top is: " << stack.top() << std::endl;
                } else if (operation == "IS_EMPTY")
                {
                    std::cout << "Is it empty?: "
                              << (stack.is_empty() ? 'Y' : 'N') << std::endl;
                }
                else if (operation == "SIZE")
                {
                    std::cout << "Size: " << stack.size() << std::endl;
                }
                else
                {
                    std::cerr << "Error: unknown operation '"
                              << operation << "'." << std::endl;
                    return EXIT_FAILURE;
                }
            }
        }
    }
    catch(std::runtime_error &e)
    {
        std::cerr << "Run time exception: " << e.what() << std::endl;
        exit_code = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Catched unknown exception!." << std::endl;
        exit_code = EXIT_FAILURE;
    }
    return exit_code;
}


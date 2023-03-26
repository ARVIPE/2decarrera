/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

#include "btree.hpp"
#include "btree_utils.hpp"

int
main(int argc, const char* argv[])
{
    int exit_code = EXIT_SUCCESS;
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
            return EXIT_FAILURE;
        }
        std::ifstream input_file (argv[1]);
        if (!input_file)
        {
            std::cerr << "Error: could not open input filename '" << argv[1]
                      << "'." << std::endl;
            std::cerr << "Usage: test_tree filename" << std::endl;
            return EXIT_FAILURE;
        }

        std::vector<BTNode<char>::Ref> nodes(5);
        std::string command;
        std::cout << std::unitbuf;
        std::string line;
        while(input_file)
        {
            std::getline(input_file, line);
            if (input_file)
            {
                if (line != "" && line[0] != '#')
                {
                    std::istringstream input_line (line);
                    std::string command;
                    input_line >> command;

                    if (command == "CREATE_LEAF")
                    {
                        size_t idx;
                        char value;
                        input_line >> idx >> value;
                        if (input_line)
                        {
                            std::cout << "Creating leaf node " << idx << " ["
                                      << value << ']' << std::endl;
                            nodes[idx] = BTNode<char>::create(value);

                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "CREATE_NODE")
                    {
                        size_t idx, left_idx, right_idx;
                        char value;
                        input_line >> idx >> value >> left_idx >> right_idx;
                        if (input_line)
                        {
                            std::cout << "Created node " << idx << " ["
                                      << value << "] left_idx:" << left_idx
                                      << " right_idx:" << right_idx << std::endl;
                            nodes[idx] = BTNode<char>::create(value,
                                                             nodes[left_idx],
                                                             nodes[right_idx]);
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "ITEM")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Node " << idx << " item: '"
                                      << nodes[idx]->item() << "'." << std::endl;
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "HAS_LEFT")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Has node " << idx << " left child? : "
                                      << (nodes[idx]->left()!=nullptr ? "Y." : "N.")
                                      << std::endl;
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "HAS_RIGHT")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Has node " << idx << " right child? : "
                                      << (nodes[idx]->right()!=nullptr ? "Y." : "N.")
                                      << std::endl;
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "LEFT_NODE")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Node " << idx << " left child item: '"
                                      << nodes[idx]->left()->item() << "'."
                                      << std::endl;
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "RIGHT_NODE")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Node " << idx << " right child item: '"
                                      << nodes[idx]->right()->item() << "'."
                                      << std::endl;
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "REMOVE_LEFT_NODE")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Removing node " << idx << " left child."
                                      << std::endl;
                            nodes[idx]->set_left(nullptr);
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else if (command == "REMOVE_RIGHT_NODE")
                    {
                        size_t idx;
                        input_line >> idx;
                        if (input_line)
                        {
                            std::cout << "Removing node " << idx << " right child."
                                      << std::endl;
                            nodes[idx]->set_right(nullptr);
                        }
                        else
                        {
                            std::cerr << "Error: wrong input format of test file."
                                      << std::endl;
                            return EXIT_FAILURE;
                        }
                    }
                    else
                    {
                        std::cerr << "Error: unknown command '"<< command
                                  << "'." << std::endl;
                        return EXIT_FAILURE;
                    }
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


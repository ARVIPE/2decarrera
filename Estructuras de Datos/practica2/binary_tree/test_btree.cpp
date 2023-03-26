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
            std::cerr << "Usage: test_tree filename" << std::endl;
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

        auto tree = BTree<int>::create();
        std::string command;
        std::cout << std::unitbuf;
        while(input_file)
        {
            input_file >> command;
            if (input_file)
            {
                if (command == "IS_EMPTY")
                {
                    std::cout << "Is empty? " << (tree->is_empty() ? 'Y' : 'N')
                              << std::endl;
                }
                else if (command == "UNFOLD")
                {
                    std::cout << "Unfolding ...";
                    std::string line;
                    std::getline(input_file, line);
                    std::istringstream input (line);
                    try {
                        tree = BTree<int>::create(input);
                    }
                    catch(std::runtime_error &e)
                    {
                        std::cout << "Run time exception: " << e.what() << std::endl;
                    }
                    std::cout << std::endl;
                }
                else if (command == "FOLD")
                {
                    std::cout << "Folding ";
                    tree->fold(std::cout);
                    std::cout << std::endl;
                }
                else if (command == "ATTACH_LEFT")
                {
                    std::cout << "Attaching a new left child..." << std::endl;
                    tree->set_left(BTree<int>::create(input_file));
                }
                else if (command == "ATTACH_RIGHT")
                {
                    std::cout << "Attaching a new right child..." << std::endl;
                    tree->set_right(BTree<int>::create(input_file));
                }
                else if (command == "HEIGHT")
                {
                    std::cout << "Tree's height: " << compute_height<int>(tree)
                              << " ." << std::endl;
                }
                else if (command == "SIZE")
                {
                    std::cout << "Number of nodes: "
                              << compute_size<int>(tree)
                              << " ." << std::endl;
                }
                else if (command == "PRINT_PREFIX")
                {
                    std::cout << "Prefix output: ";
                    print_prefix<int>(std::cout, tree);
                    std::cout << std::endl;
                }
                else if (command == "PRINT_INFIX")
                {

                    std::cout << "Infix output: ";
                    print_infix<int>(std::cout, tree);
                    std::cout << std::endl;
                }
                else if (command == "PRINT_POSTFIX")
                {                    
                    std::cout << "Postfix output: ";
                    print_postfix<int>(std::cout, tree);
                    std::cout << std::endl;
                }
                else if (command == "PRINT_BREADTH_FIRST")
                {                    
                    std::cout << "Breath first output: ";
                    print_breadth_first<int>(std::cout, tree);
                    std::cout << std::endl;
                }
                else if (command == "PREFIX_SEARCH")
                {
                    int v;
                    input_file >> v;
                    if (!input_file)
                    {
                        std::cerr << "Error: input test file worng. "
                                  << std::endl;
                        return EXIT_FAILURE;
                    }
                    size_t count=0;                    
                    std::cout << "Has (prefix search): " << v << "?: "
                              << (search_prefix<int>(tree, v, count) ? 'Y' : 'N');
                    std::cout << ". Processed " << count << " nodes."
                              << std::endl;
                }
                else if (command == "INFIX_SEARCH")
                {
                    int v;
                    input_file >> v;
                    if (!input_file)
                    {
                        std::cerr << "Error: input test file worng. "
                                  << std::endl;
                        return EXIT_FAILURE;
                    }
                    size_t count=0;                    
                    std::cout << "Has (infix search): " << v << "?: "
                              << (search_infix<int>(tree, v, count) ? 'Y' : 'N');
                    std::cout << ". Processed " << count << " nodes."
                              << std::endl;
                }
                else if (command == "POSTFIX_SEARCH")
                {
                    int v;
                    input_file >> v;
                    if (!input_file)
                    {
                        std::cerr << "Error: input test file worng. "
                                  << std::endl;
                        return EXIT_FAILURE;
                    }
                    size_t count = 0;
                    std::cout << "Has (postfix search): " << v << "?: "
                              << (search_postfix<int>(tree, v, count) ? 'Y' : 'N');
                    std::cout << ". Processed " << count << " nodes."
                              << std::endl;
                }
                else if (command == "BREADTH_FIRST_SEARCH")
                {
                    int v;
                    input_file >> v;
                    if (!input_file)
                    {
                        std::cerr << "Error: input test file worng. "
                                  << std::endl;
                        return EXIT_FAILURE;
                    }
                    size_t count = 0;
                    std::cout << "Has (breadth first search): " << v << "?: "
                              << (search_breadth_first<int>(tree, v, count)? 'Y' : 'N');
                    std::cout << ". Processed " << count << " nodes."
                              << std::endl;
                }
                else if (command == "CHECK_IN_ORDER")
                {
                    std::cout << "Is it in order? "
                              << (check_btree_in_order<int>(tree)? 'Y' : 'N')
                              << std::endl;
                }
                else if (command == "HAS_IN_ORDER")
                {
                    int v;
                    input_file >> v;
                    if (!input_file)
                    {
                        std::cerr << "Error: input test file worng. "
                                  << std::endl;
                        return EXIT_FAILURE;
                    }
                    std::cout << "Is value " << v << " in ordered tree? "
                              << (has_in_order<int>(tree, v)? 'Y': 'N')
                              << std::endl;
                }
                else if (command == "INSERT_IN_ORDER")
                {
                    std::string line;
                    std::getline(input_file, line);
                    std::istringstream values (line);
                    int v;
                    std::cout << "Inserting in order ";
                    while (values >> v)
                    {
                        std::cout << v << ' ';
                        insert_in_order<int>(tree, v);
                    }
                    std::cout << '.' << std::endl;
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


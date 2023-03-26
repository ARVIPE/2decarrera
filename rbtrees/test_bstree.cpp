/**
 * @file test_RBTree.cpp
 *
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
#include <exception>
#include <vector>
#include <valarray>

#define __ONLY_BSTREE__
#include "rbtree.hpp"

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
            std::cerr << "Error: could not open input filename '"
                      << argv[1] << "'." << std::endl;
            std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
            return EXIT_FAILURE;
        }


        auto tree = RBTree<int>::create();
        RBTNode<int>::Ref node[10];
        std::string command;
        std::cout << std::unitbuf;
        while(input_file >> command)
        {
            if (command == "NODE_CREATE")
            {
                int idx;
                int item;
                input_file >> idx;
                input_file >> item;
                std::cout << "Creating node idx " << idx << " with item "
                          << item << std::endl;
                node[idx] = RBTNode<int>::create(item);
            }
            else if (command == "NODE_ITEM")
            {
                int idx;
                input_file >> idx;
                std::cout << "Node idx " << idx << " item: "
                          << node[idx]->item() << std::endl;
            }
            else if (command == "NODE_LEFT_CHILD")
            {
                int idx;
                input_file >> idx;
                std::cout << "Node idx " << idx << " left child's item = "
                          << node[idx]->left()->item() << std::endl;
            }
            else if (command == "NODE_RIGHT_CHILD")
            {
                int idx;
                input_file >> idx;
                std::cout << "Node idx " << idx << " right child's item = "
                          << node[idx]->right()->item() << std::endl;
            }
            else if (command == "NODE_ATTACH_LEFT")
            {
                int c_idx, p_idx;
                input_file >> c_idx >> p_idx;
                std::cout << "Attaching node idx " << c_idx
                          << " as left child of node idx " << p_idx
                          << std::endl;
                node[p_idx]->set_left(node[c_idx]);                
            }
            else if (command == "NODE_ATTACH_RIGHT")
            {
                int c_idx, p_idx;
                input_file >> c_idx >> p_idx;
                std::cout << "Attaching node idx " << c_idx
                          << " as right child of node idx " << p_idx
                          << std::endl;
                node[p_idx]->set_right(node[c_idx]);                
            }
            else if (command == "IS_EMPTY")
            {
                std::cout << "Is it empty? "
                          << (tree->is_empty() ? "Y." : "N.")
                          << std::endl;
            }
            else if (command == "UNFOLD")
            {
                try
                {
                    std::cout << "Unfold btree ... ";
                    tree = RBTree<int>::create(input_file);
                    std::cout << " ok." << std::endl;
                }
                catch (std::runtime_error& e)
                {
                    std::cout << "Input error: " << e.what() << std::endl;
                }
            }
            else if (command == "CREATE_PERFECTLY_BALANCED")
            {
                std::string buffer;
                std::getline(input_file, buffer);
                std::istringstream numbers (buffer);
                std::vector<int> data;
                int v;
                while(numbers>>v)
                    data.push_back(v);
                std::cout << "Creating a perfectly balanced bstree ... ";
                tree = create_perfectly_balanced_bstree<int>(data);
                std::cout << " ok. " << std::endl;
            }
            else if (command == "HAS")
            {
                int key;
                input_file >> key;
                if (!input_file)
                {
                    std::cerr << "Error: wrong format of test file."
                              << std::endl;
                    return EXIT_FAILURE;
                }
                std::cout << "Has key value " << key << " ?: "
                          << (tree->has(key) ? "Y.": "N.") << std::endl;
            }
            else if (command == "SEARCH")
            {
                int key;
                input_file >> key;
                if (!input_file)
                {
                    std::cerr << "Error: wrong format of test file."
                              << std::endl;
                    return EXIT_FAILURE;
                }
                std::cout << "Search for key value " << key << " ... "
                          << (tree->search(key) ? " found.": "not found.")
                          << std::endl;
            }
            else if (command == "CURRENT_EXISTS")
            {
                std::cout << "Has a current item? "
                          << (tree->current_exists() ? "Y." : "N.")
                          << std::endl;
            }
            else if (command == "CURRENT")
            {
                std::cout << "Current item: "
                          << tree->current() << std::endl;
            }
            else if (command == "INSERT")
            {
                std::string buffer;
                std::getline(input_file, buffer);
                std::istringstream numbers (buffer);
                int key;
                numbers >> key;
                std::cout << "Inserting ";
                while (numbers)
                {
                    std::cout << key << ' ';
                    tree->insert(key);
                    numbers >> key;
                }
                std::cout << std::endl;
            }
            else if (command == "REMOVE")
            {
                std::cout << "Removing key " << tree->current();
                tree->remove();
                std::cout << " ok." << std::endl;
            }
            else if (command == "FOLD")
            {
               tree->fold(std::cout);
               std::cout << std::endl;
            }
            else if (command == "HEIGHT")
            {
               std::cout << "Tree's height: " << compute_height<int>(tree) << std::endl;               
            }
            else if (command == "SIZE")
            {
               std::cout << "Tree's size: " << compute_size<int>(tree) << std::endl;               
            }
            else if (command == "CURRENT_LEVEL")
            {
               std::cout << "Current's level is: " << tree->current_level() << std::endl;
            }
            else
            {
                std::cerr << "Error: input command unknown '" << command
                          << "'." << std::endl;
                return EXIT_FAILURE;
            }
        }
    }
    catch(...)
    {
        std::cerr << "Catched unknown exception!." << std::endl;
        exit_code = EXIT_FAILURE;
    }
    return exit_code;
}


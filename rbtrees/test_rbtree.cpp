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
        std::istringstream input_line;
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
        std::string line;
        while(std::getline(input_file, line))
        {
            if (line[0]=='#')
                continue;

            input_line.clear();
            input_line.str(line);            
            input_line >> command;
            
            if (command == "NODE_CREATE")
            {
                int idx;
                int item;
                input_line >> idx;
                input_line >> item;
                std::cout << "Creating node idx " << idx << " with item "
                          << item << std::endl;
                node[idx] = RBTNode<int>::create(item);
            }
            else if (command == "NODE_ITEM")
            {
                int idx;
                input_line >> idx;
                std::cout << "Node idx " << idx << " item: "
                          << node[idx]->item() << std::endl;
            }
            else if (command == "NODE_PARENT")
            {
                int idx;
                input_line >> idx;
                std::cout << "Node idx " << idx << " parent's item = "
                          << node[idx]->parent()->item() << std::endl;
            }
            else if (command == "NODE_LEFT_CHILD")
            {
                int idx;
                input_line >> idx;
                std::cout << "Node idx " << idx << " left child's item = "
                          << node[idx]->left()->item() << std::endl;
            }
            else if (command == "NODE_RIGHT_CHILD")
            {
                int idx;
                input_line >> idx;
                std::cout << "Node idx " << idx << " right child's item = "
                          << node[idx]->right()->item() << std::endl;
            }
            else if (command == "NODE_ATTACH_LEFT")
            {
                int c_idx, p_idx;
                input_line >> c_idx >> p_idx;
                std::cout << "Attaching node idx " << c_idx
                          << " as left child of node idx " << p_idx
                          << std::endl;
                node[p_idx]->set_left(node[c_idx]);
                node[c_idx]->set_parent(node[p_idx]);
            }
            else if (command == "NODE_ATTACH_RIGHT")
            {
                int c_idx, p_idx;
                input_line >> c_idx >> p_idx;
                std::cout << "Attaching node idx " << c_idx
                          << " as right child of node idx " << p_idx
                          << std::endl;
                node[p_idx]->set_right(node[c_idx]);
                node[c_idx]->set_parent(node[p_idx]);
            }
            else if (command == "NODE_DETTACH_LEFT")
            {
                int idx;
                input_line >> idx;
                std::cout << "Dettaching left child of node idx " << idx
                          << std::endl;
                node[idx]->set_left(nullptr);
            }
            else if (command == "NODE_DETTACH_RIGHT")
            {
                int idx;
                input_line >> idx;
                std::cout << "Dettaching right child of node idx " << idx
                          << std::endl;
                node[idx]->set_right(nullptr);
            }
            else if (command == "NODE_COLOR")
            {
                int idx;
                input_line >> idx;
                std::cout << "Node ["<< idx << "] color is: "
                          << ((node[idx]->color()==RBTNode<int>::Color::BLACK) ? "Black" : "Red")
                          << std::endl;
            }
            else if (command == "NODE_SET_COLOR")
            {
                int idx;
                int c_idx;
                input_line >> idx >> c_idx;
                auto color = (c_idx == 0 ? RBTNode<int>::Color::BLACK : RBTNode<int>::Color::RED);                
                std::cout << "Setting node ["<< idx << "] color to "
                          << (c_idx==0 ? "Black" : "Red")
                          << std::endl;
                node[idx]->set_color(color);
            }
            else if (command == "NODE_ATTACH")
            {
                int child_idx;
                int parent_idx;
                int dir;
                input_line >> child_idx >> parent_idx >> dir;                
                std::cout << "Attaching node ["<< child_idx << "] to node ["
                          << parent_idx << "] as "
                          << (dir==0 ? "left" : "right") << " child."
                          << std::endl;
                node[parent_idx]->set_child(dir, node[child_idx]);
            }
            else if (command == "NODE_CHILD")
            {
                int node_idx;
                int dir;
                input_line >> node_idx >> dir;
                std::cout << "Node ["<< node_idx << "] "
                          << (dir==0 ? "left" : "right") << " child = "
                          << node[node_idx]->child(dir)->item()
                          << std::endl;                
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
                    tree = RBTree<int>::create(input_line);
                    std::cout << " ok." << std::endl;
                }
                catch (std::runtime_error& e)
                {
                    std::cout << "Input error: " << e.what() << std::endl;
                }
            }
#ifdef __ONLY_BSTREE__
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
#endif // __ONLY_BSTREE__
            else if (command == "HAS")
            {
                int key;
                input_line >> key;
                if (!input_line)
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
                input_line >> key;
                if (!input_line)
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
            else if (command == "CURRENT_LEVEL")
            {
                std::cout << "Current's level is " << tree->current_level()
                          << std::endl;
            }
            else if (command == "INSERT")
            {
                int key;
                std::cout << "Inserting ";
                while (input_line >> key)
                {            
                    std::cout << key << ' ';
                    tree->insert(key);
                }
                std::cout << std::endl;
            }
            else if (command == "REMOVE")
            {
                std::cout << "Removing ";
                int key;
                while (input_line >> key)
                {
                    std::cout << " [ " << key;
                    if (tree->search(key))
                    {
                        tree->remove();
                        std::cout << " ok]";
                    }
                    else
                        std::cout << " not found]";
                }
                std::cout << std::endl;
            }
            else if (command == "FOLD")
            {
               tree->fold(std::cout);
               std::cout << std::endl;
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


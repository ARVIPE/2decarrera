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
#include <vector>

#include "packet_processor.hpp"

/** @brief Load a test case.*/
bool
load_test_case(std::istream& in,
               size_t& buffer_size,
               std::vector <Packet>& requests)
{
    requests.resize(0);
    int count;
    in >> buffer_size >> count;
    if (!in)
        return false;
    for (int i = 0; i < count; ++i)
    {
        int arrival_time, process_time;
        in >> arrival_time >> process_time;
        if (!in)
            return false;
        requests.push_back(Packet(arrival_time, process_time));
    }
    return true;
}

int
main(int argc, const char* argv[])
{
    int exit_code = EXIT_SUCCESS;
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage: packet_processor filename" << std::endl;
            return EXIT_FAILURE;
        }

        std::ifstream input (argv[1]);
        if (!input)
        {
            std::cerr << "Error: could not open input filename '" << argv[1] << "'." << std::endl;
            std::cerr << "Usage: packet_processor filename" << std::endl;
            return EXIT_FAILURE;
        }

        size_t buffer_size;
        std::vector <Packet> packets;
        if (!load_test_case(input, buffer_size, packets))
        {
            std::cerr << "Error: wrong input format." << std::endl;
            return EXIT_FAILURE;
        }

        PacketProcessor processor(buffer_size);
        std::vector <Response> responses = process_packets(packets, processor);
        write_responses(std::cout, responses);
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


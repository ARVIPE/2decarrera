/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <iostream>
#include <vector>

#include "queue.hpp"


/** @brief Models a Packet.
 * We are only interested in the arrival time and
 * how much time is spent to be processed.
*/
struct Packet {
    Packet():
        arrival_time(0), process_time(0)
    {}
    Packet(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

/** @brief Models the response to a incoming packet.
 * The package can be processed at any given time or be dropped if the
 * processor buffer is full at the time of arrival.
*/
struct Response
{
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

/** @brief Models the packet processor.*/
class PacketProcessor
{
public:
    /**
     * @brief Create a packet processor with a queue for at most size packets.
     */
    PacketProcessor(size_t size);

    /**
     * @brief generate the response when a packet arrives.
     */
    Response process(const Packet &packet);

protected:

    size_t _max_size; /**< Max number of packets. */
    Queue <int> _finish_time; /**< Saves the finishing times for packets
                                waiting to be processed **/
};

/** @brief process the packets and generate a response for each of them.*/
std::vector <Response> process_packets(const std::vector <Packet> &packets,
                PacketProcessor& p);

/** @brief print the processing start times for the packets.*/
std::ostream& write_responses(std::ostream& out,
                              const std::vector <Response> &responses);

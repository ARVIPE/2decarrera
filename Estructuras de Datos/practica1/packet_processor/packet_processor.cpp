/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */

#include "packet_processor.hpp"

PacketProcessor::PacketProcessor(size_t size) : _max_size(size),
                                                _finish_time()
{
}

Response PacketProcessor::process(const Packet &packet)
{
    Response ret(true, 0); // Default is to drop the packet.
    // TODO
    // First: deque all processed packets at packet time arrival.
    auto ultimo = packet.arrival_time;
    if (not _finish_time.is_empty())
    {
        ultimo = _finish_time.back();
        while (not _finish_time.is_empty() and _finish_time.front() <= packet.arrival_time)
        {
            _finish_time.deque();
        }
    }
    //
    // Second: Is there any place for this packet in the queue?
    if (_finish_time.size() < _max_size)
    {
        // This packet will be processed after the last packet is processed and
        // its completion time will be 'package processing time' later time units.
        // Remember that the queue saves the finish processing time for the packets.
        // Remember to update the returned response.
        ret.dropped = false;
        if (packet.arrival_time > ultimo)
            ret.start_time = packet.arrival_time;
        else
            ret.start_time = ultimo;
        _finish_time.enque(ultimo + packet.process_time);
        //
    }
    return ret;
}

/** @brief process the packets and generate a response for each of them.*/
std::vector<Response>
process_packets(const std::vector<Packet> &packets,
                PacketProcessor &p)
{
    std::vector<Response> responses;
    for (size_t i = 0; i < packets.size(); ++i)
    {
        responses.push_back(p.process(packets[i]));
    }
    return responses;
}

/** @brief print the processing start times for the packets.*/
std::ostream &
write_responses(std::ostream &out, const std::vector<Response> &responses)
{
    for (size_t i = 0; i < responses.size(); ++i)
        out << (responses[i].dropped ? -1 : responses[i].start_time)
            << std::endl;
    return out;
}

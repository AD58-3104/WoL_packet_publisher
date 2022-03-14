#include <string>
#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include <chrono>

struct magicPacket
{
    magicPacket(const std::string &target_mac_addr) : str()
    {
        for (size_t i = 0; i < 6; ++i)
        {
            str.push_back(FF);
            if(i != 5){
                str.push_back(':');
            }
        }

        for (size_t i = 0; i < 16; i++)
        {
            str.insert(str.end(), target_mac_addr.begin(), target_mac_addr.end());
        }
    }
    const uint8_t FF = {0xff};
    std::string str;
};

void sendPacket(std::string target_mac_addr, std::string target_broadcast_addr = "")
{
    using namespace boost::asio::ip;
    boost::asio::io_service io_srv;
    uint32_t port = 7650;
    magicPacket packet(target_mac_addr);
    if (target_broadcast_addr.empty())
    {
        target_broadcast_addr = "192.168.0.255";
    }
    udp::socket sock(io_srv, udp::endpoint(udp::v4(), port));
    std::cout << "Sending magic packet to " << target_mac_addr << " in " <<  target_broadcast_addr << " ...\n";
    for (int i = 0; i < 20; ++i)
    {
        sock.send_to(boost::asio::buffer(packet.str), udp::endpoint(address::from_string(target_broadcast_addr), port));
         using namespace std::literals::chrono_literals;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "End sending.\n";
}
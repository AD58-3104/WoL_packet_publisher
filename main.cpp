#include "publisher.hpp"

int main(int argc, char const *argv[])
{
    std::string target_MAC_ADDR;
    std::string target_Broadcast_ADDR;
    if(argc < 2){
        std::cout << "Please input target mac address.\n";
        return 0;
    }
    else if(argc == 2){
        target_MAC_ADDR = argv[1];
        sendPacket(target_MAC_ADDR);
    }
    else if(argc == 3){
        target_MAC_ADDR = argv[1];
        target_Broadcast_ADDR = argv[2];
        sendPacket(target_MAC_ADDR,target_Broadcast_ADDR);
    }
    return 0;
}

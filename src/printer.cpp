#include "printer.h"
#include "helpers/protocol_keyword.h"

using std::setw;
using std::left;

void printEthernetFrame(const EtherFrame &frame)
{

    std::cout << "┌───────────────────────────────────────────────────┐\n";
    std::cout << "│ "
              << left << setw(17) << "DST"
              << left << setw(17) << "SRC"
              << left << setw(10) << "TYPE"
              << left << setw(5)  << "DATA  │" 
              << "\n";

    std::cout << "│ "
              << left << setw(17) << frame.destStr()
              << left << setw(17) << frame.sourceStr()
              << left << setw(10) << frame.typeStr()
              << left << setw(5) << frame.getPayloadLen()
              << " │" << "\n";
    std::cout << "├───────────────────────────────────────────────────┤\n";
}

void printIPV4(const IpHeader& header)
{
    std::cout << "│ "
              << left << setw(10) << "VERSION"
              << left << setw(10) << "IHL"
              << left << setw(10) << "TOS"
              << left << setw(19) << "TOTAL LENGTH"
              << " │\n";

    std::cout << "│ "
              << left << setw(10) << header.versionStr()
              << left << setw(10) << header.strIHL()
              << left << setw(10) << "to add"
              << left << setw(19) << header.totalLength()
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << "IDENTIFICATION"
              << left << setw(10) << "FLAGS"
              << left << setw(19) << "FRAGMENT OFFSET"
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << header.id()
              << left << setw(10) << header.flags()
              << left << setw(19) << header.fragOffset()
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << "TIME TO LIVE"
              << left << setw(10) << "PROTOCOL"
              << left << setw(19) << "CHECKSUM"
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << header.getTTL()
              << left << setw(10) << toKeyword(header.getProtocol())
              << left << setw(19) << header.getChecksum()
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << "SOURCE ADDRESS"
              << left << setw(25) << "DESTINATION ADDRESS"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.srcStr()
              << left << setw(25) << header.dstStr()
              << " │\n";

    std::cout << "├───────────────────────────────────────────────────┤\n";
    
}

void printTCP(const TcpHeader& header)
{
    std::cout << "│ "
              << left << setw(24) << "SOURCE PORT"
              << left << setw(25) << "DESTINATION PORT"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.sourcePort()
              << left << setw(25) << header.destPort()
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << "SEQUENCE NUMBER"
              << left << setw(25) << "ACK NUMBER"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.seq()
              << left << setw(25) << header.ack()
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << "HDR LEN (bytes)"
              << left << setw(25) << "FLAGS"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.headerLengthBytes()
              << left << setw(25) << tcpFlags(header.flags)
              << " │\n";

    std::cout << "└───────────────────────────────────────────────────┘\n";
}

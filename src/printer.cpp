#include "printer.h"

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
              << left << setw(10) << "---"
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
              << left << setw(10) << protocolKeyword(header.getProtocol())
              << left << setw(19) << header.getChecksum()
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << "SOURCE ADDRESS"
              << left << setw(29) << "DESTINATION ADDRESS"
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << header.srcStr()
              << left << setw(29) << header.dstStr()
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
              << left << setw(25) << tcpFlags(header.flags, "|")
              << " │\n";

    std::cout << "└───────────────────────────────────────────────────┘\n";
}

void printUDP(const UdpHeader& header)
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
              << left << setw(24) << "LENGTH"
              << left << setw(25) << "CHECKSUM"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.length()
              << left << setw(25) << header.checksum()
              << " │\n";

    std::cout << "├───────────────────────────────────────────────────┤\n";
}

void printICMP(const IcmpHeader& header)
{
    std::cout << "│ "
              << left << setw(20) << "TYPE"
              << left << setw(20) << "CODE"
              << left << setw(9) << "CHECKSUM"
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << header.getType()
              << left << setw(20) << header.getCode()
              << left << setw(9) << header.getChecksum()
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << "IDENTIFIER"
              << left << setw(29) << "SEQUENCE"
              << " │\n";

    std::cout << "│ "
              << left << setw(20) << header.getIdentifier()
              << left << setw(29) << header.getSequence()
              << " │\n";

    std::cout << "└───────────────────────────────────────────────────┘\n";
}

void printDNS(const DnsHeader& header)
{
    std::cout << "│ " << left << setw(49) << "DNS" << " │\n";
    
    std::cout << "│ "
              << left << setw(24) << "ID"
              << left << setw(25) << "FLAGS"
              << " │\n";

    std::cout << "│ "
            << std::left << std::setw(24) << header.getId();

    const auto flags = dnsFlags(header.getFlags());

    std::size_t counter = 0;
    std::string buffer;
    bool firstLine = true;

    for (std::size_t i = 0; i < flags.size(); ++i)
    {
        if (!buffer.empty())
            buffer += '|';

        buffer += flags[i];
        ++counter;

        const bool lastItem = (i == flags.size() - 1);

        if (counter == 3 or lastItem)
        {
            if (firstLine)
            {
                std::cout << std::left << std::setw(25) << buffer << " │\n";
                firstLine = false;
            }
            else
            {
                std::cout << "│ "
                        << std::left << std::setw(24) << ""
                        << std::left << std::setw(25) << buffer << " │\n";
            }

            buffer.clear();
            counter = 0;
        }
    }

    std::cout << "│ "
              << left << setw(24) << "QUESTION COUNT"
              << left << setw(25) << "ANSWER COUNT"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.getQuestionCount()
              << left << setw(25) << header.getAnswerCount()
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << "AUTH COUNT"
              << left << setw(25) << "ADDITIONAL COUNT"
              << " │\n";

    std::cout << "│ "
              << left << setw(24) << header.getAuthCount()
              << left << setw(25) << header.getAdditionalCount()
              << " │\n";

    std::cout << "└───────────────────────────────────────────────────┘\n";
}
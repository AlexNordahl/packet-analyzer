#include "file_printer.h"

void FilePrinter::printEthernet(const EtherFrame &frame) const
{
    std::cout << "Ethernet saved\n";
}

void FilePrinter::printARP(const ArpHeader &header) const
{
    std::cout << "ARP saved\n";
}

void FilePrinter::printIPV4(const IpHeader &header) const
{
    std::cout << "IPV4 saved\n";
}

void FilePrinter::printTCP(const TcpHeader &header) const
{
    std::cout << "TCP saved\n";
}

void FilePrinter::printUDP(const UdpHeader &header) const
{
    std::cout << "UDP saved\n";
}

void FilePrinter::printICMP(const IcmpHeader &header) const
{
    std::cout << "ICMP saved\n";
}

void FilePrinter::printDNS(const DnsHeader &header) const
{
    std::cout << "DNS saved\n";
}
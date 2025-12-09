#ifndef PRINTER_H
#define PRINTER_H

#include "../net_headers/all_net_headers.h"

class Printer
{
public:
    virtual void printEthernet(const EtherFrame& frame) const = 0;
    virtual void printARP(const ArpHeader& header) const = 0;
    virtual void printIPV4(const IpHeader& header) const = 0;
    virtual void printTCP(const TcpHeader& header) const = 0;
    virtual void printUDP(const UdpHeader& header) const = 0;
    virtual void printICMP(const IcmpHeader& header) const = 0;
    virtual void printDNS(const DnsHeader& header) const = 0;

    virtual ~Printer() = default;

private:
};

#endif
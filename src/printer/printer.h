#ifndef PRINTER_H
#define PRINTER_H

#include "../net_headers/all_net_headers.h"
#include "../helpers/readable_protocols.h"
#include <iomanip>
#include <iostream>

void printEthernetFrame(const EtherFrame& frame);
void printARP(const ArpHeader& header);
void printIPV4(const IpHeader& header);
void printTCP(const TcpHeader& header);
void printUDP(const UdpHeader& header);
void printICMP(const IcmpHeader& header);
void printDNS(const DnsHeader& header);

#endif
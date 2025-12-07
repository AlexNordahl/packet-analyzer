#ifndef PRINTER_H
#define PRINTER_H

#include "net_headers/ether_frame.h"
#include "net_headers/ip_header.h"
#include "net_headers/arp_header.h"
#include "net_headers/tcp_header.h"
#include "net_headers/udp_header.h"
#include "net_headers/icmp_header.h"
#include "net_headers/dns_header.h"
#include "helpers/readable_protocols.h"
#include <iomanip>
#include <iostream>

void printEthernetFrame(const EtherFrame& frame);
void printIPV4(const IpHeader& header);
void printTCP(const TcpHeader& header);
void printUDP(const UdpHeader& header);
void printICMP(const IcmpHeader& header);
void printDNS(const DnsHeader& header);

#endif
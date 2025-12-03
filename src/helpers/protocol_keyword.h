#ifndef READABLE_PROTOCOLS_H
#define READABLE_PROTOCOLS_H

namespace protocol
{

std::string toKeyword(const int decimal)
{
    switch (decimal)
    {
    case 1: return "ICMP";
    case 2: return "IGMP";
    case 3: return "GGP";
    case 4: return "IPV4";
    case 5: return "ST";
    case 6: return "TCP";
    case 7: return "CBT";
    case 8: return "EGP";
    case 9: return "IGP";
    case 17: return "UDP";
    default: return "?";
    }
}

}

#endif
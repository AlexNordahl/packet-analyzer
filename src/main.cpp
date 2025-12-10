#include <iostream>
#include <optional>
#include "pcap_facade.h"
#include "printer/console_printer.h"
#include "printer/file_printer.h"
#include "helpers/parsers.h"

std::optional<std::string> handleCommandLineArgs(int argc, char const* argv[]);
void parseAndPrintFrame(const EtherFrame& frame, const u_char* payload, const Printer& pr);

constexpr int snaplex_max = 65535;
constexpr int timeout_ms = 1000;

int main(int argc, char const* argv[])
{
    PcapFacade pf;
    pf.autoSelectDevice();
    pf.configure(snaplex_max, true, timeout_ms);
    pf.activate();

    auto arguments = handleCommandLineArgs(argc, argv);
    if (arguments.has_value())
    {
        pf.setFilter(arguments.value().c_str());
    }

    while (true)
    {
        const auto [frame, payload] = pf.next();
        const ConsolePrinter printer {};
        parseAndPrintFrame(frame, payload, printer);
        std::cout << "\n";
    }
}

std::optional<std::string> handleCommandLineArgs(int argc, char const *argv[])
{
    if (argc == 1)
        return std::nullopt;

    if (argc != 3)
        throw std::invalid_argument("Usage: program -f \"protocol or protocol or...\"");

    if (strcmp(argv[1], "-f") != 0 or strcmp(argv[1],"--filter") != 0)
        throw std::invalid_argument("Usage: program -f \"protocol or protocol or...\"");

    return {argv[2]};
}

void parseAndPrintFrame(const EtherFrame& frame, const u_char* payload, const Printer& pr)
{
    pr.printEthernet(frame);
    
    if (frame.type == ETHERTYPE_ARP)
    {
        auto arpHeader = parseARP(payload);
        pr.printARP(arpHeader);
    }
    else if (frame.type == ETHERTYPE_IP)
    {
        const auto [header, ipData] = parseIPV4(payload);
        pr.printIPV4(header);

        switch (header.protocol)
        {
            case IPPROTO_TCP:
            {
                const auto [header, tcpData] = parseTCP(ipData);
                pr.printTCP(header);
                break;
            }
            case IPPROTO_UDP:
            {
                const auto [header, udpData, dataLen] = parseUDP(ipData);
                pr.printUDP(header);

                if (header.destPort() == 53)
                {
                    const auto dns = parseDNS(udpData);
                    pr.printDNS(dns);
                }
                break;
            }
            case IPPROTO_ICMP:
            {
                const auto header = parseICMP(ipData);
                pr.printICMP(header);
                break;
            }

            default: break;
        }
    }
}
# gRPC Chat

## Motivation

Simple traffic sniffing tool that displays information about incoming and outgoing packets on chosen interface. Tailored C++17 facade layer was created over C-based pcap library, providing a clean, modern, and type-safe API for packet capture. Tool displays information in nice readable format that's very approachable for beginners providing a learning oportunity.

## Example

Below is an example of captured packets:

![TCP Example](/examples/arp_broadcast.png)
![TCP Example](/examples/dns.png)

## Features
- Message timestamps
- Colored logs

## Usage

### List available network interfaces
./main --list

### Start sniffing on a specific interface
./main -i eth0

### Apply a capture filter
./main -i wlan0 -f "tcp or udp"

## Future Improvements

Ideas for the future:
- Storing results in a file
- Support for IPv6
- Export captured packets to PCAP files
- JSON/CSV output formatting
- Live terminal dashboard (ncurses) or Web UI
- Protocol-specific analysis plugins
- Extended IPv6 support

## Design Overview
The `pcap_facade` module wraps raw libpcap functions into a type-safe C++17 interface.  
It ensures RAII-based resource management, error-safe packet handling, and clean separation between:
- packet capture layer  
- packet parsing layer  
- output/printing layer  

## Build Instructions

```bash
# Configure (Debug + tests)
cmake -S . -B build

# Build
cmake --build build -j

# Run example
./build/main
```
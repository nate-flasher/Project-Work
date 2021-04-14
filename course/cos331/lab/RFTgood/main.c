
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>
#include <arpa/inet.h>


#define IP_SRC "127.0.0.1"
#define IP_DST "127.0.0.1"
#define UDP_SRC_PORT 12345
#define UDP_SRC_DEST 54321

int main() {

    struct ip ip_header;
    struct udphdr udp_header;
    char * data = "Hello World!";

    struct in_addr from_ip;
    struct in_addr to_ip;

    unsigned short total_dgram_size = sizeof(ip_header) + sizeof(udp_header) + strlen(data);


    ip_header.ip_v = 4; //IPv4
    ip_header.ip_hl = 5; //header length = 5
    ip_header.ip_tos = 0; //type of service

#if defined(linux) || defined(__OpenBSD) || defined(__APPLE__)
    ip_header.ip_len = htons(total_dgram_size);
#else
    ip_header.ip_len = total_dgram_size;
#endif

    ip_header.ip_id = 0; //identification
    ip_header.ip_off = 0; //fragmentation offset
    ip_header.ip_ttl = 255; //how long packet is in network before it gets thrown away, each time packet is sent between routers, value is decremented
    ip_header.ip_p = IPPROTO_UDP; //sets protocol to UDP
    ip_header.ip_sum = 0; //header checksum (always set to 0, operating system takes care of it for us)


    from_ip.s_addr = inet_addr(IP_SRC);
    ip_header.ip_src = from_ip; //sets source ip address

    to_ip.s_addr = inet_addr(IP_DST);
    ip_header.ip_dst = to_ip; //sets destination ip address


    return 0;
}
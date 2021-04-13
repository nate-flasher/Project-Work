
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>

int main() {

    struct ip ip_header;
    struct udphdr udp_header;
    char * data = "Hello World!";

    unsigned short total_dgram_size = sizeof(ip_header) + sizeof(udp_header) + strlen(data);


    ip_header.ip_v = 4;
    ip_header.ip_hl = 5;
    ip_header.ip_tos = 0;
    ip_header.ip_len = total_dgram_size;


    return 0;
}
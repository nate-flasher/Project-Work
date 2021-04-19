
#include <stdio.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>


#define IP_SRC "127.0.0.1"
#define IP_DST "127.0.0.1"
#define UDP_SRC_PORT 12345
#define UDP_SRC_DEST 54321


struct pseudo_ip_header {
    struct  in_addr ip_src;
    struct  in_addr ip_dst;
    u_char  unused; // set to zero
    u_char  ip_p;
    u_short uh_ulen;
};

unsigned short checksum1(const char *buf, unsigned size)
{
    unsigned sum = 0;
    int i;

    /* Accumulate checksum */
    for (i = 0; i < size - 1; i += 2)
    {
        unsigned short word16 = *(unsigned short *) &buf[i];
        sum += word16;
    }

    /* Handle odd-sized case */
    if (size & 1)
    {
        unsigned short word16 = (unsigned char) buf[i];
        sum += word16;
    }

    /* Fold to get the ones-complement result */
    while (sum >> 16) sum = (sum & 0xFFFF)+(sum >> 16);

    /* Invert to get the negative in ones-complement arithmetic */
    return (unsigned short) ~sum;
}

int main() {

    struct ip ip_header;
    struct udphdr udp_header;
    struct pseudo_ip_header faked_ip_header_for_checksum;
    char * fake_dgram_for_udp_checksum;
    char * data = "Hello World!";
    short total_fake_dgram_size = sizeof(faked_ip_header_for_checksum) + sizeof(udp_header) + strlen(data);


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
    ip_header.ip_sum = 0; //header checksum (always set to 0, operating system takes care of it for us, always filled in by Linux kernel)


    from_ip.s_addr = inet_addr(IP_SRC);
    ip_header.ip_src = from_ip; //sets source ip address

    to_ip.s_addr = inet_addr(IP_DST);
    ip_header.ip_dst = to_ip; //sets destination ip address


    udp_header.uh_sport = htons(UDP_SRC_PORT); //sets udp header source port to our source port global variable
    udp_header.uh_dport = htons(UDP_SRC_DEST); //sets udp header destination port to our destination port global variable
    udp_header.uh_ulen = htons(sizeof(udp_header) + strlen(data)); //sets udp header length
    udp_header.uh_sum = 0; //checksum field set to 0


    //need to fill in new (fake) ip header values to use for checksum
    faked_ip_header_for_checksum.ip_src = ip_header.ip_src;
    faked_ip_header_for_checksum.ip_dst = ip_header.ip_dst;
    faked_ip_header_for_checksum.unused = 0;
    faked_ip_header_for_checksum.ip_p = ip_header.ip_p;
    faked_ip_header_for_checksum.uh_ulen = udp_header.uh_ulen;

    fake_dgram_for_udp_checksum = malloc(total_fake_dgram_size); //creating memory on heap
    memset(fake_dgram_for_udp_checksum, 0, total_fake_dgram_size); // zeroes out memory in that buffer

    char * cursor = fake_dgram_for_udp_checksum;
    memcpy(cursor, &faked_ip_header_for_checksum, sizeof(faked_ip_header_for_checksum)); //puts faked ip header into beginning of buffer
    cursor += sizeof(faked_ip_header_for_checksum); //updates cursor

    memcpy(cursor, &udp_header, sizeof(udp_header)); //puts udp header into next part of buffer
    cursor += sizeof(udp_header); //updates cursor

    memcpy(cursor, &data, strlen(data)); //puts our data into end of buffer...we now have our buffer filled and is rdy to generate our udp checksum!

    udp_header.uh_sum = checksum1(fake_dgram_for_udp_checksum, total_fake_dgram_size); //creates udp checksum
    free(fake_dgram_for_udp_checksum);


    return 0;
}
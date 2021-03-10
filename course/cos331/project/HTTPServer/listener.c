#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <memory.h>
#include <string.h>

#define MYHOST "localhost"
#define MYPORT "8080"

int main() {

    struct addrinfo hints;
    struct addrinfo * address_resource;
    int socket_descriptor;
    int return_value;

    memset(&hints, 0, sizeof(hints)); //clears out any data in hints struct before we write to it

    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP connection, not UDP
    hints.ai_flags = AI_PASSIVE; // Specifies socket to listen

    return_value = getaddrinfo(MYHOST, MYPORT, &hints, &address_resource);

    if(return_value != 0){
        printf("Error: getaddrinfo failed");
        return 1;
    }

    socket_descriptor = socket(
            address_resource->ai_family, //IPv4
            address_resource->ai_socktype, // Streaming Protocol
            address_resource->ai_protocol //TCP
            );

    return 0;
}

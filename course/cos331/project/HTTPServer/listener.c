#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <memory.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MYHOST "localhost"
//#define MYPORT "8080"
#define MAX_CLIENT_BACKLOG 128 //amount of connections allowed at maximum to connect at one time or our socket
char * pathToDocs;
char * portNumber;


void handle_connection(int accept_desc){
    int fileSize;
    FILE *receivedFile;
    int fd;

    char HTTPHeader [10000];
    recv(accept_desc, &HTTPHeader, 10000, 0); //puts received data in buffer
    printf("%s\n", HTTPHeader);
    char * fullPathToFile = strncat(pathToDocs, "/index.html",115);
    printf("%s\n", fullPathToFile);
    //receivedFile = fopen(fullPathToFile, "r");
    //unsigned char buff[256]={0};
    //int nread = fread(buff, 1, 256, receivedFile);
    //if (nread > 0){
        send(accept_desc, &fullPathToFile, sizeof(fullPathToFile), 0);
    //}
    //fclose(receivedFile);



    //printf("%s\n", c);
    //printf("%s\n", s);
    fflush(stdout); //makes sure printf prints to terminal
}

int main(int argc, char *argv[]) {

    if (argc !=3){
        printf("Error: more or less than 3 command line arguments");
        return 0;
    }

    pathToDocs = argv[1]; //stores file path to access docs from taken from command line
    portNumber = argv[2]; //stores port number passed in from command line into variable


    int socket_descriptor, accept_desc;
    int return_value;
    int enable = 1;
    struct addrinfo hints;
    struct addrinfo * address_resource;
    struct sockaddr_storage remote_addr;
    socklen_t remote_addr_size = sizeof(remote_addr);


    memset(&hints, 0, sizeof(hints)); //clears out any data in hints struct before we write to it

    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP connection (ordered packets), not UDP DGRAM (unordered packets)
    hints.ai_flags = AI_PASSIVE; // Specifies socket to listen

    return_value = getaddrinfo(MYHOST, portNumber, &hints, &address_resource);

    if(return_value != 0){ //error check
        printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
        return return_value;
    }

    // socket(): creates a new TCP/IP packet, but no address or port is assigned yet
    socket_descriptor = socket( //created new socket here by asking OS to give us one
            address_resource->ai_family, //IPv4
            address_resource->ai_socktype, // Streaming Protocol
            address_resource->ai_protocol //TCP
            );

    if(socket_descriptor == -1){ //error check
        printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
        return socket_descriptor;
    }

    return_value = setsockopt(socket_descriptor, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)); //allows socket to be reused

    if(return_value == -1){ //error check
        printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
        return return_value;
    }

    //bind(): assign address and port to socket
    return_value = bind(socket_descriptor, address_resource->ai_addr, address_resource->ai_addrlen);

    if(return_value == -1){ //error check
        printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
        return return_value;
    }

    freeaddrinfo(address_resource); //prevents memory leak

    return_value = listen(socket_descriptor, MAX_CLIENT_BACKLOG);

    if(return_value == -1){ //error check
        printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
        return return_value;
    }


    //accept is function that gets triggered when data comes in on our socket. Second param specific address of where data is coming in from
    accept_desc = accept(socket_descriptor, (struct sockaddr *) &remote_addr, &remote_addr_size); //blocking function. waits for data to be received
    //now we will do something with the data coming in on the socket

    handle_connection(accept_desc); //handle data coming in on socket

    close(accept_desc);
    close(socket_descriptor);

    return 0;
}

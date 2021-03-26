#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <memory.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MYHOST "localhost"
#define MAX_CLIENT_BACKLOG 128 //amount of connections allowed at maximum to connect at one time or our socket
#define IS_MULTIPROCESS 1


char pathToDocs[1024];
char * portNumber;

void sendFileNotFoundHeader(int accept_desc, long contentLength, char * contentType){

    contentLength = 25;

    char timeBuf[1000];
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    strftime(timeBuf, sizeof(timeBuf), "%a, %d %b %Y %H:%M:%S %Z", &tm);
    char reply [1024];
    sprintf(reply,
            "HTTP/1.1 404 Not Found\n"
            "Date: %s\n"
            "Content-Type: %s\n"
            "Content-Length: %ld\n" //%d
            "Connection: close\n"
            "\n"
            "Error 404: File Not Found",
            timeBuf, contentType, contentLength);
    //printf("%s\n", reply);
    send(accept_desc, reply, strlen(reply), 0);

}

void sendHeaders(int accept_desc, long contentLength, char * contentType){

    if (contentLength == -1){
        //printf("%ld", contentLength);
        printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);

        sendFileNotFoundHeader(accept_desc, contentLength, contentType);
    }

    char timeBuf[1000];
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    strftime(timeBuf, sizeof(timeBuf), "%a, %d %b %Y %H:%M:%S %Z", &tm);

    char reply [1024];
    sprintf(reply,
            "HTTP/1.1 200 OK\n"
            "Date: %s\n"
            "Content-Type: %s\n"
            "Content-Length: %ld\n" //%d
            "Connection: close\n"
            "\n", timeBuf, contentType, contentLength);
    //printf("%s\n", reply);
    send(accept_desc, reply, strlen(reply), 0);
}

off_t sizeOfFile(char * fileName){

    struct stat fileInfo;

    char *fullPathToFile = strncat(pathToDocs, fileName, 115);
    //printf("fullPathToFile: %s\n", fullPathToFile);

    if (stat(fullPathToFile, &fileInfo) == -1){
        printf("Error: Stat failed");
        return -1;
    }

    return fileInfo.st_size;
}


 void sendFD(int accept_desc, char * fileName, bool trueOrFalse){

    if (trueOrFalse == true) {
        FILE *receivedFile;

        receivedFile = fopen(pathToDocs, "r");
        unsigned char buff[256] = {0};

        unsigned long nread = fread(buff, 1, 256, receivedFile);
        while (nread > 0) {
            send(accept_desc, buff, nread, 0);
            nread = fread(buff, 1, 256, receivedFile);
        }
        if (nread < 0) {
            fprintf(stderr, "Error reading remote file\n");
        }
        fclose(receivedFile);
    }
}


void handle_connection(int accept_desc) {
    char HTTPHeader[10000];
    int bytesRead;

    while (1) {
        bytesRead = recv(accept_desc, &HTTPHeader, 10000, 0); //puts received data in HTTPBuffer
        //printf("%d bytes read\n", bytesRead);
        if (bytesRead <= 0) {
        //printf("<=0 bytes read");
            if (bytesRead == -1) {
                printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
            }
            return;
        }

        else if (strlen(HTTPHeader) == 0) {
            printf("HTTPHeader == 0 len");
            return;
        }

        //printf("%s", HTTPHeader);


        if (strncmp(HTTPHeader, "GET", 3) == 0) { //checks if GET request and if looking for /index.html  (SEND condition)
            //printf("Yay! Got a file request");

            // NOTE: Trashing header
            char * start = &HTTPHeader[4];
            char * end = strchr(start, ' ');
            if (end == NULL){
                printf("MAYDAY");
                return;
            }
            *end = '\0';

            off_t fileSize = sizeOfFile(start);

            if (strstr(HTTPHeader, ".html") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "text/html");
            }
            else if (strstr(HTTPHeader, ".jpeg") != NULL || strstr(HTTPHeader, ".jpg") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "image/jpeg");
            }
            else if (strstr(HTTPHeader, ".png") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "image/png");
            }
            else if (strstr(HTTPHeader, ".gif") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "image/gif");
            }
            else if (strstr(HTTPHeader, ".pdf") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "application/pdf");
            }
            else if (strstr(HTTPHeader, ".javascript") != NULL || strstr(HTTPHeader, ".js") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "application/javascript");
            }
            else if (strstr(HTTPHeader, ".plain") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "text/plain");
            }
            else if (strstr(HTTPHeader, ".css") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "text/css");
            }


            sendFD(accept_desc, start, true);

            return;
        }

        else if (strncmp(HTTPHeader, "HEAD", 4) == 0){
            char * start = &HTTPHeader[5];
            char * end = strchr(start, ' ');
            if (end == NULL){
                printf("MAYDAY 2");
                return;
            }
            *end = '\0';

            off_t fileSize = sizeOfFile(start);

            if (strstr(HTTPHeader, ".html") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "text/html");
            }
            else if (strstr(HTTPHeader, ".jpeg") != NULL || strstr(HTTPHeader, ".jpg") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "image/jpeg");
            }
            else if (strstr(HTTPHeader, ".png") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "image/png");
            }
            else if (strstr(HTTPHeader, ".gif") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "image/gif");
            }
            else if (strstr(HTTPHeader, ".pdf") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "application/pdf");
            }
            else if (strstr(HTTPHeader, ".javascript") != NULL || strstr(HTTPHeader, ".js") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "application/javascript");
            }
            else if (strstr(HTTPHeader, ".plain") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "text/plain");
            }
            else if (strstr(HTTPHeader, ".css") != NULL){
                sendHeaders(accept_desc, (long) fileSize, "text/css");
            }

            sendFD(accept_desc, start, false);
            return;
        }

    }
}

int main(int argc, char *argv[]) {

    if (argc !=3){
        printf("Error: more or less than 3 command line arguments");
        return 0;
    }


    strncpy(pathToDocs,argv[1], 1024); //stores file path to access docs from taken from command line
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

    while(1){

        accept_desc = accept(socket_descriptor, (struct sockaddr *) &remote_addr, &remote_addr_size);

        #if IS_MULTIPROCESS == 1
            int pid = fork();

            if (pid == 0){ //child process starts ...

                handle_connection(accept_desc);
                close(accept_desc);
                close(socket_descriptor);
                exit(0); // ... child process terminated

            }

            if (pid == -1){
                printf("Error: %s (line: %d)\n", strerror(errno), __LINE__);
                return pid;
            }

            close(accept_desc);

#else
        accept_desc = accept(socket_descriptor, (struct sockaddr *) &remote_addr, &remote_addr_size);
        handle_connection(accept_desc);
        close(accept_desc);
#endif
    }


}

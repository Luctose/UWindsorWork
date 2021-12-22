#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int domain = AF_INET; // Network protocol ICP/IP
    int type = SOCK_STREAM; // Connection-oritented
    int protocol = 0; // Default transport TCP

    int client_sd; // socket descriptor
    client_sd = socket(domain, type, protocol);

    if(client_sd == -1){
        perror("Error in creating socket for the client");
        exit(1);
    }
    else{
        printf("Socket has been created for the client with sd: %d\n", client_sd);
    }

    /*The client IP:PORT binding is optional.
    Let the OS do it automatically as this may
    be run on different computers
    */

    struct in_addr server_sin_address;
    server_sin_address.s_addr = inet_addr("137.207.82.51");
    int server_sin_port = htons(2145); // Port > 1024

    struct sockaddr_in server_sin;
    server_sin.sin_family = domain;
    server_sin.sin_addr = server_sin_address;
    server_sin.sin_port = server_sin_port;

    // Connect to server
    int result = connect(client_sd, (struct sockaddr *) &server_sin, sizeof(server_sin));
    if(result == -1){
        printf("Error in connecting to the server at address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
        exit(1);
    }else{
        printf("Client is connected to the server at address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
    }

    char *msg = malloc(sizeof(char) * 25);
    char *response = malloc(sizeof(char) * 25);

    while(1){
        // Prompt user for input
        printf("Enter the data for the server\nin this format (username-password-x-y): ");
        // Get input
        scanf("%s", msg);
        printf(msg);
        // Send info to the server
        ssize_t is_sent = send(client_sd, msg, sizeof(char) * 25, 0);
        if(is_sent == -1){
            printf("Error in sending to server");
        }
        // Receive the response
        recv(client_sd, response, sizeof(char) * 25, 0);
        printf("%s\n", response);
    }
}
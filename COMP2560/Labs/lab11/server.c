#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int sepString(char *, char **);
char* addString(char*, char*);
void free2D(char **);

int main(void){
    int domain = AF_INET; // Netwrok Protocol: TCP/IP
    int type = SOCK_STREAM; // Connection-Oriented
    int protocol = 0; // Default transport: TCP for Internet connection-oriented

    int server_sd; // Socket descriptor
    // Creating socket
    server_sd = socket(domain, type, protocol);
    // Make sure it has been created
    if(server_sd == -1){
        printf("Erro in creating socket for the server!\n");
        exit(1);
    }
    else{
        printf("A socket has been created for the server with sd: %d\n", server_sd);
    }

    // Binding the socket to the address
    // Create struct for address
    struct in_addr server_sin_address;
    server_sin_address.s_addr = inet_addr("137.207.82.51"); // Host
    // Create port number
    int server_sin_port = htons(2145); // Port > 1024

    // Create struct for socket binding
    struct sockaddr_in server_sin;
    // Add elements
    server_sin.sin_family = domain;
    server_sin.sin_addr = server_sin_address;
    server_sin.sin_port = server_sin_port;

    // Finally bind
    int result = bind(server_sd, (struct sockaddr *) &server_sin, sizeof(server_sin));
    if(result == -1){
        printf("Error in binding the server to the address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
        exit(1);
    }
    else{
        printf("The server bound to the address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
    }

    // The server is ready to receive calls (ip to 5 calls. More are rejected!)
    if(listen(server_sd, 5) < 0){
        perror("The server's listening failed!\n");
        exit(1);
    }

    struct sockaddr_in client_sin; // I want to know who sends the message
    int client_sin_len;

    while(1){
        result = accept(server_sd, (struct sockaddr *) &client_sin, &client_sin_len);
        if(result == -1){
            printf("Error in opening the request from the client %d:%d !\n", client_sin.sin_addr, client_sin.sin_port);
            // Do not exit go to next client call
        }
        else{
            printf("The server opened the request from the client %d:%d\n", client_sin.sin_addr, client_sin.sin_port);
            // Create new child
            int child_pid = fork();
            if(child_pid == 0){
                printf("Child: I am the server's child handling client: %d:%d\n", client_sin.sin_addr, client_sin.sin_port);
                // Create space for the child's message
                char *msg = malloc(sizeof(char) * 25);
                char **sep_str;
                // Receive message
                if(recvfrom(result, msg, sizeof(char) * 25, 0, (struct sockaddr *) &client_sin, (int *) &client_sin_len) == -1){
                    printf("Message not received\n");
                    free(msg);
                }else{
                    printf("message received: %s\n", msg);
                    // Seperate strings
                    if(sepString(msg, sep_str) == -1){
                        printf("Memory failed to allocate");
                        free(msg);
                    }else{
                        free(msg);
                        // Check if they have correct user and password
                        if(strcmp(*(sep_str + 0), "comp2560") == 0 && strcmp(*(sep_str + 1), "f2021") == 0){ // Authentication successful
                            // Create child to handle math
                            int grandchild_pid = fork();
                            if(grandchild_pid == 0){
                                printf("Grandchild handles math of client: %d:%d\n", client_sin.sin_addr, client_sin.sin_port);
                                // Send the sum to the client
                                char * temp = addString(*(sep_str + 2), *(sep_str + 3));
                                send(result, temp, sizeof(char) * 25, 0);
                                free(temp);
                                free2D(sep_str);
                                pause();
                            }
                        }else{ // Authentication failed
                            send(result, "Authentication failed!\n", sizeof(char) * 25, 0);
                            free2D(sep_str);
                        }
                    }
                }
                pause();
            }
        }
    }
}

// Allocates new space for the message sent as seperate strings
// Must be freed
int sepString(char *msg, char ** str){
    // Allocate memory
    str = (char**)malloc(4 * sizeof(char*));
    if(str == NULL){
        // Memory failed to allocate
        return -1;
    }
    for(int i = 0; i < 4; i++){
        *(str + i) = (char*)malloc(15 * sizeof(char));
        if(*(str + i) == NULL){
            for(int j = 0; j < i; j++){
                free(*(str + j));
            }
            free(str);
            return -1;
        }
    }

    // Transfer contents to new 2D array
    int row = 0;
    for(int col = 0; col < strlen(msg) && *(msg + col) != '\0'; col++){
        if(*(msg + col) == '-'){
            *(*(str + row) + col) = '\0';
            row++;
        }else{
            *(*(str + row) + col) = *(msg + col);
        }
    }
    return 0;
}

// Add two numbers represented as strings and return the sum as strings
// Must be freed
char* addString(char* x, char* y){
    char *str = malloc(sizeof(char) * 12);
    sprintf(str, "%d", atoi(x) + atoi(y));
    return str;
}

// Frees the dynamically allocated 2D char array created ealier
void free2D(char **arr){
    // Free pointers inside
    for(int i = 0; i < 4; i++){
        free(*(arr + i));
    }
    // Free wrapper pointer
    free(arr);
}
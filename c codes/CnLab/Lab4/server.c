#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "Error, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    int portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        close(sockfd);
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        close(sockfd);
        exit(1);
    }

    printf("Connected to client with IP: %s and port: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1) {
        memset(buffer, 0, 256);
        int n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("Error reading from socket");
            close(newsockfd);
            close(sockfd);
            exit(1);
        }

        printf("Client: %s\n", buffer);

        if (strncmp("close", buffer, 5) == 0) {
            printf("Closing connection from server side...\n");

            n = write(newsockfd, "close", 5);
            if (n < 0) {
                perror("Error writing to socket");
            }
            break;
        }

        printf("Enter reply: ");
        fgets(buffer, 255, stdin);

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            close(newsockfd);
            close(sockfd);
            exit(1);
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}


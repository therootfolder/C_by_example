#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>


int main(void)
{
    int sockfd, portno, sz;

    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    // server hostname. You can change it
    char server_hostname[] = "ubuntu15";
    portno = 8059; // server port
    errno = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("\n socket() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    printf("socket has created\n");

    server = gethostbyname(server_hostname);
    if (server == NULL)
    {
        printf("\n gethostbyname() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("connecting to server....\n");
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
    {
        printf("\n connect() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    printf("connected to server\n");

    // write data
    strcpy(buffer,"this is message from client");
    sz = write(sockfd,buffer,strlen(buffer));
    if (sz < 0)
    {
        printf("\n write() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    // read data
    bzero(buffer,256);
    sz = read(sockfd,buffer,255);
    if (sz < 0)
    {
        printf("\n read() failed with error [%s]\n",strerror(errno));
        return -1;
    }
    printf("Received message: %s\n",buffer);

    // close socket
    close(sockfd);

    return 0;
}
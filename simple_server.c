#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>


int main(void)
{

    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    portno = 8056; // server port
    errno = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("\n socket() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
          sizeof(serv_addr)) < 0)
    {
        printf("\n bind() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    printf("socket has created and binded\n");
    printf("listening incoming socket client....\n");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
    {
        printf("\n accept() failed with error [%s]\n",strerror(errno));
        return -1;
    }

    printf("a client was connected\n");

    // close socket
    close(newsockfd);
    close(sockfd);

   return 0;
}
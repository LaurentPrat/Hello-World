/*

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
https://github.com/richelbilderbeek/travis_cpp_tutorial

*/

// std
#include <time.h>
#include <stdio.h>

// for getwebpage
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// local
int getwebpage();

int main(void)
{
    struct tm *newtime;
    time_t ltime;
 
/* Get the time in seconds */
    time(&ltime);
/* Convert it to the structure tm */
    newtime = localtime(&ltime);
 
        /* Print the local time as a string */
    printf("Hello, the current date and time are %s\n", asctime(newtime));
    getwebpage();
}



int getwebpage()
{
    /*Define socket variables */
    char host[1024] = "pastebin.com";
    char url[1024] = "/raw/7y7MWssc";
    char request[2000];
    struct hostent *server;
    struct sockaddr_in serverAddr;
    int portno = 80;

    printf("Trying to get source of pastebin.com/raw/7y7MWssc ...\n");

    /* Create socket */
    int tcpSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(tcpSocket < 0) 
    {
        printf("ERROR opening socket\n");
    } else 
    {
        printf("Socket opened successfully.\n");
    }

    server = gethostbyname(host);
    serverAddr.sin_port = htons(portno);
    serverAddr.sin_family = AF_INET;

    if(connect(tcpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) 
    {
        printf("Can't connect\n");
    } else 
    {
        printf("Connected successfully\n");
    }

    bzero(request, 2000);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", url, host);
    printf("\n%s", request);

    if(send(tcpSocket, request, strlen(request), 0) < 0) {
        printf("Error with send()");
        return(1);
    } else {
        printf("Successfully sent html fetch request");
        return(0);
    }
}
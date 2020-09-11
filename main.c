/*
https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
*/

#include <time.h>
#include <stdio.h>
 
int main(void)
{
    struct tm *newtime;
    time_t ltime;
 
/* Get the time in seconds */
    time(&ltime);
/* Convert it to the structure tm */
    newtime = localtime(&ltime);
 
        /* Print the local time as a string */
    printf("Hello, the current date and time are %s", asctime(newtime));
}
/* A Sample program to see how fork and pipe system calls work.
/* **************************************************************************
* pipe.c
* PROTOTYPE: int pipe(int fd[2]);
* RETURNS : 0 on success
* -1 on error
* could be because of - no file descriptors available
* - system file table is full
* - fd array is not valid
* NOTES : fd[0] is set for reading, fd[1] is set for writing
* *********************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    int fd[2], nbytes;
    pid_t childpid;
    char string[] = "Hello, world!\n";
    char readbuffer[80];
    if (-1 == pipe(fd))
    {
        fprintf(stderr, "pipe(): Failed to create pipe\n");
        exit(1); /* if you get warning, comment it out */
    }
    if((childpid = fork()) == -1)
    {
        fprintf(stderr, "fork(): Failed to create child process\n");
        exit(1); /* if you get warning, comment it out */
    }
    if(childpid == 0)
    {
        close(fd[0]); /* Child process closes up input side of pipe */
        /* Send "string" through the output side of pipe */
        write(fd[1], string, strlen(string));
        exit(0); /* if you get warning, comment it out */
    }
    else
    {
        close(fd[1]); /* Parent process closes up output side of pipe */
        /* Read in a string from the pipe */
        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
        fprintf(stderr, "Received string: %s", readbuffer);
    }
    return(0);
}
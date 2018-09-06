#include <unistd.h>
#include <stdio.h>
#include "csapp.h"

void sigint_handler(int sig)
{
    printf("\nCTRL+C\n");
}

unsigned int snooze(unsigned int secs)
{
    unsigned int rs = sleep(secs);
    printf("Slept for %d for %d secs.\n", secs - rs, secs);
    return 0;
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        printf("signal error");
    }
    unsigned int secs = atoi(argv[1]);
    snooze(secs);
    return 0;
}

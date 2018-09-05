#include <unistd.h>
#include <stdio.h>


void sigint_handler(int sig)
{

    printf("CTRL+C");
exit(0);
}

unsigned int  snooze(unsigned int secs);
{
    unsigned int rs = sleep(secs);
    if (signal(SIGINT, sigint_handler)== SIG_ERR) {
        unix_error("signal error");
    }
    printf("Slept for %d for %d secs.", secs-rs, secs);
    return 0;
}

int main(int argc, char const *argv[])
{
  unsigned int secs = argv[1];
snooze(secs);
    return 0;
}

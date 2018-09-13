#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close

int main(int argc, char const *argv[])
{
    int fd1, fd2;

    fd1 = open("foo.txt", O_RDONLY, 0);
    fd2 = open("bar.txt", O_RDONLY, 0);

    close(fd2);

    fd2 = open("baz.txt", O_RDONLY, 0);

    printf("fd2 = %d\n", fd2);

    exit(0);
}
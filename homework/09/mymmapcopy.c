#include "csapp.h"

void mmapcopy(int fd, int size)
{
    char *bufp; /* ptr to memory-remapped VM area */

    bufp = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    write(1, bufp, size);
    return;
}

/* mmapcopy driver */
int main(int argc, char **argv)
{
    struct stat stat;
    int fd;

    /* check for required command-line argument */
    if (argc != 2)
    {
        printf("usage: %s <filename>\n", argv[0]);
        exit(0);
    }

    /* Copy the input argument to stdout */
    fd = open(argv[1], O_RDONLY, 0);
    fstat(fd, &stat);
    mmapcopy(fd, stat.st_size);
    exit(0);
}

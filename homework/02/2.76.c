#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *another_calloc(size_t nmemb, size_t size)
{

    size_t buf_size = nmemb * size;

    if (nmemb == 0 || size == 0 || (nmemb != buf_size / size))
    {
        return NULL;
    }

    void *ptr = malloc(buf_size);
    memset(ptr, 0, buf_size);

    return ptr;
}

int main()
{

    void *ptr;

    size_t nmenb = 0x1234;
    size_t size = 1;
    ptr = another_calloc(0x1234, 1);
    printf("another_calloc(%zx, %zx) = %p\n", nmenb, size, ptr);
    free(ptr);

    nmenb = SIZE_MAX;
    size = 2;
    ptr = another_calloc(nmenb, size);
    printf("another_calloc(%zx, %zx) = %p\n", nmenb, size, ptr);
    assert(ptr == NULL);
    free(ptr);

    return 0;
}
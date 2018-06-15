#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *another_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
    {
        return NULL;
    }

    size_t buf_size = nmemb * size;
    if (nmemb == buf_size / size)
    {
        void *ptr = malloc(buf_size);
        memset(ptr, 0, buf_size);
        return ptr;
    }
    return NULL;
}

int main()
{

    void *ptr;

    ptr = another_calloc(0x1234, 1);
    assert(ptr != NULL);
    free(ptr);

    ptr = another_calloc(SIZE_MAX, 2);
    assert(ptr == NULL);
    free(ptr);

    return 0;
}
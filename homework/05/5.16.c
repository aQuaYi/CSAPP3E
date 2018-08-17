#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vec.h"

#define LEN 24

/* Inner Product. Accumulate in temporary */
void inner4(vec_ptr u, vec_ptr v, data_t *dest)
{
    long i;
    long length = vec_length(u);
    long limit = length - 5;
    data_t *udata = get_vec_start(u);
    data_t *vdata = get_vec_start(v);

    data_t sum = (data_t)0;

    for (i = 0; i < limit; i += 6)
    {
        sum += udata[i] * vdata[i] + udata[i + 1] * vdata[i + 1] + udata[i + 2] * vdata[i + 2] + udata[i + 3] * vdata[i + 3] + udata[i + 4] * vdata[i + 4] + udata[i + 5] * vdata[i + 5];
    }

    for (; i < length; i++)
    {
        sum += udata[i] * vdata[i];
    }

    *dest = sum;
}
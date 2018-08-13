/**
 * Bubble sort: Pointer version
 */

void bubble_p(long *data, long count)
{
    for (long *last = data + count - 1; data < last; last--)
    {
        for (long *pre = data; pre < last; pre++)
        {
            long *later = pre + 1;
            if (*later < *pre)
            {
                long t = *later;
                *later = *pre;
                *pre = t;
            }
        }
    }
}
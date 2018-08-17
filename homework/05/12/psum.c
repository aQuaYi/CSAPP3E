void psum(float a[], float p[], long n)
{
    long i;
    float sum = a[0];
    p[0] = sum;
    for (i = 1; i < n; i++)
    {
        sum += a[i];
        p[i] = sum;
    }
}
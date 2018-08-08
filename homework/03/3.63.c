long switch_prob(long x, long n)
{
    long result = x;

    switch (n)
    {
    case 60:
    case 62:
        result = x * 8;
        break;
    case 63:
        result = x / 8;
        break;
    case 64:
        x *= 15;
    case 65:
        x *= x;
    default:
        result = x + 0x4B;
        break;
    }

    return result;
}
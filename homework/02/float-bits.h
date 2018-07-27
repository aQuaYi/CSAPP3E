/**
 * Access bit-level representation floating-point number
 */
typedef unsigned float_bits;

/**
 * 把 float_bits 转换成 float
 */
float fb2f(float_bits x)
{
    return *(float *)&x;
}
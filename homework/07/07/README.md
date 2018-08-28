# 7.7

把 bar5.c 的第 2 行修改为

```C
static double x
```

两个文件中的 x 类型不一样，肯定不是同一个变量。所以，把 bar5.c 中的 x 设置成局部符号，避免歧义。

```shell
linux> gcc -Og -o main foo5.c bar5.c
linux> ./main
x = 0x3b6d, y = 0x3b6c
```
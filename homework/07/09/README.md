# 7.9

```shell
linux> make
gcc foo6.c bar6.c -o main
linux> ./main
0x55
```

```text
main 在 bar6.c 中是一个弱全局符号，在链接后，被重定位到 foo6.c 的 main 的地址。

所以，在 p2() 中使用 main 变量的时候，找到了 main() 函数的起点位置的字节。

linux> objdump -d main
...
0000000000400526 <main>:
  400526:	55                   	push   %rbp
  400527:	48 89 e5             	mov    %rsp,%rbp
  40052a:	e8 07 00 00 00       	callq  400536 <p2>
  40052f:	b8 00 00 00 00       	mov    $0x0,%eax
  400534:	5d                   	pop    %rbp
  400535:	c3                   	retq
...

可以看到 main() 的内存地址为 0x400526，这个字节中保存的内容正是 0x55。
```
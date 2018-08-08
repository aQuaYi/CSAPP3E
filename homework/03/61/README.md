# 3.61

在本目录的命令行下输入以下命令

```shell
gcc -Og cread.c -S  
gcc -Og 3.61.c -S  
gcc -Og cread_3.c -S  
```

会发现生成的汇编文件的核心代码都是

```asm
cread:
    testq %rdi, %rdi
    je .L3
    movq (%rdi), %rax
    ret
.L3:
    movl $0, %eax
    ret
```

```shell
$ gcc -v
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10)
```
# 3.64

## A

根据 178 页的二维公式，可以推理出

```text
TYPE D[R][S][T]
&D[i][j][k] = Xd + L(S*T*i + T*j + k)
```

## B

```asm
# long store_ele(long i, long j, long k, long *dest)
# i in %rdi, j in %rsi, k in %rdx, dest in %rcx
store_ele:
  leaq (%rsi, %rsi, 2), %rax    # j*3
  leaq (%rsi, %rax, 4), %rax    # j*13
  movq %rdi, %rsi               # i
  salq $6, %rsi                 # i*64
  addq %rsi, %rdi               # i*65
  addq %rax, %rdi               # i*65 + j*13
  addq %rdi, %rdx               # t = i*65 + j*13 + k
  movq A(,%rdx,8), %rax         # *(A + 8*t)
  movq %rax, (%rcx)             #  
  movl $3640, %eax              # return 3640
  ret
```

通过以上的注释，可以得到以下关系式

```text
T = 13
S * T = 65
L * R * S * T = 3640 // 最后返回了 A 的大小
L = 8 // long 的长度为 8 bit
```

可以计算出

```text
R = 7
S = 5
T = 13
```
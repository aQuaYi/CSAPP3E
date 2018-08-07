# void store_prod(int128_t* dest, int64_t x, int64_t y)
# dest in %rdi, x in %rsi, y in %rdx
store_prod:
  movq %rdx, %rax     # 令 %rax = y
  cqto                # (int128_t)y, %rdx = (-1)^y_63
  movq %rsi, %rcx     # 令 %rcx = x

  sarq $63, %rcx      # %rcx = -x_63

  # pay attention, imulq behaves differently according to param number(1/2)
  imulq %rax, %rcx    # %rcx = y * -x_63
  imulq %rsi, %rdx    # %rdx = x * -^y_63
  addq %rdx, %rcx     # %rcx = x * -y_63 + y * -x_63
  mulq %rsi           # %rdx:%rax <-- ux * uy

  # 有符号数与无符号数的关系可知
  # ux = x + x_63*2^64 
  # uy = y + y_63*2^64 
  # ux*uy = x*y + (x*y_63 + x_63*y)*2^64 + x_63*y_63*2^128
  # 根据 68 页的公式 2.18 ux*uy 与 x*y 的低位一样
  # high64bit(ux*uy) = high64bit(x*y) + (x*y_63 + x_63*y)
  # 所以 high64bit(x*y) = %rdx = high64bit(ux*uy) - (x*y_63 + x_63*y)

  addq %rcx, %rdx

  # 根据小端法，设置结果
  movq %rax, (%rdi)   # 设置低 64bits
  movq %rdx, 8(%rdi)  # 设置高 64bits
  ret

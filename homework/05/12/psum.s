	.file	"psum.c"
	.text
	.globl	psum
	.type	psum, @function
psum:
.LFB0:
	.cfi_startproc
	movss	(%rdi), %xmm0
	movss	%xmm0, (%rsi)
	movl	$1, %eax
	jmp	.L2
.L3:
	addss	(%rdi,%rax,4), %xmm0
	movss	%xmm0, (%rsi,%rax,4)
	addq	$1, %rax
.L2:
	cmpq	%rdx, %rax
	jl	.L3
	rep ret
	.cfi_endproc
.LFE0:
	.size	psum, .-psum
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

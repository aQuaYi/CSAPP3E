	.file	"cread_3.c"
	.text
	.globl	cread_3
	.type	cread_3, @function
cread_3:
.LFB0:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L3
	movq	(%rdi), %rax
	ret
.L3:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	cread_3, .-cread_3
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

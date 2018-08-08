	.file	"3.61.c"
	.text
	.globl	cread_alt
	.type	cread_alt, @function
cread_alt:
.LFB23:
	.cfi_startproc
	testq	%rdi, %rdi
	je	.L3
	movq	(%rdi), %rax
	ret
.L3:
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	cread_alt, .-cread_alt
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

	.file	"3.69.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB23:
	.cfi_startproc
	movl	288(%rsi), %eax
	addl	(%rsi), %eax
	leaq	0(,%rdi,4), %rcx
	leaq	(%rcx,%rdi), %r8
	leaq	0(,%r8,8), %rdx
	addq	%rcx, %rdi
	addq	8(%rsi,%rdx), %rdi
	cltq
	movq	%rax, 16(%rsi,%rdi,8)
	ret
	.cfi_endproc
.LFE23:
	.size	test, .-test
	.globl	test_char_index
	.type	test_char_index, @function
test_char_index:
.LFB24:
	.cfi_startproc
	movsbq	(%rdi), %rax
	movq	8(%rdi,%rax,8), %rax
	ret
	.cfi_endproc
.LFE24:
	.size	test_char_index, .-test_char_index
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"sizeof(a.idx) = %ld\n"
.LC1:
	.string	"sizeof(a) = %ld\n"
.LC2:
	.string	"sizeof(b) = 0x%lX\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB25:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$8, %edx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$40, %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$296, %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE25:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

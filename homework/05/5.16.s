	.file	"5.16.c"
	.text
	.globl	inner4
	.type	inner4, @function
inner4:
.LFB60:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rdi, %rbx
	movq	%rsi, %r14
	movq	%rdx, %r13
	call	vec_length
	movq	%rax, %rbp
	leaq	-5(%rax), %r12
	movq	%rbx, %rdi
	call	get_vec_start
	movq	%rax, %rbx
	movq	%r14, %rdi
	call	get_vec_start
	movl	$0, %edi
	movl	$0, %edx
	jmp	.L2
.L3:
	movq	(%rax,%rdx,8), %rcx
	movq	%rcx, %rsi
	imulq	(%rbx,%rdx,8), %rsi
	leaq	1(%rdx), %r8
	movq	(%rax,%r8,8), %rcx
	imulq	(%rbx,%r8,8), %rcx
	addq	%rsi, %rcx
	leaq	2(%rdx), %r8
	movq	(%rax,%r8,8), %rsi
	imulq	(%rbx,%r8,8), %rsi
	addq	%rsi, %rcx
	leaq	3(%rdx), %r8
	movq	(%rax,%r8,8), %rsi
	imulq	(%rbx,%r8,8), %rsi
	addq	%rcx, %rsi
	leaq	4(%rdx), %r8
	movq	(%rax,%r8,8), %rcx
	imulq	(%rbx,%r8,8), %rcx
	addq	%rcx, %rsi
	leaq	5(%rdx), %r8
	movq	(%rax,%r8,8), %rcx
	imulq	(%rbx,%r8,8), %rcx
	addq	%rsi, %rcx
	addq	%rcx, %rdi
	addq	$6, %rdx
.L2:
	cmpq	%r12, %rdx
	jl	.L3
	jmp	.L4
.L5:
	movq	(%rax,%rdx,8), %rcx
	imulq	(%rbx,%rdx,8), %rcx
	addq	%rcx, %rdi
	addq	$1, %rdx
.L4:
	cmpq	%rbp, %rdx
	jl	.L5
	movq	%rdi, 0(%r13)
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE60:
	.size	inner4, .-inner4
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

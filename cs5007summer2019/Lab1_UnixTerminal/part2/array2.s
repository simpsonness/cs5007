	.file	"array2.c"
	.section	.rodata
.LC0:
	.string	"%d, %d, %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$1600, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$12, %rax
	movl	$45, (%rax)
	movq	-8(%rbp), %rax
	addq	$116, %rax
	movl	$111, (%rax)
	movq	-8(%rbp), %rax
	addq	$120, %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	addq	$120, %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	addq	$116, %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	addq	$12, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits

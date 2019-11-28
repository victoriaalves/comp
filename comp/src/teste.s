	.file	"teste.c"
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	17894
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	17894
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.globl	v1
	.align 32
	.type	v1, @object
	.size	v1, 80
v1:
	.zero	80
	.section	.rodata
.LC0:
	.string	"hello "
.LC1:
	.string	"Testando 1,2,3"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L2
.L3:
	movl	$.LC0, %edi
	call	puts
	addl	$1, -4(%rbp)
.L2:
	cmpl	$9, -4(%rbp)
	jle	.L3
	jmp	.L8
.L6:
	movl	$.LC1, %edi
	call	puts
	movl	a(%rip), %eax
	movl	-4(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	test
	movl	a(%rip), %eax
	addl	$1, %eax
	movl	%eax, a(%rip)
	jmp	.L5
.L8:
	movl	a(%rip), %eax
	cmpl	$9, %eax
	jle	.L6
.L5:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
.LC2:
	.string	"ola"
	.text
	.globl	test
	.type	test, @function
test:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cltq
	movq	$2, v1(,%rax,8)
	movl	b(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jge	.L10
	movl	$.LC2, %edi
	call	puts
	jmp	.L11
.L10:
	movl	$1, b(%rip)
.L11:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	test, .-test
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

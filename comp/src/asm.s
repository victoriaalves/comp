	.globl  x
	.align 8
	.type   x, @object
	.size   x, 8
x:
	.long   10
	.globl  a
	.align 4
	.type   a, @object
	.size   a, 4
a:
	.long   100
	.globl  b
	.align 4
	.type   b, @object
	.size   b, 4
b:
	.long   1000
	.globl	v1
	.align 32
	.type v1, @object
	.size v1, 12
v1:
	.quad 1
	.quad 2
	.quad 2
.section .rodata
.LC0:
	.string "inhai"
	.globl main
	.type main, @function
main:
.LFB0:
	.cfi_startproc
	pushq %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq %rsp, %rbp
	.cfi_def_cfa_register 6
	movl $1, x(%rip)
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size main, .-main
	.globl test
	.type test, @function
test:
.LFB1:
	.cfi_startproc
	pushq %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq %rsp, %rbp
	.cfi_def_cfa_register 6
	movl $.LC0, %edi
	call puts
	movl $1, a(%rip)
	movl $1, b(%rip)
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size test, .-test

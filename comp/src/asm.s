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
	.string "hello \n"
.LC1:
	.string "Testando"
.LC2:
	.string "1,2,3"
.globl main
.type main, @function
main:
.LFB0:
	.cfi_startproc
	pushq %rbp
	.cif_def_cfa_offseet 16
	.cfi_offset 6, -16
	movq %rsp, %rbp
	.cfi_def_cfa_register 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size main, .-main
test:
.LFB1:
	.cfi_startproc
	pushq %rbp
	.cif_def_cfa_offseet 16
	.cfi_offset 6, -16
	movq %rsp, %rbp
	.cfi_def_cfa_register 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size test, .-test

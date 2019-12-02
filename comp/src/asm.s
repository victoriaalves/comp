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
	.long   100
	.globl	v1
	.align 32
	.type v1, @object
	.size v1, 12
v1:
	.quad 1
	.quad 2
	.quad 2
.VIC:
	.string "VIC"
	.globl  Temp_0
	.align  4
	.type   Temp_0, @object
	.size   Temp_0, 4
Temp_0:
	.long   0
.section .rodata
	.globl main
	.type main, @function
main:
.Bmain:
	.cfi_startproc
	pushq %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq %rsp, %rbp
	.cfi_def_cfa_register 6
	movl b(%rip), %eax
	movl a(%rip), %edx
	cmpl %eax, %edx
	jne .BL0
	movl $1, %edx
	jmp .BL1
.BL0:
	movl $0, %edx
.BL1:
	movl $1, %eax
	andl %eax, %edx
	jz .Label_2
	movl $.VIC, %edi
	call puts
.Label_2:
	popq %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.Emain:
	.size main, .-main

	.data
	.globl  x
	.align 8
	.type   x, @object
	.size   x, 8
x:
	.long   100
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
	.long   17
	.globl  i
	.align 4
	.type   i, @object
	.size   i, 4
i:
	.long   0
	.globl  dez
	.align 4
	.type   dez, @object
	.size   dez, 4
dez:
	.long   10
	.globl  um
	.align 4
	.type   um, @object
	.size   um, 4
um:
	.long   1
	.globl	v1
	.align 32
	.type v1, @object
	.size v1, 12
v1:
	.quad 1
	.quad 2
	.quad 2
.oi:
	.string "oi"
	.globl  Temp_0
	.align  4
	.type   Temp_0, @object
	.size   Temp_0, 4
Temp_0:
	.long   0
.section .rodata
.LC0:
	.string "%d\n"
	.text
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
	movl $5, v1+8(%rip)
	movl um(%rip), %eax
	movl %eax, %esi
	movl $.LC0, %edi
	movl $0, %eax
	call printf
	movl $2, um(%rip)
	movl um(%rip), %eax
	movl %eax, %esi
	movl $.LC0, %edi
	movl $0, %eax
	call printf
	movl um(%rip), %edx
	movl dez(%rip), %eax
	addl %edx, %eax
	movl %eax, Temp_0(%rip)
	movl $Temp_0, um(%rip)
	movl um(%rip), %eax
	movl %eax, %esi
	movl $.LC0, %edi
	movl $0, %eax
	call printf
	movl $.oi, %edi
	call puts
	movl $1, %eax
	andl %eax, %edx
	jz .Label_2
	jmp .Label_3
.Label_2:
.Label_3:
	popq %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.Emain:
	.size main, .-main

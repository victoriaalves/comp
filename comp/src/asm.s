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

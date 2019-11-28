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
.comm v1,12,32
.LC114:
.string "hello"
.LC115:
.string "Testando"
.LC116:
.string "1,2,3"

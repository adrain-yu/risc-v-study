.text
.global  _start

_start:
    li t0, 0x02000060
    li t1, 0xffffff14
    sw t1, 0(t0)
    li t2, 0x02000070
    li t3, 2
    sw t3, 0(t2)

stop:
    j stop
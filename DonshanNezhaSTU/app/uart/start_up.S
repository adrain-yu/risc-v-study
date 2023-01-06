.text
.global  _start

#define GPIO_BASE_ADDRESS   0x02000000
#define PC_CFG0_OFFSET      0x60
#define PC_DAT_OFFSET       0x70

_start:

    li sp, 0x50040000
    jal clear_bss
    jal  main

stop:
    j stop


clear_bss:
    la  t0, _bss_start
    la  t1, _bss_end

clbss_1:
    sw zero, 0(t0)
    addi t0, t0, 4
    blt t0, t1, clbss_1
    ret

.globl PUT32
PUT32:
    sw a1, 0(a0)
    ret

.globl GET32
GET32:
    lw a0, 0(a0)
    ret


.end

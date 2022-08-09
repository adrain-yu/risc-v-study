.text
.global  _start

#define GPIO_BASE_ADDRESS   0x02000000
#define PC_CFG0_OFFSET      0x60
#define PC_DAT_OFFSET       0x70

_start:

    li sp, 0x50040000
    jal  main

stop:
    j stop

.globl PUT32
PUT32:
    sw a1, 0(a0)
    ret

.globl GET32
GET32:
    lw a0, 0(a0)
    ret


.end

.text
.global  _start

#define GPIO_BASE_ADDRESS   0x02000000
#define PC_CFG0_OFFSET      0x60
#define PC_DAT_OFFSET       0x70

_start:
    li t0, (GPIO_BASE_ADDRESS + PC_CFG0_OFFSET)
    lw t4, 0(t0)
    li t5, 0xf
    slli t5, t5, 4
    not t5, t5
    and t4, t4, t5
    li t5, 1
    slli t5, t5, 4
    or t4, t4, t5
    sw t4, 0(t0)
    li t1, (GPIO_BASE_ADDRESS + PC_DAT_OFFSET)
    lw t4, 0(t1)
    li t5, 1
    slli t5, t5, 1
    not t5, t5
    and t4, t4, t5
    not t5, t5
    or t4, t4, t5
    sw t4, 0(t1)

stop:
    j stop

.end
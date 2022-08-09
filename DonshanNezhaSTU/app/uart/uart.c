typedef struct serial_hw
{
	volatile unsigned int rbr;		/* 0 */
	volatile unsigned int ier;		/* 1 */
	volatile unsigned int fcr;		/* 2 */
	volatile unsigned int lcr;		/* 3 */
	volatile unsigned int mcr;		/* 4 */
	volatile unsigned int lsr;		/* 5 */
	volatile unsigned int msr;		/* 6 */
	volatile unsigned int sch;		/* 7 */
}serial_hw_t;

#define thr rbr
#define dll rbr
#define dlh ier
#define iir fcr
#define   UART_BAUD    115200
/* UART Line Control Parameter */
/* Parity: 0,2 - no parity; 1 - odd parity; 3 - even parity */
#define   PARITY       0 
/* Number of Stop Bit: 0 - 1bit; 1 - 2(or 1.5)bits */
#define   STOP         0
/* Data Length: 0 - 5bits; 1 - 6bits; 2 - 7bits; 3 - 8bit */
#define   DLEN         3 


static serial_hw_t *serial_ctrl_base;

void uart_init(int uart_port, void *gpio_cfg, int gpio_max)
{
	unsigned int uart_clk;
	void *uart0_base = (void *)0x02500000;

	/* uart init */
	serial_ctrl_base = (serial_hw_t *)(uart0_base);

	serial_ctrl_base->mcr = 0x3;
	uart_clk = (24000000 + 8 * UART_BAUD)/(16 * UART_BAUD);
	serial_ctrl_base->lcr |= 0x80;
	serial_ctrl_base->dlh = uart_clk>>8;
	serial_ctrl_base->dll = uart_clk&0xff;
	serial_ctrl_base->lcr &= ~0x80;
	serial_ctrl_base->lcr = ((PARITY&0x03)<<3) | ((STOP&0x01)<<2) | (DLEN&0x03);
	serial_ctrl_base->fcr = 0x7;

	return;
}

void sunxi_serial_putc (char c)
{
	while ((serial_ctrl_base->lsr & (1 << 6)) == 0);
	serial_ctrl_base->thr = c;
}

char sunxi_serial_getc (void)
{
	while ((serial_ctrl_base->lsr & 1) == 0);
	return serial_ctrl_base->rbr;
}


void hexstrings ( unsigned int d )
{
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        sunxi_serial_putc(rc);
        if(rb==0) break;
    }
    sunxi_serial_putc(0x20);
}

void hexstring ( unsigned int d )
{
    hexstrings(d);
    sunxi_serial_putc(0x0D);
    sunxi_serial_putc(0x0A);
}
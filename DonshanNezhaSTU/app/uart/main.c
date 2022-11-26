#include <inttypes.h>

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void uart_init(void);

extern void sunxi_serial_putc (char c);
extern void hexstring ( unsigned int d );
extern void hexstrings ( unsigned int d );

static uint32_t read32(uint32_t addr)
{
	return *(volatile uint32_t *)(uintptr_t)addr;
}

static void write32(uint32_t addr, uint32_t val)
{
	*(volatile uint32_t *)(uintptr_t)addr = val;
}

static void mdelay(int x)
{
	int i = 0;

	for (; i < x; i++ );

}

int main()
{
	uart_init();

	sunxi_serial_putc(0x56);
	sunxi_serial_putc(0x56);

	PUT32(0x02000060, 0xffffff14);
	PUT32(0x02000070, 2);

	sunxi_serial_putc(0x57);
	sunxi_serial_putc(0x58);
	sunxi_serial_putc(0xD);
	sunxi_serial_putc(0xA);
	hexstring(GET32(0x02000070));
	hexstring(GET32(0x02000060));

	hexstring(read32(0x02000070));
	hexstring(read32(0x02000060));

	for (;;) {
		PUT32(0x02000070, 0);
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		mdelay(100000000);
		PUT32(0x02000070, 2);
		mdelay(100000000);
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
		hexstring(GET32(0x02000070));
	}


	return 0;
}
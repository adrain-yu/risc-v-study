CROSS_COMPILE=/home/adrain/devel/study/100ask/risc-v/Buildroot-2022/buildroot-2022.02/output/host/bin/riscv64-buildroot-linux-uclibc-

all:
	$(CROSS_COMPILE)gcc -c -o led_on.o led.S
	$(CROSS_COMPILE)ld -Ttext 0x50040000 led_on.o -o led_on.elf
	$(CROSS_COMPILE)objcopy -O binary -S led_on.elf led_on.bin
	$(CROSS_COMPILE)objdump -D led_on.elf > led_on.dis
clean:
	rm led_on.o led_on.elf led_on.bin led_on.dis

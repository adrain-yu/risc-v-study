CROSS_COMPILE=/home/adrain/devel/study/100ask/risc-v/Buildroot-2022/buildroot-2022.02/output/host/bin/riscv64-buildroot-linux-uclibc-

OBJS=start_up.o uart.o main.o

all: $(OBJS)
	#$(CROSS_COMPILE)ld -Ttext 0 -Tdata 0x50040000 $^ -o uart.elf
	#$(CROSS_COMPILE)ld -Ttext 0x50040000 $^ -o uart.elf
	$(CROSS_COMPILE)ld -T sramd.lds $^ -o uart.elf
	$(CROSS_COMPILE)objcopy -O binary -S uart.elf uart.bin
	$(CROSS_COMPILE)objdump -D uart.elf > uart.dis

%.o : %.c
	$(CROSS_COMPILE)gcc -c -o $@ $<

%.o : %.S
	$(CROSS_COMPILE)gcc -c -o $@ $<

clean:
	rm $(OBJS) uart.elf uart.bin uart.dis

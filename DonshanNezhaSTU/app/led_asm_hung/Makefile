CROSS_COMPILE=/home/adrain/devel/study/100ask/risc-v/Buildroot-2022/buildroot-2022.02/output/host/bin/riscv64-buildroot-linux-uclibc-

test: led.c led.S
	$(CROSS_COMPILE)gcc -o $@ $^
	$(CROSS_COMPILE)objdump -D $@ > $@.dis
clean:
	rm test

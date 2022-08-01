under uboot:
	setenv serverip 10.8.0.45 && setenv ipaddr 10.8.0.88 && tftpboot 0x50040000 led_on.bin
	go 0x50040000

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define GPIO_BASE_ADDRESS 0x2000000
#define PC_CFG0_OFFSET 	  0x60
#define PC_DAT_OFFSET 	  0x70
#define MMAP_SIZE 		  0x200

int main(int argc, char *argv[])
{
	int fd = -1;
	char *map_base = NULL;

	fd = open("/dev/mem", O_RDWR);
	if (fd < 0) {
		printf("open %s failed\n", "/dev/mem");
		return -1;
	}

	map_base = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO_BASE_ADDRESS);
	if (MAP_FAILED == map_base) {
		printf("mmap %s failed\n", "/dev/mem");
		return -1;
	}

	/* set pc1 for output */
	*((unsigned int *)(map_base + PC_CFG0_OFFSET)) &= ~(0xf << 4);
	*((unsigned int *)(map_base + PC_CFG0_OFFSET)) |= (0x1 << 4);

	for (;;) {
		/* led on */
		*((unsigned int *)(map_base + PC_DAT_OFFSET)) |= (1 << 1);
		sleep(1);
		/* led off */
		*((unsigned int *)(map_base + PC_DAT_OFFSET)) &= ~(1 << 1);
		sleep(1);
	}

	return 0;
}

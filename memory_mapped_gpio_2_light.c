#include <stdio.h>
#include <stdint.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define GPIO_BASE 0x3F200000
#define	GPIO_SIZE (4*1024)

//0008
typedef struct	{
	uint32_t FSEL20:3;
	uint32_t FSEL21:3;
	uint32_t FSEL22:3;
	uint32_t FSEL23:3;
	uint32_t FSEL24:3;
	uint32_t FSEL25:3;
	uint32_t FSEL26:3;
	uint32_t FSEL27:3;
	uint32_t FSEL28:3;
	uint32_t FSEL29:3;
	uint32_t 		:2;
}GPFSEL2bits_t;
//001C
typedef struct	{
	uint32_t SET0:1;
	uint32_t SET1:1;
	uint32_t SET2:1;
	uint32_t SET3:1;
	uint32_t SET4:1;
	uint32_t SET5:1;
	uint32_t SET6:1;
	uint32_t SET7:1;
	uint32_t SET8:1;
	uint32_t SET9:1;
	uint32_t SET10:1;
	uint32_t SET11:1;
	uint32_t SET12:1;
	uint32_t SET13:1;
	uint32_t SET14:1;
	uint32_t SET15:1;
	uint32_t SET16:1;
	uint32_t SET17:1;
	uint32_t SET18:1;
	uint32_t SET19:1;
	uint32_t SET20:1;
	uint32_t SET21:1;
	uint32_t SET22:1;
	uint32_t SET23:1;
	uint32_t SET24:1;
	uint32_t SET25:1;
	uint32_t SET26:1;
	uint32_t SET27:1;
	uint32_t SET28:1;
	uint32_t SET29:1;
	uint32_t SET30:1;
	uint32_t SET31:1;
}GPSET0bits_t;
//0028
typedef struct	{
	uint32_t CLR0:1;
	uint32_t CLR1:1;
	uint32_t CLR2:1;
	uint32_t CLR3:1;
	uint32_t CLR4:1;
	uint32_t CLR5:1;
	uint32_t CLR6:1;
	uint32_t CLR7:1;
	uint32_t CLR8:1;
	uint32_t CLR9:1;
	uint32_t CLR10:1;
	uint32_t CLR11:1;
	uint32_t CLR12:1;
	uint32_t CLR13:1;
	uint32_t CLR14:1;
	uint32_t CLR15:1;
	uint32_t CLR16:1;
	uint32_t CLR17:1;
	uint32_t CLR18:1;
	uint32_t CLR19:1;
	uint32_t CLR20:1;
	uint32_t CLR21:1;
	uint32_t CLR22:1;
	uint32_t CLR23:1;
	uint32_t CLR24:1;
	uint32_t CLR25:1;
	uint32_t CLR26:1;
	uint32_t CLR27:1;
	uint32_t CLR28:1;
	uint32_t CLR29:1;
	uint32_t CLR30:1;
	uint32_t CLR31:1;
}GPCLR0bits_t;

int main(int argc, char *argv[])	{
	int fd, i;
	uint32_t *gpio;
	
	GPFSEL2bits_t *GPFSEL2bits;
	GPSET0bits_t *GPSET0bits;
	GPCLR0bits_t *GPCLR0bits;
	if ((fd = open ("/dev/mem", O_RDWR | O_SYNC | O_CLOEXEC)) < 0)	{
		if ((fd = open ("/dev/gpiomem", O_RDWR | O_SYNC | O_CLOEXEC) ) >= 0)	{	// We're using gpiomem
			printf("Port properly opened\n");
		}
		else {
			printf("Can't open /dev/mem or /dev/gpiomem\n");
			return -1;
		}
	}
	gpio = (uint32_t *)mmap(0, GPIO_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, GPIO_BASE);
	if (gpio == MAP_FAILED)	{
		printf("Can't map memory for GPFSEL2\n");
		return -1;
	}
	GPFSEL2bits = (GPFSEL2bits_t*)(((uint8_t*)gpio)+0x0008);
	GPSET0bits = (GPSET0bits_t*)(((uint8_t*)gpio)+0x001C);
	GPCLR0bits = (GPCLR0bits_t*)(((uint8_t*)gpio)+0x0028);
	
	*(uint32_t*)(((uint8_t*)gpio)+0x0008) = 0x00000000;
	printf("0x%x\n", *(uint32_t*)GPFSEL2bits);
	printf("0x%x\n", *(uint32_t*)(((uint8_t*)gpio)+0x0008));
	printf("-----------------------\n");
	GPFSEL2bits->FSEL20 = 0b111;
	printf("0x%x\n", *(uint32_t*)GPFSEL2bits);
	printf("0x%x\n", *(uint32_t*)(((uint8_t*)gpio)+0x0008));
	printf("-----------------------\n");
	*(uint32_t*)(((uint8_t*)gpio)+0x0008) = 0x00000000;
	printf("0x%x\n", *(uint32_t*)GPFSEL2bits);
	printf("0x%x\n", *(uint32_t*)(((uint8_t*)gpio)+0x0008));
	printf("-----------------------\n");
	GPFSEL2bits->FSEL25 = 0b111;
	printf("0x%x\n", *(uint32_t*)GPFSEL2bits);
	printf("0x%x\n", *(uint32_t*)(((uint8_t*)gpio)+0x0008));
	printf("-----------------------\n");
	*(uint32_t*)(((uint8_t*)gpio)+0x0008) = 0x00000000;
	printf("0x%x\n", *(uint32_t*)GPFSEL2bits);
	printf("0x%x\n", *(uint32_t*)(((uint8_t*)gpio)+0x0008));
	printf("-----------------------\n");
	GPFSEL2bits->FSEL26 = 0b111;
	printf("0x%x\n", *(uint32_t*)GPFSEL2bits);
	printf("0x%x\n", *(uint32_t*)(((uint8_t*)gpio)+0x0008));
	return 0;
	
	GPFSEL2bits->FSEL25 = 0b001; //set as output
	GPFSEL2bits->FSEL26 = 0b001; //set as output
	for(i = 0; i < 2; i++)	{
		GPSET0bits->SET25 = 1;
		GPSET0bits->SET26 = 1;
		sleep(1);
		GPCLR0bits->CLR25 = 1;
		GPCLR0bits->CLR26 = 1;
		sleep(1);
		printf("Arrivato\n");
	}
	return 0;
}

/* OUTPUT:
0x0
0x0
-----------------------
0x7
0x7
-----------------------
0x0
0x0
-----------------------
0x38000
0x38000
-----------------------
0x0
0x0
-----------------------
0x0
0x0
*/

#include <stdio.h>
#include <stdint.h>
#include <sys/fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#define GPIO_BASE 0x3F200000
#define	GPIO_SIZE (4*1024)

//0000
typedef struct	{
	uint32_t FSEL0:3;
	uint32_t FSEL1:3;
	uint32_t FSEL2:3;
	uint32_t FSEL3:3;
	uint32_t FSEL4:3;
	uint32_t FSEL5:3;
	uint32_t FSEL6:3;
	uint32_t FSEL7:3;
	uint32_t FSEL8:3;
	uint32_t FSEL9:3;
	uint32_t reserved:2;
}volatile GPFSEL0bits_t;
//0004
typedef struct	{
	uint32_t FSEL10:3;
	uint32_t FSEL11:3;
	uint32_t FSEL12:3;
	uint32_t FSEL13:3;
	uint32_t FSEL14:3;
	uint32_t FSEL15:3;
	uint32_t FSEL16:3;
	uint32_t FSEL17:3;
	uint32_t FSEL18:3;
	uint32_t FSEL19:3;
	uint32_t reserved:2;
}volatile GPFSEL1bits_t;
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
	uint32_t reserved:2;
}volatile GPFSEL2bits_t;
//000C
typedef struct	{
	uint32_t FSEL30:3;
	uint32_t FSEL31:3;
	uint32_t FSEL32:3;
	uint32_t FSEL33:3;
	uint32_t FSEL34:3;
	uint32_t FSEL35:3;
	uint32_t FSEL36:3;
	uint32_t FSEL37:3;
	uint32_t FSEL38:3;
	uint32_t FSEL39:3;
	uint32_t reserved:2;
}volatile GPFSEL3bits_t;
//0010
typedef struct	{
	uint32_t FSEL40:3;
	uint32_t FSEL41:3;
	uint32_t FSEL42:3;
	uint32_t FSEL43:3;
	uint32_t FSEL44:3;
	uint32_t FSEL45:3;
	uint32_t FSEL46:3;
	uint32_t FSEL47:3;
	uint32_t FSEL48:3;
	uint32_t FSEL49:3;
	uint32_t reserved:2;
}volatile GPFSEL4bits_t;
//0014
typedef struct	{
	uint32_t FSEL50:3;
	uint32_t FSEL51:3;
	uint32_t FSEL52:3;
	uint32_t FSEL53:3;
	uint32_t FSEL54:3;
	uint32_t FSEL55:3;
	uint32_t FSEL56:3;
	uint32_t FSEL57:3;
	uint32_t FSEL58:3;
	uint32_t FSEL59:3;
	uint32_t reserved:2;
}volatile GPFSEL5bits_t;
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
}volatile GPSET0bits_t;
//0020
typedef struct	{
	uint32_t SET32:1;
	uint32_t SET33:1;
	uint32_t SET34:1;
	uint32_t SET35:1;
	uint32_t SET36:1;
	uint32_t SET37:1;
	uint32_t SET38:1;
	uint32_t SET39:1;
	uint32_t SET40:1;
	uint32_t SET41:1;
	uint32_t SET42:1;
	uint32_t SET43:1;
	uint32_t SET44:1;
	uint32_t SET45:1;
	uint32_t SET46:1;
	uint32_t SET47:1;
	uint32_t SET48:1;
	uint32_t SET49:1;
	uint32_t SET50:1;
	uint32_t SET51:1;
	uint32_t SET52:1;
	uint32_t SET53:1;
	uint32_t reserved:10;
}volatile GPSET1bits_t;
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
}volatile GPCLR0bits_t;
//002C
typedef struct	{
	uint32_t CLR32:1;
	uint32_t CLR33:1;
	uint32_t CLR34:1;
	uint32_t CLR35:1;
	uint32_t CLR36:1;
	uint32_t CLR37:1;
	uint32_t CLR38:1;
	uint32_t CLR39:1;
	uint32_t CLR40:1;
	uint32_t CLR41:1;
	uint32_t CLR42:1;
	uint32_t CLR43:1;
	uint32_t CLR44:1;
	uint32_t CLR45:1;
	uint32_t CLR46:1;
	uint32_t CLR47:1;
	uint32_t CLR48:1;
	uint32_t CLR49:1;
	uint32_t CLR50:1;
	uint32_t CLR51:1;
	uint32_t CLR52:1;
	uint32_t CLR53:1;
	uint32_t reserved:10;
}volatile GPCLR1bits_t;

int main(int argc, char *argv[])	{
	int fd, i;
	uint32_t *gpio;
	
	//GPFSEL0bits_t *GPFSEL0bits;
	//GPFSEL1bits_t *GPFSEL1bits;
	GPFSEL2bits_t *GPFSEL2bits;
	//GPFSEL3bits_t *GPFSEL3bits;
	//GPFSEL4bits_t *GPFSEL4bits;
	//GPFSEL5bits_t *GPFSEL5bits;
	GPSET0bits_t *GPSET0bits;
	//GPSET1bits_t *GPSET1bits;
	GPCLR0bits_t *GPCLR0bits;
	//GPCLR1bits_t *GPCLR1bits;
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
	//GPFSEL0bits = (GPFSEL0bits_t*)(((uint8_t*)gpio)+0x0000);
	//GPFSEL1bits = (GPFSEL1bits_t*)(((uint8_t*)gpio)+0x0004);
	GPFSEL2bits = (GPFSEL2bits_t*)(((uint8_t*)gpio)+0x0008);
	//GPFSEL3bits = (GPFSEL3bits_t*)(((uint8_t*)gpio)+0x000C);
	//GPFSEL4bits = (GPFSEL4bits_t*)(((uint8_t*)gpio)+0x0010);
	//GPFSEL5bits = (GPFSEL5bits_t*)(((uint8_t*)gpio)+0x0014);
	GPSET0bits = (GPSET0bits_t*)(((uint8_t*)gpio)+0x001C);
	//GPSET1bits = (GPSET1bits_t*)(((uint8_t*)gpio)+0x0020);
	GPCLR0bits = (GPCLR0bits_t*)(((uint8_t*)gpio)+0x0028);
	//GPCLR1bits = (GPCLR1bits_t*)(((uint8_t*)gpio)+0x002C);
	
	printf("GPSET1 = %s = 0x%x", (((uint8_t*)gpio)+0x0028), *(uint32_t*)(((uint8_t*)gpio)+0x0028));
	GPFSEL2bits->FSEL25 = 0b000; //set as output
	GPFSEL2bits->FSEL26 = 0b000; //set as output
	GPFSEL2bits->FSEL25 = 0b001; //set as output
	GPFSEL2bits->FSEL26 = 0b001; //set as output
	for(i = 0; i < 2; i++)	{
		GPSET0bits->SET25 = 1;
		getchar();
		//GPCLR0bits->CLR26 = 1;
		//sleep(1);
		//getchar();
		GPCLR0bits->CLR25 = 1;
		getchar();
		//GPSET0bits->SET26 = 1;
		//getchar();
		//sleep(1);
		printf("Arrivato\n");
	}
	GPCLR0bits->CLR26 = 1;
	GPCLR0bits->CLR25 = 1;
	return 0;
}

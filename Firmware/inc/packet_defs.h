#ifndef PACKET_DEF_H
#define PACKET_DEF_H


/* Packet for host communication */
typedef struct HostPackets {
	uint8_t ID_Field;
	uint8_t Size;
	uint8_t Transaction_ID;
	uint8_t Command_Class;
	uint8_t Command_ID;
	uint32_t *Payload; 

} HostPacket;	

//Packet Type
#define ID_COMMAND 0x55
#define ID_ACQUIRE 0xAA

//Command Classes 
#define RESET 		0x00
#define REG   		0x01
#define MEM   		0x02
#define PERIPHCTRL 	0x03
#define ADC		0x04
#define GPIO		0x05
#define SPI 		0x06
#define I2C		0x07
#define UART 		0x08
#define JTAG		0x09
#define POWER 		0x0A
#define WIFI		0x0B

//Command ID's 
//Resets
#define RESET_SRESET  	0x01
#define RESET_DMARESET 	0x02
#define RESET_ADCRESET  0x03
#define RESET_UARTRESET 0x04
#define RESET_I2CRESET  0x05
#define RESET_SPIRESET  0x06
#define RESET_PWRRESET  0x07
#define RESET_WIFIRESET 0x08

//Reg
#define REG_READ   	0x00
#define REG_WRITE	0x01

//Mem
#define MEM_READ	0x00
#define MEM_WRITE	0x01

//Periph Control 
#define PERIPH_SET_PERIPH_MAP	0x00
#define PERIPH_GET_PERIPH_MAP   0x01

//ADC 
#define ADC_INIT 	0x00
#define ADC_SET_EA_GAIN 0x01
#define ADC_READ_CHAN  	0x02

//GPIO 
#define GPIO_INIT	0x00
#define	GPIO_READ	0x01
#define GPIO_WRITE	0x02
#define GPIO_SET_DIR	0x03

//SPI
#define SPI_INIT	0x00
#define SPI_READ	0x01
#define SPI_WRITE	0x02

//i2c
#define I2C_INIT	0x00
#define I2C_READ	0x01
#define I2C_Write 	0x02

//UART
#define UART_INIT	0x00
#define UART_READ	0x01
#define UART_WRITE	0x02

//JTAG	
#define JTAG_INIT	0x00
#define JTAG_READ	0x01
#define JTAG_WRITE	0x02

//POWER
#define PWR_INIT 	0x00
#define PWR_EN_SUPPLY 	0x01
#define PWR_DIS_SUPPLy	0x02
#define PWR_BOOST_SEL 	0x03
#define PWR_TRIM_SEL	0x04
#define PWR_READ_SUPPLY 0x05
#define PWR_READ_BOARD  0x06
#define PWR_READ_STATUS 0x07

//WIFI
#define WIFI_GET_FW 	0x00
#define WIFI_SET_MODE 	0x01
#define WIFI_DEF_NET	0x02
#define WIFI_LST_NET	0x03
#define WIFI_CFG_AXS 	0x04
#define WIFI_SET_DEF 	0x05


#endif 

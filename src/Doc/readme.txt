/*********************************************************************************************/

【*】 Port

Summary:
	PA[2,3,9,10,11,12]
	PB[6:15]
	PC[0,3:12]
	PD[2,3,4,5,7,11,12]
	PE[1,6]
		
Camera:
		OV7725_OE 		<--->	PA3     //FIFO输出使能
		OV7725_RRST 	<--->	PA2		//读指针复位引脚，低电平复位
		OV7725_RCLK 	<--->	PC5		//FIFO读时钟
		OV7725_XCLK 	<--->	不需要连接，OV7725时钟输入引脚，摄像头内已自带晶振
		OV7725_VSYNC 	<--->	PC3		//OV7725帧同步信号
		OV7725_WRST 	<--->	PC4		//写指针复位引脚，低电平复位
		OV7725_WEN 		<--->	PD3		//FIFO写使能
		OV7725_HREF 	<--->	不需要连接，本程序控制不需要这个信号		
		OV7725_D[0:7] 	<--->	PB[8:15]	//FIFO数据信号线		
		OV7725_SIO_C 	<--->	PC6		//I2C 时钟信号，模拟
		OV7725_SIO_D 	<--->	PC7		//I2C 数据信号，模拟

										
LCD:
		/*液晶控制信号线*/
		ILI9341_CS 	<--->	PD7      	//片选，选择NOR/SRAM块 BANK1_NOR/SRAM1
		ILI9341_DC  <---> 	PD11		//PD11为FSMC_A16,本引脚决定了访问LCD时使用的地址
		ILI9341_WR 	<---> 	PD5			//写使能
		ILI9341_RD  <---> 	PD4			//读使能
		ILI9341_RST	<---> 	PE1			//复位引脚
		ILI9341_BK 	<---> 	PD12 		//背光引脚
		
	数据信号线省略,本实验没有驱动触摸屏。

串口(TTL-USB TO USART)：
CH340的收发引脚与STM32的发收引脚相连。
	RX<--->PA9
	TX<--->PA10
	
WIFI:
	PB[8:11]

SDIO(microSD??,??32G???SD?):
microtSD???SDIO???STM32?SDIO???
		SDIO_D0	<--->PC8
		SDIO_D1	<--->PC9
		SDIO_D2	<--->PC10
		SDIO_D3	<--->PC11
		SDIO_CK	<--->PC12
		SDIO_CMD<--->PD2
		
DHT11:
	DATA <---> PE.6

BH1750:
	SCL <---> PB.6
	SDL <---> PB.7
	
Soil Moisture Detector:
	DATA <---> PC.0

KEY3:
	DATA <---> PA.11
	
PUMP Control Signal:
	DATA <---> PA.12
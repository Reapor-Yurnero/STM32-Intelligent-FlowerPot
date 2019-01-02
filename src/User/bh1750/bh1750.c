#include "stm32f10x.h"
#include "./bh1750/bh1750.h"
#include "./bh1750/bsp_i2c_gpio.h"
#include "./SysTick/bsp_SysTick.h"


float result_lx=0;
uint8_t BUF[2]={0};
uint16_t result=0;
 void i2c_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	

	GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN| I2C_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	i2c_Stop();
}

void Init_BH1750(void)
{
 i2c_config();
}

void Cmd_Write_BH1750(u8 cmd)
{
    i2c_Start();                  
    i2c_SendByte(BH1750_Addr+0);   
	while(i2c_WaitAck())
		;
    i2c_SendByte(cmd);    
	while(i2c_WaitAck())
		;
    //BH1750_SendByte(REG_data);       
    i2c_Stop();                   
	  Delay_ms(5);
}

void Start_BH1750(void)
{
	Cmd_Write_BH1750(BH1750_ON);	 
	Cmd_Write_BH1750(BH1750_RSET);	
	Cmd_Write_BH1750(BH1750_ONE);  
}

void Read_BH1750(void)
{   	
    i2c_Start();                          
    i2c_SendByte(BH1750_Addr+1);        
	while(i2c_WaitAck())
		;
	BUF[0]=i2c_ReadByte(1);  
	BUF[1]=i2c_ReadByte(0); 

    i2c_Stop();                          
    Delay_ms(5);
}

float Convert_BH1750(void)
{
	
	result=BUF[0];
	result=(result<<8)+BUF[1];  
	result_lx=(float)result/1.2;
  return result_lx;
}













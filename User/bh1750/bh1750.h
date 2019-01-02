#ifndef _BH1750_H
#define _BH1750_H

#define BH1750_Addr 0x46
#define BH1750_ON   0x01
#define BH1750_CON  0x10
#define BH1750_ONE  0x20
#define BH1750_RSET 0x07

void Init_BH1750(void);								 
void Start_BH1750(void);			
void Read_BH1750(void);                              
float Convert_BH1750(void);
#endif









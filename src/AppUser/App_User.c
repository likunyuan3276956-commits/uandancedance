/******************************************************************************************
//FileName 			:
//ProjectName  	:
//MCU 	       	:
//Security			:
//Fosc					:
//PLL INPUT  		:
//PLL OUTPUT 		:
//Fcpu					:
//Watch_Dog			:
//LVD						:
//Writen by 		:
//Date      		:
******************************************************************************************/


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include 		<stdio.h>
#include 		"flash.h"
#include    "usb_class.h"
#include 		"App_SW_I2C.h"
#include 		"App_UART.h"
#include 		"App_User.h"
#include 		"App_RGB.h"
#include 		"App_BSP.h"
#include    "Chip2813.h"


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#define APP_USER_LOG(x)           		printf x
#define APP_USER_DBG(x)           		//printf x

//******************************************************************************
//
//------------- Constant  define    -------------------
//
//******************************************************************************

//******************************************************************************
//
//-------------  I/O  define   --------------------
//
//******************************************************************************

//******************************************************************************
//
//------------- Type Defs    -------------------
//
//******************************************************************************

//******************************************************************************
//
//-------------  Variable  define   --------------------
//
//******************************************************************************

AppUser_t					AppUser;
AppADC_t					AppADC;

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_User_TimeTick_CB(void)
{
  unsigned char i;
  //----------------------------------------------------------
	AppUser.SysTimeTick++;
	AppUser.T1MS_FG = 1;
  //----------------------------------------------------------
  for(i=0;i<MAX_VAL_CHAN;i++) //Version	V1.01	: (1)20240617		: App Param Config 
  {
    if(AppUser.Tck[i]>0)AppUser.Tck[i]--;
  }
	//----------------------------------------------------------
	AppUser.Tick10MS++;
	if(AppUser.Tick10MS>=10)
	{
		AppUser.Tick10MS 	= 0;
		AppUser.T10MS_FG	=	1;
    AppUser.N10MS_FG	=	1;  //Version	V1.05	: (1)20240719		: Mult Key Issue
	}
  //----------------------------------------------------------
	AppUser.Tick100MS++;
	if(AppUser.Tick100MS>=100)
	{
		AppUser.Tick100MS	= 0;
		AppUser.T100MS_FG	=	1;
		
		AppUser.Tick1Sec++;
		if(AppUser.Tick1Sec>=10)
		{
			AppUser.Tick1Sec 	= 0;
			AppUser.T1Sec_FG	=	1;
		}
	}
  //----------------------------------------------------------
//  AppUser.FlashSpeed++; //Version	V2.11	: (4)20260614		: RGB Issure
//  if(AppUser.FlashSpeed>=400)
//  {
//    AppUser.FlashSpeed = 0;
//    AppUser.FlashFlag  = 1;
//  }
  //----------------------------------------------------------
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


unsigned short 	const Default_Sensi_Tab[MAX_VAL_CHAN]=		
{
  DEFAULT_SENSI, // 0 : KeyPad-1A
  DEFAULT_SENSI, // 1 : KeyPad-1B
  DEFAULT_SENSI, // 2 : KeyPad-1C
  DEFAULT_SENSI, // 3 : KeyPad-1D
  
  DEFAULT_SENSI, // 4 : KeyPad-2A
  DEFAULT_SENSI, // 5 : KeyPad-2B
  DEFAULT_SENSI, // 6 : KeyPad-2C
  DEFAULT_SENSI, // 7 : KeyPad-2D
  
  DEFAULT_SENSI, // 8 : KeyPad-3A
  DEFAULT_SENSI, // 9 : KeyPad-3B
  DEFAULT_SENSI, //10 : KeyPad-3C
  DEFAULT_SENSI, //11 : KeyPad-3D
  
  DEFAULT_SENSI, //12 : KeyPad-4A
  DEFAULT_SENSI, //13 : KeyPad-4B
  DEFAULT_SENSI, //14 : KeyPad-4C
  DEFAULT_SENSI, //15 : KeyPad-4D
  
  DEFAULT_SENSI, //16 : KeyPad-5A
  DEFAULT_SENSI, //17 : KeyPad-5B
  DEFAULT_SENSI, //18 : KeyPad-5C
  DEFAULT_SENSI, //19 : KeyPad-5D

  DEFAULT_SENSI, //20 : KeyPad-6A
  DEFAULT_SENSI, //21 : KeyPad-6B
  DEFAULT_SENSI, //22 : KeyPad-6C
  DEFAULT_SENSI, //23 : KeyPad-6D
  
  DEFAULT_SENSI, //24 : KeyPad-7A
  DEFAULT_SENSI, //25 : KeyPad-7B
  DEFAULT_SENSI, //26 : KeyPad-7C
  DEFAULT_SENSI, //27 : KeyPad-7D

  DEFAULT_SENSI, //28 : KeyPad-8A
  DEFAULT_SENSI, //29 : KeyPad-8B
  DEFAULT_SENSI, //30 : KeyPad-8C
  DEFAULT_SENSI, //31 : KeyPad-8D
  
  DEFAULT_SENSI, //32 : KeyPad-9A
  DEFAULT_SENSI, //33 : KeyPad-9B
  DEFAULT_SENSI, //34 : KeyPad-9C
  DEFAULT_SENSI, //35 : KeyPad-9D  
};

unsigned short 	const Default_Color_Tab[MAX_VAL_CHAN]=		
{
  //Version	V2.11	: (1)20260614		: 5Key & 4Key macro £¨BaseOn V2.06)
  //Version	V2.03	: (1)20251208		: Change Defalut LED Color
  USER_DEFAULT_COLOR_1, // 0 : KeyPad-1A  //Version	V2.07	: (1)20260427		: Change Default Color,disable channel 5  //Version	V1.13	: (1)20240914		: Change RGB Deflaut Color 1&3=Blue,2&4=Red //Version	V1.12	: (1)20240904		: Change RGB Deflaut Color 1&3=Green,2&4=Red  //Version	V1.11	: (1)20240904		: Change RGB Deflaut Color
  USER_DEFAULT_COLOR_1, // 1 : KeyPad-1B
  USER_DEFAULT_COLOR_1, // 2 : KeyPad-1C
  USER_DEFAULT_COLOR_1, // 3 : KeyPad-1D
  
  USER_DEFAULT_COLOR_2, // 4 : KeyPad-2A  //Version	V2.07	: (1)20260427		: Change Default Color,disable channel 5  //Version	V1.11	: (1)20240904		: Change RGB Deflaut Color
  USER_DEFAULT_COLOR_2, // 5 : KeyPad-2B
  USER_DEFAULT_COLOR_2, // 6 : KeyPad-2C
  USER_DEFAULT_COLOR_2, // 7 : KeyPad-2D
  
  USER_DEFAULT_COLOR_3, // 8 : KeyPad-3A  //Version	V2.07	: (1)20260427		: Change Default Color,disable channel 5  //Version	V1.13	: (1)20240914		: Change RGB Deflaut Color 1&3=Blue,2&4=Red //Version	V1.12	: (1)20240904		: Change RGB Deflaut Color 1&3=Green,2&4=Red  //Version	V1.11	: (1)20240904		: Change RGB Deflaut Color
  USER_DEFAULT_COLOR_3, // 9 : KeyPad-3B
  USER_DEFAULT_COLOR_3, //10 : KeyPad-3C
  USER_DEFAULT_COLOR_3, //11 : KeyPad-3D
  
  USER_DEFAULT_COLOR_4, //12 : KeyPad-4A  //Version	V2.07	: (1)20260427		: Change Default Color,disable channel 5  //Version	V1.11	: (1)20240904		: Change RGB Deflaut Color
  USER_DEFAULT_COLOR_4, //13 : KeyPad-4B
  USER_DEFAULT_COLOR_4, //14 : KeyPad-4C
  USER_DEFAULT_COLOR_4, //15 : KeyPad-4D
  
  USER_DEFAULT_COLOR_5, //16 : KeyPad-5A
  USER_DEFAULT_COLOR_5, //17 : KeyPad-5B
  USER_DEFAULT_COLOR_5, //18 : KeyPad-5C
  USER_DEFAULT_COLOR_5, //19 : KeyPad-5D

  USER_COLOR_R, //20 : KeyPad-6A
  USER_COLOR_R, //21 : KeyPad-6B
  USER_COLOR_R, //22 : KeyPad-6C
  USER_COLOR_R, //23 : KeyPad-6D
  
  USER_COLOR_B, //24 : KeyPad-7A
  USER_COLOR_B, //25 : KeyPad-7B
  USER_COLOR_B, //26 : KeyPad-7C
  USER_COLOR_B, //27 : KeyPad-7D

  USER_COLOR_R, //28 : KeyPad-8A
  USER_COLOR_R, //29 : KeyPad-8B
  USER_COLOR_R, //30 : KeyPad-8C
  USER_COLOR_R, //31 : KeyPad-8D
  
  USER_COLOR_B, //32 : KeyPad-9A
  USER_COLOR_B, //33 : KeyPad-9B
  USER_COLOR_B, //34 : KeyPad-9C
  USER_COLOR_B, //35 : KeyPad-9D   
};


unsigned short 	const Default_DTick_Tab[MAX_VAL_CHAN]=		
{
  DEFAULT_DTICK, // 0 : KeyPad-1A
  DEFAULT_DTICK, // 1 : KeyPad-1B
  DEFAULT_DTICK, // 2 : KeyPad-1C
  DEFAULT_DTICK, // 3 : KeyPad-1D
  
  DEFAULT_DTICK, // 4 : KeyPad-2A
  DEFAULT_DTICK, // 5 : KeyPad-2B
  DEFAULT_DTICK, // 6 : KeyPad-2C
  DEFAULT_DTICK, // 7 : KeyPad-2D
  
  DEFAULT_DTICK, // 8 : KeyPad-3A
  DEFAULT_DTICK, // 9 : KeyPad-3B
  DEFAULT_DTICK, //10 : KeyPad-3C
  DEFAULT_DTICK, //11 : KeyPad-3D
  
  DEFAULT_DTICK, //12 : KeyPad-4A
  DEFAULT_DTICK, //13 : KeyPad-4B
  DEFAULT_DTICK, //14 : KeyPad-4C
  DEFAULT_DTICK, //15 : KeyPad-4D
  
  DEFAULT_DTICK, //16 : KeyPad-5A
  DEFAULT_DTICK, //17 : KeyPad-5B
  DEFAULT_DTICK, //18 : KeyPad-5C
  DEFAULT_DTICK, //19 : KeyPad-5D

  DEFAULT_DTICK, //20 : KeyPad-6A
  DEFAULT_DTICK, //21 : KeyPad-6B
  DEFAULT_DTICK, //22 : KeyPad-6C
  DEFAULT_DTICK, //23 : KeyPad-6D
  
  DEFAULT_DTICK, //24 : KeyPad-7A
  DEFAULT_DTICK, //25 : KeyPad-7B
  DEFAULT_DTICK, //26 : KeyPad-7C
  DEFAULT_DTICK, //27 : KeyPad-7D

  DEFAULT_DTICK, //28 : KeyPad-8A
  DEFAULT_DTICK, //29 : KeyPad-8B
  DEFAULT_DTICK, //30 : KeyPad-8C
  DEFAULT_DTICK, //31 : KeyPad-8D
  
  DEFAULT_DTICK, //32 : KeyPad-9A
  DEFAULT_DTICK, //33 : KeyPad-9B
  DEFAULT_DTICK, //34 : KeyPad-9C
  DEFAULT_DTICK, //35 : KeyPad-9D  
};


/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe:
******************************************************************************************/
void App_Get_Flash_Cofnig(unsigned int Addr, unsigned short *SensiBuffer, unsigned short *Default, unsigned char Size)
{
	//----------------------------------------------------------
	uint32_t i;
	uint16_t CS=0;
  uint16_t Flash_Buffer[FLASH_BUFEER_SIZE];
	//----------------------------------------------------------
  // read data from flash 
  flash_read(Addr, Flash_Buffer, FLASH_BUFEER_SIZE);
	printf("FlashR:%08X,%d \r\n",Addr,FLASH_BUFEER_SIZE);
	for(i=0;i<(1+Size+1);i++)
	{
		printf("%04X",Flash_Buffer[i]);
		if((i!=0)&&(((i+1)%8)==0))printf("\r\n");
	}
	printf("\r\n");
	//----------------------------------------------------------
	CS = UPDATE_CRC_16((unsigned char *)Flash_Buffer,(Size+1)*2);
	if(Flash_Buffer[0]==0xA55A && Flash_Buffer[Size+1]==CS)
	{
		printf("Load Flash Sens:CS=%04X\r\n",Flash_Buffer[Size+1]);
		for(i=0;i<Size;i++)
		{
			SensiBuffer[i] = Flash_Buffer[i+1];
		}		
	}
	else
	{
		printf("Load Default Sens:%04X,%04X\r\n",Flash_Buffer[0],Flash_Buffer[Size+1]);
		for(i=0;i<Size;i++)
		{
			SensiBuffer[i] = Default[i];
		}		
	}
	//----------------------------------------------------------
}

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe:
******************************************************************************************/
void App_Set_Flash_Cofnig(unsigned int Addr, unsigned short *SensiBuffer, unsigned char Size)
{
	//----------------------------------------------------------
	uint32_t i;
  error_status err_status;
	flash_status_type status = FLASH_OPERATE_DONE;
  uint16_t Flash_Buffer[FLASH_BUFEER_SIZE];
	//----------------------------------------------------------
	flash_unlock();
	status = flash_sector_erase(Addr);
	flash_lock();
	printf("Erase Flash: %08X,%08X\r\n",Addr,status);
	//----------------------------------------------------------
  // fill buffer_write data to test 
	Flash_Buffer[0]=0xA55A;
  for(i = 0; i < Size; i++)
  {
    Flash_Buffer[i+1] = SensiBuffer[i];
  }	
	Flash_Buffer[Size+1] = UPDATE_CRC_16((unsigned char *)Flash_Buffer,(Size+1)*2);
	//----------------------------------------------------------
	printf("FlashW:%08X,%02X,%d \r\n",Addr,err_status,FLASH_BUFEER_SIZE);
	for(i=0;i<(Size+2);i++)
	{
		printf("%04X",Flash_Buffer[i]);
		if((i!=0)&&(((i+1)%8)==0))printf("\r\n");
	}
	printf("\r\n");	
	//----------------------------------------------------------
	// write data to flash 
  err_status = flash_write(Addr, Flash_Buffer, FLASH_BUFEER_SIZE);
	//----------------------------------------------------------
}


/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe:
******************************************************************************************/
unsigned char	CommandBuffer[128];		
void App_Config_Command_Report(unsigned char *CMDBuffer,unsigned char CMDLen,unsigned char *RSPBuffer,unsigned char RSPLen)	//Version	V4.01	: (2)20240616		: USB CMD for Touch Senitivity Config
{
	//----------------------------------------------------------------
	unsigned char 	i;
	unsigned char 	CRC_U8;
  unsigned short  *ValueBuffer;
    //----------------------------------------------------------------
//  printf("TPS Cmd: %02X: Raw: ",CMDLen);
//  for(i=0;i<CMDLen;i++)
//  {
//    printf("%02X ",CMDBuffer[i]);
//  }
//  printf("\r\n"); 
  //----------------------------------------------------------------
  if((CMDBuffer[4]&0xF0)==0x00)   
  {
    for(i=0; i<RSPLen; i++)
    {
      RSPBuffer[i] = 0x00;
    }
  }
	//----------------------------------------------------------------
  //CMD : 52 45 41 44 00
  //RSP : 52 52 53 50 00
  //Data: 03 E8 03 E8 03 E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 
  //CS	: 66		
	//----------------------------------------------------------------
	if(	CMDBuffer[0]==0x52 &&		//R
			CMDBuffer[1]==0x45 && 	//E
			CMDBuffer[2]==0x41 && 	//A
			CMDBuffer[3]==0x44)			//D
	{
    //Bit[7:4] : 0x00=WMCU,  0x10=ExChip1, 0x20=ExChip2
    //Bit[3:0] : 0x00=Sensi, 0x01=Color,  0x020=DTick   
    if((CMDBuffer[4]&0xF0)==0x00)   
    {
      if((CMDBuffer[4]&0x0F)==0x01)     { ValueBuffer = &AppUser.Color[0];  }
      else if((CMDBuffer[4]&0x0F)==0x02){ ValueBuffer = &AppUser.DTick[0];  }
      else                              { ValueBuffer = &AppUser.Sensi[0];  }

      RSPBuffer[0]=0x52;				  //R
      RSPBuffer[1]=0x52;				  //R
      RSPBuffer[2]=0x53;				  //S
      RSPBuffer[3]=0x50;				  //P
      RSPBuffer[4]=CMDBuffer[4];  // 
      printf("Read Config: %02X: ",RSPBuffer[4]);
      for(i=0;i<(DATA_LEN/2);i++)
      {
        RSPBuffer[HEAD_LEN+(i*2+0)]= (ValueBuffer[i]>>8)&0xff;
        RSPBuffer[HEAD_LEN+(i*2+1)]= (ValueBuffer[i]>>0)&0xff;
        printf("%04X ",ValueBuffer[i]);
      }
      printf("\r\n");
      RSPBuffer[HEAD_LEN+DATA_LEN]=UPDATE_CRC(RSPBuffer,HEAD_LEN+DATA_LEN); 
    }
    else if((CMDBuffer[4]&0xF0)==0x10)   
    {
      AppUart5.TXD_BUF[0] = PMCU_SYNC_H;
      AppUart5.TXD_BUF[1] = PMCU_SYNC_L;
      AppUart5.TXD_BUF[2] = MAXS_LEN;
      for(i=0;i<(PAKE_LEN);i++)
      {
        AppUart5.TXD_BUF[3+i] = CMDBuffer[i];
      }
      App_UART_Send_Buff(UART5, &AppUart5, AppUart5.TXD_BUF,MAXS_LEN);
    }
    else
    {
      AppUart3.TXD_BUF[0] = PMCU_SYNC_H;
      AppUart3.TXD_BUF[1] = PMCU_SYNC_L;
      AppUart3.TXD_BUF[2] = MAXS_LEN;
      for(i=0;i<(PAKE_LEN);i++)
      {
        AppUart3.TXD_BUF[3+i] = CMDBuffer[i];
      }
      App_UART_Send_Buff(USART3, &AppUart3, AppUart3.TXD_BUF,MAXS_LEN);
    }
	}  
  //----------------------------------------------------------------
	//CMD : 57 52 49 54 00
	//Data: 03 E8 03 E8 03 E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 03E8 
	//CS	: FA
	//RSP : 57 4F 4B FA 00 
	//----------------------------------------------------------------
	else if(CMDBuffer[0]==0x57 &&
					CMDBuffer[1]==0x52 && 
					CMDBuffer[2]==0x49 && 
					CMDBuffer[3]==0x54 &&
					CMDLen>=38)						//5Bytes Head+16*2Bytes Data + 1Byte CS
	{
		//--------------------------------------------------------------
		for(i=0;i<(HEAD_LEN+DATA_LEN+1);i++)
		{
			CommandBuffer[i]= CMDBuffer[i];
		}
		CRC_U8=UPDATE_CRC(CommandBuffer,(HEAD_LEN+DATA_LEN));		
		//--------------------------------------------------------------
		if(CRC_U8==CommandBuffer[HEAD_LEN+DATA_LEN])
		{
      //Bit[7:4] : 0x00=WMCU,  0x10=ExChip1, 0x20=ExChip2
      //Bit[3:0] : 0x00=Sensi, 0x01=Color,  0x020=DTick   
      if((CMDBuffer[4]&0xF0)==0x00)   
      {
        if((CMDBuffer[4]&0x0F)==0x01)     { ValueBuffer = &AppUser.Color[0];  }
        else if((CMDBuffer[4]&0x0F)==0x02){ ValueBuffer = &AppUser.DTick[0];  }
        else                              { ValueBuffer = &AppUser.Sensi[0];  }
        
				printf("Write Config 1-16: ");
				for(i=0;i<(DATA_LEN/2);i++)
				{
					ValueBuffer[i] = ((CommandBuffer[HEAD_LEN+(i*2+0)]<<8)|(CommandBuffer[HEAD_LEN+(i*2+1)]));
          printf("%04X ",ValueBuffer[i]);
				}
        printf("\r\n");
        
        if((CMDBuffer[4]&0x0F)==0x01)     { App_Set_Flash_Cofnig(FLASH_DATA_ADDR_COLOR, AppUser.Color, MAX_VAL_CHAN);  }
        else if((CMDBuffer[4]&0x0F)==0x02){ App_Set_Flash_Cofnig(FLASH_DATA_ADDR_DTICK, AppUser.DTick, MAX_VAL_CHAN);  }
        //else                            { App_Set_Flash_Cofnig(FLASH_DATA_ADDR_SENSI, AppUser.Sensi, ADC_MAX_CHAN);  }  //Version	V1.15	: (1)20240930		: Power On Sensor Scan
        
        
        RSPBuffer[0]=0x57;
				RSPBuffer[1]=0x4F;	      //O
				RSPBuffer[2]=0x4B;	      //K
				RSPBuffer[3]=CRC_U8;
				RSPBuffer[4]=CMDBuffer[4];
				//App_User_USB_SendPacket(TP_CMD_BUF,8);
      }
      else if((CMDBuffer[4]&0xF0)==0x10)   
      {
        AppUart5.TXD_BUF[0] = PMCU_SYNC_H;
        AppUart5.TXD_BUF[1] = PMCU_SYNC_L;
        AppUart5.TXD_BUF[2] = MAXS_LEN;
        for(i=0;i<(PAKE_LEN);i++)
        {
          AppUart5.TXD_BUF[3+i] = CMDBuffer[i];
        }
        App_UART_Send_Buff(UART5, &AppUart5, AppUart5.TXD_BUF,MAXS_LEN);
      }
      else
      {
        AppUart3.TXD_BUF[0] = PMCU_SYNC_H;
        AppUart3.TXD_BUF[1] = PMCU_SYNC_L;
        AppUart3.TXD_BUF[2] = MAXS_LEN;
        for(i=0;i<(PAKE_LEN);i++)
        {
          AppUart3.TXD_BUF[3+i] = CMDBuffer[i];
        }
        App_UART_Send_Buff(USART3, &AppUart3, AppUart3.TXD_BUF,MAXS_LEN);
      }     
		}
		//--------------------------------------------------------------
		else
		{
			printf("Write Tp Sens CS:%02X-%02X\r\n",CRC_U8,CommandBuffer[HEAD_LEN+DATA_LEN]);
			RSPBuffer[0]=0x57;
			RSPBuffer[1]=0x46;    //F
			RSPBuffer[2]=0x49;    //I
			RSPBuffer[3]=CRC_U8;
			RSPBuffer[4]=CMDBuffer[4];
			//App_User_USB_SendPacket(TP_CMD_BUF,8);
		}
		//--------------------------------------------------------------
	}
	//----------------------------------------------------------------
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_User_SetKeyStatus(unsigned char Index,unsigned char State)
{
  //--------------------------------------------------
  if(State==TRUE)
  {
    AppUser.KeyCode  |= (1<<Index);
    AppUser.KeyNewsFG = 1;
  }
  //--------------------------------------------------
  else
  {
    AppUser.KeyCode  &= (1<<Index)^0xffff;
    AppUser.KeyNewsFG = 1;
  }
  //--------------------------------------------------
}

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
unsigned char App_User_GetKeyStatus(unsigned char Index)
{
  //--------------------------------------------------
  unsigned char State = 0;
  //--------------------------------------------------
  if((AppUser.KeyCode & (1<<Index)) !=0)
  {
    State = 1;
  }
  //--------------------------------------------------
  return State;
  //--------------------------------------------------
}


/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_User_Btn_Scan(void)
{	
	//-------------------------------------------------- READ BTN
	AppUser.IO_BUF	=	0;
	//-------------------------------------------------- 
//	if (IO_PMCU1_S1_READ()!=0)  AppUser.IO_BUF |= KEY_CODE_01;
//	if (IO_PMCU1_S2_READ()!=0)  AppUser.IO_BUF |= KEY_CODE_02;  
//	if (IO_PMCU1_S3_READ()!=0)  AppUser.IO_BUF |= KEY_CODE_03; 
//  //-------------------------------------------------- 
//	if (IO_PMCU2_S1_READ()!=0)  AppUser.IO_BUF |= KEY_CODE_04;
//	if (IO_PMCU2_S2_READ()!=0)  AppUser.IO_BUF |= KEY_CODE_05;  
//	if (IO_PMCU2_S3_READ()!=0)  AppUser.IO_BUF |= KEY_CODE_06;   
  //-------------------------------------------------- 
	if (IO_SW_1_READ()==0)     {IO_SW_LED1_ON();  AppUser.IO_BUF |= KEY_CODE_07;}
  else                       {IO_SW_LED1_OFF();}
	if (IO_SW_2_READ()==0)     {IO_SW_LED2_ON();  AppUser.IO_BUF |= KEY_CODE_08;}
  else                       {IO_SW_LED2_OFF();}
//	if (IO_SW_3_READ()==0)     {IO_SW_LED3_ON();  AppUser.IO_BUF |= KEY_CODE_09;}
//  else                       {IO_SW_LED3_OFF();}
  //-------------------------------------------------- 
  if (IO_USB_PWR_READ()==0)   AppUser.IO_BUF |= KEY_CODE_10;  
	if (IO_RGB_PWR_READ()==0)   AppUser.IO_BUF |= KEY_CODE_11;
  //--------------------------------------------------
  if(AppUser.IO_REG != AppUser.IO_BUF)
  {
    AppUser.BTN_DN++;
    if(AppUser.BTN_DN>5)
    {
      AppUser.IO_REG			=	AppUser.IO_BUF;		// Key Down
      AppUser.Value				=	AppUser.IO_BUF;		// New Key Value
      AppUser.BtnDownFG	=	1;		
      AppUser.BtnNewsFG	=	1;
      APP_USER_LOG(("BTN  DN : %04X\r\n",AppUser.IO_REG));
    }						
  }
  else
  {
    AppUser.BTN_DN = 0;
  }
  //--------------------------------------------------	
}

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_User_Sta_Update(void)
{
  //-----------------------------------------------------------------
  unsigned char i,NewADCFlag;
  unsigned char Index;//Version	V1.06	: (1)20240720		: RAW Date Fort App Seni Config 
  unsigned short Range; //Version	V1.15	: (1)20240930		: Power On Sensor Scan
  //-----------------------------------------------------------------
  for(i=0;i<MAX_VAL_CHAN;i++)
  {
    if(AppUser.Buf[i]!=AppADC.Buf[i])
    {
      AppUser.Buf[i]= AppADC.Buf[i];
      NewADCFlag    = 1;
    }
  }
  //-----------------------------------------------------------------
  //Version	V1.15	: (1)20240930		: Power On Sensor Scan
  if(AppUser.PwrOnTick>0)
  {
    if(NewADCFlag)
    {
      printf("SCAN 1-36: ");
      for(i=0;i<(MAX_VAL_CHAN);i++)
      {
        printf("%04X ",AppUser.Buf[i]);
        Range = (AppUser.Buf[i]+AUTO_SENSI);
        if(AppUser.Sensi[i] >= Range)
        {
          Range = AppUser.Sensi[i] - Range;
        }
        else
        {
          Range = Range - AppUser.Sensi[i];
        }
        if(Range>=10)
        {
          AppUser.Sensi[i] = AppUser.Buf[i]+AUTO_SENSI;
          AppUser.SensiNew = 1;
        }
      }
      printf("\r\n");
    }
    return;        
  }
  //-----------------------------------------------------------------
  if(NewADCFlag)
  {
    for(i=0;i<MAX_VAL_CHAN;i++)
    {
      if(AppUser.Buf[i] > AppUser.Sensi[i])
      {
        //Version	V1.06	: (1)20240720		: RAW Date Fort App Seni Config 
        if(App_User_GetKeyStatus(i/4)==0)   //Version	V2.05	: (1)20260103		: HID/KB Mode Latency ISSUE
        {
          printf("ADC  ON : %d,%04X,%04X,%04X\r\n",i,AppUser.Buf[i],AppUser.Reg[i],AppUser.KeyCode);
        }
        //if(AppUser.Buf[i] > AppUser.Max[i])AppUser.Max[i]=AppUser.Buf[i];
        
        AppUser.Reg[i]    = AppUser.Buf[i]; 
        AppUser.Tck[i/4]  = AppUser.DTick[i/4];  //Version	V1.01	: (1)20240617		: App Param Config  
        App_User_SetKeyStatus(i/4,TRUE); 
      }
      else if(AppUser.Reg[i] > AppUser.Sensi[i] && AppUser.Tck[i/4]==0) //Version	V1.01	: (1)20240617		: App Param Config   
      {
        //Version	V1.06	: (1)20240720		: RAW Date Fort App Seni Config 
        if(App_User_GetKeyStatus(i/4)!=0)
        {
          printf("ADC  New: %d,%04X,%04X,%04X\r\n",i,AppUser.Buf[i],AppUser.Reg[i],AppUser.KeyCode);
        }
        
        //Index = (i/4)*4;
        //printf("ADC  New: %d,[%04d,%04d,%04d,%04d]-[%04d,%04d,%04d,%04d]-%04X\r\n",i,
        //AppUser.Max[Index+0],AppUser.Max[Index+1],AppUser.Max[Index+2],AppUser.Max[Index+3],
        //AppUser.Sensi[Index+0],AppUser.Sensi[Index+1],AppUser.Sensi[Index+2],AppUser.Sensi[Index+3],
        //AppUser.KeyCode);
        
        Index = (i/4)*4;
        //printf("ADC  New: %d,[%04d,%04d,%04d,%04d]-%04X\r\n",i,
        //AppUser.Sensi[Index+0],AppUser.Sensi[Index+1],AppUser.Sensi[Index+2],AppUser.Sensi[Index+3],
        //AppUser.KeyCode);
        
        //Version	V2.05	: (1)20260103		: HID/KB Mode Latency ISSUE
        //printf("ADC  OFF: %d,%04X,[%04X,%04X,%04X,%04X],%04X\r\n",i,AppUser.Buf[i],AppUser.Reg[Index+0],AppUser.Reg[Index+1],AppUser.Reg[Index+2],AppUser.Reg[Index+3],AppUser.KeyCode);
        
        
        //Version	V1.09	: (1)20240727		: RAW ADC Data Continuous update
        //if(AppUser.MDRAW_FG)
        //{
        //  App_User_RAW_MODE_Update(Index, AppUser.Max,ADC_MAX_CHAN);
        //}
        
        AppUser.Reg[i] = AppUser.Buf[i];
        if(AppUser.Reg[Index+0] <= AppUser.Sensi[Index+0] &&
           AppUser.Reg[Index+1] <= AppUser.Sensi[Index+1] &&
           AppUser.Reg[Index+2] <= AppUser.Sensi[Index+2] &&
           AppUser.Reg[Index+3] <= AppUser.Sensi[Index+3])
        {
          //AppUser.Max[Index+0] = 0;
          //AppUser.Max[Index+1] = 0;
          //AppUser.Max[Index+2] = 0;
          //AppUser.Max[Index+3] = 0;
          App_User_SetKeyStatus(i/4,FALSE); 
        }  
      }
    }
    
    //Version	V1.09	: (1)20240727		: RAW ADC Data Continuous update
    if(AppUser.MDRAW_FG)
    {
      App_User_RAW_MODE_Update(Index, AppUser.Buf,MAX_VAL_CHAN);
    }
    
  }
	//-----------------------------------------------------------------
	if(AppUser.BtnNewsFG)
	{
		if(AppUser.BtnHoldFG)
		{
      printf("BTN  HD : %04X\r\n",AppUser.Value);
			//BtnHoldForMoto(AppUser.Value);
			AppUser.BtnHoldFG = 0;
		}
		else
		{
			//-------------------------------------------------------------
      //printf("BTN  New: %04X\r\n",AppUser.Value);
			//-------------------------------------------------------------
//      if(AppUser.Value & KEY_CODE_01)     { App_User_SetKeyStatus(4,TRUE);  }
//      else if(AppUser.ValBK & KEY_CODE_01){ App_User_SetKeyStatus(4,FALSE); }
//      
//      if(AppUser.Value & KEY_CODE_02)     { App_User_SetKeyStatus(5,TRUE);  }
//      else if(AppUser.ValBK & KEY_CODE_02){ App_User_SetKeyStatus(5,FALSE); }
//      
//      if(AppUser.Value & KEY_CODE_03)     { App_User_SetKeyStatus(6,TRUE);  }
//      else if(AppUser.ValBK & KEY_CODE_03){ App_User_SetKeyStatus(6,FALSE); }
//      
//      if(AppUser.Value & KEY_CODE_04)     { App_User_SetKeyStatus(7,TRUE);  }
//      else if(AppUser.ValBK & KEY_CODE_04){ App_User_SetKeyStatus(7,FALSE); }
//      
//      if(AppUser.Value & KEY_CODE_05)     { App_User_SetKeyStatus(8,TRUE);  }
//      else if(AppUser.ValBK & KEY_CODE_05){ App_User_SetKeyStatus(8,FALSE); }
//      
//      if(AppUser.Value & KEY_CODE_06)     { App_User_SetKeyStatus(9,TRUE); }
//      else if(AppUser.ValBK & KEY_CODE_06){ App_User_SetKeyStatus(9,FALSE);}      
      //-------------------------------------------------------------
      AppUser.ValBK = AppUser.Value;
			//-------------------------------------------------------------
		}
		AppUser.BtnNewsFG = 0;
	}
  //-----------------------------------------------------------------
	if(AppUser.KeyNewsFG)
	{
    if((AppUser.KeyCodeBK != AppUser.KeyCode))// || (AppUser.KeyCode!=0 && AppUser.N10MS_FG))  //AppUser.N10MS_FG	=	1;  //Version	V1.05	: (1)20240719		: Mult Key Issue
    {
      AppUser.KeyCodeBK = AppUser.KeyCode;
      //printf("KEY  NEW: %04X\r\n",AppUser.KeyCode);//Version	V2.05	: (1)20260103		: HID/KB Mode Latency ISSUE   //Version	V1.06	: (1)20240720		: RAW Date Fort App Seni Config 
      
      //Version	V1.03	: (1)20240716		: App Param Config Bug
      if((ConfigMode&USBD_MODE_MAK)==USBD_MODE_KBS)     
      {
        #ifdef  SOFT_CONIFG_KBS
        App_USB_KBS_Report_Normal(AppUser.KeyCode);
        #endif
      }
      else if((ConfigMode&USBD_MODE_MAK)==USBD_MODE_HID)
      {
        #ifdef  SOFT_CONIFG_HID
        App_USB_HID_Report(AppUser.KeyCode);
        #endif
      }
      else if((ConfigMode&USBD_MODE_MAK)==USBD_MODE_IO4)
      {
        //printf("USB Work Mode : IO4");
      }
    
      App_RGB_SetValue(AppUser.KeyCode);
    }
    AppUser.N10MS_FG  = 0;
    AppUser.KeyNewsFG = 0;
  }
	//-----------------------------------------------------------------
}


//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_User_Init(void)
{
  //----------------------------------------------------------
  unsigned char i;
	//----------------------------------------------------------
	memset((uint8_t *)&AppUser,	0,sizeof(AppUser));
  memset((uint8_t *)&AppADC,	0,sizeof(AppADC));
	//----------------------------------------------------------
	App_RGB_Init();
	//----------------------------------------------------------
  //Version	V1.01	: (1)20240617		: App Param Config  
  App_Get_Flash_Cofnig(FLASH_DATA_ADDR_SENSI, AppUser.Sensi, (unsigned short*)Default_Sensi_Tab, MAX_VAL_CHAN);	
  App_Get_Flash_Cofnig(FLASH_DATA_ADDR_COLOR, AppUser.Color, (unsigned short*)Default_Color_Tab, MAX_VAL_CHAN);	
  App_Get_Flash_Cofnig(FLASH_DATA_ADDR_DTICK, AppUser.DTick, (unsigned short*)Default_DTick_Tab, MAX_VAL_CHAN);	
  App_BSP16_LogBuf((unsigned char*)"Sensi RAW",AppUser.Sensi,MAX_VAL_CHAN);
  App_BSP16_LogBuf((unsigned char*)"Color RAW",AppUser.Color,MAX_VAL_CHAN);
  App_BSP16_LogBuf((unsigned char*)"DTick RAW",AppUser.DTick,MAX_VAL_CHAN);
  //----------------------------------------------------------
  AppUser.PwrOnTick = 0;       //Version	V1.15	: (1)20240930		: Power On Sensor Scan
  AppUser.SensiNew  = 0;
  //----------------------------------------------------------
  for(i=0;i<(MAX_VAL_CHAN);i++)
  {
    AppUser.Sensi[i] = AUTO_SENSI;
  }
  //----------------------------------------------------------
}

/*******************************************************************************
* Function Name  : 	
* Description    : 	
* Input          : 
* Output         : 
* Return         : 
* Attention		 	 : 
*******************************************************************************/
void App_User_Loop(void)
{
  //==================================================================
  //Version	V2.05	: (1)20260103		: HID/KB Mode Latency ISSUE
  CHK_ADC_SCAN(&AppADC);
  App_User_Sta_Update();
	//==================================================================
	if(AppUser.T1MS_FG)
	{
		//------------------------------------------------ Button Scan
		App_User_Btn_Scan();
		//------------------------------------------------ Button Press  
		
    //------------------------------------------------ 
		AppUser.T1MS_FG = 0;
    //------------------------------------------------ 
	}
	//================================================================== 10mS
	if(AppUser.T10MS_FG)
	{
    //------------------------------------------------ 
    wdt_counter_reload();
		//------------------------------------------------ 
		
		//------------------------------------------------
    //RGB_DMA_Driver_Start();
		//------------------------------------------------
		AppUser.T10MS_FG = 0;
		//------------------------------------------------
	}
	//================================================================== 100mS
	if(AppUser.T100MS_FG)
	{
		//------------------------------------------------ 

		//------------------------------------------------
		AppUser.T100MS_FG = 0;
		//------------------------------------------------
	}
	//================================================================== 1Second
	if(AppUser.T1Sec_FG)
	{
//		//------------------------------------------------
//    #ifdef  SOFT_CONIFG_HID
//    HidReportBuf[0]  = 0x01;   //USBD_HID_RP_ID
//    HidReportBuf[1] += 0x20;
//    App_USB_HID_SendPacket(HidReportBuf,0);
//    
//    
//    if(HidReportBuf[1] == 0x00)
//    {
//      App_USB_KBS_Report(0x01);
//    }
//    else if(HidReportBuf[1] == 0x20)
//    {
//      App_USB_KBS_Report(0x02);
//    }
//    else if(HidReportBuf[1] == 0x40)
//    {
//      App_USB_KBS_Report(0x04);
//    }
//    else if(HidReportBuf[1] == 0x60)
//    {
//      App_USB_KBS_Report(0x08);
//    }
//    #endif

//    extern unsigned char 	USART_DMA_RxdReg[65];
//    USART_DMA_RxdReg[0] = 0xA5;
//    USART_DMA_RxdReg[1] = 0x5A;
//    USART_DMA_RxdReg[2] = 0x08;
//    USART_DMA_RxdReg[3] = 0x11;
//    USART_DMA_RxdReg[4] = 0x22;
//    USART_DMA_RxdReg[5] = 0x33;
//    USART_DMA_RxdReg[6] = 0x44;
//    USART_DMA_RxdReg[7] = 0x55;
//    USART_DMA_RxdReg[8] = 0x66;
//    USART_DMA_RxdReg[9] = 0x77;
//    USART_DMA_RxdReg[10]= 0x88;

//    
//    App_UART_Send_Buff(UART5, &AppUart5, USART_DMA_RxdReg,11);
//    static unsigned char Flag;
//    IO_OPT_LED1_OUTPUT();
//    if(Flag==0)
//    {
//      Flag = 1;IO_OPT_LED1_ON();
//    }
//    else
//    {
//      Flag = 0;IO_OPT_LED1_OFF();
//    }
    
//    IO_OPT_LED1_INPUT();
//    
//    if(IO_LED1_READ()==0)
//    {
//      printf("PD2 Low \r\n");
//    }
    
    //----------------------------------------------------------
    CHK_PWR_SCAN(&AppADC);
    //----------------------------------------------------------
    if(AppUser.PwrOnTick>0)     //Version	V1.15	: (1)20240930		: Power On Sensor Scan
    {
      AppUser.PwrOnTick--;
      if(AppUser.PwrOnTick==0)
      {
        if(AppUser.SensiNew)
        {
          //App_Set_Flash_Cofnig(FLASH_DATA_ADDR_SENSI, AppUser.Sensi, ADC_MAX_CHAN);
        }
      }
    }    
		//------------------------------------------------
		AppUser.T1Sec_FG = 0;
		//------------------------------------------------
	}
	//==================================================================
  App_UART_Update();
  //==================================================================

	//==================================================================
	App_RGB_Update(AppUser.SysTimeTick);
	//==================================================================
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



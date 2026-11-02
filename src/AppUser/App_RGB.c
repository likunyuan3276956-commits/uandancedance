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
#define 	RGB_VAL     128   

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

AppRGB_t					AppRGB;
//Packet_t					AppPacket;




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_HC595_Drive1(unsigned char data)
{
//  //------------------------------------------------------------------
//  unsigned char i;
//  //------------------------------------------------------------------
//  //׼Ѹ˽ߝìҢ؅ս˽ߝIOࠚʏ
//  for(i = 0;i < 8;i++)
//  {
//    SW_595_CLK_LOW();
//    if(data >= 0x80)
//    {
//      SW_595_DAT_HIGH();  //خٟλΪ1    
//    }
//    else
//    {
//      SW_595_DAT_LOW();   //خٟλΪ0   
//    }
//    SW_595_CLK_HIGH();    //ʏʽҘì˽ߝһλһλքӆɫӆλ݄զǷ
//    data <<= 1;
//  }
//  //------------------------------------------------------------------
//  //ʏʽҘìӆλ݄զǷք˽ߝӆսզԢ݄զǷ
//  SW_595_RCK_LOW();
//  SW_595_RCK_HIGH();
//  //------------------------------------------------------------------
//  //-֍ìٟ͡߹ىɅ
//  //SW_595_DAT_LOW(); 
//  //SW_595_CLK_LOW();
//  SW_595_RCK_LOW();
//  //------------------------------------------------------------------
}

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_HC595_Drive2(unsigned char dataH, unsigned char dataL)
{
//  //------------------------------------------------------------------
//  unsigned char i;
//  unsigned char temp = 0x00;
//  //------------------------------------------------------------------dataH prepare  
//  temp = dataH;
//  for(i = 0;i < 8;i++)
//  {
//    SW_595_CLK_LOW();  
//    if((temp & 0x80) == 0x80)
//    {
//      SW_595_DAT_HIGH();  //خٟλΪ1    
//    }
//    else
//    {
//      SW_595_DAT_LOW();   //خٟλΪ0   
//    }
//    SW_595_CLK_HIGH();    //ʏʽҘì˽ߝһλһλքӆɫӆλ݄զǷ  
//    //SW_595_RCK_LOW();       
//    //SW_595_RCK_HIGH(); 
//    temp <<= 1;
//  }
//  //------------------------------------------------------------------dataL prepare 
//  temp = dataL;
//  for(i = 0;i < 8;i++)
//  {
//    SW_595_CLK_LOW();    
//    if((temp & 0x80) == 0x80)
//    {
//      SW_595_DAT_HIGH();  //خٟλΪ1    
//    }
//    else
//    {
//      SW_595_DAT_LOW();   //خٟλΪ0   
//    }
//    SW_595_CLK_HIGH();
//    //SW_595_RCK_LOW(); //ʏʽҘì˽ߝһλһλքӆɫӆλ݄զǷ
//    //SW_595_RCK_HIGH();
//    temp <<= 1;
//  }
//  //------------------------------------------------------------------data:shift --> ROM 
//  //ʏʽҘìӆλ݄զǷք˽ߝӆսզԢ݄զǷ
//  SW_595_RCK_LOW();    
//  SW_595_RCK_HIGH();
//  //-֍ìٟ͡߹ىɅ
//  //SW_595_DAT_LOW(); 
//  //SW_595_CLK_LOW();
//  SW_595_RCK_LOW(); 
//  //------------------------------------------------------------------  
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
void	Send_RGB_1_Data (unsigned char *r,unsigned char *g,unsigned char *b)	
{
  unsigned char  i;
	//-------------------------------------------------- 
	if(AppRGB.PwrFlag)		
	{
    for(i=0;i<MAX_RGB_NUMBER*3;i++) //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
    {
      AppRGB.RGB_BUF1[i*3+0]= r[0]; //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
      AppRGB.RGB_BUF1[i*3+1]= g[0]; //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
      AppRGB.RGB_BUF1[i*3+2]= b[0]; //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
    }
		Chip2813_C1_Send_Data(AppRGB.RGB_BUF1,MAX_RGB_NUMBER*3*3);//Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
	}
	//-------------------------------------------------- 	
}  
/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
//void Send_RGB_2_Data(unsigned char *r,unsigned char *g,unsigned char *b)
//{
//  unsigned char  i;
//	//----------------------------------------------------------
//	if(AppRGB.PwrFlag)		
//	{
//    for(i=0;i<MAX_RGB_NUMBER;i++)
//    {
//      AppRGB.RGB_BUF2[i*3+0]= r[i];
//      AppRGB.RGB_BUF2[i*3+1]= g[i];
//      AppRGB.RGB_BUF2[i*3+2]= b[i];
//    }
//    Chip2813_C2_Send_Data(AppRGB.RGB_BUF2,MAX_RGB_NUMBER*3);
//  }
//	//----------------------------------------------------------
//}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
//void App_RGB_Brightness_Update(void)	
//{
//  //----------------------------------------------------------
//  if(AppRGB.BrightStep==0)      {AppRGB.Brightness = RGB_VAL+35*2;}  //RGB_VAL=64 
//  else if(AppRGB.BrightStep==1) {AppRGB.Brightness = RGB_VAL+35*1;}  //RGB_VAL=56  
//  else if(AppRGB.BrightStep==2) {AppRGB.Brightness = RGB_VAL-35*0;}  //RGB_VAL=48
//  else if(AppRGB.BrightStep==3) {AppRGB.Brightness = RGB_VAL-35*1;}  //RGB_VAL=40
//  else if(AppRGB.BrightStep==4) {AppRGB.Brightness = RGB_VAL-35*2;}  //RGB_VAL=32
//  //----------------------------------------------------------
//  AppRGB.Brightness /= AppRGB.BrightCutf;
//  //----------------------------------------------------------
//}

/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_RGB_CC_PowerUpdate(unsigned int Value)	//Version	V1.10	: (1)20240830		: Brightness For RGB
{
  //----------------------------------------------------------  
  //Version	V2.03	: (1)20251208		: Change Defalut LED Color
//  if(Value>=1300)                   //5V/3A
//  {
    if(AppRGB.BrightCutf!=1)
    {
      AppRGB.BrightCutf = 1;
      AppRGB.Brightness = 0xff;//100;       //Version	V1.16	: (1)20241010		: Brightness For RGB  
      //App_RGB_Brightness_Update();
      printf("CC Value: %d,%d,%d\r\n",Value,AppRGB.BrightCutf,AppRGB.Brightness);  
    }
//  }
//  else if(Value>=700)               //5V/1.5A
//  {
//    if(AppRGB.BrightCutf!=2)
//    {
//      AppRGB.BrightCutf = 2;
//      AppRGB.Brightness = 191;//75;           //Version	V1.16	: (1)20241010		: Brightness For RGB  
//      //App_RGB_Brightness_Update();
//      printf("CC Value: %d,%d,%d\r\n",Value,AppRGB.BrightCutf,AppRGB.Brightness);  
//    }
//  }
//  else                              //5V/0.5&0.9A             
//  {
//    if(AppRGB.BrightCutf!=3)
//    {
//      AppRGB.BrightCutf = 3;
//      AppRGB.Brightness = 63;//25;//50;       //Version	V1.16	: (1)20241010		: Brightness For RGB  
//      //App_RGB_Brightness_Update();
//      printf("CC Value: %d,%d,%d\r\n",Value,AppRGB.BrightCutf,AppRGB.Brightness);   
//    }
//  }
  //----------------------------------------------------------
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

unsigned short  LastRGBCode;
unsigned char		RGB_Buffer[9][BTN_RGB_NUMBER*3];
/*******************************************************************************
* Function Name  : 	
* Description    : 	
* Input          : 
* Output         : 
* Return         : 
* Attention		 	 : 
*******************************************************************************/
void App_RGB_SetValue(unsigned short KeyCode)
{
  //----------------------------------------------------------
  static unsigned char  i;//,c;//,LED_L=0,LED_H=0;
  //unsigned short LED_Val=0;
  static unsigned char  Index=0;
  static unsigned char  Color[MAX_VAL_CHAN];
  static unsigned short LastKeyCode,KeyCodeNew;
  //----------------------------------------------------------
  //printf("App RGB :%04X,%02X,%02X,%02X,%02X\r\n",KeyCode,AppUser.Color[0*4],AppUser.Color[1*4],AppUser.Color[2*4],AppUser.Color[3*4]);  //Version	V1.06	: (1)20240720		: RAW Date Fort App Seni Config 
  //----------------------------------------------------------
  KeyCodeNew  = KeyCode ^ LastKeyCode;
  LastKeyCode = KeyCode;
  //----------------------------------------------------------
  Index = 0;
  for(Index=0;Index<(MAX_VAL_CHAN/4);Index++)
  {
    if( (KeyCode&(1<<Index)) !=0)
    {
      //Version	V1.16	: (1)20241010		: Brightness For RGB  
      if((AppUser.Color[Index*4])==(USER_COLOR_R))     {Color[Index*3+0] = AppRGB.Brightness; Color[Index*3+1] = 0x00;              Color[Index*3+2] = 0x00;}
      else if((AppUser.Color[Index*4])==(USER_COLOR_G)){Color[Index*3+0] = 0x00;              Color[Index*3+1] = AppRGB.Brightness; Color[Index*3+2] = 0x00;}
      else if((AppUser.Color[Index*4])==(USER_COLOR_B)){Color[Index*3+0] = 0x00;              Color[Index*3+1] = 0x00;              Color[Index*3+2] = AppRGB.Brightness;}
      else if((AppUser.Color[Index*4])==(USER_COLOR_Y)){Color[Index*3+0] = AppRGB.Brightness; Color[Index*3+1] = AppRGB.Brightness; Color[Index*3+2] = 0x00;}
      else if((AppUser.Color[Index*4])==(USER_COLOR_P)){Color[Index*3+0] = AppRGB.Brightness; Color[Index*3+1] = 0x00;              Color[Index*3+2] = AppRGB.Brightness;}
      else if((AppUser.Color[Index*4])==(USER_COLOR_C)){Color[Index*3+0] = 0x00;              Color[Index*3+1] = AppRGB.Brightness; Color[Index*3+2] = AppRGB.Brightness;}
      else if((AppUser.Color[Index*4])==(USER_COLOR_W)){Color[Index*3+0] = AppRGB.Brightness; Color[Index*3+1] = AppRGB.Brightness; Color[Index*3+2] = AppRGB.Brightness;}
    }
    else
    {
      Color[Index*3+0] = 0x00; Color[Index*3+1] = 0x00; Color[Index*3+2] = 0x00;
    }
    
    if( (KeyCodeNew&(1<<Index)) !=0)
    {
      //Version	V2.04	: (1)20251209		: HID Mode ISSUE
      //printf("App RGB :%d :",Index); 
      for(i=0;i<BTN_RGB_NUMBER;i++)
      {
        RGB_Buffer[Index][i*3+0] = (Color[Index*3+1]); //R  //Version	V2.06	: (1)20260112		: RGB Issue //Version	V1.16	: (1)20241010		: Brightness For RGB  //Version	V1.10	: (1)20240830		: Brightness For RGB
        RGB_Buffer[Index][i*3+1] = (Color[Index*3+0]); //G
        RGB_Buffer[Index][i*3+2] = (Color[Index*3+2]); //B
        //printf("%02X,%02X,%02X ",RGB_Buffer[Index][i*3+0],RGB_Buffer[Index][i*3+1],RGB_Buffer[Index][i*3+2]); 
      }
      //printf("\r\n"); 
      
      LastRGBCode |= (1<<Index);

      if(Index==0)     {Chip2813_BTN_1_Send_Data(RGB_Buffer[0],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
      else if(Index==1){Chip2813_BTN_2_Send_Data(RGB_Buffer[1],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
      else if(Index==2){Chip2813_BTN_3_Send_Data(RGB_Buffer[2],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
      else if(Index==3){Chip2813_BTN_4_Send_Data(RGB_Buffer[3],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
      else if(Index==4){Chip2813_BTN_5_Send_Data(RGB_Buffer[4],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
//      else if(Index==5){Chip2813_BTN_6_Send_Data(RGB_Buffer[5],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
//      else if(Index==6){Chip2813_BTN_7_Send_Data(RGB_Buffer[6],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
//      else if(Index==7){Chip2813_BTN_8_Send_Data(RGB_Buffer[7],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(2);}
//      else if(Index==8){Chip2813_BTN_9_Send_Data(RGB_Buffer[8],BTN_RGB_NUMBER*3);}//App_BSP_Delay_MS(1);}
    }
    
  }
  
//  Chip2813_BTN_1_Send_Data(RGB_Buffer[0],BTN_RGB_NUMBER*3);
//  Chip2813_BTN_2_Send_Data(RGB_Buffer[1],BTN_RGB_NUMBER*3);
//  Chip2813_BTN_3_Send_Data(RGB_Buffer[2],BTN_RGB_NUMBER*3);
//  
//  Chip2813_BTN_4_Send_Data(RGB_Buffer[3],BTN_RGB_NUMBER*3);
//  Chip2813_BTN_5_Send_Data(RGB_Buffer[4],BTN_RGB_NUMBER*3);
//  Chip2813_BTN_6_Send_Data(RGB_Buffer[5],BTN_RGB_NUMBER*3);
//  
//  Chip2813_BTN_7_Send_Data(RGB_Buffer[6],BTN_RGB_NUMBER*3);
//  Chip2813_BTN_8_Send_Data(RGB_Buffer[7],BTN_RGB_NUMBER*3);
//  Chip2813_BTN_9_Send_Data(RGB_Buffer[8],BTN_RGB_NUMBER*3);
  
//  //----------------------------------------------------------
//  Index = 0;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_1[i*3+0] = (Color[Index*3+1]); //R //Version	V1.16	: (1)20241010		: Brightness For RGB  //Version	V1.10	: (1)20240830		: Brightness For RGB
//    AppRGB.RGB_BTN_1[i*3+1] = (Color[Index*3+0]); //G
//    AppRGB.RGB_BTN_1[i*3+2] = (Color[Index*3+2]); //B
//  }
//  Chip2813_BTN_1_Send_Data(AppRGB.RGB_BTN_1,BTN_RGB_NUMBER*3);
//  //----------------------------------------------------------
//  Index = 1;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_2[i*3+0] = (Color[Index*3+1]); //Version	V1.16	: (1)20241010		: Brightness For RGB  //Version	V1.10	: (1)20240830		: Brightness For RGB
//    AppRGB.RGB_BTN_2[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_2[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_2_Send_Data(AppRGB.RGB_BTN_2,BTN_RGB_NUMBER*3);  
//  //----------------------------------------------------------
//  Index = 2;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_3[i*3+0] = (Color[Index*3+1]); //Version	V1.16	: (1)20241010		: Brightness For RGB  //Version	V1.10	: (1)20240830		: Brightness For RGB
//    AppRGB.RGB_BTN_3[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_3[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_3_Send_Data(AppRGB.RGB_BTN_3,BTN_RGB_NUMBER*3);    
//  //----------------------------------------------------------
//  Index = 3;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_4[i*3+0] = (Color[Index*3+1]); //Version	V1.16	: (1)20241010		: Brightness For RGB  //Version	V1.10	: (1)20240830		: Brightness For RGB
//    AppRGB.RGB_BTN_4[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_4[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_4_Send_Data(AppRGB.RGB_BTN_4,BTN_RGB_NUMBER*3);  
//  //----------------------------------------------------------
//  Index = 4;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_5[i*3+0] = (Color[Index*3+1]); 
//    AppRGB.RGB_BTN_5[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_5[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_5_Send_Data(AppRGB.RGB_BTN_5,BTN_RGB_NUMBER*3);  
//  //----------------------------------------------------------
//  Index = 5;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_6[i*3+0] = (Color[Index*3+1]); 
//    AppRGB.RGB_BTN_6[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_6[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_6_Send_Data(AppRGB.RGB_BTN_6,BTN_RGB_NUMBER*3);
//  //----------------------------------------------------------
//  Index = 6;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_7[i*3+0] = (Color[Index*3+1]); 
//    AppRGB.RGB_BTN_7[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_7[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_7_Send_Data(AppRGB.RGB_BTN_7,BTN_RGB_NUMBER*3);
//  //----------------------------------------------------------
//  Index = 7;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_8[i*3+0] = (Color[Index*3+1]); 
//    AppRGB.RGB_BTN_8[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_8[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_8_Send_Data(AppRGB.RGB_BTN_8,BTN_RGB_NUMBER*3);
//  //----------------------------------------------------------
//  Index = 8;
//  for(i=0;i<BTN_RGB_NUMBER;i++)
//  {
//    AppRGB.RGB_BTN_9[i*3+0] = (Color[Index*3+1]); 
//    AppRGB.RGB_BTN_9[i*3+1] = (Color[Index*3+0]);
//    AppRGB.RGB_BTN_9[i*3+2] = (Color[Index*3+2]);
//  }
//  Chip2813_BTN_9_Send_Data(AppRGB.RGB_BTN_9,BTN_RGB_NUMBER*3);
//  //----------------------------------------------------------
}

/*******************************************************************************
* Function Name  : 	
* Description    : 	
* Input          : 
* Output         : 
* Return         : 
* Attention		 	 : 
*******************************************************************************/
#define MAX_COLOR_STEP			19
unsigned char const RGB_TAB_R[MAX_COLOR_STEP]={255,255,255,255,  170, 85,  0,    0,  0,  0,    0,  0,  0,  42,  85,170,255,   255,255};
unsigned char const RGB_TAB_G[MAX_COLOR_STEP]={  0, 85,170,255,  255,255,255,  255,255,255,  170, 85, 43,   0,   0,  0,  0,     0,  0};
unsigned char const RGB_TAB_B[MAX_COLOR_STEP]={  0,  0,  0,  0,    0,  0,  0,   85,170,255,  255,255,255, 255,  255,255,255,  170, 85};
void App_RGB_AutoSwitch(unsigned char Mode)
{
  //----------------------------------------------------------
  unsigned char i,NewRGB=0; 
  //----------------------------------------------------------
  switch(Mode)
  {
    case  0:  
    {
      //-------------------------------------------------- 
      for(i=0;i<MAX_RGB_NUMBER;i++)
      {
        if(AppRGB.NextR[i] > AppRGB.Col_R[i])			{ AppRGB.Col_R[i]++;	NewRGB = 1; }
        else if(AppRGB.NextR[i] < AppRGB.Col_R[i]){ AppRGB.Col_R[i]--;  NewRGB = 1; }
        
        if(AppRGB.NextG[i] > AppRGB.Col_G[i])			{ AppRGB.Col_G[i]++;	NewRGB = 1; }
        else if(AppRGB.NextG[i] < AppRGB.Col_G[i]){ AppRGB.Col_G[i]--;  NewRGB = 1; }
          
        if(AppRGB.NextB[i] > AppRGB.Col_B[i])			{ AppRGB.Col_B[i]++;	NewRGB = 1; }
        else if(AppRGB.NextB[i] < AppRGB.Col_B[i]){ AppRGB.Col_B[i]--;  NewRGB = 1; }
      }	
      //-------------------------------------------------- 
      if(NewRGB!=0)
      {
        //printf("App RGB :%04X,%02X-%02X-%02X\r\n",AppRGB.Step,AppRGB.Col_R[0],AppRGB.Col_G[0],AppRGB.Col_B[0]);
        Send_RGB_1_Data(AppRGB.Col_R,AppRGB.Col_G,AppRGB.Col_B);
      }
      //-------------------------------------------------- 
      else
      {
        AppRGB.Step++;if(AppRGB.Step>=MAX_COLOR_STEP)AppRGB.Step=0;
        for(i=0;i<MAX_RGB_NUMBER;i++)
        {
          AppRGB.NextR[i] = (RGB_TAB_R[AppRGB.Step]);//*AppRGB.Brightness)/100; //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)//Version	V1.10	: (1)20240830		: Brightness For RGB
          AppRGB.NextG[i] = (RGB_TAB_G[AppRGB.Step]);//*AppRGB.Brightness)/100; //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
          AppRGB.NextB[i] = (RGB_TAB_B[AppRGB.Step]);//*AppRGB.Brightness)/100; //Version	V2.01	: (1)20250920		: Support New 9KEY PCBA (V2.0-20250804)
        }
      }
      //--------------------------------------------------
      break;
    }
    default:  break;
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
void App_RGB_Update(unsigned int Tick)
{
	//----------------------------------------------------------
	if(AppRGB.RGBTick!=Tick)
	{
		//--------------------------------------------------------
		AppRGB.RGBTick = Tick;
		//--------------------------------------------------------
		if(AppRGB.PwrTick>0)
		{
			AppRGB.PwrTick--;
      if(AppRGB.PwrTick==0)
      {
        AppRGB.PwrFlag  = 1;
        printf("App RGB PwrFlag:%04X,%04X\r\n",AppUser.Value,AppRGB.Mode);
      }
		}
		//--------------------------------------------------------
		else //if(AppUser.Value & KEY_CODE_11)  //IO_LED_PWR_READ
		{
			AppRGB.Speed++;
			if(AppRGB.Speed>=50)//(10*100/AppRGB.Brightness))  //Version	V1.10	: (1)20240830		: Brightness For RGB
			{
				AppRGB.Speed = 0;
				App_RGB_AutoSwitch(AppRGB.Mode);
			}
		}
    //--------------------------------------------------------
//    if((LastRGBCode&0x0007)!=0)
//    {
//      if((LastRGBCode&0x0001)!=0){Chip2813_BTN_1_Send_Data(RGB_Buffer[0],BTN_RGB_NUMBER*3);LastRGBCode &= 0xfffe;}
//      if((LastRGBCode&0x0002)!=0){Chip2813_BTN_2_Send_Data(RGB_Buffer[1],BTN_RGB_NUMBER*3);LastRGBCode &= 0xfffd;}
//      if((LastRGBCode&0x0004)!=0){Chip2813_BTN_3_Send_Data(RGB_Buffer[2],BTN_RGB_NUMBER*3);LastRGBCode &= 0xfffb;}
//    }
//    else if((LastRGBCode&0x00038)!=0)
//    {
//      if((LastRGBCode&0x0008)!=0){Chip2813_BTN_4_Send_Data(RGB_Buffer[3],BTN_RGB_NUMBER*3);LastRGBCode &= 0xfff7;}
//      if((LastRGBCode&0x0010)!=0){Chip2813_BTN_5_Send_Data(RGB_Buffer[4],BTN_RGB_NUMBER*3);LastRGBCode &= 0xffef;}
//      if((LastRGBCode&0x0020)!=0){Chip2813_BTN_6_Send_Data(RGB_Buffer[5],BTN_RGB_NUMBER*3);LastRGBCode &= 0xffdf;}
//    }
//    else if((LastRGBCode&0x01C0)!=0)
//    {
//      if((LastRGBCode&0x0040)!=0){Chip2813_BTN_7_Send_Data(RGB_Buffer[6],BTN_RGB_NUMBER*3);LastRGBCode &= 0xffbf;}
//      if((LastRGBCode&0x0080)!=0){Chip2813_BTN_8_Send_Data(RGB_Buffer[7],BTN_RGB_NUMBER*3);LastRGBCode &= 0xff7f;}
//      if((LastRGBCode&0x0100)!=0){Chip2813_BTN_9_Send_Data(RGB_Buffer[8],BTN_RGB_NUMBER*3);LastRGBCode &= 0xfeff;}
//    }
    //--------------------------------------------------------
	}
	//----------------------------------------------------------
}


/******************************************************************************************
Name		:  
Input   :  
Output  :  
describe: 
******************************************************************************************/
void App_RGB_Init(void)
{
	//----------------------------------------------------------
	memset((uint8_t *)&AppRGB,	0,sizeof(AppRGB));
//  memset((uint8_t *)&AppPacket,	0,sizeof(AppPacket));
	//----------------------------------------------------------
	AppRGB.PwrTick  = 1000;		//
	//----------------------------------------------------------
  AppRGB.PwrFlag  = 0;
	AppRGB.Step 		= 0;		//
	AppRGB.Mode 		= 0;		//
//	AppRGB.Btn_Mode	= 0;		//
//  
//  AppRGB.BrightStep = 2;
//  AppRGB.Brightness = RGB_VAL;  //RGB_VAL=48
//  AppRGB.BrightCutf = 1;
  //----------------------------------------------------------
}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



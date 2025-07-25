#include "moto.h"
#include "PWM.h"
/**************************************************************************
函数功能：电机的正反转
入口参数：mode   mode=0时为正转  mode=1时反转
返回  值：无
**************************************************************************/


void moto(int mode)
{
	if(mode==1)    //
	{
		PWMB_IN2=10000;PWMB_IN1=0;
	  PWMA_IN2=7200;PWMA_IN1=6500;
	}
	 if(mode==0)   //
	{
		PWMA_IN1=10000;PWMA_IN2=0;
	  PWMB_IN2=10000;PWMB_IN1=0;
	 }
	if(mode==3)    //
	{
		PWMB_IN1=0;PWMB_IN2=0;
	  PWMA_IN2=0;PWMA_IN1=0;
	}
	if(mode==4)
	{
		PWMB_IN2=10000;PWMB_IN1=0;
	  PWMA_IN1=7200;PWMA_IN2=3000;
	}
	if(mode==5)
	{
		PWMB_IN2=10000;PWMB_IN1=0;
	  PWMA_IN1=10000;PWMA_IN2=2000;
	}
}


/***************************************************************************
函数功能：电机的闭环控制
入口参数：电机的编码器值
返回值  ：电机的PWM
***************************************************************************/
int Velocity_A(int encoderA)
{  
     static float velocity,Encoder_Least,Encoder_bias;
	  static float Encoder_Integral;
   //================速度PI控制器=====================//	
		Encoder_Least =200-encoderA;                    //获取最新速度偏差=目标速度-测量速度
		Encoder_bias *= 0.84;		                                          //一阶低通滤波器       
		Encoder_bias += Encoder_Least*0.16;	                              //一阶低通滤波器，减缓速度变化 
		Encoder_Integral +=Encoder_bias;                                  //积分出位移 积分时间：10ms
		if(Encoder_Integral>380000)  	Encoder_Integral=380000;             //积分限幅
		if(Encoder_Integral<-380000)	  Encoder_Integral=-380000;            //积分限幅	
		velocity=Encoder_bias*20+Encoder_Integral*0.5;	//速度控制
	    return velocity;
}


int Velocity_B(int encoderB)
{  
    static float velocity,Encoder_Least,Encoder_bias;
	  static float Encoder_Integral;
   //================速度PI控制器=====================//	
		Encoder_Least =200-encoderB;                    //获取最新速度偏差=目标速度-测量速度 
		Encoder_bias *= 0.84;		                                          //一阶低通滤波器       
		Encoder_bias += Encoder_Least*0.16;	                              //一阶低通滤波器，减缓速度变化 
		Encoder_Integral +=Encoder_bias;                                  //积分出位移 积分时间：10ms
		if(Encoder_Integral>380000)  	Encoder_Integral=380000;             //积分限幅
		if(Encoder_Integral<-380000)	  Encoder_Integral=-380000;            //积分限幅	
		velocity=Encoder_bias*20+Encoder_Integral*0.5;	//速度控制
	    return velocity;
}



#include "moto.h"
#include "PWM.h"
/**************************************************************************
�������ܣ����������ת
��ڲ�����mode   mode=0ʱΪ��ת  mode=1ʱ��ת
����  ֵ����
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
�������ܣ�����ıջ�����
��ڲ���������ı�����ֵ
����ֵ  �������PWM
***************************************************************************/
int Velocity_A(int encoderA)
{  
     static float velocity,Encoder_Least,Encoder_bias;
	  static float Encoder_Integral;
   //================�ٶ�PI������=====================//	
		Encoder_Least =200-encoderA;                    //��ȡ�����ٶ�ƫ��=Ŀ���ٶ�-�����ٶ�
		Encoder_bias *= 0.84;		                                          //һ�׵�ͨ�˲���       
		Encoder_bias += Encoder_Least*0.16;	                              //һ�׵�ͨ�˲����������ٶȱ仯 
		Encoder_Integral +=Encoder_bias;                                  //���ֳ�λ�� ����ʱ�䣺10ms
		if(Encoder_Integral>380000)  	Encoder_Integral=380000;             //�����޷�
		if(Encoder_Integral<-380000)	  Encoder_Integral=-380000;            //�����޷�	
		velocity=Encoder_bias*20+Encoder_Integral*0.5;	//�ٶȿ���
	    return velocity;
}


int Velocity_B(int encoderB)
{  
    static float velocity,Encoder_Least,Encoder_bias;
	  static float Encoder_Integral;
   //================�ٶ�PI������=====================//	
		Encoder_Least =200-encoderB;                    //��ȡ�����ٶ�ƫ��=Ŀ���ٶ�-�����ٶ� 
		Encoder_bias *= 0.84;		                                          //һ�׵�ͨ�˲���       
		Encoder_bias += Encoder_Least*0.16;	                              //һ�׵�ͨ�˲����������ٶȱ仯 
		Encoder_Integral +=Encoder_bias;                                  //���ֳ�λ�� ����ʱ�䣺10ms
		if(Encoder_Integral>380000)  	Encoder_Integral=380000;             //�����޷�
		if(Encoder_Integral<-380000)	  Encoder_Integral=-380000;            //�����޷�	
		velocity=Encoder_bias*20+Encoder_Integral*0.5;	//�ٶȿ���
	    return velocity;
}



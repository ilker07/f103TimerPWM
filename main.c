

#include "stm32f10x.h"                  // Device header
#include "delay.h"




void pin_init(void);

void timer1pwm_init(void);



int main()
	
{
	delay_init();
	pin_init(); 
	
	timer1pwm_init();
	
	//GPIO_SetBits(GPIOA, GPIO_Pin_9);
	
	while(1)
	{
		
		 TIM1->CCR1 = TIM1->CCR1 * 110 / 100;
	
  
		if (TIM1->CCR1 > 35999)
            TIM1->CCR1 = 90;
		
		
		delay_ms(50);
			
		
		
	
		
		
	}
	
	
}
void pin_init()
{
   RCC->APB2ENR |=1<<11; //TIMER1 AKTIF.
   RCC->APB2ENR |=1<<3;//B portu aktif.
	 RCC->APB2ENR |=1<<0;//Alternatif fonksiyon enable.
	
	
	
	 GPIOB->CRH=0;
	 GPIOB->CRH =0x00B00000;//Alternatif function push pull.	 
		 
}


 
	

void timer1pwm_init()
{
	
	
	TIM1->CCMR1  |=1<<3; //Output Compare 1 preload enable
	TIM1->CCER   |=1<<2;//Capture/Compare 1 output enable
	
	
	
	TIM1->CCMR1  |=1<<5;    //PWM1
	TIM1->CCMR1  |=1<<6;   //PWM1
	
		
	TIM1->RCR =0;
	TIM1->BDTR |= 0x8000;
	TIM1->CNT = 0;
	
	
	
	
	TIM1->PSC =1;
	TIM1->ARR =35999;
	TIM1->CCR1=900;
	
	
	//TIM1->CR1 |=1<<7;//ARPE Bit.
	TIM1->CR1 |=1<<0; //Counter Bit.
  

}


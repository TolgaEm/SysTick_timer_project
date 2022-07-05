
#include "TM4C123.h"                   

#define GREEN  (1U<<3)

int main(){
	
	SYSCTL->RCGCGPIO |= 0X02;
	GPIOF->DIR |= GREEN;
	GPIOF->DEN |= GREEN;
	
	SysTick->LOAD = 16000000 - 1;
	SysTick->CTRL  = 5;
	
	while(1){
		
		if(SysTick->CTRL & 0x10000){
			GPIOF->DATA ^= GREEN;
		}
		
	}

}

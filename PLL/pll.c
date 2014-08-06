#include <LPC213X.H>

void delay(unsigned int i)
{unsigned int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<1000;n++);
	}}

void pll()

{
	PLLCON=0X01; //enable pll
	PLLCFG=0x35; //configure pll 
	PLLFEED=0X55;
//	delay(100);
	PLLFEED=0XAA;
	while((PLLSTAT & 0X400)==0);
	PLLCON=0X03;
	PLLFEED=0X55;
//	delay(100);
	PLLFEED=0XAA;
}

int main()
{
while(1)
{
	pll();
}	
}

	
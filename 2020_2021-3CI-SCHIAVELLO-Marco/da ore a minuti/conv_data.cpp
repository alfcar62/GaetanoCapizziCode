//marco schiavello 3^CI 1/10/2020
//da secondi ore minuti secondi 
#include <stdio.h>
#include <conio.h>

int main()
{
	int sec,ore,min,sec_ecc;
	printf("inserisci numero secondi totali per avere ora min sec: ");
	scanf("%d",&sec);
	while(sec<0 || sec>1000000000)
	{
		printf("inserisci numero secondi totali per avere ora min sec: ");
		scanf("%d",&sec);	
	}
	/* oppure su puo fare cosi
	if(sec<0)
		sec*=-1;
	if(sec>1000000000)
		sec=1000000000;
	*/
	
		
	ore=sec/3600;
	sec_ecc=sec%3600;
	min=sec_ecc/60;
	sec_ecc=sec_ecc%60;
	printf("ore:%d min:%d sec:%d ",ore,min,sec_ecc);
	getch();
}

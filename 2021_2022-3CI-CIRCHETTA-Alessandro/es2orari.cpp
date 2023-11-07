/*
ALUNNO: Circhetta Alessandro
DATA: 29/09/2021
CONSEGNA: disegnare il flow chart e scrivere il programma C che risolve il seguente problema: dato un tempo espresso in secondi, trasformarlo in ore,minuti e secondi.
*/
#include <stdio.h>
main()
{
	int h,m,s,rh,rm;
	
	printf("inserire secondi: ");
	scanf("%d", &s);
	
	h=s/3600;
	
	rh=s%3600;
	
	m=rh/60;
	
	rm=rh%60;
	
	s=rm;
	
	printf("%d ore \n",h);
	printf("%d minuti \n",m);
	printf("%d secondi \n",s);
	
	return 0;
}

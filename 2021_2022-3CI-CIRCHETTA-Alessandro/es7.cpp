/*
ALLIEVO: Alessandro CIRCHETTA
DATA: 13/10/2021  
CLASSE: 3C INFORMATICA
TESTO: Dato un numero n  letto in input, leggere n numeri e stampare il piu' piccolo.
*/

#include <stdio.h>

	int main()
{
	int num;
	int cont = 0;
	int n;
	int min;
	
	printf ("inserire quantita' di numeri che si vogliono analizzare:");
	scanf ("%d",&num);
	
	do
	 {
		printf ("inserire numero:");
		scanf ("%d",&n);
		
		if (cont==0)
		   min = n;
		
	    cont = cont + 1;
		
		if (min > n)
		  min = n;
	 }
    while (cont<num);
	
	printf ("il numero piu' piccolo tra quelli dati e':");
	printf ("%d", min);	
	
	return 0;
}

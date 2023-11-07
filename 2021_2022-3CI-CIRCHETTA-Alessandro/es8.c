/*
ALLIEVO: Alessandro CIRCHETTA
DATA: 13/10/2021  
CLASSE: 3C INFORMATICA
TESTO: Dato un numero n  letto in input, leggere n numeri e stampare il più piccolo. Effettuare il controllo dell'input in modo che i numeri inseriti siano tutti compresi tra 1 e 10. 
*/

#include <stdio.h>

	int main()
{
	int num;
	int cont = 0;
	int n;
	int min;
	
	
	
	do
	 {
		printf ("inserire quantita' di numeri che si vogliono analizzare:");
		scanf ("%d",&num);
	 } 
	while (num <= 0);
	
	do
	 {
		do
		 {
			printf ("inserire numero:");
			scanf ("%d",&n);
		 } 
		while (n<1||n>10);
		
		
		
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
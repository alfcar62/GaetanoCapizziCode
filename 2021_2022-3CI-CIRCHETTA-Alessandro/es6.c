/*
ALLIEVO: Alessandro CIRCHETTA
DATA: 06/10/2021  
CLASSE: 3C INFORMATICA
TESTO: Disegnare il flow chart e scrivere un programma C che legga in input 2 numeri interi e stampi il più piccolo (usare  l'istruzione do-while).
*/

#include <stdio.h>

int main ()
{
int n, min;
int i = 1;


do
 {
 printf("Inserire %d numero: ", i);
 scanf("%d", &n);

  if (i == 1)
    min = n;
 i = i + 1;
 
 if (min > n)
  	 min = n;
 }	
while (i < 3);

 printf("Il valore minimo e': %d", min);
	return 0;
}
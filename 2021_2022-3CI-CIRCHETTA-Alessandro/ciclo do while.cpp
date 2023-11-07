/*
ALLIEVO: Jacopo BORDONI
DATA:    06/10/2021  
CLASSE:  3C INFORMATICA
TESTO:   Dati in input 4 numeri interi stampare il piu' piccolo (do-while)
*/

#include <stdio.h>

int main ()
{
int n;
int i = 1;
int min;

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
while (i < 5);

 printf("Il valore minimo e': %d", min);
	return 0;
}

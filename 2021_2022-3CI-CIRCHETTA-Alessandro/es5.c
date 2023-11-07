/*
ALLIEVO: Alessandro CIRCHETTA
DATA: 06/10/2021  
CLASSE: 3C INFORMATICA
TESTO: Disegnare il flow chart e scrivere un programma C che legga in input 4 numeri interi e stampi il più piccolo     (usare  le istruzioni condizionali).
*/

#include <stdio.h>

int main ()

{
 int n1, n2, n3, n4, min;

 printf("Inserire 4 numeri: \n");
 scanf("%d", &n1);
 scanf("%d", &n2);
 scanf("%d", &n3);
 scanf("%d", &n4);

 min = n1;

 if (min > n2)
  min = n2;
 if (min > n3)
  min = n3;
 if (min > n4)
  min = n4;

 printf("Il valore piu' piccolo e': %d", min);

 return 0;
}
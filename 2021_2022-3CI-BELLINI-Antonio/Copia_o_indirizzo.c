/*
Autore: Bellini Antonio
Data: 31/01/2022
Classe: 3C INFORMATICA
Programma che scambia 2 parametri prima per copia e poi per indirizzo
*/
/*                                                  //Passaggio parametri per copia
#include <stdio.h>
#include <stdlib.h>

void scambia(int x, int y)
  {
   int c;
   c=x;
   x=y;
   y=c; 
   printf("\nIl valore di x e' %d",x);
   printf("\nIl valore di y e' %d",y); 
  }

int main() 
  {
   int a,
       b;

    printf("Inserisci il valore di a-->");
    scanf("%d",&a);
    printf("Inserisci il valore di b-->");
    scanf("%d",&b);
    printf("\nIl valore di a e' %d",a);
    printf("\nIl valore di b e' %d",b);
    scambia(a,b);
    printf("\nIl valore di a e' %d",a);
    printf("\nIl valore di b e' %d",b);
    
   return 0;
  }*/
//con il passaggio di parametri per copia sostanzialmente il valore di due variabili non viene cambiato. 
//Come si puo vedere eseguendo il progetto, i valori vengono cambiati solo nel void, ma poi quando rientrano nel main
//hanno lo stesso valore di prima


                                                        //Passaggio parametri per indirizzo

#include <stdio.h>
#include <stdlib.h>

void scambia(int *x, int *y)          // *x significa che si inzializza l'indirizzo di x
  {
   int appoggio;
   appoggio=*x;
   *x=*y;
   *y=appoggio; 
   printf("\n\nIl valore di x e' %d",*x);
   printf("\nIl valore di y e' %d",*y); 
  }

int main() 
  {
   int valore1,
       valore2;

    printf("Inserisci il valore del primo valore-->");
    scanf("%d",&valore1);
    printf("Inserisci il valore del secondo valore-->");
    scanf("%d",&valore2);
    printf("\nIl valore del primo valore e' %d",valore1);
    printf("\nIl valore del secondo valore e' %d",valore2);
    scambia(&valore1,&valore2);
    printf("\n\nOra il valore del primo valore e' %d",valore1);
    printf("\nOra il valore del secondo valore e' %d",valore2);
    
   return 0;
  }
//con il passaggio di parametri per indirizzo, invece, il valore delle due variabili viene cambiato. 
//Come si puo vedere eseguendo il progetto, i valori vengono cambiati nel void, e poi quando rientrano nel main
//hanno i valori cambiati.
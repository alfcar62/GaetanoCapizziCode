/*
Autore: Pansini Guglielmo e Circetta Alessandro
Data: 13 OTTOBRE 2021
Consegna: Leggere 2 numeri positivi e calcolarne la divisione con il metodo delle sottrazioni successive. Consegnare flow chart e programma in C
Classe: 3C informatica
*/

#include<stdio.h>


int main()
{
   int n1;
   int n2;


   do 
    {
        printf("inserire numero che si vuole dividere -------> ");
		scanf("%d",&n1);
    } 
   while (n1<1);

   do 
    {
        printf("inserire il numero per cui si vuole dividere -------> ");
		scanf("%d",&n2);
    } 
   while (n2<1);

    int s=n1;
    int i=0;
   do 
    {
        s=s-n2;
        i=i+1;
    }while (s>=n2);
   
   printf("il risultato e' ------> %d", i);
   printf("\nil resto e'  ------> %d", s);
   
   return 0;
}

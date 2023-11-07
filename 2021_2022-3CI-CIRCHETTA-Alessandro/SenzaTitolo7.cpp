#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define MAX 10

int main()
{
int n,ind,cont,risp;
int vet[MAX];
   
system("cls");
printf("1) Carica un vettore \n2) Visualizza un vettore \n3) Cercare un valore all'interno del vettore \n4) Esci\n\n");

printf("\n\n1) Carica un vettore:");
for(ind=0;ind<10;ind++)
    {

printf("\nInserisci il valore nell'indice %d  --->", ind);
scanf("%d",&n);


  while(n<0)
    {
printf("Il numero inserito non e' accettabile\n");
printf("\nInserire n numeri interi --->");
scanf("%d",&n);

}
vet[ind]=n;
  }
 
  do
  {

 do
{
system("cls");
printf("\n2) Visualizza un vettore \n3) Cercare un valore all'interno del vettore \n4) Esci\n\n");
printf("Selezionare modalita' : ");
scanf("%d", &risp);
}while (risp < 2 || risp > 4);
   
   
switch(risp)
   {
    case 2:
      {
     

//stampa array
system ("cls");
 for(ind=0;ind<10;ind++)
  {
   printf("\nIl valore nell'indice %d: %d", ind, vet[ind]);
  }
 
 }
   
 
   
   
   
   }
   }while(risp==4);
   




}


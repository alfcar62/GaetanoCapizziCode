/*
Autore: Bellini Antonio
Data: 15/12/2021
Classe: 3C INFORMATICA
Programma che pensa un numero compreso tra 1 e 10.000 e l'utente deve indovianrlo entro 10 tentativi.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);}

int main() 
	{
	 int i,x=3,a=1,numero,cont;
	 		  
	 		  system("cls");
	 		  srand(time(0));
	 		  cont=rand()%1000;
	 		  
	 		  for(i=0;i<10;i++)
			   {
			   	GotoXY(40,x);
			   	printf("%d)Quale numero ho pensato secondo te? -->",a);
			   	a++; 
			   	scanf("%d",&numero);
			   	x++;
			   	if(numero!=cont)
			   	  {
			   	  	if(numero>cont)
			   	  	    {
			   	  		 GotoXY(40,x);
			   	  	 	 printf("\nIl numero inserito ha un valore troppo alto\n\n");
			   	  		 x+=2;
			   	  		}
			   	  	if(numero<cont)
			   	  		{
			   	  		 GotoXY(40,x);
			   	  		 printf("\nIl numero inserito ha un valore troppo basso\n\n");
			   	  		 x+=2;
			   	  		}
				  }
			   	if(numero==cont)
			   		{
			   		 GotoXY(50,x);
			   		 printf("Bravo! Hai indovinato!");
			   		 break;
			   		}
			   }
			   if(i==10)
			     {
			      GotoXY(40,x);	
			      printf("Il numero che avevo pensato era %d",cont);
				 }
					
	 
	
	 
	 return 0;
	}

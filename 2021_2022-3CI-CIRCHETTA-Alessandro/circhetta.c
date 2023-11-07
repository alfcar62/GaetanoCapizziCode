/**********************
ALUNNO: Alessandro CIRCHETTA
DATA:   17/11/2021   
CLASSE: 3C INFORMATICA 
TESTO:  Verifica Laboratorio di Informatica  
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void  gotoxy(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main ()
{
	int    n = 0,
		   m = 0,
		cont = 0,
		pari = 0,
		risu = 0,
		  n1 = 0,
		  n2 = 0,
		base = 0,
		 esp = 0;
		
	 //   do
	  //  {
			system("cls");
			
	      	gotoxy (35,1);
			printf("VERIFICA DI INFORMATICA LABORATORIO: CIRCHETTA - 3^C - INF 01/12/2021");	//TITOLO
		   	printf("\n1) Esercizio 1\n");
		    printf("2) Esercizio 2\n");
		    printf("3) Esercizio 3\n");
		    printf("4) Esercizio 4\n");
		    printf("5) ESCI\n");
		    printf("\nSCEGLI .");
		    scanf ("%d", &m);
		    
		    system ("cls");
		    
			switch (m)
			{
			 case 1:
					
				gotoxy (35,1);
					printf("CONTATORE DI NUMERI PARI\n");	//TITOLO
				
			   
			    
				do
				{ 
					cont++;
					printf("INSERIRE IL %d NUMERO INTERI:\n", cont);
					scanf("%d", &n);
					
					if(n % 2 == 0)
					pari++;	
					
				}while (cont < 10);
				
				printf("Ecco quanti numeri pari hai inserito: %d ", pari);
				
			break;
			
			 case 2:
			 	
				gotoxy (35,1);
					printf("NUMERI POSITIVI E NEGATIVI\n");	//TITOLO
			 	do
			 	{
			 	printf("INSERIRE IL PRIMO NUMERO: "),
			 	scanf("%d", &n1);
			 	
				if (n1 < 0)
				printf("\nATTENZIONE! VALORE NON CONSIDERABILE! REINSERIRLO!\n");
				
				}while(n1 < 0);
			 	
			 	do
			 	{
			 	printf("INSERIRE IL SECONDO NUMERO NUMERO: "),
			 	scanf("%d", &n2);
			 	
				if (n2 < 0)
				printf("\nATTENZIONE! VALORE NON CONSIDERABILE! REINSERIRLO!\n");
				
				}while(n2 < 0);
		
			 	if(n1>0 & n2>0)
			 		risu = n1 + n2;
			 	else
			 		risu = n1 * n2;
			 		
			 	printf("RISULTATO: %d", risu);
			 	
			break;
			 case 3:

				gotoxy (35,1);
					printf("BASE ED ESPONENTE\n");	//TITOLO
			 	
			 	do
			 	{
			 	printf("INSERIRE LA BASE: "),
			 	scanf("%d", &base);
			 	
				if (base < 0)
				printf("\nATTENZIONE! VALORE NON CONSIDERABILE! REINSERIRLO!\n");
				}while(n1 < 0);	

			 	do
			 	{
			 	printf("INSERIRE ESPONENTE: "),
			 	scanf("%d", &esp);
			 	
				if (esp < 0)
				printf("\nATTENZIONE! VALORE NON CONSIDERABILE! REINSERIRLO!\n");
				}while(esp < 0);

			 	do
			 	{
					esp--;
					risu = base * base;
			 	
				}while(esp > 0);
				
			 	printf("RISULTATO: %d", risu);
					
			}
			
	//	}while(m < 1 || m < 5);
		
	return 0;
}

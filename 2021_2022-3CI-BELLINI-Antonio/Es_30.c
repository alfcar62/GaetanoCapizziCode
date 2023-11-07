/*
Autore: Bellini Antonio 
Data: 25/01/2022
Classe: 3C INFORMATICA
Programma che
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 5

int scelta,
	array[MAX];

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);}

void benvenuto()
	{
	 do
	  { 
	   system("cls");
	   GotoXY(50,1);
	   printf("Benvenuto!");
	   GotoXY(35,3);
	   printf("Cosa vuoi eseguire?");
	   GotoXY(35,5);
	   printf("1) Caricare dei valori all'interno di un'array");
	   GotoXY(35,7);
	   printf("2) Visualizzare i valori presenti in un'array");
	   GotoXY(35,9);
	   printf("3) Ordinamento crescente dei valori presenti in un'array");
	   GotoXY(35,11);
	   printf("4) Ordinamento decrescente dei valori presenti in un'array");
	   GotoXY(35,13);
	   printf("5) Calcolo della media dei valori presenti in un'array");
	   GotoXY(35,15);
	   printf("6) Ricerca con metodo sequenziale dei valori presenti in un'array");
	   GotoXY(35,17);
	   printf("7) Ricerca con metodo dicotomico dei valori presenti in un'array");
	   GotoXY(35,19);
	   printf("8) Esci dal programma");
	   GotoXY(35,22);
	   printf("Scelta-->");
	   scanf("%d",&scelta);
	  }while(scelta<1||scelta>8);	
	}

int main() 
	{
	 int verifica=FALSE,	//Usata per non poter permettere di svolgere altri punti se prima non si è fatto il punto 1 (caricamento dei valori)
	 	 i=0,				//i = indice (array principale)
		 pos=1,				//p = indice valori 
		 x=2;  				//x = posizione di stampa
		  			     		     	 	
	 benvenuto();
	 	 
	 switch(scelta)
	 	{	
		 //Caricamento valori
	  	 case 1:
	 		{
	 		 int contVal;		//contVal = contatore valori (inseriti) usata per contare quanti valori sono già presenti nell'array
			  	
	 		 system("cls");
	 		 for(contVal=0;contVal<MAX;contVal++)
	 		 	{
	 		 	 GotoXY(45,x);
	 		 	 printf("Inserisci il %d valore-->",pos);
	 		 	 scanf("%d",&array[i]);
	 		 	 x++;
	 		 	 pos++;
	 		 	 i++;
				}
		 	 verifica=TRUE;	
			}break;
			
			getch();
			benvenuto();
		 
		 //Visualizzazione valori
		 case 2:
	 		{
	 		 int sVal;			//sVal = stampa valori (dell'array), funziona da contatore per il ciclo for della stampa dei valori 
			  	
	 		 system("cls");
	 		 if(verifica==TRUE)
	 		 	{
	 		 	 pos=1;
	 		 	 x=2;	
				 for(sVal=0;sVal<MAX;sVal++)
	 		 		{
	 		 	   	 GotoXY(45,x);
	 		 	 	 x+=2;
	 		 	  	 printf("Questi sono i valori contenuti nell'array\n");
					 for(sVal=0;sVal<MAX;sVal++)
				 		{
				 		 GotoXY(55,x);
				 	 	 printf("valore %d)-->%d\n",pos,array[i]);
				 	 	 x++;
						 pos++;
						 i++;
						}
					}
				}
				if(verifica==FALSE)
				{
				 system("cls");
				 GotoXY(45,2);
				 printf("Ancora non hai salvato dei valori nell'array");
				}	
			}
			
			getch();
			benvenuto();
			
			break;
		 
		 //Ordinamento crescente
		 case 3:
	 		{
	 		 int j,
			  	 numero[MAX],
				 appoggio; 
				  	
	 		 system("cls");
			 if(verifica==TRUE)
			   {
			 	for(i=0;i<MAX-1;i++)
	 			  	{
	 	 			 for(j=i-1;j<MAX;j++)
		 				{
		 	 			 if(numero[j]<numero[i])
		 	 			 	{
			   			 	 appoggio=numero[j];
			   			 	 numero[j]=numero[i];
			   			 	 numero[i]=appoggio;
							}
		 				} 	
					}			    
				}
			 if(verifica==FALSE)
			 	{
			 	 system("cls");
				 GotoXY(45,2);
				 printf("Ancora non hai salvato dei valori nell'array");	
				}	
			}
			
			 getch();
			 benvenuto();
		 
			 break;
		 
		 //Ordinamento decrescente
		 case 4:
		 	{
		 	 	
			}break;
		
		 //Calcolo della media
		 case 5:
		 	{
			}break;
		
		 //Ricerca di un valore (metodo sequenziale)
		 case 6:
		 	{
			}break;
			
		 //Ricerca di un valore (metodo dicotomico)
		 case 7:
		 	{
			}break;	
		
		 //Uscita dal programma.	
		 case 8:
	 		{
	 		 system("cls");
	 		 GotoXY(50,10);
			 printf("Fine del programma.");   	
			}break;
		}
	 
	 return 0;
	}

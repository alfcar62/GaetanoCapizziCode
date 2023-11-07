//Marco Schiavello 3^Ci 26/11/2020
//menu che offre de servizzi inerenti a codifica ascii con tabella fatta con sotto-programma
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../marcoLib.h"
#define N_COL 19

void menu(int *scelta_)

/*_________Main_________*/
int main()
{
	int scelta,cod;
	char c;
	do
	{
		menu(&scelta);
		switch(scelta)
		{
			case 1:
			{
				system("cls");
				tab_ascii(N_COL);
				break;
			}
			case 2:
			{
				system("cls");
				printf("scegli carattere--> ");
				fflush(stdin);
				scanf(" %c",&c);
				printf("il codice Ascii e' --> %d\n",c);
				getch();
				break;
			}
			case 3:
			{
				system("cls");
				do
				{
					printf("scegli codice Ascii--> ");
					scanf("%d",&cod);
				}
				while(cod<0||cod>255);
				printf("il caratte ascii e' --> %c\n",cod);
				getch();
				break;
			}
			case 4:
			{
				system("cls");
				printf("scegli minuscola --> ");
				fflush(stdin);
				scanf(" %c",&c);
				if(c>96&&c<123)
					printf("il carattere maiuscolo e'--> %c\n",c-32);//	printf("il carattere maiuscolo e'--> %c\n",toupper(c));
				else
					printf("il carattere maiuscolo e'--> %c\n",c);
				getch();
				break;
			}
		}
	}
	while(scelta!=5);
}

/**
*   fa visualizzare un menu dove l'utente sceglie cosa vuole fare
*   params:
*       @param int * scelta_ : output : puntatore che punterà alla variabile dove sarà conservata la scelta del utente
*       @return void
*/
void menu(int *scelta_)
{
	do
	{
		system("cls");
		printf("1) tabella codici Ascii\n\n");
		printf("2) codifica ascii di un carattere\n\n");
		printf("3) carattere corrispondente ad un codice Ascii\n\n");
		printf("4) trasforma una lettera minuscola in maiscula\n\n");
		printf("5) esci\n\n");
		printf("scegli --> ");
		scanf("%d",scelta_);
	}
	while((*scelta_)<1||(*scelta_)>5);
}


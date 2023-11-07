//marco Schiavello 3^CI 11/12/2020
/*
	fare un menuche
	-opzione di menu 1: stampa su video i primi n numeri primi, con n inserito da tastiera.
	-opzione di menu 2: stampa su video   i numeri di AMSTRONG (A) tra 1 e 5000
	-opione 3 esca
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../marcoLib.h"

int menu();
void n_primi(int n);
void n_arm();

/*_____________Main____________*/
int main()
{
	int n,scelta;
	do
	{
		system("cls");
		singlDig(1233234242);
		scelta = menu(); //chiamata funzione
		switch(scelta)
		{
			case 1:
			{
				system("cls");
				printf("inserisci numero di fine range: ");
				scanf("%d",&n);
				n_primi(n);//chiamata sotto programma/ procedura
				getch();
				break;
			}
			case 2:
			{
				system("cls");
				n_arm();//chiamata sotto programma/ procedura
				getch();
				break;
			}
		}
	}
	while(scelta!=3);
}

/**
*   fa visualizzare un menu dove l'utente sceglie cosa vuole fare
*   params:
*       @return int numero della voce scelta dal menu
*/
int menu()
{
	int scelta;
	do
	{
		printf("Menu\n");
		printf("1) numeri primi fino a n a scelta\n");
		printf("2) stapa i numeri di AMSTRONG tra 1 e 5000\n");
		printf("3) esci\n\n");
		printf("scegli: ");
		scanf("%d",&scelta);
	}
	while(scelta<1||scelta>3);
	return scelta;
}

/**
*   stampa tutti i numeri primi nel arco 1 - n dove n e fornito dal utente
*   params:
*       @param int n : input :  fino a che numero si vuole stamapre numeri primi
*       @return void
*/
void n_primi(int n)
{
	bool prim;
	for(int i=2;n!=0;i++)//passa tutti i numeri
	{
		prim=true;
		for(int j=2;j<=i/2;j++)// per ogni numero divide da 2 a il numero i
			if(i%j==0)//se ce un divisore in questo arco di numeri mette la flag a false per dire che non e un numero primo
				prim=false;
		if(prim==true)
		{
			printf("%d\n",i);
			n--;
		}
	}
}

/**
*   stampa tutti i numeri di AMSTRONG da 1 a 5000
*   params:
*       @return void
*/
void n_arm()
{
	int n,n_arm=0;
	int *digit;
	for(n=1;n<=5000;n++)
	{
		n_arm=0;
		/*-------------------divisioni in singoli numeri-------------------------
		digit[3]=n/1000;
		digit[2]=(n-(digit[3]*1000))/100;
		digit[1]=(n-((digit[2]*100)+(digit[3]*1000)))/10;
		digit[0]=(n-((digit[2]*100)+(digit[1]*10)+(digit[3]*1000)))/1;
		*/
		digit=singlDig(n);
		//-----------------------------------------------------------------------
		for(int i=0;digit[i]!=-1;i++)//scorre per ogni numero e fa la somma di ogni cubo
		{
			n_arm+=pow(digit[i],3);

		}
		if(n_arm==n)// se la somma combacia con il numero stampa
			printf("%d\n",n);
		free(digit);
	}

}

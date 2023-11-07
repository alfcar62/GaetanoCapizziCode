//marco schiavello 3^CI 18/12/2020
/*
	dopo aver ricevuto il numero di libri che il cliente viole comperar, acquisisce altrettanti valori, cio� gli importi di tutti i libri,
	che sommati forniranno l�importo totale della spesa.
	Su questo totale, per via della campagna promozionale, � applicato uno sconto da calcolare e da detrarre, cos� formato:
	fino a 50,00 euro lo sconto � del 5%, da 50,01 a 150,00 euro lo sconto � del 10%, oltre lo sconto � del 15%.
	L�algoritmo visualizza l�importo totale della spesa, il valore dello sconto che viene applicato, e l�importo di spesa finale effettivamente pagato,
	tutti espressi in euro.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../marcoLib.h"

float getSconto(float tot);
void setNumLib(int * n_lib);
void setCostLib(float * tot,int n_lib);
void scontrino(float tot);

/*__________Main_________*/
int main()
{
	int n_lib;
	float tot=0;
	setNumLib(&n_lib);
	setCostLib(&tot,n_lib);
	scontrino(tot);
	getch();
}

/**
*   calcola lo sconto dato un totale
*   params:
*       @param float tot : input : totale senza sconto
*       @return float totale con sconto
*/
float getSconto(float tot)
{
	if(tot<50.01)
		tot =(tot * 5)/100;
	else if(tot>50&&tot<150)
		tot = (tot * 10)/100;
	else
		tot = (tot * 15)/100;
	return tot;
}

/**
*   chiede il numero da comprati
*   params:
*       @param int * n_lib : output : numero di libri
*       @return void
*/
void setNumLib(int * n_lib)
{
	do
	{
		system("cls");
		printf("inserisci numeri libri: ");
		scanf("%d",n_lib);
	}
	while(*n_lib<0||*n_lib>10);
}

/**
*   chiede il costo di ogni libro e fa il totale
*   params:
*       @param int n_lib : input : numero di libri
*       @param float * tot : output : costo libri totale
*       @return void
*/
void setCostLib(float * tot,int n_lib)
{
	float cost_lib;
	for(int i=0;i<n_lib;i++)
	{
		do
		{
			printf("inserisci costo libro %d : ",i+1);
			scanf("%f",&cost_lib);
		}
		while(cost_lib<0||cost_lib>200);
		*tot+=cost_lib;
	}
}

/**
*   stampa lo scontrino
*   params:
*       @param float tot : input : totale da stampare sullo scontrino
*       @return void
*/
void scontrino(float tot)
{
	printf("il prezzo totale non scontato e': %.2f\n",tot);
	printf("il prezzo totale scontato e': %.2f",tot - getSconto(tot));
}

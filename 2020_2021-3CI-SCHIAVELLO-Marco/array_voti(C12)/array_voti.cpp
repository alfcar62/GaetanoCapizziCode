//Marco Schiavello 3°CI 20/1/2021
/*
	A partire dal file allegato, realizzato in classe, creare un programma che permette di leggere
	da tastiera 10 voti (il cui valore può essere tra 2 a 10) e stamparli a video.
	Provare anche a stampare il valore medio tra tutti i voti inseriti
*/
#include<stdio.h>
#define N_VOTI 10

void leggiVoti(int * voti);
void stampaVoti(int * voti);
float media(int * voti);

/*________Main___________*/
int main()
{
	int caso[5]={1,2,3,4,5};
	int voti[N_VOTI];

	leggiVoti(voti);
	stampaVoti(voti);
	printf("la media di quiesti voti e': %.2f",media(voti));
}

/**
*   prende un array dove mettere i voti e continua a chiederli fino a riempire l'array
*   Params:
*       @param int * voti : output : puntatore che punta all'array dei voti il cui deve essere riempito
*       @return void
*/
void leggiVoti(int * voti)
{
	for(int i = 0;i<N_VOTI;i++)
	{
		do
		{
			printf("mettere elemento %2d dell'array: ",i+1);
			scanf("%d",&voti[i]);
		}
		while(voti[i]<2||voti[i]>10);
	}
}

/**
*   dato un array di voti lo stampa
*   Params:
*       @param int * voti : input : puntatore che punta all'array in cui ci sono i voti
*       @return void
*/
void stampaVoti(int * voti)
{
	for(int i = 0;i<N_VOTI;i++)
		printf("il %2d%c voto e': %d\n",i+1,248,voti[i]);
}

/**
*   dato array un di voti fa lka media tra di essi
*   Params:
*       @param int * voti : input : puntatore che punta all'array in cui ci sono i voti con cui dare la media
*       @return float : la media dei voti
*/
float media(int * voti)
{
	int somma = 0,i;
	for(i = 0;i<N_VOTI;i++)
		somma += voti[i];
	return somma/i;
}

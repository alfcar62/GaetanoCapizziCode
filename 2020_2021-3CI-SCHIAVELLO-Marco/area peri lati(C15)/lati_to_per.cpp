//Marco Schiavello 3^CI 05/02/2021
/*
	Progettare l’algoritmo che dopo aver acquisito 20 numeri interi e positivi nel vettore LATO, ognuno rappresentante il lato di un quadrato,
	provvede a calcolare il perimetro e l’area di ciascuno di essi.
	I valori calcolati devono essere posti in due distinti vettori, PERIMETRO e AREA, ciascuno sempre di 20 elementi.
	Dopo tale calcolo, l’algoritmo visualizzerà in forma tabellare i valori relativi ai 20 quadrati,
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 20
#define MAX_VAL 99
#define MIN_VAL 1
#define N_LATI 4

void caricaLati(int lati[]);
void calcolaPeri(int lati[],int peri[]);
void calcolaAree(int lati[],int aree[]);
void stampaTab(int lati[],int peri[],int aree[]);

/*__________Main___________*/
int main()
{
	int lati[DIM],aree[DIM],peri[DIM];
	caricaLati(lati);
	calcolaPeri(lati,peri);
	calcolaAree(lati,aree);
	stampaTab(lati,peri,aree);
	system("pause");
}



/**
*   carcica i lati dato l'array di lati
*   params:
*       @param int lati[] : output : dove mette i lati chiesti in input
*       @return void
*/
void caricaLati(int lati[])
{
	for(int i = 0;i<DIM;i++)
	{
		do
		{
			printf("mettere lato %2d : ",i+1);
			scanf("%d",&lati[i]);
		}
		while(lati[i]>MAX_VAL||lati[i]<MIN_VAL);
	}

}

/**
*   calcola per ogni lato calcola il suo perimentro con lo stesso contatore
*   params:
*       @param int lati[] : input : lati dati in ingresso per calcolare i loro perimetri
*       @param int peri[] : output : dove vanno a finire i perimetri calcolati
*       @return void
*/
void calcolaPeri(int lati[],int peri[])
{
	for(int i = 0;i<DIM;i++)
		peri[i] = lati[i]*N_LATI;
}

/**
*   calcola le aree dei quadrati con lati immessi come parametro
*   params:
*       @param int lati[] : input : lati dati in ingresso per calcolare le loro aree
*       @param int aree[] : output : dove vanno a finire le aree calcolate
*       @return void
*/
void calcolaAree(int lati[],int aree[])
{
	for(int i = 0;i<DIM;i++)
		aree[i] = lati[i]*lati[i];
}

/**
*   dati tre array contenenti lati peri e aree stampa una tabeli conetnedo i dati salvati negli array
*   params:
*       @param int lati[] : input : dati da stamapre in tabella
*       @param int aree[] : input : dati da stamapre in tabella
*       @param int peri[] : input : dati da stamapre in tabella
*       @return void
*/
void stampaTab(int lati[],int peri[],int aree[])
{
	system("cls");
	printf("o------o------o------o------o\n");
	printf("| quad | lati | peri | aree |\n");
	printf("o------o------o------o------o\n");
	for(int i = 0;i<DIM;i++)
	{
		printf("| %4d | %4d | %4d | %4d |\n",i+1,lati[i],peri[i],aree[i]);
		printf("o------o------o------o------o\n");
	}
}

/*
	Marco Schiavello 3^CI
	Dati due vettori di interi, fondere i due vettori in un terzo vettore
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM1 5
#define DIM2 6


void caricaRand(int vett[],int len);
void swap(int vett[],int a,int b);
void ordina(int vett[],int len);
int pulisci(int vett[],int len);
void merge(int vet[],int vet2[],int ris[]);
void stampaVet(int ris[],int dim);


/*__________Main___________*/
int main()
{
	//fase inizializazione dei dati
	int vet[DIM1],vet2[DIM2],ris[DIM1+DIM2];
	caricaRand(vet,DIM1);
    caricaRand(vet2,DIM2);

	printf("vattore 1\n\n");
	stampaVet(vet,DIM1);

	printf("vattore 2\n\n");
	stampaVet(vet2,DIM2);

	merge(vet,vet2,ris);
    ordina(ris,DIM1+DIM2);

    printf("vattore unito e ordianto ma non pulito\n\n");
    stampaVet(ris,DIM1+DIM2);

    int newLen = pulisci(ris,DIM1+DIM2);
    printf("vattore unito,ordianto e pulito \n\n");
	stampaVet(ris,newLen);
}

/**
*	carica nel vettore numeri random
*   Params:
*       @param int vet[] : output : vettore dove mettere i numeri random
*       @param int len : input : lunghezza array
*       @return void
*/
void caricaRand(int vett[],int len)
{
    srand(time(0));
    for(int i = 0;i<len;i++)
        vett[i] = (rand()%20)+1;
}

/**
*   dato un array prende due valori e li scambia con ausilio di una variabile temporanea
*   Params:
*       @param int vett[] : input/output : array su cui fare lo scambio
*       @param int a : input : primo elemento da scambiare
*       @param int b : input : secondo elemento da scambiare
*       @return void
*/
void swap(int vett[],int a,int b)
{
	int tmp = vett[a];
	vett[a] = vett[b];
	vett[b] = tmp;
}

/**
*	ordina l'array in modo crescente
*   Params:
*       @param int vett[] : input/output : vettore da ordinare
*       @param int len : input : lunghezza array
*       @return void
*/
void ordina(int vett[],int len)
{
	int i,j;
	for(i = 0;i<len-1;i++)
		for(j = i+1;j<len;j++)
			if(vett[i]>vett[j])
				swap(vett,i,j);
}

/**
*    dato un array toglie i doppioni
*    Params:
*       @param int vett[] : input/output : vettore da pulire
*       @param int len : input : lunghezza array
*       @return int : nuova lunghezza dell'array dopo la pulizia
*/
int pulisci(int vett[],int len)
{
    int newLen = 0;
    for(int i = 0;i<len && vett[i] != vett[len-1]; i++)
    {
        int j = i + 1;
        if(vett[i] != vett[j])
            continue;

        while(vett[i] == vett[j] && j != len)
            j++;
        for(int dest = i+1,src = j;src < len;src++,dest++)
            vett[dest] = vett[src];

        newLen++;
    }

    return newLen+2;
}

/**
*   prendendo tre array di cui due di input e l'ultimo di output che sarebbbe anche l'unione dei due di input
*   params:
*       @param int vet[] : input : primo vettore da unire
*       @param int vet2[] : input : secondo vettore da unire
*       @param int ris[] : output : array risultante dall'unione
*       @return void
*/
void merge(int vet[],int vet2[],int ris[])
{
	for(int i = 0;i<(DIM1+DIM2);i++)
	{
		if(i<DIM1)
			ris[i] = vet[i];
		else
			ris[i] = vet2[i-DIM1];
	}
}

/**
*   stampa l'array passato di lunghezza dim
*   params:
*       @param int ris[] : input : vettore risultante da stampare
*       @param int dim : input : lunghezza vettore
*       @return void
*/
void stampaVet(int ris[],int dim)
{
	for(int i = 0;i<dim;i++)
		printf("elemento dell'array in pos %2d e' : %d \n",i,ris[i]);
	printf("\n\n");
}

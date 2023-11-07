/*
	Marco Schiavello 3^CI 11/02/2021

	Scrivere un programma che:
	1) Caricare un vettore di interi (con valori generati in modo random)
	2) Stampare il vettore
	3) Ricerca di un elemento nell'array (primo trovato)
	4) Ricerca di un elemento nell'array (trova tutti)
	Nota: usare la ricerca dicotomica se il vettore è ordinato
	          usare la ricerca sequenziale altrimenti
	5) Ordinamento del vettore in ordine decrescente
	6) Ordinare il vettore in ordine crescente
	7) Uscita da programma
*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include "../marcoLib.h"
#define DIM 5
#define DIM_MERGE1 5
#define DIM_MERGE2 6
#define GRAD 248

void swap(int vett[],int a,int b);
void menu(int *scelta, bool caricato, char ordinato);
int pulisciVet(int vett[],int len);
void mergeVet(int vet[],int vet2[],int ris[]);
int ricercaDico(int vet[],int ele,char ord);
void caricaVetRand(int vet[],int len);
void caricaVet(int vet[]);
int cercaVet(int vet[],int val);
void visVet(int vet[],int len);
void cercaPlusVet(int vet[], int val);
void ordinaVet(int vet[],int len);
void ordinaVetRev(int vet[]);

/*_________Main_________*/
int main()
{
	int vet[DIM], scelta, val;
	bool caricato;
	char ordinato = ' ';

	do
	{
		menu(&scelta,caricato,ordinato);
		switch(scelta)
		{
		  case 1:
		  {
		  	system("cls");
		    caricaVet(vet);
		    caricato = true;
		    getch();
		    break;
		  }
		  case 2:
		  {
		  	system("cls");
		    caricaVetRand(vet,DIM);
		    caricato = true;
		    visVet(vet,DIM);
		    getch();
		    break;
		  }
		  case 3:
		  {
		  	system("cls");
		    visVet(vet,DIM);
		    getch();
		    break;
		  }
		  case 4:
		  {
		    system("cls");
		    printf("metti il valore da cercare : ");
		    scanf("%d",&val);
		    int index = cercaVet(vet,val);
		    if(index == -1)
		    	printf("il valore non e' presente nell'array\n");
			else
		    	printf("il valore e' in posizione : %d",index);
		    getch();
		    break;
		  }
		  case 5:
		  {
		    system("cls");
		    printf("inserisci quale valore voui cercare nel vettore : ");
		    scanf("%d",&val);
		    printf("il numero %d si trova alla posizione : ",val);
		    cercaPlusVet(vet,val);
		    getch();
		    break;
		  }
		  case 6:
		  {
		    system("cls");
		    ordinaVet(vet,DIM);
		    ordinato = 'C';
		    visVet(vet,DIM);
		    getch();
		    break;
		  }
		  case 7:
		  {
		    system("cls");
		    ordinaVetRev(vet);
		    ordinato = 'D';
		    visVet(vet,DIM);
		    getch();
		    break;
		  }
		  case 8:
		  {
		  	system("cls");
		    printf("metti il valore da cercare : ");
		    scanf("%d",&val);
		    int index = ricercaDico(vet,val,ordinato);
		    if(index == -1)
		    	printf("il valore non e' nell'array \n");
		    else
		    	printf("il valore e' in posizione : %d \n",index);
		    getch();
		    break;
		  }
          case 9:
		  {
            system("cls");
            int vet[DIM_MERGE1],vet2[DIM_MERGE2],ris[DIM_MERGE1+DIM_MERGE2];
            caricaVetRand(vet,DIM_MERGE1);
            caricaVetRand(vet2,DIM_MERGE2);

            printf("vattore 1\n\n");
            visVet(vet,DIM_MERGE1);

            printf("\n");
            printf("vattore 2\n\n");
            visVet(vet2,DIM_MERGE2);

            mergeVet(vet,vet2,ris);
            ordinaVet(ris,DIM_MERGE1+DIM_MERGE2);

            printf("\n");
            printf("vattore unito e ordianto ma non pulito\n\n");
            visVet(ris,DIM_MERGE1+DIM_MERGE2);

            printf("\n");
            int newLen = pulisciVet(ris,DIM_MERGE1+DIM_MERGE2);
            printf("vattore unito,ordianto e pulito \n\n");
            visVet(ris,newLen);

            getch();
		  }
		}
	}
	while(scelta != 10);

	return 0;
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
*   dato un array prende due valori e li scambia con ausilio di una variabile temporanea
*   Params:
*       @param int *scelta :  output : puntatore che punta alla variabile dove verra messa la scelta dell'utente
*       @param bool caricato : input : informazione se e caricato o meno
*       @param char ordinato : input : informazione se e ordinato o meno
*       @return void
*/
void menu(int *scelta, bool caricato, char ordinato)
{
  bool err;

  do
  {
    err=false;
    system("cls");
    printf("1) carica il vettore manuale\n");
    printf("2) carica il vettore random\n");
	printf("3) visualizza il vettore\n");
	printf("4) carica la prima occorrenza del valore nel vettore\n");
    printf("5) tutte le occorrenze del valore nel vettore\n");
    printf("6) ordina crescente\n");
    printf("7) ordina decrescente\n");
    printf("8) ricerca dicotomica\n");
    printf("9) unisci due array generati random in uno ordinato e pulito\n");
	printf("10) esci\n");
    printf("scegli l'operazione da eseguire: ");
	scanf("%d",scelta);

    if((*scelta<=8 && *scelta>=3) && caricato==false)
    {
      	err=true;
      	system("cls");
		printf("dato inserito incorretto\ndevi prima caricare il vettore\n");
		getch();
    }
    else if(*scelta == 8 && ordinato==' ')
    {
    	err=true;
      	system("cls");
		printf("il vettore devo essere prima ordinato\n");
		getch();
	}
	else if(*scelta<1||*scelta>10)
    {
      	err=true;
      	system("cls");
		printf("dato inserito incorretto\nla scelta deve essere compresa tra 1 e 9");
		getch();
    }
  }
  while(err==true);
}

/**
*    dato un array toglie i doppioni
*    Params:
*       @param int vett[] : input/output : vettore da pulire
*       @param int len : input : lunghezza array
*       @return int : nuova lunghezza dell'array dopo la pulizia
*/
int pulisciVet(int vett[],int len)
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
*    prendendo tre array di cui due di input e l'ultimo di output che
*    sarebbbe l'unione dei due di input
*    Params:
*       @param int ris[] : output : risultato del merge
*       @param int vet[] : input : vettore da unire
*       @param int vet2[] : input : vettore da unire
*       @return void
*/
void mergeVet(int vet[],int vet2[],int ris[])
{
	for(int i = 0;i<(DIM_MERGE1+DIM_MERGE2);i++)
	{
		if(i<DIM_MERGE1)
			ris[i] = vet[i];
		else
			ris[i] = vet2[i-DIM_MERGE1];
	}
}

/**
*	pratica una ricerca dicotomica prendendo la meta di un range e confrontandolo il calore
*	con il valore da cercare il base alla grandezza del valore alla metà del range esso prendera
*	una parte o l'atra di esso in base alla sua grandezza e all'ordinamento fatto
*   Params:
*       @param int vet[] : input : vettore su cui cercare l'elemento
*       @param int ele : input : elemento da cercare
*       @param char ord : input : indica il tipo di ordinamento
*       @return int : indice dell'array in cui si trova l'elemento voluto
*/
int ricercaDico(int vet[],int ele,char ord)
{
	int min = 0,max = DIM-1,sele = (max + min)/2;

	while(vet[sele] != ele && sele != -1)
	{
		if(min == max)
			sele = -1;
		else
		{
			if(vet[sele]<ele)
			{
				if(ord == 'C')
					min = sele+1;
				else
					max = sele-1;

			}
			else
			{
				if(ord == 'C')
					max = sele-1;
				else
					min = sele+1;
			}
			sele = (max + min)/2;
		}
	}
	return sele;
}

/**
*	carica nel vettore numeri random
*   Params:
*       @param int vet[] : output : vettore dove mettere i numeri random
*       @param int len : input : lunghezza array
*       @return void
*/
void caricaVetRand(int vet[],int len)
{
	system("cls");
	srand(time(0));
  	int i;
	for(i=0;i<len;i++)
		vet[i] = rand()%100;
}

/**
*	carica nel vettore chiedendo all'utente ogni elemento
*   Params:
*       @param int vet[] : output : vettore dove mettere i valori inseriti dall'utente
*       @return void
*/
void caricaVet(int vet[])
{
	system("cls");
  	int i;
	for(i=0;i<DIM;i++)
	{
		printf("inserisci il numero %d : ",i+1);
		scanf("%d",&vet[i]);
	}
}

/**
*	cerca nel vettore la prima occorrenza e ritorna l'indice
*   Params:
*       @param int vet[] : output : vettore in cui cercare
*       @param int val : input : valore da cercare
*       @return int : indice dove si trova l'elemento
*/
int cercaVet(int vet[],int val)
{
	int i;
	for(i = 0;i<DIM;i++)
		if(vet[i] == val)
	  		return i;
	return  -1;
}

/**
*	stampa il vettore
*   Params:
*       @param int vet[] : output : vettore da stampare
*       @param int len : input : lunghezza array
*       @return void
*/
void visVet(int vet[],int len)
{
  int i;
  printf("o-----o-----o\n");
  printf("|index| val |\n");
  printf("o-----o-----o\n");
  for(i = 0;i<len;i++)
  {
  	printf("| %3d | %3d |\n",i,vet[i]);
  	printf("o-----o-----o\n");
  }
}

/**
*	cerca anche dopo la prima occorrenza il valore coluto e ritorna gl'indici
*   Params:
*       @param int vet[] : output : vettore in cui cercare
*       @param int val : input : valore da cercare
*       @return void
*/
void cercaPlusVet(int vet[], int val)
{
  int i,pos= -1;
  for(i=0;i<DIM;i++)
    if(vet[i]==val)
    {
    	pos = i;
    	printf(" %d",pos);
	}

  if(pos == -1)
  {
	system("cls");
	printf("inserisci quale valore voui cercare nel vettore : %d\n",val);
    printf("il numero %d non e' presente nel vettore\n",val);
  }
}

/**
*	ordina l'array in modo crescente
*   Params:
*       @param int vet[] : input/output : vettore da ordinare
*       @param int len : input : lunghezza array
*       @return void
*/
void ordinaVet(int vet[],int len)
{
	int i,j;
	for(i = 0;i<len-1;i++)
		for(j = i+1;j<len;j++)
			if(vet[i]>vet[j])
				swap(vet,i,j);
}

/**
*	ordina l'array in modo decrescente
*   Params:
*       @param int vet[] : input/output : vettore da ordinare
*       @return void
*/
void ordinaVetRev(int vet[])
{
	int i,j;
	for(i = 0;i<DIM-1;i++)
		for(j = i+1;j<DIM;j++)
			if(vet[i]<vet[j])
				swap(vet,i,j);
}

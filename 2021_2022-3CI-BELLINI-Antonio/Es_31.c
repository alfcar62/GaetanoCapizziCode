/************************************************************************************************************
Consegna: esercizio 31
Realizzare un programma in C language che  permetta all'utente di giocare al master mind con il compuer.
Il computer crea un numero random di 4 cifre numeriche (tutte diverse) e l'utente deve indovinare le 4 cifre
con un certo numero di tentativi. Ad ogni tentativo il computer risponde  indicando il n. di cifre
nella posizione giusta e il n. di cifre nella posizione sbagliata.

Nome:Antonio		Cognome:Bellini
Classe: 3C INFO		Data: 01/02/2022
*************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX_NUMERI 4
#define MAX_TENTATIVI 10

//Void per inizializzazione numero pensato dal pc e controllo del numero
void creaNumeroPc(int i, int pc[MAX_NUMERI])
{
	srand(time(NULL));

	for(i=0;i<MAX_NUMERI;i++)
	{
		pc[i]=rand()%9;		
					
		//Controllo per dare sempre numeri diversi
		if(pc[i]==pc[i-1]||pc[i]==pc[i-2]||pc[i]==pc[i-3])
			i--;
	}
}
	
//Void che fa inserire il numero all'utente e poi lo scompone in migliaia, centinaia, decine e unità
void conversioneNumeroUtente(int utente[MAX_NUMERI], int numeroInserito, int resto1, int resto2)
{
	utente[0] = numeroInserito / 1000;
	resto1 = numeroInserito % 1000;
	utente[1] = resto1 / 100;
	resto2 = resto1 % 100;
	utente[2] = resto2 / 10;
	utente[3] = resto2 % 10;
}

//Void per il controllo dei numeri uguali presenti nell'array dell'utente e del pc
void controllo(int utente[MAX_NUMERI], int pc[MAX_NUMERI], int i, int a, int posizioneGiusta, int posizioneErrata)
{
	posizioneGiusta=0;
	posizioneErrata=0;

	for(i=0;i<MAX_NUMERI;i++)
		{
			for(a=0;a<MAX_NUMERI;a++)
				{
					if(utente[a]==pc[i]&&a==i)
	   					posizioneGiusta+=1;
	    
					if(utente[a]!=pc[i])
	   					i++;

	    			if(utente[a]==pc[i]&&a!=i)
	   					posizioneErrata+=1;
				}
		}
	printf("Hai inserito:\n");
	printf("%d valori giusti e nella posizione giusta\n",posizioneGiusta);
	printf("%d valori giusti ma nella posizione errata\n",posizioneErrata);
}

int main()
{
	int pc[MAX_NUMERI],
		utente[MAX_NUMERI],
		posizioneGiusta,
		posizioneErrata,
		tentativi,
		numeroInserito,
		resto1,
		resto2,
		a,
		i;
	bool vittoria=false;

	creaNumeroPc(i, pc);

	for(tentativi=1;tentativi<MAX_TENTATIVI;tentativi++)
		{
			posizioneGiusta=0;
			posizioneErrata=0;
			printf("Inserisci il numero-->");
			scanf("%d",&numeroInserito);
			conversioneNumeroUtente(utente, numeroInserito, resto1, resto2);
			controllo(utente, pc, i, a, posizioneGiusta, posizioneErrata);
		}

	if(posizioneGiusta==4)
		vittoria=true;
	
	if(vittoria==true)
		printf("Complimenti, hai indovinato!");

	return 0;
}

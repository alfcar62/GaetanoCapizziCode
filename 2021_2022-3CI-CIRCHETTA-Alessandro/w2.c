/**********************
ALUNNO: Ciccio Gamer
DATA:   11/09/2001
CLASSE: 3C INFORMATICA 
CONSEGNA:  Verifica - In un vettore è contenuta la classifica di una gara podistica, con i numeri di pettorale in ordine di arrivo. Dato il numero di un concorrente, stampare la sua posizioneizione in classifica. Se il numero non compare nel vettore, segnala l’errore. 
**********************/
#include <stdlib.h>
#include <stdio.h>
#define NCLASS 10

int main()
{
    int i,
    	posizione,
        gareggiante,
        classifica[NCLASS]={104,69,96,777,666,208,420,15,6,13};
        
    printf("Inserire il numero di pettorina del gareggiante che le interessa ->");
    scanf("%d",&gareggiante);

    for (i = 0; i < NCLASS; i++)
    {
        if (gareggiante == classifica[posizione])
        {
            printf("Il gareggiante da lei cercato e' arrivato in posizione %d\n COMPLIMENTI!",posizione+1);
            break;
        }
	    else
        	posizione++;
    }

    if (i == NCLASS)
        printf("Il gareggiante col numero fornito non e' arrivato nella classifica dei primi dieci\n");
    
    return 0;
}
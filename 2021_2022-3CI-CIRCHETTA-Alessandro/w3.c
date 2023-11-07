/**********************
ALUNNO: Ciccio Gamer
DATA:   11/09/2001
CLASSE: 3C INFORMATICA 
CONSEGNA:  Verifica - In un vettore è contenuta la classifica di una gara podistica, con i numeri di pettorale in ordine di arrivo. Dato il numero di un concorrente, stampare la sua posizioneizione in classifica. Se il numero non compare nel vettore, segnala l’errore. 
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NCLASS 10

int Input()
{
    int gareggiante;
    printf("Inserire il numero di pettorina del gareggiante che le interessa -> ");
    scanf("%d", &gareggiante);

    return gareggiante;
}

int Trova(int vettore[], int pett)
{
    for (int i = 0; i < NCLASS; i++)
        if (vettore[i] == pett)
            return i;
            
    return -1; 
}

int main()
{
    int i;

    int classifica[NCLASS] = {104,69,96,777,666,208,420,15,6,13}; 
    
    int pettorina = Input();
    int posizione = Trova(classifica, pettorina);

    if (posizione == -1)
        printf("Il gareggiante col numero fornito non e' arrivato nella classifica dei primi dieci\n");
    else
        printf("Il gareggiante da lei cercato e' arrivato in posizione %d\n COMPLIMENTI!", posizione + 1);

    return 0;
}

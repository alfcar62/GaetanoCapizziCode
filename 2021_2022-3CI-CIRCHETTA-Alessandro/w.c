/**********************
ALUNNO: Ciccio Gamer
DATA:   11/09/2001
CLASSE: 3C INFORMATICA 
CONSEGNA:  Verifica - In un vettore è contenuta la classifica di una gara podistica, con i numeri di pettorale in ordine di arrivo. Dato il numero di un concorrente, stampare la sua posizioneizione in classifica. Se il numero non compare nel vettore, segnala l’errore. 
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Input()
{
    int gareggiante;
    printf("Inserire il numero di pettorina del gareggiante che le interessa -> ");
    scanf("%d", &gareggiante);

    return gareggiante;
}

int Trova(int vettore[], int pett)
{
    for (int i = 0; i < 10; i++)
        if (vettore[i] == pett)
            return i;

    return -1; 
}

int main()
{
    srand(time(NULL));
    int classifica[10];

    for (int i = 0; i < 10; i++)
        classifica[i] = rand() % 100;
    
    int pettorina = Input();
    int posizione = Trova(classifica, pettorina);

    if (posizione == -1)
        printf("Il gareggiante col numero fornito non e' arrivato in classifica dei primi dieci\n");
    else
        printf("Il gareggiante da lei cercato e' arrivato in posizione %d\n COMPLIMENTI!", posizione);

    return 0;
}

/*
Alunno:		Alessandro Circhetta
Classe: 	3c inf
Data:		30/03/2022
Esercizio: 	DATO UN NUMERO DI RAGAZZI E LE LORO ETA' CALCOLARE IL NUMERO DI MINORENNI E MAGGIORENNI, FARE LA MEDIA DELLA LORO ETA' E STAMPARE UN AVVISO NEL CASO I MINORENNI RAPPRESENTANO + DEL 50% DEL GRUPPO
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  
#include <windows.h>    
#include <string.h>
#include <ctype.h>
#define MAGGETA 18


int main()
{
    int raga = 0, i = 0, maggiorenni = 0, minorenni = 0; 
    float  rag = 0, media = 0, somma = 0;


    printf("inserire numero di ragazzi -->");
    scanf("%d", &raga);
    
    int eta[raga];

    for (i = 0; i < raga; i++)
    {
        printf("inserire eta' ragazzo n.%d-->", i+1);
        scanf("%d", &eta[i]);

        if(eta[i]>=MAGGETA)
            maggiorenni++;
        else
            minorenni++;

        somma += eta[i];

        media = somma / raga; 
    }
    
    rag  = raga;

    if (minorenni > (raga/2))
    {
        printf("ATTENZIONE!! IN QUESTO GRUPPO C'E' UN ECCESSO DI O8 e/o FOTTNAIT KIDS\n");
    }
    

    printf("i minorenni sono --> %d \ni maggiorenni sono --> %d \nla media della loro eta' e' %f", minorenni, maggiorenni, media);
    return 0;
}
/**
ALUNNO: Alessandro Circhetta
DATA:   30/03/2022
CLASSE: 3C INFORMATICA 
TESTO:  Tabella pitagorica
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>                                                //stringhe
#include <ctype.h>                                                 //upper / lower
#define MAX 10

int main()
{
    //tabella pitagorica
    int tp [MAX][MAX];
    //variabili di riga e colonna
    int righe, colonne;


    for(righe=0; righe< MAX; righe++)
    {
        for(colonne=0; colonne< MAX; colonne++)
        {
            if(colonne!= MAX - 1)
            {
                tp[MAX][MAX] = (righe+1)*(colonne+1);
                printf(" %03d ",tp[MAX][MAX]);
            }
            if(colonne== MAX - 1)
            {
                tp[MAX][MAX] = (righe+1)*(colonne+1);
                printf(" %03d\n",tp[MAX][MAX]);
            }
        }
    }
    return 0;
}

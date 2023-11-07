/*
ALUNNO: Circhetta Alessandro 
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA: Calcolare il codice fiscale
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

void input(char stringa[], char var[])
{
    bool errore;
    int i = 0;

    do
    {
    
        printf("inserisci il tuo %s -->", var);
        gets(stringa);

        for(i = 0; i < strlen(stringa); i++)
        {
            stringa[i] = toupper(stringa[i]);
        }
            errore = false;

        for(i = 0; i < strlen(stringa); i++)
        {
            if ((stringa[i] < 'A' || stringa[i]> 'Z') && stringa[i] != ' ' && stringa[i] != '\'' )
                errore = true;
        }
    } while (errore == true);
}

void divisioneconsonantivocali(char stringa[], char vocali[], char consonanti[])
{
    int icons = 0, 
        ivoca = 0;
    
    for(int i = 0; i < strlen(stringa); i++)
    {
        stringa[i] = toupper(stringa[i]);

        if( stringa[i] != 'A' && stringa[i] != 'E' && stringa[i] != 'I' && stringa[i] != 'O' && stringa[i] != 'U' && stringa[i] != ' ')
        {
          //printf("trovata consonante %c\n", stringa[i] );
            consonanti[icons] = stringa[i];
            icons ++;
        }
        else
        {  
          //printf("trovata vocale %c\n", stringa[i] );
            vocali[ivoca] = stringa[i];
            ivoca ++;
        }
    }
    consonanti[icons] = 0;
    vocali[ivoca] = 0;
}

void generacf(char consonanti[], char vettcogn[])
{
  //printf("consonanti = %s\n", consonanti);
    vettcogn[3] = 0;

    int i = 0;

    for (; i < strlen(consonanti) && i < 3; i++)
        vettcogn[i] = consonanti[i];

  //printf("vettcogn = %s\n", vettcogn);
    for(; i < 3; i++)
        vettcogn[i] = 'X';
}


int  main()
{

    char cognome[MAX];
    char nome[MAX];
    char vocalicognome[MAX];
    char consonanticognome[MAX];
    char citta[MAX];
    char cfcognome[3];


    char voceinput[10] = "cognome";
    input(cognome,voceinput);

    char voceinput2[10] = "nome";
    input(nome,voceinput2);

    char voceinput3[10] = "citta'";
    input(citta,voceinput3);
    
    divisioneconsonantivocali(cognome,vocalicognome,consonanticognome);
    generacf(consonanticognome,cfcognome);
    
    puts(cfcognome);

    return 0;
}

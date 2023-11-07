/*
    Marco Schiavello 3^CI 16/08/2021

    Realizzare un programma che
        - prenda in input da un file .csv i nomi e i voti di una serie di studenti in un compito in classe.
          Un voto con valore 0 indica che lo studente è assente al momento della prova.
        - Stampi la media dei voti non considerando le assenze
        - Stampi il nome dello studente che ha riportato il voto massimo
        - Stampi l’elenco degli studenti insufficienti (esclusi gli assenti)
        - Stampi la percentuale di studenti assenti
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define NOME_LEN 40
#define NUM_STUD 30
#define OK 1
#define ERR -1

typedef struct
{
    char nome[NOME_LEN];
    float voto;
} tupla;

int caricaFile(tupla voti[]);
void menu(int * scelta);
float aveMarks(tupla voti[],int len);
tupla highestMark(tupla voti[],int len);
void insuffStud(tupla voti[],int len);
float absentRate(tupla voti[],int len);
void printMarks(tupla voti[],int len);

/*_________Main________*/
int main()
{
    tupla voti[NUM_STUD];
    int numStud = caricaFile(voti),scelta;
    tupla highMark;

    if(numStud == ERR)
        return EXIT_FAILURE;

    do
    {
        menu(&scelta);
        switch(scelta)
        {
            case 1:
                printf("la media dei vote e': %.3f",aveMarks(voti,numStud));
            break;
            case 2:
                highMark = highestMark(voti,numStud);
                printf("la persona con il voto piu alto e': %s con %.2f",highMark.nome,highMark.voto);
            break;
            case 3:
                insuffStud(voti,numStud);
            break;
            case 4:
                printf("la percentuale degli studenti assenti e': %.2f%% ",absentRate(voti,numStud));
            break;
            case 5:
                printMarks(voti,numStud);
            break;
        }

        getch();
    }
    while(scelta > 0 && scelta <6);

    return EXIT_SUCCESS;
}

/**
*   legge un file csv e lo trasforma in un array di tuple alunno voto
*   params:
*       @param tupla voti[] : output : arrray dove finiranno le tuple lette
*       @return int : status code / numero di tuple
*/
int caricaFile(tupla voti[])
{
    FILE * f;
    char file[20];
    int i;

    printf("file da caricare: ");
    scanf("%s",file);
    f = fopen(file,"r");

    if(f == NULL)
        return ERR;

    for(i = 0;!feof(f);i++)
        fscanf(f,"\n%[^,], %f",voti[i].nome,&voti[i].voto);


    return i-1;
}


/**
*   visualizza un menu dove l'utente sceglie che operazaione fare
*   params:
*       @param int * scelta : output : dove viene messa la scelta
*       @return void
*/
void menu(int * scelta)
{
    system("cls");
    printf("Scegliere operazione da fare sui voti\n");
    printf("1)media dei voti escludendo gli assenti\n");
    printf("2)nome dello studente con voto piu' alto\n");
    printf("3)elenco studenti insufficenti esclusi assenti\n");
    printf("4)percentuale di studenti assenti\n");
    printf("5)stampa tutta la tabella dei voti\n");
    printf("premi qualsiasi altro numero per uscire ...\n");
    printf("Scelta: ");
    scanf("%d", scelta);
}

/**
*   fa la media dei voti di tutti gli alunni presenti
*   params:
*       @param tupla voti[] : input : tuple alunno voto
*       @param int len : input : fino a quando considerare le tuple
*       @return void
*/
float aveMarks(tupla voti[],int len)
{
    float sum = 0;
    for(int i = 0;i < len;i++)
        if(voti[i].voto != 0)
            sum += voti[i].voto;

    return (float) sum/len;
}

/**
*   restituisce la tupla con il voto piu alto
*   params:
*       @param tupla voti[] : input : tuple alunno voto
*       @param int len : input : fino a quando considerare le tuple
*       @return void
*/
tupla highestMark(tupla voti[],int len)
{
    tupla highest;
    highest.voto = 0;
    for(int i = 0;i < len;i++)
        if(voti[i].voto > highest.voto)
            highest = voti[i];

    return highest;
}

/**
*   stampa tutti gli alunni insufficenti presenti
*   params:
*       @param tupla voti[] : input : tuple alunno voto
*       @param int len : input : fino a quando considerare le tuple
*       @return void
*/
void insuffStud(tupla voti[],int len)
{
    for(int i = 0;i < len;i++)
        if(voti[i].voto < 6 && voti[i].voto != 0)
            printf("lo studente %s e' insufficente con un voto di: %0.2f\n",voti[i].nome,voti[i].voto);
}

/**
*   ritorna la percentuale delle assenze nella classe
*   params:
*       @param tupla voti[] : input : tuple alunno voto
*       @param int len : input : fino a quando considerare le tuple
*       @return void
*/
float absentRate(tupla voti[],int len)
{
    int numAsse = 0;
    for(int i = 0;i < len;i++)
        if(voti[i].voto == 0)
            numAsse++;
    return (float) (numAsse*100)/len;
}

/**
*   stampa tutti gli alunni della classe con i loro rispettivi voti
*   params:
*       @param tupla voti[] : input : tuple alunno voto da stampare
*       @param int len : input : fino a quando considerare le tuple
*       @return void
*/
void printMarks(tupla voti[],int len)
{
    for(int i = 0;i < len;i++)
        printf("%s: %0.2f\n",voti[i].nome,voti[i].voto);
}

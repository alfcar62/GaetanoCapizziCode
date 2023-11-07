/*
ALUNNO: Circhetta Alessandro & Guglielmo Pansini
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA: CODICE FISCALE
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

void input(char stringa[], char var[])
{
    bool errore = false;
    int i = 0;

    if(strcmp(var, "cognome")==0)
    {
        do
        {
            gotoxy (9,5);
            printf("inserisci il tuo cognome: ..............................");
            gotoxy(35,5);
            gets(stringa);

            for(i = 0; i < strlen(stringa); i++)
            {
                stringa[i] = toupper(stringa[i]);

                if ((stringa[i] < 'A' || stringa[i]> 'Z') && stringa[i] != ' ' && stringa[i] != '\'' )
                    errore = true;
            }
        } while (errore == true);
    }
    if(strcmp(var, "nome")==0)
    {
        do
        {
            gotoxy (9,6);
            printf("inserisci il tuo nome: ..............................");
            gotoxy(32,6);
            gets(stringa);

            for(i = 0; i < strlen(stringa); i++)
            {
                stringa[i] = toupper(stringa[i]);

                if ((stringa[i] < 'A' || stringa[i]> 'Z') && stringa[i] != ' ')
                    errore = true;
            }
        } while (errore == true);
    }
}


int main()
{

    char cognome[MAX];
    char nome[MAX];
    char voceinputc[10] = "cognome"; 
    char voceinputn[10] = "nome";
    system("cls");

    gotoxy (35, 1);
    printf("CODICE FISCALE");


    input(cognome,voceinputc);
    input(cognome,voceinputn);












    return 0;
}
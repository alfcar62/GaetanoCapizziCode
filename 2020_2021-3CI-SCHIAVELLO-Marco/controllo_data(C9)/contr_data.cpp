//marco schiavello 3^CI 12/11/2020
//controllo formale della data
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

void chiediData(int * var,int gg = -1,int mm = -1);
bool checkFeb(int gg,int mm,int aaaa);
char continuare();

/*__________Main_________*/
int main()
{
	int gg,mm,aaaa;
	bool rep=false;
	char risp;
	do
	{
	    do
	    {
	        do
	        {
	            do
	            {
	               chiediData(&gg);
	            }
	            while(gg<1||gg>31);
	            do
	            {
	                chiediData(&mm,gg);
	            }
	            while(mm<1||mm>12);
	        }
	        while((mm==4||mm==6||mm==9||mm==11)&&gg==31);
	        do
	        {
	           chiediData(&aaaa,gg,mm);
	        }
	        while(aaaa<1);

            rep = checkFeb(gg,mm,aaaa);
	    }
	    while(rep==true);

	    printf("\nva bene\n\n");

        risp = continuare();

	}
	while(risp == 's');
}

/**
*   chiede la data e in base a cosa e gia stato chiesto combia cosa chiedi input
*   params:
*       @param int * var : output : variabile dove varra messo il valore
*       @param int gg = -1 : input : il giorno se scelto altrimenti lo setta a -1
*       @param int mm = -1 : input : il mese se scelto altrimenti lo setta a -1
*       @return void
*/
void chiediData(int * var,int gg,int mm)
{
    system("cls");
    printf("immettere data\n");
    if(gg != -1)
    {
        printf("inserisci il giorno  --> %d",gg);
        if(mm != -1)
        {
            printf("\ninserisci il mese    --> %d",mm);
            printf("\ninserisci il anno    --> ");
        }
        else
            printf("\ninserisci il mese    --> ");
    }
    else
        printf("inserisci il giorno  --> ");

    scanf("%d",var);
}

/**
*   controlla che il giorno di febbraio e vede in base all'anno se e compreso o meno
*   params:
*       @param int gg : input : giorno
*       @param int mm : input : mese
*       @param int aaaa : input : anno
*       @return bool
*/
bool checkFeb(int gg,int mm,int aaaa)
{
    bool rep;
    if(mm==2&&gg>28)
        if((aaaa%4==0&&aaaa<=1917)||((aaaa%4==0&&aaaa%100!=0)||aaaa%400==0)&&aaaa>1917)
            if(gg==29)
                rep=false;
            else
                rep=true;
        else
            rep=true;
    else
        rep=false;

    return rep;
}

/**
*   chiede all'utente se vuole continuare
*   params:
*       @return char
*/
char continuare()
{
    char risp;
    do
    {
        fflush(stdin);
        printf("vuoi continuare (s o n): ");
        scanf("%c",&risp);
        tolower(risp);
    }
    while(risp!='s'&& risp!='n');

    return risp;
}

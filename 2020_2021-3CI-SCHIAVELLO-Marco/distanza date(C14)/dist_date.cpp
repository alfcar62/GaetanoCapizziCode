//Marco Schiavello 3^CI 31/01/2021
/*
	leggere due date dello stesso anno.
	Nota: effettuare il controllo formale delle date inserite
	(compreso il controllo sul fatto che le due date siano dello stesso anno)
	e dire quanti giorni intercorrono tra una data e l'altra.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define N_DATE 2

int deltaGioni(int gg[],int mm[], bool bise);
void setDate(int gg[],int mm[],int aaaa[],bool * bise);
void chiediData(int * var,int gg = -1,int mm = -1);
bool checkFeb(int gg,int mm,int aaaa);


/*________Main_________*/
int main()
{
	int gg[N_DATE], mm[N_DATE], aaaa[N_DATE];
    bool bise = false;
    setDate(gg,mm,aaaa,&bise);
    printf("%d",deltaGioni(gg,mm,bise));
    return 0;
}

/**
*   date due date calcola la differenza di giorni
*   params:
*       @param int gg[] : input : giorno prima e seconda data
*       @param int mm[] : input : mese prima e seconda data
*       @param bool bise : input : indica se l'anno e bisestile
*       @return int : numero di giorni tra le due date
*/
int deltaGioni(int gg[],int mm[], bool bise)
{
  int ris,i,anno[12] = {31,28,31,30,31,30,31,31,30,31,30,31},min,max;
  if(bise == true)
    anno[1] = 29;
  if(mm[0]==mm[1])
    ris = abs(gg[0] - gg[1]);
  else
  {
    if(mm[0]<mm[1])
      min = 0,max = 1;
    else
      min = 1,max = 0;

    ris=anno[mm[min]-1]-gg[min];
    ris+=gg[max];
    for(i = mm[min];i<mm[max]-1;i++)
      ris+=anno[i];
  }
  return ris;
}

/**
*   date due date calcola la differenza di giorni
*   params:
*       @param int gg[] : input : giorno prima e seconda data
*       @param int mm[] : input : mese prima e seconda data
*       @param int aaaa[] : input : anno prima e seconda data
*       @param bool * bise : input : puntatore che punta alla fariabile flag che indica se un anno e bisestile o meno
*       @return void
*/
void setDate(int gg[],int mm[],int aaaa[],bool * bise)
{
	bool rep=false;
	char risp;
	int i;
	do
	{
		for(i=0;i<N_DATE;i++)
		{
            do
            {
                do
                {
                    do
                    {
                       chiediData(&gg[i]);
                    }
                    while(gg[i]<1||gg[i]>31);
                    do
                    {
                        chiediData(&mm[i],gg[i]);
                    }
                    while(mm[i]<1||mm[i]>12);
                }
                while((mm[i]==4||mm[i]==6||mm[i]==9||mm[i]==11)&&gg[i]==31);
                do
                {
                   chiediData(&aaaa[i],gg[i],mm[i]);
                }
                while(aaaa[i]<1);

                rep = checkFeb(gg[i],mm[i],aaaa[i]);
            }
            while(rep==true);

            printf("\nva bene\n\n");

		}
	}
	while(aaaa[0]!=aaaa[1]);

	if((aaaa[0]%4==0&&aaaa[0]<=1917)||((aaaa[0]%4==0&&aaaa[0]%100!=0)||aaaa[0]%400==0)&&aaaa[0]>1917)
		if((mm[0]<=2 || mm[1]<=2)&&(mm[0]>2 || mm[1]>2))
		*bise=true;
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



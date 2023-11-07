/*
  Marco Schiavello, Alberto Benedicenti, Guido Panzieri 3^CI 18/02/2021
  Scrivere un programma che:
  leggere  in un primo vettore i voti riportati da uno studente in diverse materie,
  e costruire un nuovo vettore contenente solo i voti sufficienti e stamparne il contenuto
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void caricaVoti(float voti[]);
void ricercaVotiSuf(float voti[], float votiSuf[], int * numsuf);
void output(float votiSuf[],int numsuf);

/*__________Main___________*/
int main()
{
  int numsuf = 0;
  float voti[DIM];
  float votiSuf[DIM];
  caricaVoti(voti);
  ricercaVotiSuf(voti,votiSuf,&numsuf);
  output(votiSuf,numsuf);
}

/**
*   carica l'array con i voti
*   params:
*       @param float voti[] : output : array dove verranno messi i voti
*       @return void
*/
void caricaVoti(float voti[])
{
  for(int i = 0;i<DIM;i++)
  {
    do
    {
      printf("inserisci il %2d ° valore : ",i+1);
      scanf("%f",&voti[i]);
    }
    while(voti[i]<1 || voti[i]>10);
  }
}

/**
*   cerca ed assegna i voti sufficenti al array apposito
*   params:
*       @param float voti[] : input : array di voti da smistare
*       @param float votiSuf[] : output : array di voti sufficenti
*       @param int * numsuf : output : puntatore che punta alla variabile che contiene il numero di voti sufficenti
*       @return void
*/
void ricercaVotiSuf(float voti[], float votiSuf[], int * numsuf)
{
  for(int i=0;i<DIM;i++)
  {
    if(voti[i]>=6)
    {
      votiSuf[*numsuf] = voti[i];
      *numsuf = *numsuf + 1;
    }
  }
}

/**
*   stampa solo i voti sufficenti dall'array
*   params:
*       @param float votiSuf[] : input : array di voti sufficenti da stamapre
*       @param int numsuf : output : numero di voti sufficenti
*       @return void
*/
void output(float votiSuf[],int numsuf)
{
  printf("i voti sufficenti sono : ");
  for(int i = 0;i<numsuf;i++)
  {
    printf(" %.2f ",votiSuf[i]);
  }
}

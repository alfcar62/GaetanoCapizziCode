/*
NOME: Circhetta Alessandro
DATA: 29/09/2021
CONSEGNA: Scrivere il flow chart e il programma C che risolve il seguente problema:  leggere il tempo in ore, minuti e secondi e trasformare il tutto in secondi. 
CLASSE: 3^C INFORMATICA
*/
#include <stdio.h>

int main()
{
 int s, h, m, tot;

 printf("inserire ore: ");
 scanf("%d", &h);

 printf("inserire minuti: ");
 scanf("%d", &m);

 printf("inserire secondi: ");
 scanf("%d", &s);

 tot = (h * 3600) + (m * 60) + s;

 printf("l'orario è: %d", tot);

 return 0;
}
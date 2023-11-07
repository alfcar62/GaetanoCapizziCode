/*
NOME: Circhetta Alessandro
DATA: 29/09/2021
CONSEGNA: Disegnare flow chart e scrivere il programma C che risolve il seguente problema: prendere due tempi t1 e t2 espressi in ore,minuti, secondi e   calcolare la somma di t1 e t2 espressa in ore,minuti,secondi 
CLASSE: 3^C INFORMATICA
*/

#include<stdio.h>


int main()
{
    int h1, m1, s1, tot1, h2, m2, s2, tot2, tot, h, m, s;
    printf("inserire primo valore ore:");
    scanf("%d",&h1);
    printf("inserire primo valore minuti:");
    scanf("%d",&m1);
    printf("inserire primo valore secondi:");
    scanf("%d",&s1);
    
    tot1=(h1 * 3600) + (m1 * 60) + s1;
    
    printf("inserire secondo valore ore:");
    scanf("%d",&h2);
    printf("inserire secondo valore minuti:");
    scanf("%d",&m2);
    printf("inserire secondo valore secondi:");
    scanf("%d",&s2);
    
    tot2=(h2 * 3600) + (m2 * 60) + s2;
    tot=tot1 + tot2;
    h=(tot / 3600);
    m=(tot % 3600) / 60;
    s=tot-(m * 60 + h * 3600);
    
    printf("%d\n",h);
    printf("%d\n",m);
    printf("%d\n",s);

    return 0;
}
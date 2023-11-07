/*
Autore: Pansini Guglielmo e Circhetta Alessandro
Data: 13 OTTOBRE 2021
Consegna:Leggere 2 numeri positivi e calcolarne il prodotto con il metodo delle addizioni successive. Consegnare flow chart e programma in C
Classe: 3°c informatica
*/

#include<stdio.h>


int main()
{
    int x, y, s=0, i=0;

    do
    {
     
        printf("inserire il primo  numero maggiore di 0-----> ");
        scanf("%d", &x);
        
    } while (x <= 0);

    do
    {
     
        printf("inserire il secondo numero maggiore di 0 -----> ");
        scanf("%d", &y);

    } while (y <= 0);

    do
    {
        i = i + 1;
        s = s + x;
    } while (i < y);
    
    printf("il risultato e' uguale a %d", s);
    return 0;
}

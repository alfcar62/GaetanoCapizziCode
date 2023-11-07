/*
Autore: Circhetta Alessandro
Data: 13 OTTOBRE 2021
Consegna: dato num in input stampare il minore di num numeri (con controllo dell'input)
Classe: 3°c informatica
*/

#include<stdio.h>


int main()
{
    int num, n, min, cont = 0;

    do
    {
        printf("inserire il numero di volte che bisogna eseguire il programma ----> ");
        scanf("%d", &num);
    } while (num <= 0);

    while (cont < num)
    {
     
        printf("inserire un numero -----> ");
        scanf("%d", &n);
        
        cont = cont + 1;

        if (min > n) min = n;

    }

    printf("il numero minore e' ------> %d", min);
    return 0;
}

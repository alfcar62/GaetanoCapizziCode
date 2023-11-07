/*
Autore: Alessandro Circhetta
Data: 12 OTTOBRE 2021
Consegna: dato num in input stampare il minore di num numeri (con ciclo for)
Classe: 3°c informatica
*/

#include <stdio.h>


int main()
{
    int i = 0, min, num, n;
    
    printf("inserire il numero di volte in cui il programma va eseguito-----> ");
    scanf("%d",&num);

    for ( i = 0; i < num; i++)
    {
        printf("inserire un numero -----> ");
        scanf("%d",&n);

        if (n < min) min = n;
        
    }

    printf("il numero minore e': %d",min);

    return 0;

}

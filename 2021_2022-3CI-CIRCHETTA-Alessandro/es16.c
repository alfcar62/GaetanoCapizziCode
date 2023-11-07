/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Dato un numero n in input, stampare i primi n numeri primi.
*****************************************/
#include <stdio.h>


int main()
{
    int num   = 0,
        primi = 0,
        div   = 0,
        i     = 0;

    printf("Inserire numero di numeri da analizzare -> ");
    scanf("%d", &primi);

    for (i = 0; i < primi; i++)
    {
        do
        {
            num++;
            div = 0;

            for (int n = 2; n < num; n++)
                if (num % n == 0)
                    div++;
        } while (div != 0);

        printf(" %d ", num);
    }

    return 0; 
}
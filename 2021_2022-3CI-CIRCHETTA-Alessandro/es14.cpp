/*
Autore: Pansini Guglielmo e Circhetta Alessandro
Data: 13 OTTOBRE 2021
Consegna: Leggere un numero n positivo e calcolare il quadrato con il metodo della somma dei primi n numeri dispari (es. se n = 6  il suo quadrato è = 1+3+5+7+9+11 = 36). Consegnare flow chart + programma in C
Classe: 3°c informatica
*/

#include<stdio.h>


int main()
{
    int n, disp=-1, i=0, s=0;
    do
    {
        printf("inserire il numero di cui si vuole fare il quadrato ----> ");
        scanf("%d", &n);

    } while (n < 1);

    do
    {
    disp += 2;
    i++;
    s = s + disp;
    } while (i < n);

    printf("il risultato e' -----> %d", s);

    return 0;
}

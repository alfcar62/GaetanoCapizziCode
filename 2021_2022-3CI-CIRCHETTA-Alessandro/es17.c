/*
Data: 09/11/2021
Autore: Pansini Guglielmo & Circhetta Alessandro
consegna: Scrivere un programma in C language che raccoglie in un menu tutti i programmi svolti da Es.12 a Es.16
*/



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int risp;

    printf("selezionare 1 per la MOLTIPLICAZIONE\n");
    printf("selezionare 2 per la DIVISIONE\n");
    printf("selezionare 3 per la QUADRATO\n");
    printf("selezionare 4 per la FIBONACCI\n");
    printf("selezionare 5 per la FIBONACCI\n");
    printf("selezionare 6 per la ESCI\n");

    printf("inserire il numero del programma che si vuole scegliere ----> ");
    scanf("%d", &risp);
    switch (risp)
    {
        case 1:
        {    
            int x, y, s=0, i=0;

            do
            {
        
                printf("inserire il primo numero maggiore di 0 ----> ");
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
        }break;
    
    default:
     break;
    }

    switch (risp)
    {
    case 2:{
        
    int n1, n2;


    do 
        {
            printf("inserire numero che si vuole dividere -------> ");
            scanf("%d",&n1);
        } 
    while (n1<1);

    do 
        {
            printf("inserire il numero per cui si vuole dividere -------> ");
            scanf("%d",&n2);
        } 
    while (n2<1);

        int s=n1;
        int i=0;
    do 
        {
            s=s-n2;
            i=i+1;
        }while (s>=n2);
    
    printf("il risultato e' ------> %d", i);
    printf("\nil resto e'  ------> %d", s);
    

    }break;
    
    default:
        break;
    }

    switch (risp)
    {
    case 3:{
        int n, disp=-1, i=0, s=0;
        
        do
        {
            printf("inserire il numero di cui si vuole fare il quadrato ----> ");
            scanf("%d", &n);

        } while (n > 46340 || n <1);

        do
        {
            disp += 2;
            i++;
            s = s + disp;
        } while (i < n);

        printf("il risultato e' -----> %d", s);

    }break;
    
    default:
        break;
    }

    switch (risp)
    {
    case 4:{
        int pre=0, sub=1, fi, n, cont=0;
    
        printf("inserire il numero di volte che si vuole eseguire il programma: ");
        scanf("%d",&n);

        do
        {
            fi = pre + sub;

            pre = sub;
    
            sub = fi;

            cont++;

            printf("il risultato e' ------> %d\n", fi);
        } while(cont < n);

        }break;
    
    default:
        break;
    }

    switch (risp)
    {
    case 5:{
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

    }break;
    
    default:
        break;
    }

    switch (risp)
    {
    case 6:
    {
        return 0;
    }break;
    
    default:
        break;
    }
   return 0;
}
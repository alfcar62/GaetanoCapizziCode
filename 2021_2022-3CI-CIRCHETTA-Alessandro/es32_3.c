/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   02/02/2022
CLASSE: 3C INFORMATICA
CONSEGNA:Scrivere un programma che chiama una procedura che, dati tre numeri interi in input, 
li restituisca tutti e tre incrementati  ognuno del doppio. Ad es: i numeri 3,5,7 devono diventare 6,10,14.
Il main effettuerà la stampa dei tre numeri modificati dalla procedura.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void raddoppia(int *a, int *b, int *c)
{
    *a = (*a)*2;
    *b = (*b)*2;
    *c = (*c)*2;

}

int  main()
{
    int n1,n2,n3;

    printf("inserire il primo numero -->");
    scanf("%d",&n1);

    printf("inserire il primo numero -->");
    scanf("%d",&n2);

    printf("inserire il primo numero -->");
    scanf("%d",&n3);

    raddoppia(&n1,&n2,&n3);

    printf("il doppio del primo numero e' -->%d\n",n1);

    printf("il doppio del primo numero e' --> %d\n",n2);

    printf("il doppio del primo numero e' --> %d\n",n3);

return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define MAX 10

int main()
	{
		int i = 0,
			n = 0,
			a = 0;
	    int vet[MAX];
			
			
		for(i=0; i<10; i++)
		{
			printf("inserire il numero nella locazione %d:  ", i);
			scanf("%d", &n);
		}
			while(n<0)
			{
			printf("Il numero inserito non e' accettabile\n");
			printf("\nInserire n numeri interi --->");
			scanf("%d",&n);
			}
			
			vet[i]=n;

    return 0;
}
			 

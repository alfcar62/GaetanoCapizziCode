/*****************************************
Autori:   Alessandro Circhetta
Classe:   3C Inf
Data:     03/11/2021
Consegna: Dato un numero n in input, stampare i primi n numeri primi. Scrivere una analisi del problema e  disegnare il flow chart su file pdf.
*****************************************/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int
		cont = 0,
           n = 0,
		prec = 0,
		succ = 1, 	
		fibo = 0;
		
		do
		{
			printf("inserire numero di numeri che si vogliono far apparire:");
			scanf ("%d", &n);
			
			if (n < 0)
			printf("\nATTENZIONE! VALORE NON CONSENTITO! REINSERIRLO POSITIVO\n");
		}
		while(n < 0);
		
		do
		{	
			fibo = prec + succ;
			prec = succ;
			succ = fibo;
			cont++;
			
			printf ("%d\n", fibo);
		}
		while (cont < n);
		
	return 0;	
}

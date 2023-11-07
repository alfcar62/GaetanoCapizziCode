/*****************************************
Autori:   Jacopo Bordoni - Alessandro Circhetta
Classe:   3C Inf
Data:     20/10/2021
Consegna: Leggere 2 numeri positivi e calcolarne il prodotto con il metodo delle addizioni successive.
*****************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int 
	 n = 0,
	n1mol = 0,
	n2mol = 0,
 	 imol = 0,
 	 smol = 0,
 	n1div = 0,
 	n2div = 0,
 	 idiv = 0,
 	 sdiv = 0,
 	nquad = 0,
 	iquad = 0,
 	squad = 0,
 	ciclo = 0;
	
	do
	{
		printf("1) Moltiplicazione\n");
		printf("2) divisione\n");
		printf("3) Quadrato\n");
		printf("4) Esci\n");
		printf("\nSCEGLI:");
		scanf ("%d", &n);
		
		system("cls");
		
		if(n = 1);
		{
			do
			{
				printf("Inserire PRIMO numero: ");
				scanf ("%d", &n1mol);
				
				if (n1mol <= 0)
				printf("\n\nATTENZIONE! \nIl numero inserito deve essere positivo.\n\n");
		 	}
	 		while (n1mol < 1);
		 	
			do
	 		 {
			 
	 			printf("\nInserire SECONDO numero: ");
				scanf ("%d", &n2mol);
				
				if (n2mol <= 0)
				printf("\nATTENZIONE! \nIl numero inserito deve essere positivo. \n\n");
			 }
		 	while (n2mol < 1);	
		 	
		 	do
	   		 {
		 	 	imol ++;
		 		smol = smol + n1mol;
		 	 }
		 	while (imol < n2mol);
		 	
		 	printf("\nIl prodotto tra il PRIMO e il SECONDO numero e': ");
		 	printf("%d", smol);
		}
		
		system("cls");
		
		if(n = 2)
		{
			do
	 		 {
			 
	 			printf("Inserire PRIMO numero: ");
				scanf ("%d", &n1div);
				
				if (n1div <= 0)
				printf("\n\nATTENZIONE! \nIl numero inserito deve essere positivo.\n\n");
			 }
		 	while (n1div < 1);
			 	
			do
	 		 {
			 
	 			printf("\nInserire SECONDO numero: ");
				scanf ("%d", &n2div);
				
				if (n2div <= 0)
				printf("\nATTENZIONE! \nIl numero inserito deve essere positivo. \n\n");
			 }
		 	while (n2div < 1);	
		 	
			sdiv = n1div;
		 	
			do
	   		 {
		 	 	idiv ++;
		 		sdiv = sdiv - n2div;
		 	 }
		 	while (sdiv >= n2div);
		 	
		 	printf("\nLa differenza tra il PRIMO e il SECONDO numero e': ");
		 	printf("%d", idiv);
		 	printf("\nIl resto tra il PRIMO e il SECONDO numero e': ");
		 	printf("%d", sdiv);
		}
		
		system("cls");
		
		if(n = 3)
			do
	 		 {
			 
	 			printf("Inserire PRIMO numero: ");
				scanf ("%d", &nquad);
				
				if (nquad <= 0)
				printf("\n\nATTENZIONE! \nIl numero inserito deve essere positivo.\n\n");
			 }
		 	while (nquad < 1);
			 	
			do 
			 { 
				iquad = iquad + 2;
				ciclo ++;
				squad = squad + iquad;
			 }
			while (ciclo < nquad);
			
			printf("%d", squad);	
		
	}
	while(n < 1 || n > 4);
	
	return 0;	
}

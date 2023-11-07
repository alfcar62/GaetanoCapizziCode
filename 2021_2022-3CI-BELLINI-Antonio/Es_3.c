#include <stdio.h>
#include <stdlib.h>

int main() {
	int ore1, min1, sec1, secTot1;
	int ore2, min2, sec2, secTot2;
	int ore3, min3, sec3;
	int somma;
	int n=1;
	

	while(n==1){
	printf("Dimmi un valore le ore--> ");
	scanf("%d",&ore1);
	printf("Dimmi un valore per i minuti--> ");
	scanf("%d",&min1);
	printf("Dimmi un valore per i secondi-->");
	scanf("%d",&sec1);	
		
	ore1=ore1*3600;
	min1=min1*60;
	secTot1=ore1+min1+sec1;
				
	printf("Dimmi un secondo valore per le ore--> ");
	scanf("%d",&ore2);
	printf("Dimmi un secondo valore per i minuti--> ");
	scanf("%d",&min2);
	printf("Dimmi un secondo valore per i secondi--> ");
	scanf("%d",&sec2);	
		
	ore2=ore2*3600;
	min2=min2*60;
	secTot2=ore2+min2+sec2;	
	somma=secTot1+secTot2;
	
	ore3=somma/3600;
	min3=(somma-(ore3*3600))/60;
	sec3=(somma-(ore3*3600)-(min3*60));	
	
	printf("\n");
	printf("Il totale delle ore vale %d, dei minuti %d e dei secondi %d",ore3,min3,sec3);
	printf("\n");
	printf("Se vuoi continuare premi 1\n");
	scanf("%d",&n);
	}
		 
	return 0;
}

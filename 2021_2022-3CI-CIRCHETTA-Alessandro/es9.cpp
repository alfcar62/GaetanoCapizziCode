/*
ALLIEVO: Alessandro CIRCHETTA
DATA: 13/10/2021  
CLASSE: 3C INFORMATICA
TESTO: stampare i primi numeri dispari (da 0 a 10).
*/

#include <stdio.h>

	int main()
{
	int I = -1;
	
	do
	 {
		I = I + 2;
		printf ("%d \n", I);
	 }
	while (I < 9);
	return 0;
}

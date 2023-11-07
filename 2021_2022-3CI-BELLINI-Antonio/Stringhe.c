/*
Autore: Bellini Antonio
Data: 10/01/2022
Classe: 3C INFORMATICA
Prima prova di inizializzazione e utilizzo di una stringa
Una stringa � semplicemente un array ma per i caratteri. Un esempio di utilizzo di una stringa puo essere il registro scolastico, dove tutti i nomi degli alluni sono contenuti 
in stringhe separate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
	{
	 char arrS[5]={'C','I','A','O','\0'}; 	//Si puo inizizializzare lettera per lettera (ricordati di mettere il "null terminator" ovvero l'ultimo termine della stringa '\0').
	 int dim=sizeof(arrS);
	 int size=strlen(arrS);					//'strlen' � una funzione di C che indica la lunghezza di una stringa, ovvero i caratteri che contiene (es. arrS vale 4).
	 
	 printf("La dimensione di arrS vale %d",dim);
	 printf("\nLa lunghezza di arrS vale %d",size);

	 
	 return 0;
	}

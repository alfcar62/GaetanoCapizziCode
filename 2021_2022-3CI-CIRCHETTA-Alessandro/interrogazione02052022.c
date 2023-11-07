/**
ALUNNO: Domenico Savelli & Circhetta Alessandro & Adam Eloksch
DATA:   02/05/2022
CLASSE: 3C INFORMATICA
CONSEGNA: creare un programma che richiede in input una stringa dove vengono
		  inserite delle note musicali con uno spazio tra di loro. quando 
		  l'utente ha finito di inserire le note può stoppare inserendo $
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//funzione che conterà il numero di DO presenti nella stringa
int conta_do(char stringa[])
{
	int i 	 = 0,
		cont = 0;
//	printf("\n%s",stringa);
	for(i = 0; i<strlen(stringa); i++)
	{
		stringa[i]=toupper(stringa[i]);
		stringa[i+1]=toupper(stringa[i+1]);
	//printf("%c",stringa[i]);
//	printf("%c",stringa[i+1]);
		if(stringa[i] == 'D' && stringa[i+1] == 'O')
			cont++;
	}
//	printf("\n%s\n %d",stringa, cont);
	return cont;
}
//funzione che conta le note musicali
int conta_note(char stringa[])
{
	bool check_conta;
	check_conta=is_nota(stringa);
	int i = 0,
		cont = 0;
	for(i = 0; i<strlen(stringa); i++)
	{
	//printf("%c",stringa[i]);
//	printf("%c",stringa[i+1]);
		if(stringa[i] == ' ')
			cont++;
	}
//	printf("\n%s\n %d",stringa, cont);
	return cont+1;
}
//funzione che ritorna true se la stringa passata in input corrisponde ad una nota musicale, false altrimenti
bool is_nota(char stringa[])
{
	bool check=false
	if(stringa[0]=='D'&&stringa[1]=='O')
		check=true;
	if(stringa[0]=='R'&&stringa[1]=='E')
		check=true;
	if(stringa[0]=='F'&&stringa[1]=='A')
		check=true;
	if(stringa[0]=='S'&&stringa[1]=='O'&&stringa[2]=='L')
		check=true;
		
	return check;
}

int main()
{
	char spartito[30];
	int numeroDo;
	int n_note;
	printf("Inserisci le note Musicali di uno spartito-->");
	gets(spartito);
	numeroDo=conta_do(spartito);
	printf("Il numero di Do e':%d",numeroDo);
	n_note= conta_note(spartito);
	printf("\nIl numero delle note e':%d",n_note);
	 
}

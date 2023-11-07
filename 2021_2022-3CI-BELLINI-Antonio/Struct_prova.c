#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 20

typedef struct Person
{
	int matricola;
	int eta;
	float altezza;
	char nome[MAX_CHAR];
	char cognome[MAX_CHAR];
}Person;

int main(){
	Person p1;
	p1.matricola = 1;
	p1.eta = 16; 
	p1.altezza = 1.75;
	gets(p1.nome);
	puts(p1.nome);
	printf("%f \n\n", p1.altezza);
	Person p2;
	p2.matricola = 15;
	p2.eta = 16;
	p2.altezza = 1.63;
	p2.nome[0] = 'c';
	p2.nome[1] = 'i';
	p2.nome[2] = 'a';
	p2.nome[3] = 'o';
	p2.cognome[0] = 'P';
	puts(p2.nome);
	printf("%f ", p2.altezza);
	
}

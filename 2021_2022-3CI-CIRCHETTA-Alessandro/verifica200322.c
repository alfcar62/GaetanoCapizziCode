/**
ALUNNO:		Circhetta Alessandro
DATA:   	23/03/2022
CLASSE: 	3C INFORMATICA
CONSEGNA: 	Verifica Informatica laboratorio
**/

#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define MAX 201

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

//PROCEDURA DI INPUT DELLA STRINGA
void input(char stringa[MAX])
{
	printf("Digitare qui ---> ");
	gets(stringa);
}

// FUNZIONE PER CREAZIONE MENU' CON LE RISPETTIVE VOCI
int menu()
{
    int option;
    do
    {
    system("cls");
    printf("MENU CONTEGGIO \n");
    printf("\n1) conteggio caratteri totali\n");
    printf("\n2) conteggio caratteri totali senza spazi\n");
    printf("\n3)Conteggio numero consonanti e vocali \n");
    printf("\n4)conteggio numero parole inserite \n");
    printf("\n5)Calcolo Checksum (somma dei valori ascii) \n");
    printf("\n6) Uscita\n");


        printf("\nScegliere processo da eseguire -> ");
        scanf("%d", &option);
    } while (option < 1 || option > 6);
    return option;
}
//PROCEDURA PER IL CONTEGGIO DEI CARATTERI DOVE SI METTE NUM (VARIABILE IN CUI SI SALVERA' IL NUMERO) = AL COMANDO CHE CONTA I CARATTERI INSERITI NELLA STRINGA
void conteggio_caratteri(char stringa[])
{
	int num=0;
	num=strlen(stringa);
	
	printf("NUMERO CARATTERI--> %d", num);
}

// PROCEDURA PER CONTEGGIO CARATTERI ESCLUDENDO LO SPAZIO DOVE IL CICLO OGNI VOLTA INCREMENTA IL CONTATORE DEI CARATTERI TRANNE QUANDO IL CARATTERE HA VALORE 32 CIOE' E' UNO SPAZIO
void conteggio_caratteri_spazi_esclusi (char stringa[])
{
	int num = 0, i = 0;
	
	for(i = 0; i < strlen(stringa); i++)
	{
		if(stringa[i] != 32)
			num++;	
	}
	
	printf("NUMERO CARATTERI SPAZI ESCLUSI--> %d", num);
}

//PROCEDURA PER CONTEGGIO VOCALI E CONSONANTI DOVE DENTRO IL CLASSICO FOR C'E' IL COMANDO CHE RENDE TUTTE LE LETTERE MAIUSCOLE E POI SI HA UN IF PER CONTROLLARE CHE IL CARATTERE SIA PRIMA DI TUTTO UNA LETTERA E POI ANDANDO A ESCLUSIONE DELLE VOCALI SI INCREMENTA LA SEZIONE GIUSTA (VOCALI E CONSONANTI)
void conteggio_vocali_consonanti(char stringa[])
{
		int voc = 0, cons = 0, i = 0;
	
	for(i = 0; i < strlen(stringa); i++)
	{
		stringa[i]= toupper(stringa[i]);
		if(stringa[i]>=65 && stringa[i]<=90)
		{
			if(stringa[i] != 'A' && stringa[i] != 'E' && stringa[i] != 'I' && stringa[i] != 'O' && stringa[i] != 'U')
				cons++;	
			else
				voc++;		
		}
	}

	printf("\nNUMERO VOCALI--> %d\n", voc);	
	printf("\nNUMERO CONSONANTI--> %d\n", cons);	
}

//PROCEDURA PER IL CONTEGGIO DELLE PAROLE DOVE VENGONO SEMPLICEMENTE CONTATI GLI SPAZI GRAZIE AD UN FOR CON UN IF ALL'INTERNO E VI SI AGGIUNGE 1 PER RICEVERE IL NUMERO DI PAROLE TOTALI
void conteggio_parole(char stringa[])
{
	int space = 0, i = 0, num = 0;
		
	for(i = 0; i < strlen(stringa); i++)
	{
		if(stringa[i] == 32)
			space++;	
	}
	
	num = space + 1;
			
	printf("NUMERO PAROLE--> %d", num);	
}

//PROCEDURA PER LA SOMMA DEI VALORI ASCII DOVE SEMPLICEMENTE NEL FOR C'E' IL COMANDO CHE SOMMA OGNI VOLTA IL VALORE ASCII DEL CARATTERE INSERITO
void checksum(char stringa[])
{
	int tot = 0, i = 0;

	for(i = 0; i < strlen(stringa); i++)
		tot += stringa[i];	
		
	printf("CHECKSUM--> %d", tot);	
}
	
int main()
{
//INIZIALIZZAZIONE DELLA STRINGA E DELLE VARIE VARIABILI
	char caratteri[MAX];
    int risp, ans;

//RICHIAMO DELLA FUNZIONE PER INPUT DELLA STRINGA
    input(caratteri);
    
    do
    {

		// RICHIAMO IL MENU'
        ans = menu();

        switch (ans)
        {
        	//RICHIAMO PROCEDURA PER IL CONTEGGIO DEI CARATTERI
            case 1: { conteggio_caratteri(caratteri);   				} break;
            //RICHIAMO PROCEDURA PER CONTEGGIO CARATTERI ESCLUDENDO LO SPAZIO
            case 2: { conteggio_caratteri_spazi_esclusi(caratteri);     } break;
            //RICHIAMO PROCEDURA PER CONTEGGIO VOCALI E CONSONANTI
            case 3: { conteggio_vocali_consonanti(caratteri);     		} break;
            //RICHIAMO PROCEDURA PER IL CONTEGGIO DELLE PAROLE
            case 4: { conteggio_parole(caratteri);     			  		} break;
            //RICHIAMO PROCEDURA PER LA SOMMA DEI VALORI ASCII
            case 5: { checksum(caratteri);     							} break;
        };

        getchar();
        getchar();
    }while (ans != 6);
    
    

  
}

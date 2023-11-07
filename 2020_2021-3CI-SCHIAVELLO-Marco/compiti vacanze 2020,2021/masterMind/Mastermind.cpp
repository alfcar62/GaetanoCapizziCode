/*
    Marco Schiavello 3^CI 16/08/2021

    Scrivere un programma che realizzi il gioco del Master Mind. Bisogna indovinare in 10 tentativi
    un numero di 4 cifre pensato dal computer. Il numero in realtà sarà composto da 4 cifre singole
    contenute in un vettore di tipo int di 4 posizioni. Ad ogni tiro il computer risponde indicando quante
    cifre giuste al posto giusto e quante cifre giuste al posto sbagliato ci sono nel vostro numero.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <string.h>

#define LEN_MAX 100
#define CODE_LEN 4
#define MAX_ATTEMPTS 100

typedef struct
{
    int correct;
    int semiCorrect;
} solutions;

void arrayCpy(int arr[],int arr2[]);
bool printRes(int code[],solutions solutions);
solutions checkCodes(int code[],int secretCode[]);
void askInput(int code[]);
void clearArray(int arr[]);
void secretCodeGen(int secretCode[]);
void printBevenuto();
void spazzi(int nSpaz);
void linea();
void printArray(int arr[],int len);

/*_______Main_______*/
int main()
{

	srand(time(NULL));
	int code[CODE_LEN],secretCode[CODE_LEN],attempts = 0;
	solutions solutions;

    printBevenuto();

	spazzi(50);

	secretCodeGen(secretCode);

	do
	{
        askInput(code);

        solutions = checkCodes(code,secretCode);

		attempts++;
	}
	while(attempts < MAX_ATTEMPTS && !printRes(code,solutions));

	if(solutions.correct < CODE_LEN)
		printf("HAI PERSO \n\n");

	printf("la combinazione giusta era: ");
	printArray(secretCode,CODE_LEN);

	spazzi(4);

	getch();
}

/**
*   procedura che stampa i risultati del controllo ovvero gli indizzi
*   e il codice messo dal'utente
*   Parametri:
*       @param int code[]: input: codice dell'utente
*       @param solutions solutions: input: indizzi dalla comparazione dei due codici
*       @return bool : status code se ha finto prima dei tentativi dati
*/
bool printRes(int code[],solutions solutions)
{
    printArray(code,CODE_LEN);
    printf(" indizzi: %d giuste al posto giusto, %d giuste ma non al posto giusto",solutions.correct,solutions.semiCorrect);

    spazzi(3);
    linea();
    spazzi(3);

    if(solutions.correct == CODE_LEN)
    {
        printf("HAI VINTO \n\n");
        return true;
    }

    return false;
}

/**
*   funzione che compara e controlla i due codici per vedere
*   dove divergono e ritornare sulla base di questo gli indizzi
*   Parametri:
*       @param int code[]: input: codice dell'utente
*       @param int secretCode[]: input: codice segreto creato dal programma
*       @param solutions return: output: indizzi dalla comparazione dei due codici
*       @return void
*/
solutions checkCodes(int code[],int secretCode[])
{

    int tmpCode[CODE_LEN];
    solutions solutions;
    solutions.correct = 0;
    solutions.semiCorrect = 0;
    bool isEqual;

    arrayCpy(tmpCode,secretCode);

    for(int i=0;i<CODE_LEN;i++)
    {
        isEqual = false;

        for(int j=0;j<CODE_LEN && !isEqual;j++)
        {
            if(code[i] == tmpCode[j])
            {
                if(i==j)
                    solutions.correct++;
                else
                    solutions.semiCorrect++;

                isEqual = true;
                tmpCode[j] = -1;
            }
        }
    }

    return solutions;
}

/**
*   procedura che chiede l'input del utente
*   lo scompone nel codice e lo mette dentro l'array
*   Parametri:
*       @param int code[]: output: codice scomposto
*       @return void
*/
void askInput(int code[])
{
    int tmpCode;
    printf("cifre a disposizione : ");
    for(int i=0;i<10;i++)
        printf("%d;",i);

    spazzi(4);

    do
    {
        printf("mettere tua combinazione: ");
        scanf("%d",&tmpCode);
    }
    while(tmpCode > (pow(10,CODE_LEN)-1) || tmpCode < 0);

    printf("\n");

    for(int i = 0;i < CODE_LEN;i++)
    {
        code[(CODE_LEN-1)-i] = tmpCode % 10;
        tmpCode /= 10;
    }
}

/**
*   procedura che pulisce l'array
*   Parametri:
*       @param int arr[]: output: array da cancellare
*       @return void
*/
void clearArray(int arr[])
{
    for(int i=0;i<CODE_LEN;i++)
        arr[i]=0;
}

/**
*   procedura che crea il codice segreto del mistermind
*   avendo in come output un array passato come parametro
*   Parametri:
*       @param int secretCode[]: output: dove conserva il codice generato
*       @return void
*/
void secretCodeGen(int secretCode[])
{
	int digitCode;
	for(int i=0;i<CODE_LEN;i++)
	{
        digitCode = rand()%10;
		secretCode[i] = digitCode;
	}
}

/**
*   procedura che da il benvenuto all'utente
*   chiedendogli se vuole vedere il manuele di gioco
*   Parameti:
*       @return void
*/
void printBevenuto()
{
    char risposta[4];

	printf("Benvenuto sul gioco Mastermind \nvuoi leggere il manuale prima di iniziare rispondi si o no : ");
	scanf("%s",risposta);
	while(strcmp(risposta,"no") != 0 && strcmp(risposta,"si") != 0)
	{
		printf("mettere si o no : ");
		scanf("%s",risposta);
	}
	if(strcmp(risposta,"si") == 0)
	{
		spazzi(20);
		printf("Questo programma si basa su un gioco da tavolo chiamato 'Mastermind'\n");
		printf("dove c'e' un codificatore (in questo caso il programma) che crea un codice nascosto a chi deve cercare di indovinarte \n");
		printf("colui che cerca di indovinare ha 10 tentativi per indovinare la combinaziione nascosta se no perde\n");
		printf("in caso sbagliasse la conmbinazione gli verranno dati degli indizzi\n");
		printf("dove il 2 significa che un numero non specificato della combinazione e'esatto ed e' nella posizione giusta \n");
		printf("l'indizio con numero 1 indica che un numero non specificato e' giusto ma non nella posizione corretta \n");
		printf("\n\n\n\n PREMERE QUALSIASI TASTO PER INIZIARE A GIOCARE\n\n\n\n");

		getch();
	}
}

/**
*   stampa degli spazzi quanti passati dall'apposito parametro
*   Paramertri:
*       @param int nSpaz: input: numero di spazzi
*       @return void
*/
void spazzi(int nSpaz)
{
	for(int i=0;i<nSpaz;i++)
		printf("\n");
}

/**
*   stampa una linea
*   Paramertri:
*       @return void
*/
void linea()
{
	for(int i=0;i<70;i++)
		printf("-");
}

/**
*   stampa un array dato come parametro
*   Parameti:
*       @param int arr[]: input: aray da stampare
*       @param int len: input: lunghezza array
*       @return void
*/
void printArray(int arr[],int len)
{
    for(int i=0;i<len;i++)
		printf("%d",arr[i]);
}

/**
*   copia contenuto array2 in array
*   Parametro:
*       @param int arr[]: input: aray destinatario
*       @param int arr2[]: input: aray sorgente
*       @return void
*/
void arrayCpy(int arr[],int arr2[])
{
    for(int i = 0;i < CODE_LEN;i++)
        arr[i] = arr2[i];
}

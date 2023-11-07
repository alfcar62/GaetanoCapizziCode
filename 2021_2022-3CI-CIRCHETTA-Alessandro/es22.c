/**********************
ALUNNO: Alessandro CIRCHETTA & Jacopo BORDONI
DATA:   17/11/2021   
CLASSE: 3C INFORMATICA 
TESTO: ES 22 - AKINATOR
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void  gotoxy(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}


int main()
{
    int ind = 0;
    int num = 0;
    int aki = 0;
    srand (time(0));
    int cont = 0;
    int tent = 10;

		gotoxy(35, 1);
	printf("ES 22: AKINATOR\n");

	aki = rand()%10000;

	for(cont = 0; cont < 10; cont++)
	{
		printf("\n Indovina il numero a cui sto pensando! Ricordati pero' che hai solo %d tentativi!: \n", tent );
		scanf ("%d", &ind);
		tent--;
		
		if(aki == ind)
		{
			printf("\n Bravo! Hai indovinato! \n");
			cont = 10;
		}
		else
		{
			if (ind > aki) 
				printf("\n %d e' maggiore del numero a cui sto pensando\n", ind);
				
			else 
				printf("\n %d e' minore del numero a cui sto pensando\n", ind);
		}
	}
printf("\n Il numero a cui stavo pensando era: %d", aki);		
getch();

return 0;
}
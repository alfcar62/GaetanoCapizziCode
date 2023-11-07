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
    int n = 0;
    int ind = 0;
    int num = 0;
    int aki = 0;
    srand (time(0));
    int cont = 0;
    int tent = 10;

    do
    {
    	system("cls");
    	
        	gotoxy (35, 1);
		printf("ES 22: MENU'- AKINATOR, LUCI DI NATALE, ALBERO DI NATALE");
		
			gotoxy (15, 5);
		printf("1) AKINATOR");
		
			gotoxy (15, 6);
        printf("2) LUCI DI NATALE");
        
        	gotoxy (15, 7);
        printf("3) ALBERO DI NATALE");
        
        	gotoxy (15, 8);
        printf("4) ESCI");
        
        	gotoxy (20, 10);
        printf("SCEGLI: ");
        
        scanf ("%d", &n);

        system("cls");

        switch (n)
        {
        case 1:
        	
        	gotoxy (35, 1);
		printf("ES 22: MENU'- AKINATOR\n");
	
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
			break;
		
        case 2:
        	
        	gotoxy (35, 1);
		printf("ES 22: MENU'- LUCI DI NATALE");
  
        case 3: 
        
        	gotoxy (35, 1);
		printf("ES 22: MENU'- ALBERO DI NATALE");
 

            break;
        }
    }
    while (n < 1 || n > 4);

    return 0;
}
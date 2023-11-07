/**********************
ALUNNO: Alessandro CIRCHETTA
DATA:   24/11/2021   
CLASSE: 3C INFORMATICA 
TESTO: 
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void gotoxy (int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

int main ()
{
	int col = 0,
		 gg = 0,
		 mm = 0,
		 aa = 0;
		 

		do // controllo gg in mm
		{

			do //gg
			{
				system ("cls");
				gotoxy (35,1);
					printf("CONTROLLO FORMALE DI UNA DATA (anno 0 ->3000)");	//TITOLO
				
				gotoxy (0,2);
					printf("../../....");
				
				gotoxy (0,2);
					scanf("%d", &gg);
			}
			while(gg < 1 || gg > 31);
			
			do //mm
			{
				gotoxy (4,2);
					printf("../....");
				
				gotoxy (4,2);
					scanf("%d", &mm);
			}
			while(mm < 1 || mm > 12);

		}while(gg == 31 && (mm == 11 || mm == 4 || mm == 6 || mm == 9) || gg > 29 && mm == 2);

			do //aa
			{
				
				gotoxy (35,1);
				
				gotoxy (7,2);
					printf("....");
				
				gotoxy (7,2);
					scanf("%d", &aa);
					
			}while(aa < 0 || aa > 3000);	

// da fare controllo anno bisestile

	return 0;
}

/*
Autore: Bellini Antonio
Data: 15/12/2021
Classe: 3C INFORMATICA
Programma che genera casualmente delle "luci di natale" di colore diverso e in modo casuale sullo schermo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Void per comando GotoXY
void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

//Void per text color
typedef unsigned char color_t;
enum
{Black,Red,Green,Yellow,Blue,Magenta,Brown,Cyan,LightGray,Gray,LightRed,LightGreen,LightYellow,LightBlue,LightMagenta,LightCyan,White};
void textcolor(color_t fgcolor, color_t bgcolor)
{printf("\033[38;5;%dm\033[48;5;%dm",fgcolor, bgcolor);}

int main() 
	{
	 int x,y;
			 
			 system("cls");
		     srand(time(0));
			 do
			  {
	 		   x=rand()%100;	
	 		   y=rand()%100;
	 		   GotoXY(x,y);
	 		   textcolor(rand()%255,Black);
	 		   printf("*");
	 		   Sleep(150);
			  }while(!kbhit());	
	
	 
	 return 0;
	}

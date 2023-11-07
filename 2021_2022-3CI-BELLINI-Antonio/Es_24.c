/*
Autore: Bellini Antonio
Data: 15/12/2021
Classe: 3C INFORMATICA
Programma che crea sullo schermo un albero di Natale con le luci che cambiano colore.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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
	 system("cls");
			do
			 {	
			 	Sleep(250);
			 	//Linea 1 dell'albero
			 	textcolor(rand()%255,Black); 
			 	GotoXY(60,1);
			 	printf("*");
			 	//Linea 2 dell'albero
			 	textcolor(rand()%255,Black);
				GotoXY(59,2);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(60,2);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(61,2);
			 	printf("*");
			 	//linea 3 dell'albero
			 	textcolor(rand()%255,Black);
			 	GotoXY(58,3);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(59,3);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(60,3);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(61,3);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(62,3);
			 	printf("*");
			 	//Linea 4 dell'albero
			  	textcolor(rand()%255,Black);
			 	GotoXY(57,4);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(58,4);
			 	printf("*");
				textcolor(rand()%255,Black);
			 	GotoXY(59,4);
			 	printf("*");
				textcolor(rand()%255,Black);
			 	GotoXY(60,4);
			 	printf("*");
				textcolor(rand()%255,Black);
			 	GotoXY(61,4);
			 	printf("*");
				textcolor(rand()%255,Black);
			 	GotoXY(62,4);
			 	printf("*");
				textcolor(rand()%255,Black);
			 	GotoXY(63,4);
			 	printf("*");
			 	//Linea 5 dell'albero
			 	textcolor(rand()%255,Black);
			 	GotoXY(56,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(57,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(58,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(59,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(60,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(61,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(62,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(63,5);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(64,5);
			 	printf("*");
				//Linea 6 dell'albero
				textcolor(rand()%255,Black);
			 	GotoXY(55,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(56,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(57,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(58,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(59,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(60,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(61,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(62,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(63,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(64,6);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(65,6);
			 	printf("*");
			 	//Linea 7 dell'albero
			 	textcolor(rand()%255,Black);
			 	GotoXY(54,7);
			 	printf("*");
				textcolor(rand()%255,Black);
			 	GotoXY(54,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(55,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(56,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(57,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(58,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(59,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(60,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(61,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(62,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(63,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(64,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(65,7);
			 	printf("*");
			 	textcolor(rand()%255,Black);
			 	GotoXY(66,7);
			 	printf("*");
			 	//Tronco dell'albero
				textcolor(94,Black);//94 rappresenta il colore marrone.
			 	GotoXY(58,8);
			 	printf("*****");
			 	GotoXY(58,9);
			 	printf("*****");
			 	GotoXY(58,10);
			 	printf("*****");
			}while(!kbhit());
			 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 return 0;
	}

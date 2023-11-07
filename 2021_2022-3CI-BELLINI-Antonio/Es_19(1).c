/*
Autore: Bellini Antonio
Data: 10/11/2021
Classe: 3C INFORMATICA 
ScreenSaver verticale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define MAX 28

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main() 
	{
	 int riga=0,col=56;
	 
	 do
	{
	  do
	   {
	   	system("cls");
	    GotoXY(col,riga);
	    printf("Ciao");
	    Sleep(10);
	    riga++;
	   }while(!kbhit()&&riga<=MAX);
	   
	  do
	   {
	   	system("cls");
	    GotoXY(col,riga);
	    printf("Ciao");
	    Sleep(10);
	    riga--;
	   }while(!kbhit()&&riga>0);
	   
	   }while(!kbhit());
	 
	 return 0;
	}

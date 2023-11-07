/*
Autore: Bellini Antonio
Data: 10/11/2021
Classe: 3C INFORMATICA
ScreenSaver di prova numero 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define MAX 116

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main() 
	{
	 int col=0,riga=13;
	 system("cls");
	do
	{
	  do
	   {
	   	system("cls");
	    GotoXY(col,riga);
	    printf("Ciao");
	    Sleep(10);
	    col++;
	   }while(!kbhit()&&col<=MAX);
	   
	  do
	   {
	   	system("cls");
	    GotoXY(col,riga);
	    printf("Ciao");
	    Sleep(10);
	    col--;
	   }while(!kbhit()&&col>=0);
	   
	   }while(!kbhit());
	 
	 return 0;
	}

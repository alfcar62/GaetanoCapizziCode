/*
Autore: Bellini Antonio
Data: 10/11/2021
Classe: 3C INFORMATICA
ScreenSaver obliquo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define MAXCOL 117
#define MAXRIG 28
#define INC 4

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main() 
	{
	 int riga=MAXRIG/2, col=0;
	 
	 do
	{
	  do
	   {
	   	system("cls");
	    GotoXY(col,riga);
	    printf("Ciao");
	    Sleep(100);
	    riga--;
	    col+=INC;
	
	   }while(!kbhit()&&riga>0);
	
	  do
	   {
	   	system("cls");
	    GotoXY(col,riga);
	    printf("Ciao");
	    Sleep(100);
	    riga++;
	    col+=INC;
	   }while(!kbhit()&&riga<MAXRIG/2);
	   
	   do
	    {
	     system("cls");
	     GotoXY(col,riga);
	     printf("Ciao");
	     Sleep(100);
	     riga++;
	     col-=INC;
		}while(!kbhit()&&riga<MAXRIG);
	
		do
	    {
	     system("cls");
	     GotoXY(col,riga);
	     printf("Ciao");
	     Sleep(100);
	     riga--;
	     col-=INC;
		}while(!kbhit()&&riga>MAXRIG/2);
		
	}while(!kbhit());
		
	 
	 return 0;
	}

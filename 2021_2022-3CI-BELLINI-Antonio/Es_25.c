/*
Autore: Bellini Antonio
Data: 17/12/2021
Classe: 3C INFORMATICA
Programma che fornisce tutti i caratteri della tabella ascii.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);}

int main() 
	{
	 int numero=0, carattere=0,x=5;
	 
	 GotoXY(50,1);
	 printf("Tabella caratteri ASCII");
	 do
	  {
	  	printf("%d) %c\n",numero,carattere);
	  	printf("\n");
	  	numero++;
	  	carattere++;
	  	x++;
	  }while(numero<256);
	  

	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 return 0;
	}

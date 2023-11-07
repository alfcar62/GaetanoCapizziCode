/**********************
ALUNNO: Alessandro CIRCHETTA 
DATA:   17/11/2021   
CLASSE: 3C INFORMATICA 
TESTO:  TABELLA ASCII
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void  gotoxy(int x, int  y) 
    {
        COORD CursorPos = {x, y};
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsole, CursorPos);
    }


int main()
{
  int i = 0;

  gotoxy(35, 1);
    printf("\nES 25: TABELLA ASCII\n");    

  printf("VALORE\tCARATTERE\n");

  for (i = 32; i < 128; i++) {
      printf("%d\t%c\n", i, i);
  }

    return 0;
}

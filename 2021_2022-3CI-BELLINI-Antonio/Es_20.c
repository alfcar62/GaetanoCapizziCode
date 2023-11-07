/*
Autore: Bellini Antonio
Data: 17/11/2021
Classe: 3C INFORMATICA
Programma che esegue il controllo formale di una data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main() 
	{
	 int X,Y,day,month,year;
	 
	//Controllo day>31
	do
	{
    //Inserimento e controllo dei giorni
	 do
	  {
	   system("cls");
	   GotoXY(54,1);
	   printf("Benvenuto!");
	   GotoXY(50,3);
	   printf("Inserisci una data");
	   GotoXY(52,5);
	   printf("Day/Month/Year");
	   GotoXY(54,7);
	   printf("../../....");
	   GotoXY(54,7);
	   scanf("%d",&day);
	  }while(day<1||day>31);	  
	
	//Inserimento e controllo month
	 do
	  {
	   system("cls");
	   GotoXY(54,1);
	   printf("Benvenuto!");
	   GotoXY(50,3);
	   printf("Inserisci una data");
	   GotoXY(52,5);
	   printf("Day/Month/Year");
	   GotoXY(54,7);
	   printf("%d/../....",day,month);
	   GotoXY(57,7);
	   scanf("%d",&month);
	  }while(month<1||month>12);
	}while ((day>30&&month==4)||
	  		(day>30&&month==6)||
	  		(day>30&&month==9)||
	  		(day>30&&month==11));
	 
	//Controllo day se month=2
	  while(day>29&&month==2)	   
	   {
	    system("cls");
	    GotoXY(54,1);
	    printf("Benvenuto!");
	    GotoXY(50,3);
	    printf("Inserisci una data");
	    GotoXY(52,5);
	    printf("Day/Month/Year");
	    GotoXY(54,7);
	    printf("%d/%d/....",day,month);
	    scanf("%d",&day);
	    GotoXY(59,7);
	    scanf("%d",&month);
	   };
	  
	//Inseriemento e controllo anno 
	 do
	  {
	   	system("cls");
	    GotoXY(54,1);
	    printf("Benvenuto!");
	    GotoXY(50,3);
	    printf("Inserisci una data");
	    GotoXY(52,5);
	    printf("Day/Month/Year");
	    GotoXY(54,7);
	    printf("%d/%d/....",day,month);
	   	  if(month<10)
	  	   {	
		 	GotoXY(59,7);
			scanf("%d",&year);
		   }
		  else
		   {
		  	GotoXY(60,7);
		  	scanf("%d",&year);
		   }  
	  }while(year<1||year>5000);
	  
	//Controllo if year � bisestile  
	  while((day==29&&month==2&&(year%4==1))||(day==29&&month==2&&(year%100==1))||(day==29&&month==2&&(year%400==1)))
	   {
	    system("cls");
	    GotoXY(54,1);
	    printf("Benvenuto!");
	    GotoXY(50,3);
	    printf("Inserisci una data");
	    GotoXY(52,5);
	    printf("Day/Month/Year");
	    GotoXY(54,7);
	    printf("%d/%d/....",day,month);
	    if(month<10)
	  	   {	
		 	GotoXY(59,7);
			scanf("%d",&year);
		   }
		  else
		   {
		  	GotoXY(60,7);
		  	scanf("%d",&year);
		   }  
	   }
			
	   
	    
	 return 0;
	}

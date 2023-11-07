/*
Autore: Bellini Antonio
Data: 10/11/2021
Classe: 3C INFORMATICA
Unione dello ScreenSaver con scritto "ciao" orizzontalmente, verticalmente, e in obliquo. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define MAXCOL 115
#define MAXRIG 28
#define INC 4

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int main() 
	{
	 int A,scelta;
	 menu:
	 GotoXY(52,2);
	 printf("Benvenuto!");
	 GotoXY(40,5);
	 printf("Quale ScreenSaver vuoi eseguire?\n");
	 GotoXY(23,9);
	 printf("1= ScreenSaver numero 1 - scritta ciao che si muove orizzontalmente\n");
	 GotoXY(24,12);
	 printf("2= ScreenSaver numero 2 - scritta ciao che si muove verticalmente\n");
	 GotoXY(25,15);
	 printf("3= ScreenSaver numero 3 - scritta ciao che si muove in obliquo\n");
	 GotoXY(46,18);
	 printf("4= esci dal programma");
	 GotoXY(52,21);
	 printf("Scelta-->");
	 scanf("%d",&A);
	do
	{ 
	 switch(A)
	 {
	 	//ScreenSaver orizzontale.
	 	case 1:
	 	 {
	 	 	int col=0,riga=MAXRIG/2;
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
	   		   }while(!kbhit()&&col<=MAXCOL);
	   
	  		 do
	   		  {
	   		   system("cls");
	    	   GotoXY(col,riga);
	    	   printf("Ciao");
	    	   Sleep(10);
	    	   col--;
	   		  }while(!kbhit()&&col>=0);
	   
			}while(!kbhit());
		 
		 }break;
		 
		 //ScreenSaver verticale.
		 case 2:
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
	   		   }while(!kbhit()&&riga<=MAXRIG);
	   
	  		 do
	   		  {
	   		   system("cls");
	    	   GotoXY(col,riga);
	           printf("Ciao");
	           Sleep(10);
	           riga--;
	   		  }while(!kbhit()&&riga>0);
	   
	   		}while(!kbhit());
		 
		 }break;
		 
		 //ScreenSaver obliquo.
		 case 3:
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
		 
		 }break;
	 
	 }
	 system("cls");
	 GotoXY(39,2);
	 printf("Vuoi eseguire un altro ScreenSaver?");
	 GotoXY(46,5);
	 printf("Premi 1 se SI\n");
	 GotoXY(46,7);
	 printf("Premi 0 se NO\n");
	 GotoXY(48,9);
	 printf("Scelta-->");
	 GotoXY(57,9);
	 scanf("%d",&scelta);
	 system("cls");
	 	if(scelta==1)
	 		goto menu;
	}while(scelta==1);
	
	 return 0;
	}

#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>   //contiene la funzione getch
//#include<conio2.h>  contiene la funzione gotoxy
//#include<iostream>  contiene le funzioni cin>> e cout<< del C++


int main()
{
 float X, Y;
 int Q;

 system("cls");
 printf("Individuazione quadrante punto (X,Y)\n");

 do{
    printf("\nInserisci la coordinata X del punto (X diverso da 0) --> ");
    scanf("%f", &X);
 }while(X==0);

 do{
    printf("\nInserisci la coordinata Y del punto (Y diverso da 0) --> ");
    scanf("%f", &Y);
 }while(Y==0);

 if(X>0 && Y>0){
   Q = 1;
  }
  else if(X < 0 && Y > 0){
    Q = 2;
  }
  else if(X < 0 && Y < 0){
    Q = 3;
  }
  else{
    Q = 4;
  }

 printf("\nIl punto di coordinate\n\n X=%7.1f e Y=%7.1f", X, Y);
 printf("\n\nsi trova nel %d^ Quadrante", Q);

 getch();
}

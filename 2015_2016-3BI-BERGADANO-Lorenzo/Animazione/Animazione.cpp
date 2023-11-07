#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<iostream>

int c,r;//indicano le colonne e le righe nelle quali si dovrà muovere la scritta
int const tempo = 50;//il tempo da aspettare (millisecondi)
int scelta;//serve per capire la scelta dell'utente
int colore;

void orizzontale(){
     do{
       c = 1;
       r = 1;
       colore = 1;
       
        do{
        if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
        system("CLS");
        gotoxy(c,r);
        printf("CIAO");
        c = c + 1;
        Sleep(tempo);
        }while(c < 77);
        
        do{
           if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
           system("CLS");
           gotoxy(c,r);
           printf("CIAO");
           c = c - 1;
           Sleep(tempo);
        }while(c > 1);
    }while(!kbhit());
    getch();
}


void verticale(){
     do{ //ALTO - BASSO
        c = 38;
        r = 1;
        colore = 1;
        
       do{
          if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
          system("CLS");
          gotoxy(c,r);
          printf("CIAO");
          r = r + 1;
          Sleep(tempo);
       }while(r < 24);
       
       do{
          if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
          system("CLS");
          gotoxy(c,r);
          printf("CIAO");
          r = r - 1;
          Sleep(tempo);
       }while(r > 1);
    }while(!kbhit());
    getch();
}

void diagonale(){
     do{ //45 gradi
    
        c = 40;
        r = 1;
        colore = 1;
        
        do{
           if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
           system("CLS");
           gotoxy(c,r);
           printf("CIAO");
           c = c + 3;
           r = r + 1;
           Sleep(tempo);
        }while(c < 76);
        
        do{
           if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
           system("CLS");
           gotoxy(c,r);
           printf("CIAO");
           c = c - 3;
           r++;
           Sleep(tempo);
        }while(r <= 24);
        
        do{
           if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
           system("CLS");
           gotoxy(c,r);
           printf("CIAO");
           c = c - 3;
           r--;
           Sleep(tempo);
        }while(c > 1);
        
        do{
           if(colore < 15){
                  textcolor(colore);
                  colore++;
        }
        else if(colore == 15){
             textcolor(colore);
             colore = 1;
        }
           system("CLS");
           gotoxy(c,r);
           printf("CIAO");
           c = c + 3;
           r--;
           Sleep(tempo);
        }while(r > 1);
    }while(!kbhit());
    
    getch();
}

int main(){
do{  
    do{
       system("CLS");
       system("color F");
       gotoxy(13,1);
       printf("ANIMAZIONE PAROLA:");
       gotoxy(8,2);
       printf("1 - Movimento Orizzontale");
       gotoxy(8,3);
       printf("2 - Movimento Verticale");
       gotoxy(8,4);
       printf("3 - Movimento Diagonale");
       gotoxy(8,5);
       printf("4 - Esci");
       gotoxy(19,7);
       printf("SCEGLI .");
       gotoxy(26,7);
       scanf("%d",&scelta);
    }while(scelta < 1 || scelta > 4);
    
    switch(scelta){
                   case 1:{
                        orizzontale();
                   }break;
                   case 2:{
                        verticale();
                   }break;
                   case 3:{
                        diagonale();
                   }break;
                   case 4:{
                   }break;
    }
}while(scelta != 4);
}

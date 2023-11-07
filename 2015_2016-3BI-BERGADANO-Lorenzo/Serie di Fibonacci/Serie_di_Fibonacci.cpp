#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>

int movimento,posizione;//variabili per MENU 2.0
int scelta;

void inizio(){
     do{
        system("CLS");
        textcolor(15);
        gotoxy(20,1);
        printf("PROGRAMMA SERIE DI FIBONACCI\n\n");
        gotoxy(19,3);
        textbackground(15);
        textcolor(0);
        printf("> Calcola N termini della seria di Fibonacci");
        gotoxy(19,4);
        textbackground(0);
        textcolor(15);
        printf("  Calcola i termini della serie di Fibonacci entro un valore X");
        
        movimento = getch();
     }while(movimento != 13 && movimento != 75 && movimento != 77);
     
}

void istruzioni(){
     system("CLS");
     textcolor(15);
     gotoxy(20,1);
     printf("PROGRAMMA SERIE DI FIBONACCI\n\n");
     
}

int main(){
    
    posizione = 1;
    do{
       system("CLS");
       textcolor(15);
       gotoxy(20,1);
       printf("PROGRAMMA SERIE DI FIBONACCI");
       gotoxy(20,3);
       textbackground(15);
       textcolor(0);
       printf("> INIZIA");
       gotoxy(20,4);
       textbackground(0);
       textcolor(15);
       printf("  ISTRUZIONI");
       gotoxy(20,5);
       textbackground(0);
       textcolor(15);
       printf("  ESCI");
       
       movimento = getch();
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    do{
    movimento = getch();
    switch(movimento){
                      
                      case 72:{
                           if(posizione == 2){
                                        posizione = 1;
                                        gotoxy(20,3);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> INIZIO");
                                        gotoxy(20,4);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ISTRUZIONI");
                                        gotoxy(20,5);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ESCI");
                           }
                           else if(posizione == 3){
                                posizione = 2;
                                gotoxy(20,3);
                                textbackground(0);
                                textcolor(15);
                                printf("  INIZIO");
                                gotoxy(20,4);
                                textbackground(15);
                                textcolor(0);
                                printf("> ISTRUZIONI");
                                gotoxy(20,5);
                                textbackground(0);
                                textcolor(15);
                                printf("  ESCI");
                           }
                           else{
                                posizione = posizione;
                           }
                      }break;
                      case 80:{
                           if(posizione == 1){
                                        posizione = 2;
                                        
                                        gotoxy(20,3);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  INIZIO");
                                        gotoxy(20,4);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> ISTRUZIONI");
                                        gotoxy(20,5);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ESCI");
                           }
                           else if(posizione == 2){
                                posizione = 3;
                                
                                gotoxy(20,3);
                                textbackground(0);
                                textcolor(15);
                                printf("  INIZIO");
                                gotoxy(20,4);
                                textbackground(0);
                                textcolor(15);
                                printf("  ISTRUZIONI");
                                gotoxy(20,5);
                                textbackground(15);
                                textcolor(0);
                                printf("> ESCI");
                           }
                           else{
                                posizione = posizione;
                           }
                      }break;
                      case 13:{
                           if(posizione == 3){
                              scelta = 3;          
                           }
                           else if(posizione == 1){
                                inizio();
                           }
                           else if(posizione == 2){
                                istruzioni();
                           }
                      }
    }
}while(scelta != 3);
}

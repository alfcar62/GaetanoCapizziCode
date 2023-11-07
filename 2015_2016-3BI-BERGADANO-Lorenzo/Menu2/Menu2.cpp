#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>

int main(){
    int movimento,posizione;
    
    posizione = 1;
    do{
       system("CLS");
       gotoxy(20,1);
       textbackground(15);
       textcolor(0);
       printf("> CIAO");
       gotoxy(20,2);
       textbackground(0);
       textcolor(15);
       printf("  ESCI");
       
       movimento = getch();
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU
    
    do{
    movimento = getch();
    switch(movimento){
                      
                      case 72:{
                           if(posizione == 2){
                                       posizione = 1;
                                        gotoxy(20,1);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> CIAO");
                                        gotoxy(20,2);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ESCI");
                           }
                           else{
                                posizione = 2;
                           }
                      }break;
                      case 80:{
                           if(posizione == 1){
                                        posizione = 2;
                                        gotoxy(20,1);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  CIAO");
                                        gotoxy(20,2);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> ESCI");
                           }
                           else{
                                posizione = 1;
                           }
                      }break;
                      case 13:{
                           if(posizione == 2){
                              movimento = 13;          
                           }
                           else{
                                movimento = 1;
                           }
                      }
    }
}while(movimento != 13);
}

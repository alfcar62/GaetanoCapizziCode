#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<time.h>

int main(){
    int carattere,riga;
    
    do{
       system("CLS");
       gotoxy(35,1);
       textcolor(12);
       printf("TABELLA ASCII");
       
       carattere = 1;
       riga = 2;
       
       do{
          if(carattere <= 23){
                       gotoxy(1,riga);
                       textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       
                       if(riga == 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 46){
               gotoxy(8,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
               if(riga == 24){
                       riga = 2;
               }
               else{
                    riga++;
               }
          }
          else if(carattere <= 69){
               gotoxy(14,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
       
                       if(riga == 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 92){
               gotoxy(20,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
               
                       if(riga == 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 115){
               gotoxy(26,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);;
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 138){
               gotoxy(32,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 161){
               gotoxy(38,riga);
              textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 184){
               gotoxy(44,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 207){
               gotoxy(50,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 230){
               gotoxy(56,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 253){
               gotoxy(62,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          else if(carattere <= 255){
               gotoxy(68,riga);
               textcolor(14);
                       printf("%d:",carattere);
                       textcolor(15);
                       printf("%c\n",carattere);
                       if(riga >= 24){
                               riga = 2;
                       }
                       else{
                             riga++;
                       }
          }
          
          carattere++;
       }while(carattere <= 255);
       getch();
    }while(!kbhit);
}

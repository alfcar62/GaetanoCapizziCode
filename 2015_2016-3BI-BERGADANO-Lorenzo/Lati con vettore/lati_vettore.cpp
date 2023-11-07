#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<conio2.h>

char risp;
float lato[30],area[30],perimetro[30];
int i,scelta,movimento,n,y;
bool lc,flag,flag2,ac,pc;

void visualizza(){
     system("CLS");
     if(lc == true && pc == true && ac == true){
           y = 3;
           gotoxy(10,y);
           textcolor(12);
           printf("LATO");
           textcolor(15);
           for(i = 0;i < n;i++){
                 y++;
                 gotoxy(12,y);
                 printf("%3.2f",lato[i]);
           }
           y = 3;
           gotoxy(20,y);
           textcolor(12);
           printf("AREA");
           textcolor(15);
           for(i = 0;i < n;i++){
                 y++;
                 gotoxy(22,y);
                 printf("%3.2f",area[i]);
           }
           y = 3;
           gotoxy(30,y);
           textcolor(12);
           printf("PERIMETRO");
           textcolor(15);
           for(i = 0;i < n;i++){
                 y++;
                 gotoxy(33,y);
                 printf("%3.2f",perimetro[i]);
           }
           
     }
     else{
          printf("Impossibile visualizzare i vettori.");
     }
     getch();
}

void cperimetro(){
     system("CLS");
     if(lc == true){
           for(i = 0;i < n;i++){
                 perimetro[i] = lato[i] * 4;
           }
           printf("Perimetro Calcolato con successo!");
     }
     else{
          printf("Impossibile calcolare il perimetro. Nessun lato caricato");
     }
     pc = true;
     getch();
}

void carea(){
     system("CLS");
     if(lc == true){
           for(i = 0;i < n;i++){
                 area[i] = lato[i] * lato[i];
           }
           printf("Area Calcolata con successo!");
     }
     else{
          printf("Impossibile calcolare l'area. Nessun lato caricato");
     }
     ac = true;
     getch();
}

void carica(){
     system("CLS");
     do{
        printf("Quanti lati vuoi inserire? ");
        scanf("%d",&n);
     }while(n <= 0 || n > 30);
     
     for(i = 0;i < n;i++){
           printf("\nInserisci le dimensioni del lato numero %d: ",i+1);
           scanf("%f",&lato[i]);
     }
     lc = true;
}

int main(){
    do{//inizio ripetizione
    system("CLS");
    gotoxy(17,4);
    textcolor(12);
    printf("CALCOLO AREA E PERIMETRO DI UN QUADRATO");
    textcolor(15);
    do{//menu
         gotoxy(20,7);
         textbackground(15);
         textcolor(0);
         printf("> Carica Lati");
         gotoxy(20,9);
         textbackground(0);
         textcolor(15);
         printf("  Calcola Area");
         gotoxy(20,11);
         textbackground(0);
         textcolor(15);
         printf("  Calcola Perimetro");
         gotoxy(20,13);
         textbackground(0);
         textcolor(15);
         printf("  Visualizza Vettori");
         gotoxy(20,15);
         textbackground(0);
         textcolor(15);
         printf("  Esci");

    movimento = getch();
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    scelta = 1;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        gotoxy(20,7);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Carica Lati");
                                   gotoxy(20,9);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 4){
                                   scelta = 3;
                                   gotoxy(20,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 5){
                                   scelta = 4;
                                   gotoxy(20,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else{
                                   scelta = scelta;
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        gotoxy(20,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   gotoxy(20,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 3){
                                   scelta = 4;
                                   gotoxy(20,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 4){
                                   scelta = 5;
                                   gotoxy(20,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Carica Lati");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Area");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcola Perimetro");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizza Vettori");
                                        gotoxy(20,15);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Esci");
                              }
                              else{
                                   scelta = scelta;
                              }
                         }break;
                         case 13:{
                              if(scelta == 1){
                                        carica();
                                        flag2 = true;
                              }
                              else if(scelta == 2){
                                   carea();
                                   flag2 = true;
                              }
                              else if(scelta == 3){
                                   cperimetro();
                                   flag2 = true;
                              }
                              else if(scelta == 4){
                                   visualizza();
                                   flag2 = true;
                              }
                              else{
                                   textcolor(15);
                                   textbackground(0);
                                   do{
                                      system("CLS");
                                      printf("\n\nVuoi veramente uscire? (s/n)");
                                      fflush(stdin);
                                      scanf("%c",&risp);
                                   }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
                                   
                                   if(risp == 'N'|| risp == 'n'){
                                           scelta = 0;
                                   }
                                   else{
                                        scelta = 5;
                                   }
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 5 && flag2 == false);
    }while(scelta != 5);
    
}

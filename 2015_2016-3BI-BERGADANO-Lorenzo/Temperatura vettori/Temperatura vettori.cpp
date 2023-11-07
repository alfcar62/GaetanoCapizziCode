#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<conio2.h>

char risp;
int const n = 5;
float t[n],max,min,media = 0;
int i,scelta,movimento,orario;
bool tc,flag,flag2;

void tmedia(){
     system("CLS");
     if(tc == true){
           for(i = 0;i < n;i++){
                 media = media + t[i];
           }
           media = media / n;
           printf("La temperatura media giornaliera e' di %3.2f gradi",media);
     }
     else{
          printf("Impossibile ricercare temperature perche' non sono presenti");
     }
     getch();
}

void massima(){
     system("CLS");
     if(tc == true){
           max = t[0];
           for(i = 1;i < n;i++){
                 if(t[i] > max){
                        max = t[i];
                 }
           }
           printf("Il valore massimo caricato e' di %3.2f gradi",max);
     }
     else{
          printf("Impossibile ricercare temperature perche' non sono presenti");
     }
     getch();
}

void minima(){
     system("CLS");
     if(tc == true){
           min = t[0];
           for(i = 1;i < n;i++){
                 if(t[i] < min){
                        min = t[i];
                 }
           }
           printf("Il valore minimo caricato e' di %3.2f gradi",min);
     }
     else{
          printf("Impossibile ricercare temperature perche' non sono presenti");
     }
     getch();
}

void ricerca(){
     system("CLS");
     if(tc == true){
           do{
           printf("Inserisci orario: ");
           scanf("%d",&orario);
           }while(orario < 0 || orario > 23);
     
           if(orario < 10){
                     printf("\n\nLa temperatura alle ore 0%d:00 e' di %3.2f gradi",orario,t[orario]);
           }
           else{
                printf("\n\nLa temperatura alle ore %d:00 e' di %3.2f gradi",orario,t[orario]);
           }
     }
     else{
          printf("Impossibile ricercare temperature perche' non sono presenti");
     }
     
     getch();
}


void visualizza(){
     system("CLS");
     if(tc == true){
           for(i = 0;i < n;i++){
                 if(i < 10){
                      printf("\n\nLa tamperatura alle ore 0%d:00 e' di %3.2f gradi",i,t[i]);
                 }
                 else{
                      printf("\n\nLa tamperatura alle ore %d:00 e' di %3.2f gradi",i,t[i]);
                 }
           }
     }
     else{
          printf("Impossibile caricare le temperature");
     }
     getch();
}

void carica(){
     system("CLS");
     for(i = 0;i < n;i++){
           if(i < 10){
                printf("\nInserisci la temperatura delle ore 0%d:00 = ",i);
           }
           else{
                printf("\nInserisci la temperatura delle ore %d:00 = ",i);
           }
           scanf("%f",&t[i]);
     }
     tc = true;
}

void menu(){
     do{//menu
         gotoxy(20,7);
         textbackground(15);
         textcolor(0);
         printf("> Caricamento Temperature");
         gotoxy(20,9);
         textbackground(0);
         textcolor(15);
         printf("  Visualizzazione Temperature");
         gotoxy(20,11);
         textbackground(0);
         textcolor(15);
         printf("  Ricerca per orario");
         gotoxy(20,13);
         textbackground(0);
         textcolor(15);
         printf("  Temperatura minima");
         gotoxy(20,15);
         textbackground(0);
         textcolor(15);
         printf("  Temperatura massima");
         gotoxy(20,17);
         textbackground(0);
         textcolor(15);
         printf("  Calcolo Temperatura media del giorno");
         gotoxy(20,19);
         textbackground(0);
         textcolor(15);
         printf("  Esci");

    movimento = getch();
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    scelta = 1;
}

int main(){
    do{//inizio ripetizione
    system("CLS");
    gotoxy(25,3);
    textcolor(10);
    printf("CALCOLO TEMPERATURE");
    textcolor(15);
    
    menu();
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
                                        printf("> Caricamento Temperature");
                                        gotoxy(20,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Visualizzazione Temperature");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Ricerca per orario");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Temperatura minima");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Temperatura massima");
                                        gotoxy(20,17);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcolo Temperatura media del giorno");
                                        gotoxy(20,19);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 4){
                                   scelta = 3;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 5){
                                   scelta = 4;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 6){
                                   scelta = 5;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 7){
                                   scelta = 6;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
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
                                        printf("  Caricamento Temperature");
                                        gotoxy(20,9);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Visualizzazione Temperature");
                                        gotoxy(20,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Ricerca per orario");
                                        gotoxy(20,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Temperatura minima");
                                        gotoxy(20,15);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Temperatura massima");
                                        gotoxy(20,17);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Calcolo Temperatura media del giorno");
                                        gotoxy(20,19);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  Esci");
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 3){
                                   scelta = 4;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 4){
                                   scelta = 5;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 5){
                                   scelta = 6;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Esci");
                              }
                              else if(scelta == 6){
                                   scelta = 7;
                                   gotoxy(20,7);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Caricamento Temperature");
                                   gotoxy(20,9);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Visualizzazione Temperature");
                                   gotoxy(20,11);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Ricerca per orario");
                                   gotoxy(20,13);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura minima");
                                   gotoxy(20,15);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Temperatura massima");
                                   gotoxy(20,17);
                                   textbackground(0);
                                   textcolor(15);
                                   printf("  Calcolo Temperatura media del giorno");
                                   gotoxy(20,19);
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
                                   visualizza();
                                   flag2 = true;
                              }
                              else if(scelta == 3){
                                   ricerca();
                                   flag2 = true;
                              }
                              else if(scelta == 4){
                                   minima();
                                   flag2 = true;
                              }
                              else if(scelta == 5){
                                   massima();
                                   flag2 = true;
                              }
                              else if(scelta == 6){
                                   tmedia();
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
                                        scelta = 8;
                                   }
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 8 && flag2 == false);
    }while(scelta != 8);
    
}

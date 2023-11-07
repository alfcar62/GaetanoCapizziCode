#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>

int main(){
    int m,c,d,u,n,calcolo,resto,risp;

    do{//INIZIO RIPETIZIONE
    do{
       system("CLS");
       system("color F0");
       gotoxy(23,2);
       printf("TRASFORMAZIONE DA NUMERO A LETTERE");
       gotoxy(20,4);
       printf("Inserisci il numero (da 1 a 10000): ");
       scanf("%d",&n);
    }while(n < 1 || n > 10000);
    
    if(n < 10){
         u = n;
         d = 0;
         c = 0;
         m = 0;
    }
    else if(n < 100){
         calcolo = n / 10;
         resto = n % 10;
         d = calcolo;
         u = resto;
         c = 0;
         m = 0;
    }
    else if(n < 1000){
         calcolo = n / 100;
         resto = n % 100;
         c = calcolo;
         d = resto / 10;
         u = resto % 10;
         m = 0;
    }
    else if(n < 10000){
         calcolo = n / 1000;
         resto = n % 1000;
         m = calcolo;
         c = resto / 100;
         d = (resto - (c * 100)) / 10 ;
         u = (resto - (c * 100)) % 10;
    }
    else{
         printf("DICIMILA");
    }
    
    gotoxy(23,6);
    switch(m){
              case 1:{
                   printf("MILLE");
              }break;
              case 2:{
                   printf("DUEMILA");
              }break;
              case 3:{
                   printf("TREMILA");
              }break;
              case 4:{
                   printf("QUATTROMILA");
              }break;
              case 5:{
                   printf("CINQUEMILA");
              }break;
              case 6:{
                   printf("SEIMILA");
              }break;
              case 7:{
                   printf("SETTEMILA");
              }break;
              case 8:{
                   printf("OTTOMILA");
              }break;
              case 9:{
                   printf("NOVEMILA");
              }break;
    }
    
    switch(c){
              case 1:{
                   printf("CENTO");
              }break;
              case 2:{
                   printf("DUECENTO");
              }break;
              case 3:{
                   printf("TRECENTO");
              }break;
              case 4:{
                   printf("QUATTROCENTO");
              }break;
              case 5:{
                   printf("CINQUECENTO");
              }break;
              case 6:{
                   printf("SEICENTO");
              }break;
              case 7:{
                   printf("SETTECENTO");
              }break;
              case 8:{
                   printf("OTTOCENTO");
              }break;
              case 9:{
                   printf("NOVECENTO");
              }break;
    }
    
    switch(d){
              case 1:{
                   if(u == 0){
                        printf("DIECI");     
                   }
                   else if(u == 1){
                        printf("UNDICI");
                   }
                   else if(u == 2){
                        printf("DODICI");
                   }
                   else if(u == 3){
                        printf("TREDICI");
                   }
                   else if(u == 4){
                        printf("QUATTORDICI");
                   }
                   else if(u == 5){
                        printf("QUINDICI");
                   }
                   else if(u == 6){
                        printf("SEDICI");
                   }
                   else if(u == 7){
                        printf("DICIASETTE");
                   }
                   else if(u == 8){
                        printf("DICIOTTO");
                   }
                   else{
                        printf("DICIANNOVE");
                   }
              }break;
              case 2:{
                   if(u == 1 || u == 8 ){
                        printf("VENT");
                   }
                   else{
                        printf("VENTI");
                   }
              }break;
              case 3:{
                   if(u == 1 || u == 8 ){
                        printf("TRENT");
                   }
                   else{
                        printf("TRENTA");
                   }
              }break;
              case 4:{
                   if(u == 1 || u == 8 ){
                        printf("QUARANT");
                   }
                   else{
                        printf("QUARANTA");
                   }
              }break;
              case 5:{
                   if(u == 1 || u == 8 ){
                        printf("CINQUANT");
                   }
                   else{
                        printf("CINQUANTA");
                   }
              }break;
              case 6:{
                   if(u == 1 || u == 8 ){
                        printf("SESANT");
                   }
                   else{
                        printf("SESANTA");
                   }
              }break;
              case 7:{
                   if(u == 1 || u == 8 ){
                        printf("SETTANT");
                   }
                   else{
                        printf("SETTANTA");
                   }
              }break;
              case 8:{
                   if(u == 1 || u == 8 ){
                        printf("OTTANT");
                   }
                   else{
                        printf("OTTANTA");
                   }
              }break;
              case 9:{
                   if(u == 1 || u == 8 ){
                        printf("NOVANT");
                   }
                   else{
                        printf("NOVANTA");
                   }
              }break;
    }
    
    if(d != 1){
    switch(u){
              case 1:{
                   printf("UNO");
              }break;
              case 2:{
                   printf("DUE");
              }break;
              case 3:{
                   printf("TRE");
              }break;
              case 4:{
                   printf("QUATTRO");
              }break;
              case 5:{
                   printf("CINQUE");
              }break;
              case 6:{
                   printf("SEI");
              }break;
              case 7:{
                   printf("SETTE");
              }break;
              case 8:{
                   printf("OTTO");
              }break;
              case 9:{
                   printf("NOVE");
              }break;
    }
}
    
    gotoxy(20,9);
    printf("1) Continua");
    gotoxy(50,9);
    printf("2) Esci");
    gotoxy(35,10);
    printf("Scegli: ");
    scanf("%d",&risp);
    
 }while(risp == 1);
}

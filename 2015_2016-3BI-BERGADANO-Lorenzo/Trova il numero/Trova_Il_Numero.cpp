#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<time.h>

int numero_random,scelta,numero,tentativi;
char risp;

void gioco(){
     tentativi = 0;
     do{//ripetizione
     do{
        gotoxy(30,1);
        printf("TROVA IL NUMERO");
        gotoxy(5,3);
        printf("Qual'e il numero? .....            ");
        gotoxy(60,1);
        printf("Tentativi: %d",tentativi);
        gotoxy(23,3);
        scanf("%d",&numero);
        tentativi++;
     }while(numero < 1 || numero > 10000);
     
     if(numero < numero_random){
               gotoxy(1,5);
               printf("-Il numero inserito e' troppo PICCOLO");
     }
     else if(numero > numero_random){
          gotoxy(1,5);
          printf("-Il numero inserito e' troppo GRANDE        ");
     }
     else{
          system("CLS");
          gotoxy(35,2);
          printf("HAI VINTO");
          gotoxy(30,4);
          printf("Tentativi utilizzati: %d",tentativi);
          getch();
     }
     
     }while(numero != numero_random);
}

int main(){
    
    srand(time(NULL));
    numero_random = rand() % 10000 + 1;
    
    do{//inizio ripetizione
    do{//menu
       system("CLS");
       gotoxy(30,1);
       printf("TROVA IL NUMERO");
       gotoxy(25,3);
       printf("1 - Gioca");
       gotoxy(25,4);
       printf("2 - Istruzioni");
       gotoxy(25,5);
       printf("3 - Esci");
       gotoxy(27,7);
       printf("-> ");
       scanf("%d",&scelta);
    }while(scelta < 1 || scelta > 3);
    
    switch(scelta){
                   case 1:{
                        system("CLS");
                        gioco();//inizio gioco
                   }break;
                   case 2:{
                        do{
                        system("CLS");
                        gotoxy(25,1);
                        printf("TROVA IL NUMERO - Istruzioni");
                        gotoxy(1,3);
                        printf("Il gioco genera un numero da 1 a 10000 e lo scopo e' fare dei tentativi per trovare il numero generato.");
                        gotoxy(20,6);
                        printf("1 - Gioca");
                        gotoxy(47,6);
                        printf("2 - Indietro");
                        gotoxy(35,7);
                        printf("-> ");
                        scanf("%d",&scelta);
                        }while(scelta < 1 || scelta > 2);
                        
                        switch(scelta){
                                       case 1:{
                                            system("CLS");
                                            gioco();//inizio gioco
                                       }break;
                                       case 2:{
                                       }
                        }
                   }break;
                   case 3:{
                        do{
                           printf("\nVuoi uscire veramente? -> ");
                           fflush(stdin);
                           scanf("%c",&risp);
                        }while(risp != 'S' && risp != 's' && risp != 'N' && risp != 'n');
                        
                        if(risp == 'N' || risp == 'n'){
                                scelta = 0;
                        }
                   }
                        
    }
}while(scelta != 3);
}

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

int g,m,a,calc,calc2;
char risp;

void acquiszione_dati(){
     //Controllo e immisione giorno,mese,anno
    do{
      printf("Immetti il giorno: ");
      scanf("%d",&g);
    }while(g <= 0 || g >31);
    
    do{
      printf("Immetti il mese: ");
      scanf("%d",&m);
    }while(m <= 0 || m > 12);
    
    do{
      printf("Immetti l'anno: ");
      scanf("%d",&a);
    }while(a < 1500 || a > 2500);
    
     //calcol da fare per capire se e' inizio secolo o no
    calc = a % 400;
    calc2 = a % 4;
    //controlli per i mesi
    if(calc == 0 || calc2 == 0){
            //bisestile (febb 29)
            if(m == 4 || m == 6 || m == 9 || m == 11){
                 if(g < 30){
                      printf("\n\nLa data inserita (%d / %d / %d) e' valida!\n\n",g,m,a);//30 giorni
                 }
                 else{
                      printf("\n\nLa data inserita (%d / %d / %d) non e' valida!\nRiprova con un'altra data:\n\n",g,m,a);
                      acquiszione_dati();
                 }
            }
            else if(m == 2){
                 if(g < 29){
                      printf("\n\nLa data inserita (%d / %d / %d) e' valida!\n\n",g,m,a);//Febbraio 29 giorni
                 }
                 else{
                      printf("\n\nLa data inserita (%d / %d / %d) non e' valida!\nRiprova con un'altra data:\n\n",g,m,a);
                      acquiszione_dati();
                 }
            }
            else{
                 printf("\n\nLa data inserita (%d / %d / %d) e' valida!\n\n",g,m,a);//31 giorni
            }
    }
    else{
         //non bisestile (febb 28)
         if(m == 4 || m == 6 || m == 9 || m == 11){
                 if(g < 30){
                      printf("\n\nLa data inserita (%d / %d / %d) e' valida!\n\n",g,m,a);//30 giorni
                 }
                 else{
                      printf("\n\nLa data inserita (%d / %d / %d) non e' valida!\nRiprova con un'altra data:\n\n",g,m,a);
                      acquiszione_dati();
                 }
            }
            else if(m == 2){
                 if(g < 28){
                      printf("\n\nLa data inserita (%d / %d / %d) e' valida!\n\n",g,m,a);//Febb 28 giorni
                 }
                 else{
                      printf("\n\nLa data inserita (%d / %d / %d) non e' valida!\nRiprova con un'altra data:\n\n",g,m,a);
                      acquiszione_dati();
                 }
            }
            else{
                 printf("\n\nLa data inserita (%d / %d / %d) e' valida!\n\n",g,m,a);//31 giorni
            }
    }
}

int main(){
    //inizio ripetizione
    do{
    system("cls");
    
    printf("PROGRAMMA PER LA VALIDITA' DELLA DATA INSERITA\n\n");
    
    acquiszione_dati();
    
    do{
       printf("\n\nVuoi ripetere il programma? (s/n)");
       fflush(stdin);
       scanf("%c",&risp);
    }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
 }while(risp == 'S' || risp == 's');
}


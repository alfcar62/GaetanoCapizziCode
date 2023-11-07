#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<iostream>

int main(){
    int na,a,c,bis,calc,calc2,cl;
    char risp,sez;
    
    system("color 6");
    gotoxy(10,1);
    printf("PROGRAMMA CALCOLO ALUNNI NATI IN ANNI BISESTILI\n");
    gotoxy(15,2);
    printf("//Creato da Bergadano & Cernusco//\n\n");
    
    do{//inizio ripetizione
       
       do{
          printf("Che classe stai calcolando? (dalla 1' alla 5') --> ");
          scanf("%d",&cl);
       }while(cl <= 0 || cl >= 6);
       
       do{
          printf("\nDi che sezione? (scrivi in stampatello) --> ");
          fflush(stdin);
          scanf("%c",&sez);
       }while(sez != 'A' && sez != 'B' && sez != 'C' && sez !='D' && sez != 'E');
       
       do{
          printf("\nQuanti alunni sono? --> ");
          scanf("%d",&na);
       }while(na <= 0);
       
       c = 0;
       bis = 0;
       printf("\n\n");
       
       do{
           do{
              printf("Inserisci anno del %d alunno: ",c+1);
              scanf("%d",&a);
           }while(a < 1980 || a > 2016);
           
           calc = a % 400;
           calc2 = a % 4;
           
           if(calc == 0 || calc2 == 0){
                   bis++;
           }
           
           c++;
       }while(c < na);
       
       if(bis == 1){
            printf("\n\nNella classe %d%c c'e %d alunno nato in un anno bisestile\n\n",cl,sez,bis);
            printf("Premi un tasto per continuare...");
            getch();  
       }
       else{
            printf("\n\nNella classe %d%c ci sono %d alunni nati in un anno bisestile\n\n",cl,sez,bis);
            printf("Premi un tasto per continuare...");
            getch();
       }
       
       do{
          printf("\nVuoi ripetere il programma? (s/n) --> ");
          fflush(stdin);
          scanf("%c",&risp);
       }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
       system("CLS");
    }while(risp == 's' || risp == 'S');
}

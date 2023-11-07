#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main(){
    int s,q,m,r,q1,o,r1;
    
    system("CLS");
    printf("PROGRAMMA CALCOLO ORA, MINUTI E SECONDI (in base ai secondi)\n\n");
    
    do{
       printf("Inserisci numero di secondi (maggiore di 0): ");
       scanf("%d",&s);
    }while(s <= 0);
    //divisione con calcolo del resto
    q = s / 60;
    r = s % 60;//calcola solo il resto della divisione
    
    if(q > 0){
         m = q;
         s = r;
         //calcolo delle ore
         q1 = m / 60;
         r1 = m % 60;
         if(q1 > 0){
               o = q1;
               m = r1;
               }
         else{
              o = 0;
              m = r1;
              }
         }
    else{
         o = 0;
         m = 0;
         s = r;
         }
    
    printf("\nOre: %d\nMinuti: %d\nSecondi: %d\n\n",o,m,s);
    system("PAUSE");
                      
}

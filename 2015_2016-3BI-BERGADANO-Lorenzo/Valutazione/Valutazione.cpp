#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main(){
    int p;
    char v;
     
    system("CLS");
    printf("Programma per il calcolo della valutazoione in base al punteggio");
    
    do{
      printf("\n\nInserire il punteggio(da 0 a 100): ");
      scanf("%d",&p);
    }while(p<0 || p>100);
    
    if(p>=0 && p<=40){
            v='E';
            }
    else if(p>40 && p<=60){
         v='D';
         }
    else if(p>60 && p<=70){
         v='C';
         }
    else if(p>70 && p<=85){
         v='B';
         }             
    else {
         v='A';
         }
    
    printf("\n\nCon un punteggio di %d la valutazione finale e': %c\n",p,v);
    system("PAUSE");
}

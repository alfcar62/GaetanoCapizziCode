#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main(){
    int n,c,s,i;
    char risp;
    
    printf("PROGRAMMA CALCOLO QUADRATO DI UN NUMERO SOMMANDO I NUMERI DISPARI\n\n");
    
    do{//inizio ripetizione
          
      do{
         printf("Inserisci il numero (diverso da 0): ");
         scanf("%d",&n);
      }while(n == 0);
      
      c = -1;//contatore che genera i numeri dispari
      s = 0;//sommatore
      i = 0;//contatore ciclo
      
      /*do{
         i = i + 1;
         c = c + 2;
         s = s + c;
      }while(i < n);*/
      
      for(i;i < n;i++){
              c = c + 2;
              s = s + c; 
      }
      
      printf("\n\nIl quadrato di %d e' uguale a %d",n,s);

      do{
         printf("\n\nVuoi ripetere il programma? (s/n) --> ");
         fflush(stdin);
         scanf("%c",&risp);
      }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
      system("CLS");
    }while(risp == 's' || risp == 'S');
}

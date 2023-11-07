#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
//#include<conio2.h>
#include<windows.h>

int main(){
    int s,n,u,d,c,m,n1,p;
    int i;
    char risp;
    
    do{//inizio ripetizione
    
    //gotoxy(10,1);
    printf("PROGRAMMA CALCOLO NUMERI DI AMSTRONG\n\n");
    
       do{//inizio ciclo
       //gotoxy(7,3);
       printf("Inserisci fino a che numero devo calcolare: ");
       scanf("%d",&i);
    }while(i <= 0);
    
    n = 0;
    
    do{
        n++;
        n1 = n;
        
        if(n < 10){
             printf("%d\n", n);
        }
        else if(n > 9 && n < 100){
             d = n1 / 10;
             p = d * 10;
             n1 = n1 - p;
             u = n1 / 1;
             s = (d * d) + (u * u);
             
             if(s == n){
                  printf("%d\n",n);
             }
        }
        else if(n > 99 && n < 1000){
             c = n1 / 100;
             p = c * 100;
             n1 = n1 - p;
             d = n1 / 10;
             p = d * 10;
             n1 = n1 - p;
             u = n1 / 1;
             s = (c * c * c) + (d * d * d) + (u * u * u);
             
             if(s == n){
                  printf("%d\n", n);
             }
        }
        else{
             m = n1 / 1000;
             p = m * 1000;
             n1 = n1 - p;
             c = n1 / 100;
             p = c * 100;
             n1 = n1 - p;
             d = n1 / 10;
             p = d * 10;
             n1 = n1 - p;
             u = n1 / 1;
             s = (m * m * m * m) + (c * c * c * c) + (d * d * d * d) + (u * u * u * u);
             
             if(s == n){
                  printf("%d\n", n);
             }
        }
    }while(n < i);
    
    do{
       printf("\n\nVuoi ripetere il programma? (s/n): ");
       fflush(stdin);
       scanf("%c",&risp);
    }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
    system("CLS");
    }while(risp == 's' || risp == 'S');
}

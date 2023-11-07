#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<math.h>

int main(){
    float a,b,c,delta,x1,x2,radice;

    system("CLS");

    printf("PROGRAMMA RISOLUZIONE EQUAZIONE DI SECONDO GRADO DELLA FORMA: ax2+bx+c=0\n\n");
    //acquisizione dati con relativo controllo
    do{
        printf("Immetti il primo valore: ");
        scanf("%f",&a);
    }while(a == 0);
    do{
        printf("Immetti il secondo valore: ");
        scanf("%f",&b);
    }while(b == 0);
    do{
        printf("Immetti il terzo valore: ");
        scanf("%f",&c);
    }while(c == 0);
    
    //calcolo del delta
    delta = (b * b) - (4 * a * c);
    radice = sqrt(delta);
    
    if(delta >= 0){
             //calcolo dei risultati
             x1 = (b * -1) + radice / (2 * a);
             x2 = (b * -1) - radice / (2 * a);
    
             printf("\n\nIl primo risultato dell equazione e' di: %7.2f\nIl secondo risultato e' di: %7.2f\n",x1,x2);
             }
    else{
             printf("\nI risultati sono numeri irrazionali\n");
         }
    system("PAUSE");
}

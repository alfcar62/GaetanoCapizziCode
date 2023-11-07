#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

int main() {
    int lista,c,sconto;
    float costo = 0;
    float totale = 0;
    float calc,totsconto;

    system("CLS");
    do{
        printf("Inserisci numero di prodotti comprati: ");
        scanf("%d",&lista);
    }while(lista <= 0);

    do{
        for(c = 0; c < lista; c++){
            printf("\nInserisci il costo del %d' prodotto: ", c+1);
            scanf("%f",&costo);
            totale = totale + costo;
        }
    }while(costo <= 0);

    if(totale <= 100.00){
        sconto = 5;
    }
    else if(totale <= 250.00){
        sconto = 10;
    }
    else{
        sconto = 20;
    }

    calc = (totale * sconto)/100;
    totsconto = totale - calc;

    printf("\n\nLa somma totale della spesa e' di: %5.2f euro.\nIl totale scontato e' %5.2f euro con uno sconto del %d%%\n",totale,totsconto,sconto);

    getch();
}

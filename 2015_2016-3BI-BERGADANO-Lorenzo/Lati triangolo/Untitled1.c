#include<stdio.h>

int main() {
    int a,b,c,err;

    do{
        printf("IMMETTI VALORE A: ");
    scanf("%d",&a);
    printf("\nIMMETTI VALORE B: ");
    scanf("%d",&b);
    printf("\nIMMETTI VALORE C: ");
    scanf("%d",&c);
    err = a + b + c;
    }while(a == 0 || b == 0 || c == 0 || err < 180);

    printf("\nIl triangolo e' di tipo: ");

    if(a == 90 || b == 90 || c == 90){
        printf("rettangolo");
    }
    else if(a < 90 && b < 90 && c < 90){
        printf("acutangolo");
    }
    else{
        printf("ottusangolo");
    }

    printf("\nLa somma dei lati interni e' di: %d gradi",err);
    getch();
}

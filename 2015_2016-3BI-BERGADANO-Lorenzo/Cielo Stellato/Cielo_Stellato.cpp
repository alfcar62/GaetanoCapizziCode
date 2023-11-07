#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<time.h>

int main(){
    
    int n_stelle,cont,c,r,colore;
    char risp;
    
    srand(time(NULL));
    
    do{//inizio ripetizione
    do{
       system("CLS");
       gotoxy(30,1);
       printf("CIELO STELLATO");
       gotoxy(5,3);
       printf("Quante stelle vuoi vedere nel cielo? -> ");
       scanf("%d",&n_stelle); 
    }while(n_stelle < 1);
    
    system("CLS");
    cont = 0;
    colore = 1;
    
    do{
       c = rand() % 80 + 1;
       r = rand() % 24 + 1;
       gotoxy(c,r);
       if(colore <= 15){
                 textcolor(colore);
                 colore++;
       }
       else{
            colore = 1;
            textcolor(colore);
       }
       printf("*");
       cont++;
    }while(cont < n_stelle);
    
    getch();
    
    do{
    system("CLS");
    textcolor(15);
    gotoxy(30,2);
    printf("Vuoi ripetere? (s/n)");
    gotoxy(40,3);
    printf("-> ");
    scanf("%c",&risp);
    }while(risp != 'S' && risp != 's' && risp != 'N' && risp != 'n');
}while(risp == 'S' || risp == 's');
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int main(){
    int condizione,velocita;
    float f,s;
    
    system("CLS");
    printf("PROGRAMMA CALCOLO SPAZIO DI FRENATA A PARTIRE DALLA VELOCITA\n\n");
    //calcolo coefficente
    do{
       printf("In quale condizione stradale stai guidando?\n (1) = Asfalto ruvido\n (2) = Asfalto liscio\n (3) = Asfalto bagnato\n (4) = Asfalto ghiacciato\n-->");
       scanf("%d",&condizione);
    }while(condizione >= 0 && condizione > 4);
    
    if(condizione == 1){
                  f = 0.6;  
    }
    else if(condizione == 2){
         f = 0.5;
         }
    else if(condizione == 3){
         f = 0.4;
         }
    else{
         f = 0.1;
         }
    
    do{
         printf("Inserisci la velocita' alla quale stai andando (km/h): ");
         scanf("%d",&velocita);
       }while(velocita <= 0);
    
    s = (velocita * velocita) / (250 * f);
    
    printf("\n\nLo spazio di frenata necessario ad una velocita' di %dkm/h e' di: %6.2fm\n\n",velocita,s);
    system("PAUSE");
}

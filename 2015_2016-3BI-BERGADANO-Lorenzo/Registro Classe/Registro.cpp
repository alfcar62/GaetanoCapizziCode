#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>

int main(){
    int const N = 50;
    FILE *classe;
    char s[N];
    
    //Controllo se esiste il file classe.txt
    classe = fopen("classe.txt","a+");
    if(classe){
             while(!feof(classe)){
                                  fscanf(classe,"%s",s);
             }
             if(s[0] == '\0'){
                     printf("FILE VUOTO");
             }
             else{
                  printf("FILE PIENO");
             }
    }else{
          printf("ERRORE GRAVE: il programma ha riscontrato un errore nella lettura del file!");
    }
    
    fclose(classe);
    
    getch();
}

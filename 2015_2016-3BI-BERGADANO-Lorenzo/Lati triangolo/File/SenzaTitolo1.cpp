#include<stdio.h>
#include<conio.h>

FILE *fp;
char parola[10],lettera,nomeMax[10],nome[10];
int numero,max = 0,punti,i,indice = 1;

void Output(){
     
     while(!feof(fp)){
           //fseek(fp,0,SEEK_SET);
           fscanf(fp,"%d",&numero);
           indice++;
           //fseek(fp,2,SEEK_SET);
           fscanf(fp,"%s",&parola);
           fscanf(fp,"%d",&punti);
           if(punti > max){
                     max = punti;
                     for(i=0;i<10;i++){
                          lettera = parola[i];
                          nomeMax[i] = lettera; 
                     }
           }
           printf("%d\t%s\t%d\n\n",numero,parola,punti);
     }
     fprintf(fp,"\n%d %s 22",indice,nome);
     printf("%d\t%s\t22\n\n",indice,nome);
     printf("l'indicatore si trova in posizione: %ld\n\n",ftell(fp));
     printf("I punti maggiori sono: %d realizzati da: %s",max,nomeMax);
}

int main(){
    
    fp = fopen("test.txt","a+");
    if(fp){
           do{
              printf("NUOVO RECORD!! Inserisci il tuo nome: ");
              scanf("%s",&nome);
           }while(nome == "");
           
           Output();
    }
    else{
         printf("Impossibile aprire il file");
    }
    
    fclose(fp);
    
    getch();
}

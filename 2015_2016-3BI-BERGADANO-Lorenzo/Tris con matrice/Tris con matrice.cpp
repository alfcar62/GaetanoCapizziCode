#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>//per la funzione gotoxy();
#include<time.h>//serve per la randomizzazione

int riga,colonna;//variabili per la matrice
int matrice[3][3];
int mod,partenza;//variabili per capire la modalità del gioco e in caso chi deve partire tra PC o Utente
char risp;//variabile per la ripetizione del programma
int vittoria = 0;//variabile per capire se si ha vinto o no e far continuare il ciclo del gioco
int turno = 1;//variabile per capire di chi è il turno in modalità MULTIPLAYER
int mosse = 0;//contatore delle mosse del gioco

void aggiorna(){//aggiornamento del campo da gioco
     mosse = mosse + 1;
     
     if(mosse == 1){
          printf("\n\nSITUAZIONE DOPO %d MOSSA\n\n",mosse);    
     }
     else{
          printf("\n\nSITUAZIONE DOPO %d MOSSE\n\n",mosse);
     }
        
     printf("\n\n[%d]  [%d]  [%d]\n[%d]  [%d]  [%d]\n[%d]  [%d]  [%d]\n\n",matrice[0][0],matrice[0][1],matrice[0][2],matrice[1][0],matrice[1][1],matrice[1][2],matrice[2][0],matrice[2][1],matrice[2][2]);
     printf("\n\n---MOSSA COMPLETATA. Premere un tasto per continuare il gioco---");
     getch();
     printf("\n\n");
}

void acquisizione_dati(){
     //Acquisizione posizione (Riga e Colonna) utente con relativo controllo
    textcolor(2);
    printf("---");
    textcolor(15);
    printf("E' ");
    textcolor(3);
    printf("il tuo turno. ");
    textcolor(15);
    printf("Inserisci la posizione");
    textcolor(2);
    printf("---\n");
    textcolor(15);
    
    do{
       textcolor(14);
       printf("-Colonna: ");
       textcolor(15);
       scanf("%d",&colonna);
    }while(colonna <= 0 || colonna > 3);
    do{
       textcolor(13);
       printf("-Riga: ");
       textcolor(15);
       scanf("%d",&riga);
    }while(riga <= 0 || riga > 3);
    //calcolo per muoversi all'interno della matrice
    riga = riga - 1;
    colonna = colonna - 1;
    //controllo
    if(matrice[riga][colonna] == 0){
              matrice[riga][colonna] = 1; 
              aggiorna();                
     }
     else{
          textcolor(12);
          printf("\n\n--QUESTA CASELLA E' GIA STATA ASSEGNATA--\n\n");
          textcolor(15);
          acquisizione_dati();
     }
}

void acquisizione_pc(){
     //Generazione di numeri random (da 1 a 3) sia per le Colonne sia per le Righe
     colonna = rand() % 3 + 1;
     riga = rand() % 3 + 1;
     //calcolo per muoversi all'interno della matrice
     riga = riga - 1;
     colonna = colonna - 1;
     //controllo
     if(matrice[riga][colonna] == 0){
                               matrice[riga][colonna] = 2;
                               textcolor(2);
                               printf("---");
                               textcolor(15);
                               printf("E' ");
                               textcolor(5);
                               printf("il turno del PC. ");
                               textcolor(15);
                               printf("Posizione:(");
                               textcolor(14);
                               printf("%d  ",colonna+1);
                               textcolor(13);
                               printf("%d",riga+1);
                               textcolor(15);
                               printf(")");
                               textcolor(2);
                               printf("---\n");
                               textcolor(15);
                               aggiorna();
     }
     else{
          printf(" ");//Sleep(30);
          acquisizione_pc();
     }
}

void acquisiz_giocatore1(){
     //Acquisizione posizione (Riga e Colonna) GIOCATORE 1 con relativo controllo
    printf("---E' il turno del GIOCATORE 1. Inserisci la posizione---\n");
    turno = 2;//in questo modo dopo la verifica si passerà all'acquisizione del GIOCATORE 2
    do{
       printf("-Colonna: ");
       scanf("%d",&colonna);
    }while(colonna <= 0 || colonna > 3);
    do{
       printf("-Riga: ");
       scanf("%d",&riga);
    }while(riga <= 0 || riga > 3);
    //calcolo per muoversi all'interno della matrice
    riga = riga - 1;
    colonna = colonna - 1;
    //controllo
    if(matrice[riga][colonna] == 0){
              matrice[riga][colonna] = 1; 
              aggiorna();                
     }
     else{
          printf("--QUESTA CASELLA E' GIA STATA ASSEGNATA--\n\n");
          acquisiz_giocatore1();
     }
}

void acquisiz_giocatore2(){
     //Acquisizione posizione (Riga e Colonna) GIOCATORE 2 con relativo controllo
    printf("---E' il turno del GIOCATORE 2. Inserisci la posizione---\n");
    turno = 1;//in questo modo dopo la verifica si passerà all'acquisizione del GIOCATORE 1
    do{
       printf("-Colonna: ");
       scanf("%d",&colonna);
    }while(colonna <= 0 || colonna > 3);
    do{
       printf("-Riga: ");
       scanf("%d",&riga);
    }while(riga <= 0 || riga > 3);
    //calcolo per muoversi all'interno della matrice
    riga = riga - 1;
    colonna = colonna - 1;
    //controllo
    if(matrice[riga][colonna] == 0){
              matrice[riga][colonna] = 2; 
              aggiorna();         
     }
     else{
          printf("--QUESTA CASELLA E' GIA STATA ASSEGNATA--\n\n");
          acquisiz_giocatore2();
     }
}

void vittoria_Utente(){
     printf("\n\nVITTORIA UTENTE. Hai vinto dopo %d mosse",mosse);
}
void vittoria_Pc(){
     printf("\n\nVITTORIA PC. Ti ha battuto dopo %d mosse",mosse);
}
void pareggio(){
     printf("\n\nPAREGGIO. Riprova a vincere!");
}

void verifica1(){//verifica dopo la mossa eseguita
     if(matrice[0][0] == 1 && matrice[0][1] == 1 && matrice[0][2] == 1 ||
     matrice[1][0] == 1 && matrice[1][1] == 1 && matrice[2][2] == 1 ||
     matrice[2][0] == 1 && matrice[2][1] == 1 && matrice[2][2] == 1 ||
     matrice[0][0] == 1 && matrice[1][0] == 1 && matrice[2][0] == 1 ||
     matrice[0][1] == 1 && matrice[1][1] == 1 && matrice[2][1] == 1 ||
     matrice[0][2] == 1 && matrice[1][2] == 1 && matrice[2][2] == 1 ||
     matrice[0][0] == 1 && matrice[1][1] == 1 && matrice[2][2] == 1 ||
     matrice[0][2] == 1 && matrice[1][1] == 1 && matrice[2][0] == 1){
                   vittoria_Utente();
                   vittoria = 1;
     }
     else if(matrice[0][0] == 2 && matrice[0][1] == 2 && matrice[0][2] == 2 ||
     matrice[1][0] == 2 && matrice[1][1] == 2 && matrice[2][2] == 2 ||
     matrice[2][0] == 2 && matrice[2][1] == 2 && matrice[2][2] == 2 ||
     matrice[0][0] == 2 && matrice[1][0] == 2 && matrice[2][0] == 2 ||
     matrice[0][1] == 2 && matrice[1][1] == 2 && matrice[2][1] == 2 ||
     matrice[0][2] == 2 && matrice[1][2] == 2 && matrice[2][2] == 2 ||
     matrice[0][0] == 2 && matrice[1][1] == 2 && matrice[2][2] == 2 ||
     matrice[0][2] == 2 && matrice[1][1] == 2 && matrice[2][0] == 2){
                   vittoria_Pc();
                   vittoria = 1;
     }
     else{
          if(matrice[0][0] > 0 && matrice[0][1] > 0 && matrice[0][2] > 0 &&
          matrice[1][0] > 0 && matrice[1][1] > 0 && matrice[1][2] > 0 &&
          matrice[2][0] > 0 && matrice[2][1] > 0 && matrice[2][2] > 0){
                   pareggio();
                     vittoria = 1;
          }
          else if(mod == 2 && partenza == 1){
                 acquisizione_dati();
          }
          else if(mod == 2 && partenza == 2){
               acquisizione_pc();
          }
     }
}

void verifica2(){//verifica dopo la mossa eseguita
     if(matrice[0][0] == 1 && matrice[0][1] == 1 && matrice[0][2] == 1 ||
     matrice[1][0] == 1 && matrice[1][1] == 1 && matrice[2][2] == 1 ||
     matrice[2][0] == 1 && matrice[2][1] == 1 && matrice[2][2] == 1 ||
     matrice[0][0] == 1 && matrice[1][0] == 1 && matrice[2][0] == 1 ||
     matrice[0][1] == 1 && matrice[1][1] == 1 && matrice[2][1] == 1 ||
     matrice[0][2] == 1 && matrice[1][2] == 1 && matrice[2][2] == 1 ||
     matrice[0][0] == 1 && matrice[1][1] == 1 && matrice[2][2] == 1 ||
     matrice[0][2] == 1 && matrice[1][1] == 1 && matrice[2][0] == 1){
                   if(vittoria == 0){
                              vittoria_Utente();
                              vittoria = 1;
                   }
     }
     else if(matrice[0][0] == 2 && matrice[0][1] == 2 && matrice[0][2] == 2 ||
     matrice[1][0] == 2 && matrice[1][1] == 2 && matrice[2][2] == 2 ||
     matrice[2][0] == 2 && matrice[2][1] == 2 && matrice[2][2] == 2 ||
     matrice[0][0] == 2 && matrice[1][0] == 2 && matrice[2][0] == 2 ||
     matrice[0][1] == 2 && matrice[1][1] == 2 && matrice[2][1] == 2 ||
     matrice[0][2] == 2 && matrice[1][2] == 2 && matrice[2][2] == 2 ||
     matrice[0][0] == 2 && matrice[1][1] == 2 && matrice[2][2] == 2 ||
     matrice[0][2] == 2 && matrice[1][1] == 2 && matrice[2][0] == 2){
                   if(vittoria == 0){
                               vittoria_Pc();
                               vittoria = 1;
                   }
     }
     else{
          if(matrice[0][0] > 0 && matrice[0][1] > 0 && matrice[0][2] > 0 &&
          matrice[1][0] > 0 && matrice[1][1] > 0 && matrice[1][2] > 0 &&
          matrice[2][0] > 0 && matrice[2][1] > 0 && matrice[2][2] > 0){
                        pareggio();
                        vittoria = 1;
                        }
          else if(mod == 2 && partenza == 1){
                 acquisizione_pc();
          }
          else if(mod == 2 && partenza == 2){
               acquisizione_dati();
          }
     }
}

void verifica_multiplayer(){//viene usata in modalita MULTIPLAYER
     if(matrice[0][0] == 1 && matrice[0][1] == 1 && matrice[0][2] == 1 ||
     matrice[1][0] == 1 && matrice[1][1] == 1 && matrice[2][2] == 1 ||
     matrice[2][0] == 1 && matrice[2][1] == 1 && matrice[2][2] == 1 ||
     matrice[0][0] == 1 && matrice[1][0] == 1 && matrice[2][0] == 1 ||
     matrice[0][1] == 1 && matrice[1][1] == 1 && matrice[2][1] == 1 ||
     matrice[0][2] == 1 && matrice[1][2] == 1 && matrice[2][2] == 1 ||
     matrice[0][0] == 1 && matrice[1][1] == 1 && matrice[2][2] == 1 ||
     matrice[0][2] == 1 && matrice[1][1] == 1 && matrice[2][0] == 1){
                   printf("\n\nVITTORIA GIOCATORE 1. Hai stracciato il Giocatore2 in %d mosse",mosse);
                   vittoria = 1;
     }
     else if(matrice[0][0] == 2 && matrice[0][1] == 2 && matrice[0][2] == 2 ||
     matrice[1][0] == 2 && matrice[1][1] == 2 && matrice[2][2] == 2 ||
     matrice[2][0] == 2 && matrice[2][1] == 2 && matrice[2][2] == 2 ||
     matrice[0][0] == 2 && matrice[1][0] == 2 && matrice[2][0] == 2 ||
     matrice[0][1] == 2 && matrice[1][1] == 2 && matrice[2][1] == 2 ||
     matrice[0][2] == 2 && matrice[1][2] == 2 && matrice[2][2] == 2 ||
     matrice[0][0] == 2 && matrice[1][1] == 2 && matrice[2][2] == 2 ||
     matrice[0][2] == 2 && matrice[1][1] == 2 && matrice[2][0] == 2){
                   printf("\n\nVITTORIA GIOCATORE 2. Hai stracciato il Giocatore1 in %d mosse",mosse);
                   vittoria = 1;
     }
     
     else{
          if(matrice[0][0] > 0 && matrice[0][1] > 0 && matrice[0][2] > 0 &&
          matrice[1][0] > 0 && matrice[1][1] > 0 && matrice[1][2] > 0 &&
          matrice[2][0] > 0 && matrice[2][1] > 0 && matrice[2][2] > 0){
                        pareggio();
                        vittoria = 1;
                        }
          else if(turno == 1){
                   acquisiz_giocatore1();
          }
          else if(turno == 2){
               acquisiz_giocatore2();
          }    
     }
}

void inizio(){
     do{//ripetizione del gioco finchè non c'è una vittoria
        verifica1();
        verifica2();//Queste due ripetizioni vengono usate perchè in questo modo il gioco controlla la vittoria sia dopo la mossa dell'utente sia dopo quella del PC
     }while(vittoria == 0);
}

void inizio_pc(){//funzione se deve iniziare il PC
     do{
        verifica1();
        verifica2();
     }while(vittoria == 0);
}

void multiplayer(){
     do{
        verifica_multiplayer();
     }while(vittoria == 0);
}

int main(){
    system("CLS");
    srand(time(NULL));
    
    gotoxy(30,1);
    textcolor(2);
    printf("GIOCO DEL TRIS\n\n");
    gotoxy(23,2);
    printf("//Creato da Lorenzo Bergadano//\n\n");
    textcolor(9);
    printf("SCOPO: ");
    textcolor(15);
    printf("completare una fila di tre caselle in Diagonale,Verticale o Orizzontale\n\n");
    printf("Le ");
    textcolor(14);
    printf("COLONNE ");
    textcolor(15);
    printf("sono numerate da Destra a Sinistra.\n");
    printf("Le ");
    textcolor(13);
    printf("RIGHE ");
    textcolor(15);
    printf("sono numerate dall'Alto verso il Basso\n\n");
    
    //inizio ripetizione programma
    do{
       textcolor(9);
       printf(".....................INIZIO GIOCO....................\n\n");
       textcolor(15);
       //azzeramento matrice
       for(riga = 0;riga < 3;riga++){
             for(colonna = 0;colonna < 3;colonna++){
                   matrice[riga][colonna] = 0;
             }
       }
       //azzeramento vitttoria
       vittoria = 0;
       //azzeramento mosse
       mosse = 0;
       //chiediamo la modalita del gioco:
       do{
          printf("Scegli la ");
          textcolor(9);
          printf("MODALITA' ");
          textcolor(15);
          printf("del gioco: 1)MULTIPLAYER  2)CONTRO PC -> ");
          scanf("%d",&mod);
          printf("\n");
       }while(mod <= 0 || mod > 2);
       //chiediamo chi deve iniziare a giocare (se la modalita è multiplayer allora il controllo di chi inizia verra' saltato)
       if(mod == 2){
               do{
                    printf("Chi deve ");
                    textcolor(9);
                    printf("INIZIARE ");
                    textcolor(15);
                    printf("a giocare: 1)UTENTE  2)PC -> ");
                    scanf("%d",&partenza);
                    printf("\n");
               }while(partenza <= 0 || partenza > 2);
             
             textcolor(3);
             printf("\nL'UTENTE ");
             textcolor(15);
             printf("SEI IL NUMERO: ");
             textcolor(3);
             printf("1.");
             textcolor(15);
             printf("\nIL ");
             textcolor(5);
             printf("PC ");
             textcolor(15);
             printf("E' IL NUMERO: ");
             textcolor(5);
             printf("2.\n\n");
             textcolor(15);
             //controllo per chi inizia e la modalita
             if(partenza == 1){
                   inizio();
             }
             else{
                   inizio_pc();
             }
       }
       else{
           printf("\nIL ");
           textcolor(3);
           printf("PRIMO GIOCATORE ");
           textcolor(15);
           printf("E' IL NUMERO: ");
           textcolor(3);
           printf("1.\n");
           textcolor(15);
           printf("IL ");
           textcolor(5);
           printf("SECONDO GIOCATORE ");
           textcolor(15);
           printf("E' IL NUMERO: ");
           textcolor(5);
           printf("2.\n\n");
           textcolor(15);
           multiplayer();
       }
       
       do{
          printf("\n\nVUOI RIGIOCARE?(s/n) --> ");
          fflush(stdin);
          scanf("%c",&risp);
       }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
       printf("\n\n");
       system("CLS");
    }while(risp == 's' || risp == 'S');
}

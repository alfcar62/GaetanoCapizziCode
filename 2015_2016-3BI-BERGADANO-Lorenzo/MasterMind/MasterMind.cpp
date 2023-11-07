#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<time.h>

int movimento,posizione,x,y,flag,flag2,colore;//variabili per MENU 2.0
int scelta,c1,c2,c3,c4,numero,n1,n2,n3,n4,modalita,gpg,gps,tentativi;//variabili del gioco
bool animazione = true,vincita = false,record = false;//variabili tipo boleano del gioco
FILE *fp;//puntatore file
//variabili per gestione file
int indice,punteggio,i,max = 0;
char nome[20],nomeRecord[20],nomeInput[20],lettera;

void perso(){
      system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
       
       textbackground(4);
       textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
       
       //TITOLO HAI PERSO
       textbackground(4);
       textcolor(15);
       gotoxy(20,10);
       printf(" _____     _    _____                 ");
       gotoxy(20,11);
       printf("|  |  |___|_|  |  _  |___ ___ ___ ___ ");
       gotoxy(20,12);
       printf("|     | .'| |  |   __| -_|  _|_ -| . |");
       gotoxy(20,13);
       printf("|__|__|__,|_|  |__|  |___|_| |___|___|");
       textbackground(0);
       //OUTPUT MIGLIOR GIOCATORE
       gotoxy(15,16);
       printf("Il miglior giocatore e' %s con un totale di %d punti",nomeRecord,max);
       getch();
}

void vittoria(){
       system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
       
       textbackground(4);
       textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
       
     //TITOLO HAI VINTO
     textbackground(2);
     gotoxy(20,10);
     printf(" _____  _  _    _              _      ");
     gotoxy(20,11);
     printf("|  |  ||_|| |_ | |_  ___  ___ |_| ___ ");
     gotoxy(20,12);
     printf("|  |  || ||  _||  _|| . ||  _|| || .'|");
     gotoxy(20,13);
     printf(" |___/ |_||_|  |_|  |___||_|  |_||__,|");
     textbackground(0);
     ///CONTROLLO RECORD
     if(record == true){
               fp = fopen("punteggi.txt","a+");
               gotoxy(25,16);
               printf("HAI REALIZZATO UN NUOVO RECORD!!!!");
               do{
                  gotoxy(15,17);
                  printf("Inserisci il tuo nome per metterlo nella classifica");
                  gotoxy(16,20);
                  printf("Nome(massimo 20 lettere): ");
                  scanf("%s",&nomeInput);
               }while(nomeInput == "");
               
               if(fp){
                      indice++;
                      fprintf(fp,"\n%d %s %d",indice,nomeInput,tentativi);
               }
               else{
                    printf("Impossibile aggiornare il file.");
               }
               tentativi = 0;
               record = false;
               fclose(fp);
     }
     else{
          tentativi = 0;
          getch();
     }
}

void gioco(){
       system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
       
       textbackground(4);
       textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
     
     vincita = false;
     textbackground(0);
     
     if(modalita == 1){//MODALITA' FACILE
                 //GENERAZIONE NUMERI RANDOM
                 c1 = rand()%9 + 1;
                 do{
                      c2 = rand()%9 + 1;
                 }while(c2 == c1 || c2 == c3 || c2 == c4);
                 do{
                    c3 = rand()%9 + 1;
                 }while(c3 == c1 || c3 == c2 || c3 == c4);
                 do{
                    c4 = rand()%9 + 1;
                 }while(c4 == c1 || c4 == c2 || c4 == c3);
                 printf("%d%d%d%d",c1,c2,c3,c4);
                 //Settaggio Tentativi
                 tentativi = 10;
                 y = 8;//serve per andare a capo ogni volta
                 //INIZIO CICLO GIOCO
                 do{
                    gotoxy(5,7);
                    printf("TENTATIVI RIMASTI: %d ",tentativi);
                 do{//INPUT DI NUMERO 
                    gotoxy(5,y);
                    printf(" )");
                    gotoxy(9,y);
                    printf("                                       ");//Questo serve per cancellare il numero precedente 
                    gotoxy(9,y);
                    scanf("%d",&numero);
                 }while(numero < 1000 || numero > 9999);
                 //ANALISI DEL NUMERO
                 n1 = numero / 1000;
                 n2 = (numero % 1000) / 100;
                 n3 = ((numero % 1000) - (n2 * 100)) / 10;
                 n4 = ((numero % 1000) - (n2 * 100)) % 10;
                 //Azzero Variabili GPG e GPS (ogni turno si azzerano
                 gpg = 0;
                 gps = 0;
                 //CONTROLLO
                 if(n1 == c1){
                       gpg++;
                 }
                 else if(n1 == c2 || n1 == c3 || n1 == c4){
                      gps++;
                 }
                 if(n2 == c2){
                       gpg++;
                 }
                 else if(n2 == c1 || n2 == c3 || n2 == c4){
                      gps++;
                 }
                 if(n3 == c3){
                       gpg++;
                 }
                 else if(n3 == c3 || n3 == c2 || n3 == c4){
                      gps++;
                 }
                 if(n4 == c4){
                       gpg++;
                 }
                 else if(n4 == c3 || n4 == c2 || n4 == c1){
                      gps++;
                 }
                 //OUTPUT RISULTATI
                 gotoxy(60,7);
                 printf("GPG");
                 gotoxy(65,7);
                 printf("GPS");
                 gotoxy(61,y);
                 printf("%d",gpg);
                 gotoxy(66,y);
                 printf("%d",gps);
                 //CONTROLLO EVENTUALE VITTORIA
                 if(gpg == 4){
                        if(tentativi >= max){
                                     record = true;
                        }
                        vincita = true;
                        vittoria();
                 }
                 else{
                      //AGGIORNO VARIABILI
                      tentativi--;
                      y++;
                 }
                 }while(tentativi != 0);
                 
                 if(vincita == false){
                             perso();
                 }
     }
     else if(modalita == 2){//MODALITA' MEDIA (NUMERI UGUALI VICINI)
          //GENERAZIONE NUMERI RANDOM
          c1 = rand()%9 + 1;
          do{
             c2 = rand()%9 + 1;
          }while(c2 == c1 && c2 == c3 && c2 == c4);
          do{
             c3 = rand()%9 + 1;
          }while(c3 == c1 && c3 == c2 && c3 == c4);
          do{
             c4 = rand()%9 + 1;
          }while(c4 == c1 && c4 == c2 && c4 == c3);
          printf("%d%d%d%d",c1,c2,c3,c4);
          //Settaggio Tentativi e Y
          tentativi = 10;
          y = 8;
          //INIZIO CICLO GIOCO
          do{
             gotoxy(5,7);
             printf("TENTATIVI RIMASTI: %d ",tentativi);
             do{//ACQUISIZIONE DI NUMERO
                gotoxy(5,y);
                printf(" )");
                gotoxy(9,y);
                printf("                  ");//Questo serve per cancellare il numero precedente 
                gotoxy(9,y);
                scanf("%d",&numero);
             }while(numero < 1000 || numero > 9999);
             //ANALISI DEL NUMERO
             n1 = numero / 1000;
             n2 = (numero % 1000) / 100;
             n3 = ((numero % 1000) - (n2 * 100)) / 10;
             n4 = ((numero % 1000) - (n2 * 100)) % 10;
             //Azzero Variabili GPG e GPS (ogni turno si azzerano
             gpg = 0;
             gps = 0;
             //CONTROLLO
             if(n1 == c1){
                   gpg++;
             }
             else if(n1 == c2 || n1 == c3 || n1 == c4){
                  gps++;
             }
             if(n2 == c2){
                   gpg++;
             }
             else if(n2 == c1 || n2 == c3 || n2 == c4){
                  gps++;
             }
             if(n3 == c3){
                   gpg++;
             }
             else if(n3 == c1 || n3 == c2 || n3 == c4){
                  gps++;
             }
             if(n4 == c4){
                   gpg++;
             }
             else if(n4 == c1 || n4 == c2 || n4 == c3){
                  gps++;
             }
             //OUTPUT RISULTATI
             gotoxy(60,7);
             printf("GPG");
             gotoxy(65,7);
             printf("GPS");
             gotoxy(61,y);
             printf("%d",gpg);
             gotoxy(66,y);
             printf("%d",gps);
             //CONTROLLO EVENTUALE VITTORIA
             if(gpg == 4){
                    if(tentativi >= max){
                                     record = true;
                    }
                    vincita = true;
                    vittoria();
             }
             else{
                  //AGGIORNO VARIABILI
                  tentativi--;
                  y++;
             }
          }while(tentativi != 0);
          if(vincita == false){
                       perso();
          }
     }
     else{//MODALITA' DIFFICILE (TUTTI NUMERI RANDOM)
          //GENERAZIONE NUMERI RANDOM
          c1 = rand()%9 + 1;
          c2 = rand()%9 + 1;
          c3 = rand()%9 + 1;
          c4 = rand()%9 + 1;
          printf("%d%d%d%d",c1,c2,c3,c4);
          //Settaggio Tentativi e Y
          tentativi = 10;
          y = 8;
          //INIZIO CICLO GIOCO
          do{
             gotoxy(5,7);
             printf("TENTATIVI RIMASTI: %d ",tentativi);
             do{//ACQUISIZIONE DI NUMERO
                gotoxy(5,y);
                printf(" )");
                gotoxy(9,y);
                printf("                  ");//Questo serve per cancellare il numero precedente 
                gotoxy(9,y);
                scanf("%d",&numero);
             }while(numero < 1000 || numero > 9999);
             //ANALISI DEL NUMERO
             n1 = numero / 1000;
             n2 = (numero % 1000) / 100;
             n3 = ((numero % 1000) - (n2 * 100)) / 10;
             n4 = ((numero % 1000) - (n2 * 100)) % 10;
             //Azzero Variabili GPG e GPS (ogni turno si azzerano
             gpg = 0;
             gps = 0;
             //CONTROLLO
             if(n1 == c1){
                   gpg++;
             }
             else if(n1 == c2 || n1 == c3 || n1 == c4){
                  gps++;
             }
             if(n2 == c2){
                   gpg++;
             }
             else if(n2 == c1 || n2 == c3 || n2 == c4){
                  gps++;
             }
             if(n3 == c3){
                   gpg++;
             }
             else if(n3 == c1 || n3 == c2 || n3 == c4){
                  gps++;
             }
             if(n4 == c4){
                   gpg++;
             }
             else if(n4 == c1 || n4 == c2 || n4 == c3){
                  gps++;
             }
             //OUTPUT RISULTATI
             gotoxy(60,7);
             printf("GPG");
             gotoxy(65,7);
             printf("GPS");
             gotoxy(61,y);
             printf("%d",gpg);
             gotoxy(66,y);
             printf("%d",gps);
             //CONTROLLO EVENTUALE VITTORIA
             if(gpg == 4){
                    if(tentativi >= max){
                                     record = true;
                    }
                    vincita = true;
                    vittoria();
             }
             else{
                  //AGGIORNO VARIABILI
                  tentativi--;
                  y++;
             }
          }while(tentativi != 0);
          if(vincita == false){
                       perso();
          }
     }
     textbackground(0);
}

void inizio(){
     textbackground(0);
     
     do{
     do{//menu
       system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
     
     textbackground(4);
     textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
       gotoxy(25,7);
       textbackground(4);
       printf("SELEZIONA UNA MODALITA' DI GIOCO:");
       gotoxy(30,9);
       textbackground(15);
       textcolor(0);
       printf("> FACILE");
       gotoxy(30,11);
       textbackground(0);
       textcolor(15);
       printf("  MEDIO");
       gotoxy(30,13);
       textbackground(0);
       textcolor(15);
       printf("  DIFFICILE");
       
       movimento = getch();
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO

    flag = 0;
    posizione = 1;   
    
    do{
    flag2 = 0;        
    if(flag == 1){
            movimento = getch();
    }
    switch(movimento){
                      
                      case 72:{
                           if(posizione == 2){
                                        posizione = 1;
                                        scelta = 1;
                                        gotoxy(30,9);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> FACILE");
                                        gotoxy(30,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  MEDIO");
                                        gotoxy(30,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  DIFFICILE");
                           }
                           else if(posizione == 3){
                                posizione = 2;
                                scelta = 2;
                                gotoxy(30,9);
                                textbackground(0);
                                textcolor(15);
                                printf("  FACILE");
                                gotoxy(30,11);
                                textbackground(15);
                                textcolor(0);
                                printf("> MEDIO");
                                gotoxy(30,13);
                                textbackground(0);
                                textcolor(15);
                                printf("  DIFFICILE");
                           }
                           else{
                                posizione = posizione;
                           }
                      }break;
                      case 80:{
                           if(posizione == 1){
                                        posizione = 2;
                                        scelta = 2;
                                        gotoxy(30,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  FACILE");
                                        gotoxy(30,11);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> MEDIO");
                                        gotoxy(30,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  DIFFICILE");
                           }
                           else if(posizione == 2){
                                posizione = 3;
                                gotoxy(30,9);
                                textbackground(0);
                                textcolor(15);
                                printf("  FACILE");
                                gotoxy(30,11);
                                textbackground(0);
                                textcolor(15);
                                printf("  MEDIO");
                                gotoxy(30,13);
                                textbackground(15);
                                textcolor(0);
                                printf("> DIFFICILE");
                           }
                           else{
                                posizione = posizione;
                           }
                      }break;
                      case 13:{
                           if(posizione == 3){//MODALITA' DIFFICILE (TUTTI CASUALI)
                              //variabili per il menu
                              scelta = 3;
                              flag2 = 1;
                              //Animazione Caricamento
                                gotoxy(32,17);
                                textcolor(15);
                                textbackground(0);
                                printf("CARICAMENTO...");
                                x = 25;
                                y = 18;
                                textbackground(colore);
                                do{
                                   gotoxy(x,y);
                                   printf(" ");
                                   Sleep(100);
                                   x++;
                                }while(x != 52);
                              //inizio gioco
                              modalita = 3;
                              textbackground(0);
                              gioco(); 
                           }
                           else if(posizione == 2){//MODALITA' MEDIA (CASUALI MA DOPPI NON VICINI)
                                //variabili per il menu
                                scelta = 2;
                                flag2 = 1;
                                //Animazione Caricamento
                                gotoxy(32,17);
                                printf("CARICAMENTO...");
                                x = 25;
                                y = 18;
                                textbackground(colore);
                                do{
                                   gotoxy(x,y);
                                   printf(" ");
                                   Sleep(100);
                                   x++;
                                }while(x != 52);
                                //inizio gioco
                                modalita = 2;
                                textbackground(0);
                                gioco();
                           }
                           else if(posizione == 1){//MODALITA' FACILE (TUTTI DIVERSI)
                                //variabili per il menu
                                scelta = 2;
                                flag2 = 1;
                                //Animazione Caricamento
                                gotoxy(32,17);
                                printf("CARICAMENTO...");
                                x = 25;
                                y = 18;
                                textbackground(colore);
                                do{
                                   gotoxy(x,y);
                                   printf(" ");
                                   Sleep(100);
                                   x++;
                                }while(x != 52);
                                //inizio gioco
                                modalita = 1;
                                textbackground(0);
                                gioco();
                           }
                      }
    }
    flag = 1;
}while (scelta != 0 && flag2 == 0);    
}while(scelta == 0);
textbackground(0);
}

void classifica(){
     do{//ripetizione
     system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
       
       textbackground(4);
       textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
       textbackground(0);
       //INIZIO GESTIONE FILE
     fp = fopen("punteggi.txt","a+");
     if(fp){
            gotoxy(27,7);
            printf("NOME");
            gotoxy(40,7);
            printf("PUNTEGGIO");
            y = 9;
            while(!feof(fp) || indice > 10){
                             //acquisizione dati
                             fscanf(fp,"%d",&indice);
                             fscanf(fp,"%s",&nome);
                             fscanf(fp,"%d",&punteggio);
                             if(punteggio > max){
                                          max = punteggio;
                                          for(i=0;i<20;i++){
                                                            lettera = nome[i];
                                                            nomeRecord[i] = lettera;
                                          }
                             }
                             //output
                             gotoxy(24,y);
                             printf("%d)",indice);
                             gotoxy(27,y);
                             printf("%s",nome);
                             gotoxy(43,y);
                             printf("%d",punteggio);
                             y++;
            }
            gotoxy(17,y+1);
            printf("Il maggior punteggio e' %d realizzato da: %s",max,nomeRecord);
     }
     else{
          printf("Impossibile aprire il file. Controllare se e' cambiata la directory!");
     }
     fclose(fp);
     //MENU
     do{
        gotoxy(30,22);
        textbackground(15);
        textcolor(0);
        printf("> HOME");
        gotoxy(40,22);
        textbackground(0);
        textcolor(15);
        printf("  GIOCO");
        movimento = getch();
     }while(movimento != 13 && movimento != 77 && movimento != 75);//77 = DESTRA 75 = SINISTRA
     
     posizione = 1;
     flag = 0;

     do{
        flag2 = 0;        
        if(flag == 1){
                movimento = getch();
        }
        switch(movimento){
                          case 77:{
                               if(posizione == 1){
                                            posizione = 2;
                                            scelta = 2;
                                            gotoxy(30,22);
                                            textbackground(0);
                                            textcolor(15);
                                            printf("  HOME");
                                            gotoxy(40,22);
                                            textbackground(15);
                                            textcolor(0);
                                            printf("> GIOCO");            
                               }
                               else{
                                    posizione = posizione;
                               }
                          }break;
                          case 75:{
                               if(posizione == 2){
                                            posizione = 1;
                                            scelta = 0;
                                            gotoxy(30,22);
                                            textbackground(15);
                                            textcolor(0);
                                            printf("> HOME");
                                            gotoxy(40,22);
                                            textbackground(0);
                                            textcolor(15);
                                            printf("  GIOCO");
                               }
                               else{
                                    posizione = posizione;
                               }
                          }break;
                          case 13:{
                               if(scelta == 2){
                                         inizio();
                                         flag2 = 1;
                                         scelta = 0;
                               }
                               else{
                                    scelta = 0;
                                    flag2 = 1;
                               }
                          }
        }
        flag = 1;
        }while(scelta != 0 && flag2 == 0);
     }while(scelta != 0);
}

void istruzioni(){
     textbackground(0);
       
       do{//ripetizione
       
       do{//menu
       system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(100);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
       
       textbackground(4);
       textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
       
       textbackground(0);
       gotoxy(3,7);
       printf("Il gioco Master Mind consiste nell'indovinare una sequenza di 4 numeri,");
       gotoxy(3,8);
       printf("generati casualmente, entro 10 tentativi. Nella modalita' FACILE i numeri");
       gotoxy(3,9);
       printf("della squenza sono tutti diversi, nella modalita' MEDIA i numeri possono");
       gotoxy(3,10);
       printf("essere uguali ma non vicini fra loro e nella modalita' DIFFICILE i numeri");
       gotoxy(3,11);
       printf("possono essere uguali e vicini. GPG (Giusto al Posto Giusto) e GPS (Giusto");
       gotoxy(3,12);
       printf("al Posto Sbagliato) sono indicati ogni volta che si fa un tentativo.");
       
          gotoxy(7,16);
          textbackground(15);
          textcolor(0);
          printf("> HOME");
          gotoxy(17,16);
          textbackground(0);
          textcolor(15);
          printf("  GIOCO");
          movimento = getch();
       }while(movimento != 13 && movimento != 77 && movimento != 75);//77 = DESTRA 75 = SINISTRA
       
       posizione = 1;
       flag = 0;

       do{
          flag2 = 0;        
          if(flag == 1){
                  movimento = getch();
            }
          switch(movimento){
                            case 77:{
                                 if(posizione == 1){
                                             posizione = 2;
                                             scelta = 2;
                                             gotoxy(7,16);
                                             textbackground(0);
                                             textcolor(15);
                                             printf("  HOME");
                                             gotoxy(17,16);
                                             textbackground(15);
                                             textcolor(0);
                                             printf("> GIOCO");            
                                 }
                                 else{
                                      posizione = posizione;
                                 }
                            }break;
                            case 75:{
                                 if(posizione == 2){
                                              posizione = 1;
                                              scelta = 0;
                                              gotoxy(7,16);
                                              textbackground(15);
                                              textcolor(0);
                                              printf("> HOME");
                                              gotoxy(17,16);
                                              textbackground(0);
                                              textcolor(15);
                                              printf("  GIOCO");
                                 }
                                 else{
                                      posizione = posizione;
                                 }
                            }break;
                            case 13:{
                                 if(scelta == 2){
                                           inizio();
                                           flag2 = 1;
                                           scelta = 0;
                                 }
                                 else{
                                      scelta = 0;
                                      flag2 = 1;
                                 }
                            }
            }
            flag = 1;
            }while(scelta != 0 && flag2 == 0);
          }while(scelta != 0);
}

int main(){
	textbackground(0);
    srand(time(NULL));
    //GESTIONE FILE
    fp = fopen("punteggi.txt","a+");
    if(fp){
             while(!feof(fp)){
                              //acquisizione dati
                             fscanf(fp,"%d",&indice);
                             fscanf(fp,"%s",&nome);
                             fscanf(fp,"%d",&punteggio);
                             if(punteggio > max){
                                          max = punteggio;
                                          for(i=0;i<20;i++){
                                                            lettera = nome[i];
                                                            nomeRecord[i] = lettera;
                                          }
                             }
             }
    }
    else{
         printf("Impossibile aprire il file. Controllare se e' cambiata la directory");
         getch();
    }
    
    fclose(fp);
    do{//ripetizione programma
    
    do{//menu
       system("CLS");
       x = 0;
       y = 0;
       colore = 1;
       
       do{//bordo alto orizzontale (spesso 4)
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(70);
          }
          printf("   ");
          
          if(x == 80){
               y++;
               x = 0;
          }
          else{
               x++;
          }
       }while(y != 3 && x != 80);    
       
       x = 0;
       y = 3;
       colore = 1;
       do{//bordo sinistro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(70);
          }
          
          printf(" \n \n \n");
          if(y != 24){
               y = y + 3;
          }
       }while(y != 24);
       
       x = 1;
       y = 25;
       do{//bordo basso orizzontale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(70);
          }
          
          printf("   ");
          if(x != 79){
               x = x + 3;
          }
               
       }while(x != 79);
       
       colore++;
       textbackground(colore);
       printf("  ");
       
       x = 80;
       y = 4;
       do{//bordo destro verticale
          gotoxy(x,y);
          textbackground(colore);
          colore++;
          if(colore == 14){
                   colore = 1; 
          }
          if(animazione == true){
                        Sleep(70);
          }
          
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
          printf(" ");
          y++;
          gotoxy(x,y);
       }while(y < 24);
       
       textbackground(4);
       textcolor(15);
       gotoxy(17,1);
       printf(" _____         _              _____ _       _ ");
       gotoxy(17,2);
       printf("|     |___ ___| |_ ___ ___   |     |_|___ _| |");
       gotoxy(17,3);
       printf("| | | | .'|_ -|  _| -_|  _|  | | | | |   | . |");
       gotoxy(17,4);
       printf("|_|_|_|__,|___|_| |___|_|    |_|_|_|_|_|_|___|");
       gotoxy(30,7);
       textbackground(15);
       textcolor(0);
       printf("> INIZIA");
       gotoxy(30,9);
       textbackground(0);
       textcolor(15);
       printf("  ISTRUZIONI");
       gotoxy(30,11);
       textbackground(0);
       textcolor(15);
       printf("  CLASSIFICA");
       gotoxy(30,13);
       textbackground(0);
       textcolor(15);
       printf("  ESCI");

       movimento = getch();
       animazione = false;
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO

    flag = 0;
    posizione = 1;   
    
    do{
    flag2 = 0;        
    if(flag == 1){
            movimento = getch();
    }
    switch(movimento){
                      
                      case 72:{
                           //_beep(2000,100);
                           if(posizione == 2){
                                        posizione = 1;
                                        scelta = 1;
                                        gotoxy(30,7);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> INIZIO");
                                        gotoxy(30,9);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ISTRUZIONI");
                                        gotoxy(30,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  CLASSIFICA");
                                        gotoxy(30,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ESCI");
                           }
                           else if(posizione == 3){
                                posizione = 2;
                                scelta = 2;
                                gotoxy(30,7);
                                textbackground(0);
                                textcolor(15);
                                printf("  INIZIO");
                                gotoxy(30,9);
                                textbackground(15);
                                textcolor(0);
                                printf("> ISTRUZIONI");
                                gotoxy(30,11);
                                textbackground(0);
                                textcolor(15);
                                printf("  CLASSIFICA");
                                gotoxy(30,13);
                                textbackground(0);
                                textcolor(15);
                                printf("  ESCI");
                           }
                           else if(posizione == 4){
                                posizione = 3;
                                scelta = 3;
                                gotoxy(30,7);
                                textbackground(0);
                                textcolor(15);
                                printf("  INIZIO");
                                gotoxy(30,9);
                                textbackground(0);
                                textcolor(15);
                                printf("  ISTRUZIONI");
                                gotoxy(30,11);
                                textbackground(15);
                                textcolor(0);
                                printf("> CLASSIFICA");
                                gotoxy(30,13);
                                textbackground(0);
                                textcolor(15);
                                printf("  ESCI");
                           }
                           else{
                                posizione = posizione;
                           }
                      }break;
                      case 80:{
                           //_beep(2000,100);
                           if(posizione == 1){
                                        posizione = 2;
                                        gotoxy(30,7);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  INIZIO");
                                        gotoxy(30,9);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> ISTRUZIONI");
                                        gotoxy(30,11);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  CLASSIFICA");
                                        gotoxy(30,13);
                                        textbackground(0);
                                        textcolor(15);
                                        printf("  ESCI");
                           }
                           else if(posizione == 2){
                                posizione = 3;
                                gotoxy(30,7);
                                textbackground(0);
                                textcolor(15);
                                printf("  INIZIO");
                                gotoxy(30,9);
                                textbackground(0);
                                textcolor(15);
                                printf("  ISTRUZIONI");
                                gotoxy(30,11);
                                textbackground(15);
                                textcolor(0);
                                printf("> CLASSIFICA");
                                gotoxy(30,13);
                                textbackground(0);
                                textcolor(15);
                                printf("  ESCI");
                           }
                           else if(posizione == 3){
                                posizione = 4;
                                gotoxy(30,7);
                                textbackground(0);
                                textcolor(15);
                                printf("  INIZIO");
                                gotoxy(30,9);
                                textbackground(0);
                                textcolor(15);
                                printf("  ISTRUZIONI");
                                gotoxy(30,11);
                                textbackground(0);
                                textcolor(15);
                                printf("  CLASSIFICA");
                                gotoxy(30,13);
                                textbackground(15);
                                textcolor(0);
                                printf("> ESCI");
                           }
                           else{
                                posizione = posizione;
                           }
                      }break;
                      case 13:{
                           //_beep(1000,100);
                           if(posizione == 4){
                              scelta = 4;         
                           }
                           else if(posizione == 1){
                                inizio();
                                flag2 = 1;
                           }
                           else if(posizione == 2){
                                istruzioni();
                                flag2 = 1;
                           }
                           else if(posizione == 3){
                                classifica();
                                flag2 = 1;
                           }
                      }
    }
    flag = 1;
}while (scelta != 4 && flag2 == 0);    
}while(scelta != 4);
}

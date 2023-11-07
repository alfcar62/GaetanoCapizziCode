#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>

int main(){
    int const N = 35, Max_Righe = 10, N_Materie = 5;
    //Dichiarazione Struct
    struct rubrica{
           char nome[N+1];
           char cognome[N+1];
           char indirizzo[N+1];
           float voti[N_Materie];
           float media;
           int suff;
           int insuff;
    };
    rubrica elenco[Max_Righe],comodo;
    //Dichiarazione variabili
    int scelta,i,nc,num_ele,ir,insuff,suff,j;
    char risp,STRINGA[N],stringa[N];
    bool errore,ordinato = false,caricato = false;
    float voto,media,sommatore;
    char Materia[N_Materie][N+1] = {"Matematica\0","Infomratica\0","Storia\0","Italiano\0","Inglese\0"};
    
    system("CLS");
    gotoxy(20,1);
    printf("**BANCA DATI DI TORINO**");
    getch();
    
    do{//Ripetizione del programma
       do{
          gotoxy(5,3);
          printf("1) Carica Elementi nella rubrica");
          gotoxy(5,4);
          printf("2) Ordina rubrica");
          gotoxy(5,5);
          printf("3) Visualizza rubrica");
          gotoxy(5,6);
          printf("4) Ricerca nella rubrica");
          gotoxy(5,7);
          printf("5) Esci");
          gotoxy(5,9);
          printf("Scegli -->");
          scanf("%d",&scelta);
       }while(scelta < 1 || scelta > 5);
       
       switch(scelta){
                      case 1:{
                           system("CLS");
                           do{
                              printf("Quanti elementi vuoi aggiungere? (max %d)",Max_Righe);
                              scanf("%d",&num_ele);
                           }while(num_ele < 1 || num_ele > Max_Righe);
                           
                           for(ir = 0; ir < num_ele; ir++){
                                  //Input del Nome
                                  do{
                                     //Pulizia stringe
                                     for(i = 0; i < N; i++){
                                           stringa[i] = ' ';
                                           STRINGA[i] = ' ';
                                     }
                                     //Acquisizione del nome con controllo
                                     do{
                                        gotoxy(2,2);
                                        printf("\n Nome --> ");
                                        gets(stringa);
                                        nc = strlen(stringa);
                                     }while(nc > N);
                                     //Trasformo in maiuscolo
                                     for(i = 0;i < nc; i++){
                                           STRINGA[i] = toupper(stringa[i]);
                                     }
                                     //Inizio controlli
                                     errore = false;
                                     for(i = 0; i < nc && errore == false; i++){
                                           if(!(STRINGA[i]>='A' && STRINGA[i]<='Z') || !(STRINGA[i] == ' ') || !(STRINGA[i] == '\''))
                                           {
                                                                errore = true;
                                                                printf("\nERRORE NEL FORMATO DEL TESTO");
                                                                getch();
                                                                
                                           }
                                     }
                                  }while(errore == true);
                                  strcpy(elenco[ir].nome,stringa);
                                  elenco[ir].nome[nc] = '\0';
                                  //Input Cognome
                                  do{
                                     //Pulizia stringhe
                                     for(i = 0; i < N; i++){
                                           stringa[i] = ' ';
                                           STRINGA[i] = ' ';
                                     }
                                     //Acquisizione del cognome con controllo
                                     do{
                                        printf("\n Cognome --> ");
                                        gets(stringa);
                                        nc = strlen(stringa);
                                     }while(nc > N);
                                     //Trasformazione in maiuscolo
                                     for(i = 0; i < nc; i++){
                                           STRINGA[i] = toupper(stringa[i]);
                                     }
                                     //Controllo
                                     errore = false;
                                     for(i = 0; i < nc && errore == false; i++){
                                           if(!((STRINGA[i]>='A' && STRINGA[i]<='Z') || STRINGA[i] == ' ' || STRINGA[i] == '\'')){
                                                    errore = true;
                                                    printf("\nERRORE NEL FORMATO DEL TESTO");
                                                    getch();             
                                           }
                                     }
                                  }while(errore == true);
                                  strcpy(elenco[ir].cognome,stringa);
                                  elenco[ir].cognome[nc] = '\0';
                                  //Input dell'indirizzo
                                  do{
                                     //Pulizia stringhe
                                     for(i = 0; i < N; i++){
                                           stringa[i] = ' ';
                                           STRINGA[i] = ' ';
                                     }
                                     //Acquisizione dell'indirizzo con controllo
                                     do{
                                        printf("\n Indirizzo --> ");
                                        gets(stringa);
                                        nc = strlen(stringa);
                                     }while(nc > N);
                                     //Trasformazione in maiuscolo
                                     for(i = 0; i < nc; i++){
                                           STRINGA[i] = toupper(stringa[i]);
                                     }
                                     //Controllo
                                     errore = false;
                                     for(i = 0; i < nc && errore == false; i++){
                                           if(!((STRINGA[i]>='A' && STRINGA[i]<='Z') || STRINGA[i] == ' ' || STRINGA[i] == '\'')){
                                                    errore = true;
                                                    printf("\nERRORE NEL FORMATO DEL TESTO");
                                                    getch();             
                                           }
                                     }
                                  }while(errore == true);
                                  strcpy(elenco[ir].indirizzo,stringa);
                                  elenco[ir].indirizzo[nc] = '\0';
                                  //Input dei voti
                                  insuff = 0;
                                  suff = 0;
                                  sommatore = 0;
                                  for(j = 0; j < N_Materie; j++){
                                        do{
                                           printf("\n &s --> ",Materia[j]);
                                           scanf("%f",&voto);
                                        }while(voto < 0 || voto > 10);
                                        elenco[ir].voti[j] = voto;//Mettiamo il voto
                                        if(voto < 6){
                                             insuff++;        
                                        }else{
                                              suff++;
                                        }
                                        sommatore = sommatore + voto;
                                  }
                                  media = sommatore / N_Materie;
                                  elenco[ir].media = media;
                                  elenco[ir].suff = suff;
                                  elenco[ir].insuff = insuff;
                           }//Fine ciclo for
                           caricato = true;
                           ordinato = false;
                           system("CLS");
                           printf("CARICAMENTO COMPLETATO");
                           getch();
                      }break;
                      
                      case 2:{
                           system("CLS");
                           if(caricato == false){
                                       printf("DEVI ANCORA CARICARE LA RUBRICA");
                                       getch();
                           }
                           else{
                                printf("Ordinamento della rubrica in corso...");
                                int scansioni,c;
                                for(scansioni = 0,ordinato = false;scansioni < num_ele-1 && ordinato == false;scansioni++){
                                      for(i = 0, ordinato = true; i < (num_ele-scansioni-1);i++){
                                            c = strcmp(elenco[i].cognome,elenco[i+1].cognome);
                                            if(c > 0){
                                                 comodo = elenco[i];
                                                 elenco[i] = elenco[i+1];
                                                 elenco[i+1] = comodo;
                                                 ordinato = false;
                                            }
                                      }
                                }
                                ordinato = true;
                           }
                           printf("\n\n...Vettore ordinato con successo!");
                           getch();
                      }break;
                      
                      case 3:{
                           int decidi;
                           system("CLS");
                           if(caricato == false){
                                         printf("DEVI ANCORA CARICARE LA RUBRICA");
                                         getch();   
                           }
                           else{
                                if(ordinato == true){
                                            printf("Visualizzazione della rubrica ORDINATA\n\n");
                                            getch();
                                }else{
                                      printf("Visualizzazione della rubrica NON ORDINATA\n\n");
                                      getch();
                                }
                                do{
                                   printf("1)Visualizza singolo elemento\n");
                                   printf("2)Visualizza tutti gli elementi\n");
                                   printf("-->");
                                   scanf("%d",&decidi);
                                }while(decidi < 0 || decidi > 2);
                                
                                switch(decidi){
                                               case 1:{
                                                    for(i = 0; i < num_ele; i++){
                                                          system("CLS");
                                                          printf("%d ^ Alunno ------------------------- \n\n",i+1);
                                                          printf("Cognome: %s \n",elenco[i].cognome);
                                                          printf("Nome: %s \n",elenco[i].nome);
                                                          printf("Indirizzo: %s \n",elenco[i].indirizzo);
                                                          for(j = 0; j < N_Materie; j++){
                                                                printf("%s : ",Materia[j]);
                                                                if(elenco[i].voti[j] < 6){
                                                                                     textcolor(12);
                                                                                     printf("%2f \n",elenco[i].voti[j]);
                                                                                     textcolor(15);
                                                                }else{
                                                                      textcolor(2);
                                                                      printf("%2f \n",elenco[i].voti[j]);
                                                                      textcolor(15);
                                                                }
                                                          }
                                                          textcolor(15);
                                                          printf("Media Voti: %f \n",elenco[i].media);
                                                          printf("Voti Sufficenti: %d \n",elenco[i].suff);
                                                          printf("Voti Insufficenti: %d \n\n",elenco[i].indirizzo);
                                                          printf("--------------------------------");
                                                          getch();
                                                    }
                                               }break;
                                               
                                               case 2:{
                                                    system("CLS");
                                                    printf("Nr  Cognome      Nome       Mat Inf Ita Sto Ing \n");
                                                    printf("------------------------------------------------------------------------- \n\n");
                                                    for(i = 0; i < num_ele; i++){
                                                          printf(" %2d  ", i+1);
                                                          puts(elenco[i].cognome);
                                                          puts(elenco[i].nome);
                                                          for(j = 0;j < N_Materie;j++)
                                                          {
                                                           printf(" %2d",elenco[i].voti[j]);
                                                          }
                                                    }
                                                    printf("\n\n -------------------------------------------------------------------------\n");
                                                    getch(); 
                                               }
                                }
                                system("CLS");
                                printf("\n\n\n ------- Fine Visualizzazione -------\n");
                                getch()
                           }
                      }break;
                      
                      case 4:{
                           char ricerca[N];
                           int x;
                           bool trovato = false;
                           system("CLS");
                           if(!caricato){
                                         printf("DEVI ANCORA CARICARE LA RUBRICA");
                                         getch(); 
                           }else{
                                 if(!ordinato){
                                               printf("Ricerca per COGNOME con elenco NON ORDINATO");
                                               getch();
                                               do{
                                                  printf("\nRicerca cognome: ");
                                                  gets(ricerca);
                                                  nc = strlen(ricerca);
                                               }while(nc > N);
                                               printf("\n\nRisulati trovati:\n");
                                               for(i = 0; i < num_ele && trovato == false; i++){
                                                     x = strcmp(ricerca,elenco[i].cognome);
                                                     if(x == 0){
                                                          printf("%d) %s %s \n"i+1,elenco[i].nome,elenco[i].cognome);
                                                     }
                                               }
                                               if(!trovato){
                                                            printf("NESSUN RISULTATO TROVATO CON %s",ricerca);
                                               }
                                               getch();
                                 }else{
                                 }
                           }
                      }break;
                      
                      case 5:{
                           do{
                              system("CLS");
                              printf("\n\n Sei sicuro? (s/n S/N) ");
                              fflush(stdin);
                              scanf("%c", &risp);
                           }while(risp!='s'&&risp!='n'&&risp!='S'&&risp!='N');
                           if(risp=='n'||risp=='N'){
                                                    scelta=0;                
                           }
                      }
       }
    }while(scelta != 5);
}

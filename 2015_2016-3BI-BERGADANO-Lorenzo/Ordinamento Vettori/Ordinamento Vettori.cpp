#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<conio2.h>

char risp;
int const n = 5,z = 5;
int v[n],v2[z],vu[z+n],i,k,j,scelta,movimento,s,comodo,ricerca,y,li,ls,m;//i = v, k = v2, j = vu
bool vc = false,vo = false,vo2 = false,vc2 = false,vuc = false,flag,flag2,trovato = false,continuare = true;

void box(){
     y=5;
     gotoxy(48,y);
     printf("  _____________________________");
     gotoxy(48,y+1);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+2);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+3);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+4);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+5);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+6);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+7);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+8);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+9);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+10);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+11);
     printf(" %c                             %c",179,179);
     gotoxy(48,y+12);
     printf(" %c_____________________________%c",179,179);
}

void menu(){
            gotoxy(22,4);
            textbackground(0);
            textcolor(3);
            printf("ORDINAMENTO VETTORI");
            textcolor(15);
         gotoxy(20,7);
         textbackground(0);
         textcolor(15);
         printf("  Caricamento Vettore");
         gotoxy(20,9);
         textbackground(0);
         textcolor(15);
         printf("  Visualizzazione Vettore");
         gotoxy(20,11);
         textbackground(0);
         textcolor(15);
         printf("  Ordinamento Vettore");
         gotoxy(20,13);
         textbackground(0);
         textcolor(15);
         printf("  Ricerca Dicotomica");
         gotoxy(20,15);
         textbackground(0);
         textcolor(15);
         printf("  Ricerca Sequenziale");
         gotoxy(20,17);
         textbackground(0);
         textcolor(15);
         printf("  Unisci Vettori (Merge)");
         gotoxy(20,19);
         textbackground(0);
         textcolor(15);
         printf("  Esci");
}

void merge(){
     textbackground(0);
     textcolor(15);
     system("CLS");
     box();
     gotoxy(48,13);
     printf("< ");
     menu();
     y = 8;
     gotoxy(51,y);
     if(vc == true && vc2 == true && vo == true && vo2 == true){
           for(i=0,k=0,j=0;i < n && k < z; j++){
                             if(v[i] < v2[k]){
                                     vu[j] = v[i];
                                     i++;
                             }else{
                                   vu[j] = v2[k];
                                   k++;
                             }
           }
           if(i == n){
                do{
                   vu[j] = v2[k];
                   k++;
                   j++;
                }while(k < z);
           }else{
                 do{
                    vu[j] = v[i];
                    i++;
                    j++;
                 }while(i < n);
           }
           vuc = true;
           printf("Vettori uniti correttamente");
     }
     else{
          printf("Impossibile unire i");
          y++;
          gotoxy(51,y);
          printf("vettori, vettori non");
          y++;
          gotoxy(51,y);
          printf("caricati o ordinati");
     }
     getch();
}

void ricerca_dicotomica(){
     do{//inizio ripetizione
     textbackground(0);
     textcolor(15);
    system("CLS");
    
    do{//menu
    box();
    gotoxy(48,13);
    printf("< ");
    menu();
    scelta = 1;
    y = 8;
    gotoxy(51,y);
    textcolor(15);
    if(vc == false && vc2 == false && vo == false && vo2 == false){
          printf("Impossibile ricercare");
          y++;
          gotoxy(51,y);
          printf("i valori nei vettori");
          y = y + 2;
          gotoxy(51,y);
          printf("> Indietro");
          scelta = 5;
    }
    else{
         if(vc == false && vo == false){
               textcolor(12);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          else{
               textcolor(15);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          if(vc2 == false && vo2 == false){
                 textcolor(12);
                 printf("  Vettore 2");
                 y = y + 2;
                 gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Vettore 2");
               y = y + 2;
               gotoxy(51,y);
          }
           if(vuc == false){
                  textcolor(12);
                  printf("  Unione");
                  y = y + 2;
                  gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Unione");
               y = y + 2;
               gotoxy(51,y);
          }
          textcolor(15);
          printf("  Indietro");
          
    }
    movimento = getch();
    
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        y = 8;
                                        if(vc == true && vo == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true && vo2 == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 2");
                                        y = y + 2;
                                        if(vuc == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Unione");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   y = 8;
                                   if(vc == true && vo == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true && vo2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else if(scelta == 4){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true && vo == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true && vo2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        y = 8;
                                        if(vc == true && vo == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true && vo2 == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 2");
                                        y = y + 2;
                                        if(vuc == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Unione");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true && vo == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true && vo2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 4;
                                   y = 8;
                                   if(vc == true && vo == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true && vo2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("> Indietro");
                              }
                         }break;
                         case 13:{
                              textbackground(0);
                              textcolor(15);
                              if(scelta == 1){
                                        system("CLS");
                                        box();
                                        gotoxy(48,13);
                                        printf("< ");
                                        menu();
                                        y = 8;
                                        gotoxy(52,y);
                                        if(vc == true && vo == true){
                                        trovato = false;
                                        continuare = true;
                                        printf("Ricerca valore: ");
                                        scanf("%d",&ricerca);
                                        li = 0;
                                        ls = n - 1;
                                        do{
                                           m = (li + ls) / 2;
                                           if(ricerca == v[m]){
                                           trovato = true;
                                           continuare = false;
                                        }
                                        else{
                                             if(ricerca > v[m]){
                                                        li = m + 1;
                                             }
                                             else{
                                             ls = m - 1;
                                             }
                                             if(li > ls){
                                             continuare = false;
                                             }
                                             }
                                        }while(continuare == true);
                 
                                        y = y + 2;
                                        gotoxy(53,y);
                                        if(trovato){
                                        printf("Valore trovato alla ");
                                        gotoxy(52,y+1);
                                        printf("posizione %d dell'array 1",m + 1);
                                        }
                                        else{
                                        printf("Valore non trovato!");
                                        }
                                        getch();
                                        flag2 = true;
                                        }
                              }
                              else if(scelta == 2){
                                   system("CLS");
                                        box();
                                        gotoxy(48,13);
                                        printf("< ");
                                        menu();
                                        y = 8;
                                        gotoxy(52,y);
                                        if(vc2 == true && vo2 == true){
                                        trovato = false;
                                        continuare = true;
                                        printf("Ricerca valore: ");
                                        scanf("%d",&ricerca);
                                        li = 0;
                                        ls = n - 1;
                                        do{
                                           m = (li + ls) / 2;
                                           if(ricerca == v2[m]){
                                           trovato = true;
                                           continuare = false;
                                        }
                                        else{
                                             if(ricerca > v2[m]){
                                                        li = m + 1;
                                             }
                                             else{
                                             ls = m - 1;
                                             }
                                             if(li > ls){
                                             continuare = false;
                                             }
                                             }
                                        }while(continuare == true);
                 
                                        y = y + 2;
                                        gotoxy(53,y);
                                        if(trovato){
                                        printf("Valore trovato alla ");
                                        gotoxy(52,y+1);
                                        printf("posizione %d dell'array 2",m + 1);
                                        }
                                        else{
                                        printf("Valore non trovato!");
                                        }
                                        getch();
                                        flag2 = true;
                                        }
                              }
                              else if(scelta == 3){
                                          system("CLS");
                                          box();
                                          gotoxy(48,13);
                                          printf("< ");
                                          menu();
                                          y = 8;
                                          gotoxy(52,y);
                                          if(vuc == true){
                                        trovato = false;
                                        continuare = true;
                                        printf("Ricerca valore: ");
                                        scanf("%d",&ricerca);
                                        li = 0;
                                        ls = n - 1;
                                        do{
                                           m = (li + ls) / 2;
                                           if(ricerca == vu[m]){
                                           trovato = true;
                                           continuare = false;
                                        }
                                        else{
                                             if(ricerca > vu[m]){
                                                        li = m + 1;
                                             }
                                             else{
                                             ls = m - 1;
                                             }
                                             if(li > ls){
                                             continuare = false;
                                             }
                                             }
                                        }while(continuare == true);
                 
                                        y = y + 2;
                                        gotoxy(53,y);
                                        if(trovato){
                                        printf("Valore trovato alla ");
                                        gotoxy(52,y+1);
                                        printf("posizione %d dell'array merge",m + 1);
                                        }
                                        else{
                                        printf("Valore non trovato!");
                                        }
                                        getch();
                                        flag2 = true;
                                        }
                              }
                              else{
                                   scelta = 5;
                                   flag2 = true;
                              }
                              }
       }
       flag = true;
    }while(scelta != 5 && flag2 == false);
    }while(scelta != 5);
}

void ricerca_sequenziale(){
     do{//inizio ripetizione
     textbackground(0);
     textcolor(15);
    system("CLS");
    
    do{//menu
    box();
    gotoxy(48,15);
    printf("< ");
    menu();
    scelta = 1;
    y = 8;
    gotoxy(51,y);
    textcolor(15);
    if(vc == false && vc2 == false){
          printf("Impossibile ricercare");
          y++;
          gotoxy(51,y);
          printf("i valori nei vettori");
          y = y + 2;
          gotoxy(51,y);
          printf("> Indietro");
          scelta = 5;
    }
    else{
         if(vc == false){
               textcolor(12);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          else{
               textcolor(15);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          if(vc2 == false){
                 textcolor(12);
                 printf("  Vettore 2");
                 y = y + 2;
                 gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Vettore 2");
               y = y + 2;
               gotoxy(51,y);
          }
           if(vuc == false){
                  textcolor(12);
                  printf("  Unione");
                  y = y + 2;
                  gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Unione");
               y = y + 2;
               gotoxy(51,y);
          }
          textcolor(15);
          printf("  Indietro");
          
    }
    movimento = getch();
    
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        y = 8;
                                        if(vc == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 2");
                                        y = y + 2;
                                        if(vuc == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Unione");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else if(scelta == 4){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        y = 8;
                                        if(vc == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 2");
                                        y = y + 2;
                                        if(vuc == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Unione");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 4;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("> Indietro");
                              }
                         }break;
                         case 13:{
                              textbackground(0);
                              textcolor(15);
                              if(scelta == 1){
                                        system("CLS");
                                        box();
                                        gotoxy(48,15);
                                        printf("< ");
                                        menu();
                                        y = 8;
                                        gotoxy(52,y);
                                        if(vc == true){
                                        printf("Ricerca valore: ");
                                        scanf("%d",&ricerca);
                                        trovato = false;
                                        continuare = true;
     
                                        if(vo){
                                               for(i = 0;i < n && continuare == true;i++){
                                               if(ricerca == v[i]){
                                                          trovato = true;
                                                          continuare = false;
                                               }
                                               else if(ricerca < v[i]){
                                                    continuare = false;
                                               }
                                          }
                                        }
                                        else{
                                        for(i = 0;i < n && !trovato;i++){
                                        if(v[i] == ricerca){
                                                trovato = true;
                                          }
                                         }
                                        }
                                        y = y + 2;
                                        gotoxy(53,y);
                                        if(trovato){
                                                    printf("Valore trovato alla ");
                                                    gotoxy(52,y+1);
                                                    printf("posizione %d dell'array 1",i);
                                        }
                                        else{
                                             printf("Valore non trovato!");
                                        }
                                        getch();
                                        flag2 = true;
                                        }
                              }
                              else if(scelta == 2){
                                   if(vc2 == true){
                                          system("CLS");
                                          box();
                                          gotoxy(48,15);
                                          printf("< ");
                                          menu();
                                          y = 8;
                                          gotoxy(52,y);
                                        printf("Ricerca valore: ");
                                        scanf("%d",&ricerca);
                                        trovato = false;
                                        continuare = true;
                                        if(vo2){
                                               for(k = 0;k < z && continuare == true;k++){
                                               if(ricerca == v2[k]){
                                                          trovato = true;
                                                          continuare = false;
                                               }
                                               else if(ricerca < v2[k]){
                                                    continuare = false;
                                               }
                                          }
                                        }
                                        else{
                                        for(k = 0;k < z && !trovato;k++){
                                        if(v2[k] == ricerca){
                                                trovato = true;
                                          }
                                         }
                                        }
                                        y = y + 2;
                                        gotoxy(53,y);
                                        if(trovato){
                                                    printf("Valore trovato alla ");
                                                    gotoxy(52,y+1);
                                                    printf("posizione %d dell'array 2",k);
                                        }
                                        else{
                                             printf("Valore non trovato!");
                                        }
                                        getch();
                                        flag2 = true;
                                        }                  
                              }
                              else if(scelta == 3){
                                   if(vuc == true){
                                          system("CLS");
                                          box();
                                          gotoxy(48,15);
                                          printf("< ");
                                          menu();
                                          y = 8;
                                          gotoxy(52,y);
                                        printf("Ricerca valore: ");
                                        scanf("%d",&ricerca);
                                        trovato = false;
                                        continuare = true;
                                        for(j = 0;j < n+z && continuare == true;j++){
                                              if(ricerca == vu[j]){
                                                         trovato = true;
                                                         continuare = false;
                                               }
                                               else if(ricerca < vu[j]){
                                                    continuare = false;
                                               }
                                        }
                                        y = y + 2;
                                        gotoxy(53,y);
                                        if(trovato){
                                                    printf("Valore trovato alla ");
                                                    gotoxy(52,y+1);
                                                    printf("posizione %d dell'array",j);
                                        }
                                        else{
                                             printf("Valore non trovato!");
                                        }
                                        getch();
                                        flag2 = true;
                                        }  
                              }
                              else{
                                   scelta = 5;
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 5 && flag2 == false);
    }while(scelta != 5);
}

void ordina(){
     do{//inizio ripetizione
    system("CLS");
    
    do{//menu
    box();
    gotoxy(48,11);
    printf("< ");
    menu();
    scelta = 1;
    y = 8;
    gotoxy(51,y);
    textcolor(15);
    if(vc == false && vc2 == false){
          printf("Impossibile ordinare");
          y++;
          gotoxy(51,y);
          printf("i vettori");
          y = y + 2;
          gotoxy(51,y);
          printf("> Indietro");
          scelta = 4;
    }
    else{
         if(vc == false){
               textcolor(12);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          else{
               textcolor(15);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          if(vc2 == false){
                 textcolor(12);
                 printf("  Vettore 2");
                 y = y + 2;
                 gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Vettore 2");
               y = y + 2;
               gotoxy(51,y);
          }
          textcolor(15);
          printf("  Indietro");
    }
    movimento = getch();
    
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        y = 8;
                                        if(vc == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 2");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Vettore 2");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        y = 8;
                                        if(vc == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 2");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("> Indietro");
                              }
                         }break;
                         case 13:{
                              textbackground(0);
                              textcolor(15);
                              if(scelta == 1){
                                        if(vc == true){
                                              system("CLS");
                                              box();
                                              gotoxy(48,11);
                                              printf("< ");
                                              menu();
                                              y = 8;
                                              gotoxy(52,y);
                                              for(s = 1;s < n;s++){
                                              for(i = 0;i < n-s;i++){
                                              if(v[i] > v[i+1]){
                                                      comodo = v[i];
                                                      v[i] = v[i+1];
                                                      v[i+1] = comodo;
                                              }
                                              }
                                        }
                                        printf("Ordinamento crescente");
                                        gotoxy(52,y+1);
                                        printf("completato");
                                        vo = true;
                                        getch();
                                        flag2 = true;
                              }        
                              }
                              else if(scelta == 2){
                                   if(vc2 == true){
                                          system("CLS");
                                              box();
                                              gotoxy(48,11);
                                              printf("< ");
                                              menu();
                                              y = 8;
                                              gotoxy(52,y);
                                              for(s = 1;s < z;s++){
                                              for(k = 0;k < z-s;k++){
                                              if(v2[k] > v2[k+1]){
                                                      comodo = v2[k];
                                                      v2[k] = v2[k+1];
                                                      v2[k+1] = comodo;
                                              }
                                              }
                                        }
                                        printf("Ordinamento crescente");
                                        gotoxy(52,y+1);
                                        printf("completato");
                                        vo2 = true;
                                        getch();
                                        flag2 = true;
                              }
                              }
                              else{
                                   scelta = 4;
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 4 && flag2 == false);
    }while(scelta != 4);
}
void visualizza(){
     do{//inizio ripetizione
    system("CLS");
    
    do{//menu
    box();
    gotoxy(48,9);
    printf("< ");
    menu();
    scelta = 1;
    y = 8;
    gotoxy(51,y);
    textcolor(15);
    if(vc == false && vc2 == false){
          printf("Impossibile visualizzare");
          y++;
          gotoxy(51,y);
          printf("i vettori");
          y = y + 2;
          gotoxy(51,y);
          printf("> Indietro");
          scelta = 5;
    }
    else{
         if(vc == false){
               textcolor(12);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          else{
               textcolor(15);
               printf("> Vettore 1");
               y = y + 2;
               gotoxy(51,y);
          }
          if(vc2 == false){
                 textcolor(12);
                 printf("  Vettore 2");
                 y = y + 2;
                 gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Vettore 2");
               y = y + 2;
               gotoxy(51,y);
          }
           if(vuc == false){
                  textcolor(12);
                  printf("  Unione");
                  y = y + 2;
                  gotoxy(51,y);
           }
           else{
               textcolor(15);
               printf("  Unione");
               y = y + 2;
               gotoxy(51,y);
          }
          textcolor(15);
          printf("  Indietro");
          
    }
    movimento = getch();
    
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        y = 8;
                                        if(vc == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 2");
                                        y = y + 2;
                                        if(vuc == true){
                                              textcolor(15);
                                        }
                                        else{
                                             textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Unione");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else if(scelta == 4){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        y = 8;
                                        if(vc == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Vettore 1");
                                        y = y + 2;
                                        if(vc2 == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("> Vettore 2");
                                        y = y + 2;
                                        if(vuc == true){
                                              textcolor(15);
                                         }
                                         else{
                                              textcolor(12);
                                        }
                                        gotoxy(51,y);
                                        printf("  Unione");
                                        y = y + 2;
                                        textcolor(15);
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("> Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 4;
                                   y = 8;
                                   if(vc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   if(vc2 == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   if(vuc == true){
                                         textcolor(15);
                                   }
                                   else{
                                        textcolor(12);
                                   }
                                   gotoxy(51,y);
                                   printf("  Unione");
                                   y = y + 2;
                                   textcolor(15);
                                   gotoxy(51,y);
                                   printf("> Indietro");
                              }
                         }break;
                         case 13:{
                              textbackground(0);
                              textcolor(15);
                              if(scelta == 1){
                                        if(vc == true){
                                              system("CLS");
                                              box();
                                              gotoxy(48,9);
                                              printf("< ");
                                              menu();
                                              y = 8;
                                              gotoxy(52,y);
                                              if(vo == true){
                                                    printf("Visualizzazione Vettore 1");
                                                    y++;
                                                    gotoxy(60,y);
                                                    printf("ORDINATO");
                                                    y = y + 2;
                                                    for(i = 0;i < n;i++){
                                                          gotoxy(53,y);
                                                          printf("%d) %d",i+1,v[i]);
                                                          y++;
                                                    }
                                              }else{
                                                    printf("Visualizzazione Vettore 1");
                                                    y++;
                                                    gotoxy(57,y);
                                                    printf("NON ORDINATO");
                                                    y = y + 2;
                                                    for(i = 0;i < n;i++){
                                                          gotoxy(53,y);
                                                          printf("%d) %d",i+1,v[i]);
                                                          y++;
                                                    }
                                              }
                                              getch();
                                              flag2 = true;
                                        }
                              }
                              else if(scelta == 2){
                                   if(vc2 == true){
                                              system("CLS");
                                              box();
                                              gotoxy(48,9);
                                              printf("< ");
                                              menu();
                                              y = 8;
                                              gotoxy(52,y);
                                              if(vo2 == true){
                                                    printf("Visualizzazione Vettore 2");
                                                    y++;
                                                    gotoxy(60,y);
                                                    printf("ORDINATO");
                                                    y = y + 2;
                                                    for(k = 0;k < z;k++){
                                                          gotoxy(53,y);
                                                          printf("%d) %d",k+1,v2[k]);
                                                          y++;
                                                    }
                                              }else{
                                                    printf("Visualizzazione Vettore 2");
                                                    y++;
                                                    gotoxy(57,y);
                                                    printf("NON ORDINATO");
                                                    y = y + 2;
                                                    for(k = 0;k < z;k++){
                                                          gotoxy(53,y);
                                                          printf("%d) %d",k+1,v2[k]);
                                                          y++;
                                                    }
                                              }
                                              getch();
                                              flag2 = true;
                                        }
                              }
                              else if(scelta == 3){
                                   if(vuc == true){
                                              system("CLS");
                                              box();
                                              gotoxy(48,9);
                                              printf("< ");
                                              menu();
                                              y = 8;
                                              gotoxy(51,y);
                                              printf("Visualizzazione Vettore");
                                              y = y + 2;
                                              for(int x = 53,j = 0;j < n+z;j++){
                                                    gotoxy(x,y);
                                                    printf("%d) %d",j+1,vu[j]);
                                                    y++;
                                                    if(y == 15){
                                                         y = 10;
                                                         x = 66;
                                                    }
                                              }
                                              getch();
                                              flag2 = true;
                                        }
                              }
                              else{
                                   scelta = 5;
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 5 && flag2 == false);
    }while(scelta != 5);
}

void carica(){
     do{//inizio ripetizione
    system("CLS");
    
    do{//menu
    box();
    gotoxy(48,7);
    printf("< ");
    menu();
    scelta = 1;
    y = 8;
    gotoxy(51,y);
    printf("> Vettore 1");
    y = y + 2;
    gotoxy(51,y);
    printf("  Vettore 2");
    y = y + 2;
    gotoxy(51,y);
    printf("  Indietro");
    movimento = getch();
    
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        y = 8;
                                        gotoxy(51,y);
                                        printf("> Vettore 1");
                                        y = y + 2;
                                        gotoxy(51,y);
                                        printf("  Vettore 2");
                                        y = y + 2;
                                        gotoxy(51,y);
                                        printf("  Indietro");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   y = 8;
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   gotoxy(51,y);
                                   printf("> Vettore 2");
                                   y = y + 2;
                                   gotoxy(51,y);
                                   printf("  Indietro");
                              }
                              else{
                                   scelta = scelta;
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        y = 8;
                                        gotoxy(51,y);
                                        printf("  Vettore 1");
                                        y = y + 2;
                                        gotoxy(51,y);
                                        printf("> Vettore 2");
                                        y = y + 2;
                                        gotoxy(51,y);
                                        printf("  Indietro");
                                   
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   y = 8;
                                   gotoxy(51,y);
                                   printf("  Vettore 1");
                                   y = y + 2;
                                   gotoxy(51,y);
                                   printf("  Vettore 2");
                                   y = y + 2;
                                   gotoxy(51,y);
                                   printf("> Indietro");
                              }
                              else{
                                   scelta = scelta;
                              }
                         }break;
                         case 13:{
                              textbackground(0);
                              textcolor(15);
                              if(scelta == 1){
                                        system("CLS");
                                        box();
                                        gotoxy(48,7);
                                        printf("< ");
                                        menu();
                                        y = 8;
                                        gotoxy(54,y);
                                        printf("VETTORE 1");
                                        for(i = 0;i < n;i++){
                                              y++;
                                              gotoxy(51,y);
                                              printf("%d) ",i+1);
                                              scanf("%d",&v[i]);
                                        }                                  
                                        vc = true;
                                        flag2 = true;
                              }
                              else if(scelta == 2){
                                   system("CLS");
                                   box();
                                   gotoxy(48,7);
                                   printf("< ");
                                   menu();
                                   y = 8;
                                   gotoxy(54,y);
                                   printf("VETTORE 2");
                                   for(k = 0;k < z;k++){
                                         y++;
                                         gotoxy(51,y);
                                         printf("%d) ",k+1);
                                         scanf("%d",&v2[k]);
                                   }                                  
                                   vc2 = true;
                                   flag2 = true;
                              }
                              else{
                                   scelta = 4;
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 4 && flag2 == false);
    }while(scelta != 4);
}



int main(){
    vo = false;
    vo2 = false;
    vc = false;
    vc2 = false;
    vuc = false;
    do{//inizio ripetizione
    system("CLS");
    
    do{//menu
    menu();
    gotoxy(20,7);
    textbackground(15);
    textcolor(0);
    printf("> Caricamento Vettore");
    scelta = 1;
    movimento = getch();
    
    }while(movimento != 13 && movimento != 80 && movimento != 72);//80 = GIU 72 = SU 13 = INVIO
    
    flag = false;
    
    do{
       flag2 = false;
       if(flag == true){
               movimento = getch();
       }
       switch(movimento){
                         case 72:{
                              if(scelta == 2){
                                        scelta = 1;
                                        menu();
                                        gotoxy(20,7);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Caricamento Vettore");
                              }
                              else if(scelta == 3){
                                   scelta = 2;
                                   menu();
                                   gotoxy(20,9);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Visualizzazione Vettore");
                              }
                              else if(scelta == 4){
                                   scelta = 3;
                                   menu();
                                   gotoxy(20,11);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ordinamento Vettore");
                              }
                              else if(scelta == 5){
                                   scelta = 4;
                                   menu();
                                   gotoxy(20,13);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ricerca Dicotomica");
                              }
                              else if(scelta == 6){
                                   scelta = 5;
                                   menu();
                                   gotoxy(20,15);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ricerca Sequenziale");
                              }
                              else if(scelta == 7){
                                   scelta = 6;
                                   menu();
                                   gotoxy(20,17);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("  Unisci Vettori (Merge)");
                              }
                              else{
                                   scelta = scelta;
                              }
                         }break;
                         case 80:{
                              if(scelta == 1){
                                        scelta = 2;
                                        menu();
                                        gotoxy(20,9);
                                        textbackground(15);
                                        textcolor(0);
                                        printf("> Visualizzazione Vettore");
                                   
                              }
                              else if(scelta == 2){
                                   scelta = 3;
                                   menu();
                                   gotoxy(20,11);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ordinamento Vettore");
                              }
                              else if(scelta == 3){
                                   scelta = 4;
                                   menu();
                                   gotoxy(20,13);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ricerca Dicotomica");
                              }
                              else if(scelta == 4){
                                   scelta = 5;
                                   menu();
                                   gotoxy(20,15);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Ricerca Sequenziale");
                              }
                              else if(scelta == 5){
                                   scelta = 6;
                                   menu();
                                   gotoxy(20,17);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Unisci Vettori (Merge)");
                              }
                              else if(scelta == 6){
                                   scelta = 7;
                                   menu();
                                   gotoxy(20,19);
                                   textbackground(15);
                                   textcolor(0);
                                   printf("> Esci");
                              }
                              else{
                                   scelta = scelta;
                              }
                         }break;
                         case 13:{
                              textbackground(0);
                              textcolor(15);
                              if(scelta == 1){
                                        carica();
                                        flag2 = true;
                              }
                              else if(scelta == 2){
                                   visualizza();
                                   flag2 = true;
                              }
                              else if(scelta == 3){
                                   ordina();
                                   flag2 = true;
                              }
                              else if(scelta == 4){
                                   ricerca_dicotomica();
                                   flag2 = true;
                              }
                              else if(scelta == 5){
                                   ricerca_sequenziale();
                                   flag2 = true;
                              }
                              else if(scelta == 6){
                                   merge();
                                   flag2 = true;
                              }
                              else{
                                   textcolor(15);
                                   textbackground(0);
                                   system("CLS");
                                   box();
                                   gotoxy(48,17);
                                   printf("< ");
                                   menu();
                                   y = 8;
                                   
                                   do{
                                      gotoxy(51,y);
                                      printf("Vuoi veramente uscire?(s/n)");
                                      gotoxy(53,y+2);
                                      printf("                  ");
                                      gotoxy(53,y+2);
                                      printf("--> ");
                                      fflush(stdin);
                                      scanf("%c",&risp);
                                   }while(risp != 's' && risp != 'S' && risp != 'n' && risp != 'N');
                                   
                                   if(risp == 'N'|| risp == 'n'){
                                           scelta = 0;
                                   }
                                   else{
                                        scelta = 8;
                                   }
                                   flag2 = true;
                              }
                         }
       }
       flag = true;
    }while(scelta != 8 && flag2 == false);
    }while(scelta != 8);
    
}

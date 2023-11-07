#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
#include<string.h>
#include<ctype.h>

int verifica_data(int anno, int mese, int giorno){
    int data_ok = 1,gf;
    if((mese == 4 || mese == 6 || mese == 9 || mese == 11) && giorno > 30){
             data_ok = 0;
    }else if(mese == 2){
          if(anno % 400 == 0 || (anno % 100 != 0 && anno % 4 == 0)){
                  gf = 29;
          }else{
                gf = 28;
          }
          if(giorno > gf){data_ok = 0;}
    }
    return(data_ok);
}

POINT mouse;
FILE *fp;
char dati[8][30];//RIGE: 0=cognome, 1=nome, 2=anno, 3=mese, 4=sesso, 5=giorno, 6=citta, 7=codice finale

int main(){
    int x,y;
    bool esci = false;
    
    textbackground(0);
    system("CLS");
    void titolo(); void voce_menu1(int colore); void voce_menu2(int colore); void box(); void textbox();
    void calcolo();
    
    titolo();
    
    while(esci == false){
               GetCursorPos(&mouse);
               x = mouse.x;
               y = mouse.y;
               /*gotoxy(1,1);
               printf("x:%d      \n",x);
               printf("y:%d        ",y);*/
               
               if(y >= 164 && y <= 199 && x >= 478 && x<= 788){
                    voce_menu1(11);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){//Inizio Calcolo
                                                   calcolo();
                                                   system("CLS");
                                                   titolo();             
                    }
               }
               else if(y >= 211 && y <= 246 && x >= 478 && x<= 788){
                    voce_menu2(11);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){//Esci
                                                    esci = true;         
                    }
               }
               else{
                    voce_menu1(9); voce_menu2(9);
               }
    }
}
//Titolo Box e Textbox
void titolo(){
     textcolor(12);
     gotoxy(20,3);
     printf(" ___   ___         ___   ___         ___         ___   ___   ___   ___   ___   ___         ___   ___   ___   ___   ___         ___");
     gotoxy(20,4);
     printf("|     |   | |     |     |   | |     |   |       |     |   |   | |   |   |     |           |       |   |     |     |   | |     |   ");
     gotoxy(20,5);
     printf("|     |-+-| |     |     |   | |     |   |       |     |   |   + |   +   |     |-+-        |-+-    +    -+-  |     |-+-| |     |-+-");
     gotoxy(20,6);
     printf("|     |   | |     |     |   | |     |   |       |     |   |   | |   |   |     |           |       |       | |     |   | |     |   ");
     gotoxy(20,7);
     printf(" ---         ---   ---   ---   ---   ---         ---   ---   ---   ---   ---   ---               ---   ---   ---         ---   ---");
     textcolor(15);
}
void box(){
     int carattere = 219,i,x,y;
     x = 8;
     y = 13;
     gotoxy(x,y);
     for(i = 0; i < 70; i++){//lato orizzontale alto
           x++;
           gotoxy(x,y);
           printf("%c",carattere);
     }
     for(i = 0; i < 40; i++){//lato verticale destro
           y++;
           gotoxy(x,y);
           printf("%c",carattere);
     }
     for(i = 0; i < 70; i++){//lato orizzontale basso
           x--;
           gotoxy(x,y);
           printf("%c",carattere);
     }
     for(i = 0; i < 40; i++){//lato verticale sinistro
           y--;
           gotoxy(x,y);
           printf("%c",carattere);
     }
     
}
void textbox(){
     //Cognome
     textbackground(0);textcolor(15);
     gotoxy(25,15);
     for(int i = 0; i < 40; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,16);
     printf("   cognome                              ");
     gotoxy(25,17);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 40; i++){
             printf("%c",223);
     }
     //Nome
     textbackground(0);textcolor(15);
     gotoxy(25,19);
     for(int i = 0; i < 40; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,20);
     printf("   nome                                 ");
     gotoxy(25,21);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 40; i++){
             printf("%c",223);
     }
     //Anno
     textbackground(0);textcolor(15);
     gotoxy(25,23);
     for(int i = 0; i < 12; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,24);
     printf("   anno     ");
     gotoxy(25,25);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 12; i++){
             printf("%c",223);
     }
     //Mese
     textbackground(0);textcolor(15);
     gotoxy(25,27);
     for(int i = 0; i < 12; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,28);
     printf("   mese     ");
     gotoxy(25,29);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 12; i++){
             printf("%c",223);
     }
     //Giorno
     textbackground(0);textcolor(15);
     gotoxy(25,31);
     for(int i = 0; i < 12; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,32);
     printf("   giorno   ");
     gotoxy(25,33);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 12; i++){
             printf("%c",223);
     }
     //Sesso
     textbackground(0);textcolor(15);
     gotoxy(25,35);
     for(int i = 0; i < 40; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,36);
     printf("   sesso                                ");
     gotoxy(25,37);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 40; i++){
             printf("%c",223);
     }
     //Citta
     textbackground(0);textcolor(15);
     gotoxy(25,39);
     for(int i = 0; i < 40; i++){
             printf("%c",220);
     }
     textbackground(15);textcolor(7);
     gotoxy(25,40);
     printf("   citta'                               ");
     gotoxy(25,41);
     textbackground(0);textcolor(15);
     for(int i = 0; i < 40; i++){
             printf("%c",223);
     }
     textbackground(0);
}

//Voci Menu
void voce_menu1(int colore){
     textbackground(colore);
     gotoxy(60,12);
     printf("                                       ");
     gotoxy(60,13);
     printf("             INIZIA CALCOLO            ");
     gotoxy(60,14);
     printf("                                       ");
     textbackground(0);
}
void voce_menu2(int colore){
     textbackground(colore);
     gotoxy(60,16);
     printf("                                       ");
     gotoxy(60,17);
     printf("                  ESCI                 ");
     gotoxy(60,18);
     printf("                                       ");
     textbackground(0);
}


//INIZIO PROGRAMMA
void calcolo(){
     char S[30];
     bool esci = false;
     int nc,i,count,indice_matrice,g,m,a,flagData = 0,data_valida;
     
     system("CLS");
     titolo();
    // box();
     textbox();
     gotoxy(15,16);
     printf("Cognome: ");
     gotoxy(15,20);
     printf("Nome: ");
     gotoxy(15,24);
     printf("Anno: ");
     gotoxy(15,28);
     printf("Mese: ");
     gotoxy(15,32);
     printf("Giorno: ");
     gotoxy(15,36);
     printf("Sesso: ");
     gotoxy(15,40);
     printf("Citta': ");
     
     textbackground(9);
     gotoxy(27,45);
     printf("                               ");
     gotoxy(27,46);
     printf("            ANNULLA            ");
     gotoxy(27,47);
     printf("                               ");
     textbackground(0);
     
     while(esci == false){
                GetCursorPos(&mouse);
                gotoxy(1,1);
                printf("x:%d      \n",mouse.x);
                printf("y:%d        ",mouse.y);
                //cognome
                if(mouse.y >= 204 && mouse.y <= 227 && mouse.x >= 115 && mouse.x<= 518){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[0]);//cancelliamo la stringa cognome
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[0][i] = ' ';
                                                          }
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    gotoxy(25,16);
                                                    printf("                                        ");
                                                    gotoxy(27,16);
                                                    fflush(stdin);
                                                    gets(dati[0]);
                                                    nc = strlen(dati[0]);
                                                    //Elaboro cognome
                                                    for(i = 0; i < nc; i++){
                                                          S[i] = tolower(dati[0][i]);
                                                    }
                                                    S[i] = '\0';
                                                    //Automa Riconoscitore
                                                    i = 0;
                                                    count = 0;
                                                    while(i < nc){
                                                            for(;(S[i]<'a' || S[i]>'z') && (S[i] == ' ') && i<nc; i++);
                                                            if(i < nc){
                                                                 for(;(S[i]>='a' && S[i]<='z') || !(S[i] == ' ') && i < nc; i++){
                                                                                 if(S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u'){
                                                                                         //E' una consonante
                                                                                         if(count < 3){
                                                                                                  dati[7][count] = S[i];
                                                                                                  count++;
                                                                                         }
                                                                                 }
                                                                                 
                                                                 }
                                                            }
                                                    }
                                                    if(count < 3){
                                                             i = 0;
                                                             while(i < nc){
                                                            for(;(S[i]<'a' || S[i]>'z') && !(S[i] == ' ') && i<nc; i++);
                                                            if(i < nc){
                                                                 for(;(S[i]>='a' && S[i]<='z') || (S[i] == ' ') && i < nc; i++){
                                                                                 if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u'){
                                                                                         //E' una vocale
                                                                                         if(count < 3){
                                                                                                  dati[7][count] = S[i];
                                                                                                  count++;
                                                                                         }
                                                                                 }
                                                                                 
                                                                 }
                                                            }
                                                    }
                                                    }
                                                    if(count < 3){
                                                             for(; count < 3; count++){
                                                                   dati[7][count] = 'X';
                                                             }
                                                    }
                                                    
                    }
               }
               //nome
               else if(mouse.y >= 263 && mouse.y <= 277 && mouse.x >= 115 && mouse.x<= 518){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[1]);//cancelliamo la stringa nome
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[1][i] = ' ';
                                                          }
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    gotoxy(25,20);
                                                    printf("                                        ");
                                                    gotoxy(27,20);
                                                    gets(dati[1]);
                                                    nc = strlen(dati[1]);
                                                    //Elaboro Nome
                                                    for(i = 0; i < nc; i++){
                                                          S[i] = tolower(dati[1][i]);
                                                    }
                                                    S[i] = '\0';
                                                    i = 0;
                                                    count = 0;
                                                    //Automa Riconoscitore per contare le consonanti
                                                    while(i < nc){
                                                            for(;(S[i]<'a' || S[i]>'z') && i<nc; i++);
                                                            if(i < nc){
                                                                 for(;(S[i]>='a' && S[i]<='z') && i < nc; i++){
                                                                                 if(S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u'){
                                                                                         //E' una consonante
                                                                                         count++;
                                                                                 }
                                                                                 
                                                                 }
                                                            }
                                                    }
                                                    if(count <= 3){//Si comporta come il cognome
                                                          i = 0;
                                                          count = 0;
                                                          while(i < nc){
                                                            for(;(S[i]<'a' || S[i]>'z') && (S[i] == ' ') && i<nc; i++);
                                                            if(i < nc){
                                                                 for(;(S[i]>='a' && S[i]<='z') || !(S[i] == ' ') && i < nc; i++){
                                                                                 if(S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u'){
                                                                                         //E' una consonante
                                                                                         if(count < 3){
                                                                                                  dati[7][count+3] = S[i];
                                                                                                  count++;
                                                                                         }
                                                                                 }
                                                                                 
                                                                 }
                                                            }
                                                    }
                                                    if(count < 3){
                                                             i = 0;
                                                             while(i < nc){
                                                            for(;(S[i]<'a' || S[i]>'z') && !(S[i] == ' ') && i<nc; i++);
                                                            if(i < nc){
                                                                 for(;(S[i]>='a' && S[i]<='z') || (S[i] == ' ') && i < nc; i++){
                                                                                 if(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u'){
                                                                                         //E' una vocale
                                                                                         if(count < 3){
                                                                                                  dati[7][count+3] = S[i];
                                                                                                  count++;
                                                                                         }
                                                                                 }
                                                                                 
                                                                 }
                                                            }
                                                    }
                                                    }
                                                    if(count < 3){
                                                             for(; count < 3; count++){
                                                                   dati[7][count+3] = 'X';
                                                             }
                                                    }    
                                                    }else if(count > 3){
                                                          i = 0;
                                                          count = 0;
                                                          indice_matrice = 3;
                                                          while(i < nc){
                                                            for(;(S[i]<'a' || S[i]>'z') && (S[i] == ' ') && i<nc; i++);
                                                            if(i < nc){
                                                                 for(;(S[i]>='a' && S[i]<='z') || !(S[i] == ' ') && i < nc; i++){
                                                                                 if(S[i] != 'a' && S[i] != 'e' && S[i] != 'i' && S[i] != 'o' && S[i] != 'u'){
                                                                                         //E' una consonante
                                                                                         if(count != 1){
                                                                                                  if(count <= 3){
                                                                                                           dati[7][indice_matrice] = S[i];
                                                                                                           indice_matrice++;
                                                                                                           count++;
                                                                                                  }
                                                                                         }else{
                                                                                               count++;
                                                                                         }
                                                                                 }
                                                                                 
                                                                 }
                                                            }
                                                    }
                                                    }
                    }
               }
               //anno
               else if(mouse.y >= 301 && mouse.y <= 324 && mouse.x >= 115 && mouse.x<= 294){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[2]);//cancelliamo la stringa anno
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[2][i] = ' ';
                                                          }
                                                          flagData--;
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    do{
                                                        gotoxy(25,24);
                                                        printf("            ");
                                                        gotoxy(27,24);
                                                        gets(dati[2]);
                                                        nc = strlen(dati[2]);
                                                        a = atoi(dati[2]);//Conversione da stringa a intero
                                                        /*if(a >= 1900){
                                                             errore(2);
                                                        }*/
                                                    }while(a <= 1900 || a >= 2017);
                                                    flagData++;
                                                    if(flagData == 3){
                                                          data_valida = verifica_data(a, m, g);
                                                          if(data_valida){
                                                                          //anno
                                                                          dati[7][6] = dati[2][2];
                                                                          dati[7][7] = dati[2][3];
                                                                          //mese
                                                                          if(m == 1){
                                                                               dati[7][8] = 'A';
                                                                          }else if(m == 2){
                                                                                dati[7][8] = 'B';
                                                                          }else if(m == 3){
                                                                                dati[7][8] = 'C';
                                                                          }else if(m == 4){
                                                                                dati[7][8] = 'D';
                                                                          }else if(m == 5){
                                                                                dati[7][8] = 'E';
                                                                          }else if(m == 6){
                                                                                dati[7][8] = 'H';
                                                                          }else if(m == 7){
                                                                                dati[7][8] = 'L';
                                                                          }else if(m == 8){
                                                                                dati[7][8] = 'M';
                                                                          }else if(m == 9){
                                                                                dati[7][8] = 'P';
                                                                          }else if(m == 10){
                                                                                dati[7][8] = 'R';
                                                                          }else if(m == 11){
                                                                                dati[7][8] = 'S';
                                                                          }else if(m == 12){
                                                                                dati[7][8] = 'T';
                                                                          }
                                                                          //giorno
                                                                          if(g < 10){
                                                                               dati[7][9] = '0';
                                                                               dati[7][10] = dati[4][0];
                                                                          }else{
                                                                                dati[7][9] = dati[4][0];
                                                                                dati[7][10] = dati[4][1];
                                                                          }
                                                          }else{
                                                                /*errore(2);*/
                                                          }
                                                    }
                    }
               }
               //mese
               else if(mouse.y >= 349 && mouse.y <= 373 && mouse.x >= 115 && mouse.x<= 294){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[3]);//cancelliamo la stringa mese
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[3][i] = ' ';
                                                          }
                                                          flagData--;
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    do{
                                                       gotoxy(25,28);
                                                       printf("            ");
                                                       gotoxy(27,28);
                                                       gets(dati[3]);
                                                       nc = strlen(dati[3]);
                                                       m = atoi(dati[3]);
                                                    }while(m <= 1 && m >= 12);
                                                    flagData++;
                                                    if(flagData == 3){
                                                          data_valida = verifica_data(a, m, g); 
                                                          if(data_valida){
                                                                          //anno
                                                                          dati[7][6] = dati[2][2];
                                                                          dati[7][7] = dati[2][3];
                                                                          //mese
                                                                          if(m == 1){
                                                                               dati[7][8] = 'A';
                                                                          }else if(m == 2){
                                                                                dati[7][8] = 'B';
                                                                          }else if(m == 3){
                                                                                dati[7][8] = 'C';
                                                                          }else if(m == 4){
                                                                                dati[7][8] = 'D';
                                                                          }else if(m == 5){
                                                                                dati[7][8] = 'E';
                                                                          }else if(m == 6){
                                                                                dati[7][8] = 'H';
                                                                          }else if(m == 7){
                                                                                dati[7][8] = 'L';
                                                                          }else if(m == 8){
                                                                                dati[7][8] = 'M';
                                                                          }else if(m == 9){
                                                                                dati[7][8] = 'P';
                                                                          }else if(m == 10){
                                                                                dati[7][8] = 'R';
                                                                          }else if(m == 11){
                                                                                dati[7][8] = 'S';
                                                                          }else if(m == 12){
                                                                                dati[7][8] = 'T';
                                                                          }
                                                                          //giorno
                                                                          if(g < 10){
                                                                               dati[7][9] = '0';
                                                                               dati[7][10] = dati[4][0];
                                                                          }else{
                                                                                dati[7][9] = dati[4][0];
                                                                                dati[7][10] = dati[4][1];
                                                                          }
                                                          } 
                                                    }
                    }
               }
               //giorno
               else if(mouse.y >= 396 && mouse.y <= 422 && mouse.x >= 115 && mouse.x<= 294){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[4]);//cancelliamo la stringa giorno
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[4][i] = ' ';
                                                          }
                                                          flagData--;
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    do{
                                                       gotoxy(25,32);
                                                       printf("            ");
                                                       gotoxy(27,32);
                                                       gets(dati[4]);
                                                       nc = strlen(dati[4]);
                                                       g = atoi(dati[4]);
                                                    }while(g <= 1 && g >= 31);
                                                    flagData++;
                                                    if(flagData == 3){
                                                          data_valida = verifica_data(a, m, g);
                                                          if(data_valida){
                                                                          //anno
                                                                          dati[7][6] = dati[2][2];
                                                                          dati[7][7] = dati[2][3];
                                                                          //mese
                                                                          if(m == 1){
                                                                               dati[7][8] = 'A';
                                                                          }else if(m == 2){
                                                                                dati[7][8] = 'B';
                                                                          }else if(m == 3){
                                                                                dati[7][8] = 'C';
                                                                          }else if(m == 4){
                                                                                dati[7][8] = 'D';
                                                                          }else if(m == 5){
                                                                                dati[7][8] = 'E';
                                                                          }else if(m == 6){
                                                                                dati[7][8] = 'H';
                                                                          }else if(m == 7){
                                                                                dati[7][8] = 'L';
                                                                          }else if(m == 8){
                                                                                dati[7][8] = 'M';
                                                                          }else if(m == 9){
                                                                                dati[7][8] = 'P';
                                                                          }else if(m == 10){
                                                                                dati[7][8] = 'R';
                                                                          }else if(m == 11){
                                                                                dati[7][8] = 'S';
                                                                          }else if(m == 12){
                                                                                dati[7][8] = 'T';
                                                                          }
                                                                          //giorno
                                                                          if(g < 10){
                                                                               dati[7][9] = '0';
                                                                               dati[7][10] = dati[4][0];
                                                                          }else{
                                                                                dati[7][9] = dati[4][0];
                                                                                dati[7][10] = dati[4][1];
                                                                          }
                                                          } 
                                                    }
                    }
               }
               //sesso
               else if(mouse.y >= 444 && mouse.y <= 469 && mouse.x >= 115 && mouse.x<= 518){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[5]);//cancelliamo la stringa sesso
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[5][i] = ' ';
                                                          }
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    do{
                                                       gotoxy(25,36);
                                                       printf("                                        ");
                                                       gotoxy(27,36);
                                                       gets(dati[5]);
                                                       nc = strlen(dati[5]);
                                                       //Elaboro sesso
                                                       for(i = 0; i < nc; i++){
                                                             S[i] = tolower(dati[5][i]);
                                                       }
                                                       S[i] = '\0';
                                                    }while(S[0] < 'a' || S[0] > 'z');
                                                    //Controllo
                                                    if(S[0] == 'f'){
                                                            char c[3];
                                                            g = g + 40;
                                                            sprintf(c, "%d", g);
                                                            dati[7][9] = c[0];
                                                            dati[7][10] = c[1];
                                                    }    
                    }
               }
               //citta
               else if(mouse.y >= 492 && mouse.y <= 517 && mouse.x >= 115 && mouse.x<= 518){
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    nc = strlen(dati[6]);//cancelliamo la stringa cognome
                                                    if(nc > 0){
                                                          for(i = 0;i < nc;i++){
                                                                dati[6][i] = ' ';
                                                          }
                                                    }
                                                    textbackground(15);textcolor(8);
                                                    gotoxy(25,40);
                                                    printf("                                        ");
                                                    gotoxy(27,40);
                                                    gets(dati[6]);
                                                    nc = strlen(dati[6]);
                                                    //Elaboro citta
                                                    for(i = 0; i < nc; i++){
                                                          S[i] = tolower(dati[6][i]);
                                                    }
                                                    S[i] = '\0';
                                                    //GESTIONE FILE
                                                    char citta[20],codice[20];
                                                    int ris,ncc;
                                                    bool trovato = false;
                                                    fp = fopen("nomi_codici.txt","r");
                                                    if(fp){
                                                          while(!feof(fp) || trovato == false){
                                                                           fscanf(fp,"%s",&citta);//Acquisisco la citta del file
                                                                           fscanf(fp,"%s",&codice);//Acquisisco il codice
                                                                           //ELABORO CITTA DEL FILE
                                                                           ncc = strlen(citta);
                                                                           for(i = 0; i < ncc; i++){
                                                                                 citta[i] = tolower(citta[i]);
                                                                           }
                                                                           citta[i] = '\0';
                                                                           ris = strcmp(S,citta);
                                                                           if(ris == 0){
                                                                                  indice_matrice = 11;
                                                                                  ncc = strlen(codice);
                                                                                  for(i = 0; i < ncc; i++){
                                                                                        dati[7][indice_matrice] = codice[i];
                                                                                        indice_matrice++;
                                                                                  }
                                                                                  trovato = true;
                                                                           }
                                                          }
                                                    }else{
                                                          printf("Impossibile aprire il file... Controllare la directory");
                                                    }
                                                    fclose(fp);
                    }
               }
               else{
                    int y = 20;
                    gotoxy(80,y);
                    for(int r = 0; r < 8; r++){
                            y++;
                            gotoxy(80,y);
                            for(int c = 0; c < 19; c++){
                                    printf("%c",dati[r][c]);
                            }
                    }
               }
     }
}

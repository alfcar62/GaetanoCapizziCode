#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include<conio2.h>
#include<ctype.h>

POINT mouse;
int x,y;

int main(){
    int const N = 100;//99 caratteri disponibili
    bool esci = false, fl = false;
    int risultato;
    char S[N];
    //Dichiarazione prototipi
    void hover1(int colore); void hover2(int colore); void hover3(int colore);
    void hover4(int colore); void hover5(int colore);
    
    bool lettura(char* frase);
    void VocaliConsonanti(char* frase);
    int NumeroParole(char* frase);
    void VisualizzaParole(char* frase);
    //INIZIO PROGRAMMA
    textbackground(0);
    system("CLS");
    gotoxy(60,5);
    printf("PROGRAMMA STRINGHE");
    
    while(esci == false){
               GetCursorPos(&mouse);
               x = mouse.x;
               y = mouse.y;
               
               if(y >= 114 && y <= 150 && x >= 517 && x<= 863){
                    hover1(14);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    fl = lettura(S);
                                                    system("CLS");
                                                    gotoxy(60,5);
                                                    printf("PROGRAMMA STRINGHE");
                    }
               }
               else if(y >= 177 && y <= 210 && x >= 517 && x<= 863){
                    if(fl == true){
                          hover2(14);
                          if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                          VocaliConsonanti(S);
                                                          system("CLS");
                                                          gotoxy(60,5);
                                                          printf("PROGRAMMA STRINGHE");
                          }
                    }   
               }
               else if(y >= 237 && y <= 273 && x >= 517 && x<= 863){
                    if(fl == true){
                          hover3(14);
                          if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                          risultato = NumeroParole(S);
                                                          printf("Numero di parole nella frase: %d",risultato);
                                                          getch();
                                                          system("CLS");
                                                          gotoxy(60,5);
                                                          printf("PROGRAMMA STRINGHE");
                          }
                    } 
               }
               else if(y >= 297 && y <= 329 && x >= 517 && x<= 863){
                    if(fl == true){
                          hover4(14);
                          if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                          VisualizzaParole(S);
                                                          getch();
                                                          system("CLS");
                                                          gotoxy(60,5);
                                                          printf("PROGRAMMA STRINGHE");
                          }
                    } 
               }
               else if(y >= 356 && y <= 390 && x >= 517 && x<= 863){
                    hover5(14);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    esci = true;
                    }
               }
               else{
                    hover1(6); hover5(6);
                    if(fl == false){
                         hover2(8); hover3(8); hover4(8); 
                    }else{
                          hover2(6); hover3(6); hover4(6); 
                    }
               }
    }
}
//INIZIO PROCEDURE PER LA GRAFICA
void hover1(int colore){
    textbackground(colore);
    gotoxy(60,8);
    printf("                                           ");
    gotoxy(60,9);
    printf("             Leggere una frase             ");
    gotoxy(60,10);
    printf("                                           ");
}
void hover2(int colore){
     textbackground(colore);
    gotoxy(60,13);
    printf("                                           ");
    gotoxy(60,14);
    printf("  Contare il numero di vocali e consonanti ");
    gotoxy(60,15);
    printf("                                           ");
}
void hover3(int colore){
    textbackground(colore);
    gotoxy(60,18);
    printf("                                           ");
    gotoxy(60,19);
    printf("        Contare il numero di parole        ");
    gotoxy(60,20);
    printf("                                           ");
}
void hover4(int colore){
    textbackground(colore);
    gotoxy(60,23);
    printf("                                            ");
    gotoxy(60,24);
    printf("    Visualizzare ogni parola su una riga    ");
    gotoxy(60,25);
    printf("                                            ");
}
void hover5(int colore){
    textbackground(colore);
    gotoxy(60,28);
    printf("                                            ");
    gotoxy(60,29);
    printf("                    Esci                    ");
    gotoxy(60,30);
    printf("                                            ");
}
//INIZIO PROCEDURE DEL PROGRAMMA
bool lettura(char* frase){
     textbackground(0);
     system("CLS");
     printf("Inserisci la frase: ");
     gets(frase);
     return true;
}
void VocaliConsonanti(char* frase){
     int lung,count_v,count_c,i;
     char upper[100];//serve per trasformare tutto in maiuscolo
     
     textbackground(0);
     system("CLS");
     lung = strlen(frase);
     //Trasformazione in maiuscolo
     for(i = 0; i < lung; i++){
             upper[i] = toupper(frase[i]);
     }
     upper[i] = '\0';
     count_v = 0;
     count_c = 0;
     //Inizio conteggio
     /*i = 0;
     while(i < lung){
             for(;(upper[i]<'A' || uppper[i] > 'Z') && (upper[i] >= '0' && upper[i] <= '9') && i<lung; i++);
             if(i < lung){
                  for(;(upper[i]>='A' && upper[i]<='Z') || !();i++)
             }
     }*/
     
     for(i = 0; i < lung; i++){
           if(upper[i]=='A' || upper[i]=='E' || upper[i]=='I' || upper[i]=='O' || upper[i]=='U'){
                            count_v++;
           }
           else{
                if(upper[i] >= 'A' && upper[i] <= 'Z')count_c++;
           }
     }
     printf("Nella frase: %s\n\n",frase);
     printf("Numeri vocali: %d\n",count_v);
     printf("Numeri consonanti: %d",count_c);
     getch();
}
int NumeroParole(char* frase){
     int lung,count,i;
     char upper[100];
     
     textbackground(0);
     system("CLS");
     lung = strlen(frase);
     //Trasormazione
     for(i = 0; i < lung; i++){
             upper[i] = toupper(frase[i]);
     }
     upper[i] = '\x0';
     //Inizio conteggio parole
     i = 0;
     count = 0;
     while(i < lung){
             //NON ALFABETICO
             for(; ((upper[i] < 'A' || upper[i] > 'Z') && !(upper[i] >= '0' && upper[i] <= '9')) && i < lung; i++);
             if(i < lung){
                  //ALFABETICO
                  for(; ((upper[i] >= 'A' && upper[i] <= 'Z') || (upper[i] >= '0' && upper[i] <= '9')) && i < lung; i++);
                  count++;
             }
     }
     return (count);
}
void VisualizzaParole(char* frase){
     int lung,i;
     textbackground(0);
     system("CLS");
     lung = strlen(frase);
     //Inizio ricerca
     i = 0;
     while(i < lung){
             //NON ALFABETICO
             for(; ((frase[i] < 'A' || frase[i] > 'z') && !(frase[i] >= '0' && frase[i] <= '9')) && i < lung; i++);
             if(i < lung){
                  //ALFABETICO
                  for(; ((frase[i] >= 'A' && frase[i] <= 'z') || (frase[i] >= '0' && frase[i] <= '9')) && i < lung; i++){
                        printf("%c",frase[i]);
                  }
                  printf("\n");
             }
     }
     getch();
}

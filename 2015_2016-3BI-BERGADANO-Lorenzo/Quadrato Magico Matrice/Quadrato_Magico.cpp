#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
int x,y;
POINT mouse;
int main(){
    
    int const N = 5, M = 5;
    int mat[N][M],c,r;
    bool esci = false;
    
    void hover1(int colore); void hover2(int colore); void hover3(int colore); void hoverBack(int colore);
    void OnClick1(); void OnClick2();
    
    system("CLS");
    gotoxy(60,3);
    printf("QUADRATO MAGICO e TABELLA PITAGORICA");

    while(esci == false){
               GetCursorPos(&mouse);
               x = mouse.x;
               y = mouse.y;
               if(y >= 116 && y <= 150 && x >= 518 && x<= 702){
                    hover1(14);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    OnClick1();
                    }
               }
               else if(y >= 177 && y <= 210 && x >= 518 && x<= 702){
                    hover2(14);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    OnClick2();
                    }
               }
               else if(y >= 237 && y <= 273 && x >= 518 && x<= 702){
                    hover3(14);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                    esci = true;
                    }
               }
               else{
                    hover1(12); hover2(12); hover3(12);
               }
    }
    
}

void hover1(int colore){
    textbackground(colore);
    gotoxy(65,8);
    printf("                       ");
    gotoxy(65,9);
    printf("    Quadrato Magico    ");
    gotoxy(65,10);
    printf("                       ");
}
void hover2(int colore){
     textbackground(colore);
    gotoxy(65,13);
    printf("                       ");
    gotoxy(65,14);
    printf("  Tabella  Pitagorica  ");
    gotoxy(65,15);
    printf("                       ");
}
void hover3(int colore){
    textbackground(colore);
    gotoxy(65,18);
    printf("                       ");
    gotoxy(65,19);
    printf("         Esci          ");
    gotoxy(65,20);
    printf("                       ");
}
void hoverBack(int colore){
    textbackground(colore);
    gotoxy(3,3);
    printf("                       ");
    gotoxy(3,4);
    printf("       Indietro        ");
    gotoxy(3,5);
    printf("                       ");
}

void OnClick1(){
     textbackground(0);
     system("CLS");  
}
void OnClick2(){
     bool indietro = false,premuto = false;
     int numeroCol,numeroRiga,c,r,x1,y1;
     
     textbackground(0);
     system("CLS");
     hoverBack(12);
     
     while(indietro == false){
                    GetCursorPos(&mouse);
                    x = mouse.x;
                    y = mouse.y;
                    if(x >= 22 && x <= 203 && y >= 57 && y <= 92){
                    hoverBack(14);
                    if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                                   indietro = true;
                                                   textbackground(0);
                                                   system("CLS");
                                                   gotoxy(60,3);
                                                   printf("QUADRATO MAGICO e TABELLA PITAGORICA");
                    }
               }else{
                     hoverBack(12);
               }
               textbackground(0);
               gotoxy(60,3);
               printf("DISEGNA LA TUA TABELLA");
               if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                              if(premuto == false){
                                              premuto = true;
                                              x = mouse.x / 8;
                                              y = mouse.y / 13;
                                              gotoxy(x,y);
                                              textbackground(12);
                                              printf(" ");   
                                              textbackground(0);
                                              }
                                              else if(premuto == true){
                                                   x1 = mouse.x / 8;
                                                   y1 = mouse.y / 13;
                                                   gotoxy(x1,y1);
                                                   textbackground(12);
                                                   for(r = y;r < y1;r++){
                                                         numeroRiga++;
                                                         for(c = x;c < x1;c++){
                                                               numeroCol++;
                                                               printf("%d  ",numeroCol*numeroRiga);
                                                         }   
                                                   }
                                                   premuto = false;     
                                                   textbackground(0);
                                              }                  
             }
     }
}

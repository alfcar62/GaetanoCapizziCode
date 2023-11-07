#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>
//DIMENSIONI 1320x767

int main(){
    POINT mouse;
    int x,y,carattere = 254;
    
    gotoxy(1,1);
    printf("COLORI:  ");
    textbackground(12);
    printf(" ");
    textbackground(0);
    printf(" ");
    textbackground(13);
    printf(" ");
    textbackground(0);
    printf(" ");
    textbackground(14);
    printf(" ");
    textbackground(0);
    printf(" ");
    textbackground(11);
    printf(" ");
    textbackground(0);
    printf(" ");
    textbackground(10);
    printf(" ");
    textbackground(0);
    printf(" ");
    textbackground(9);
    printf(" ");
    textbackground(0);
    printf(" ");
    textbackground(8);
    printf(" ");
    //COLORE DEFALUT = ROSSO
    textbackground(12);
    
    while(1){
             GetCursorPos(&mouse);
             /*gotoxy(10,10);
             printf("X: %ld - y: %ld    ", mouse.x, mouse.y);*/
             if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                             if(mouse.x > 75 && mouse.x < 85 && mouse.y > 32 && mouse.y < 42){
                                                        //COLORE 12 = rosso
                                                        textbackground(12);
                                             }
                                             else if(mouse.x > 94 && mouse.x < 102 && mouse.y > 32 && mouse.y < 42){
                                                  //COLORE 13
                                                  textbackground(13);
                                             }
                                             else if(mouse.x > 110 && mouse.x < 117 && mouse.y > 32 && mouse.y < 42){
                                                  //COLORE 14
                                                  textbackground(14);
                                             }
                                             else if(mouse.x > 126 && mouse.x < 133 && mouse.y > 32 && mouse.y < 42){
                                                  //COLORE 11
                                                  textbackground(11);
                                             }
                                             else if(mouse.x > 141 && mouse.x < 149 && mouse.y > 32 && mouse.y < 42){
                                                  //COLORE 10
                                                  textbackground(10);
                                             }
                                             else if(mouse.x > 158 && mouse.x < 166 && mouse.y > 32 && mouse.y < 42){
                                                  //COLORE 9
                                                  textbackground(9);
                                             }
                                             else if(mouse.x > 174 && mouse.x < 182 && mouse.y > 32 && mouse.y < 42){
                                                  //COLORE 8
                                                  textbackground(8);
                                             }
                                             else{
                                                  x = mouse.x / 8;
                                                  y = mouse.y / 13;
                                                  gotoxy(x,y);
                                                  printf("%c",carattere);
                                             }
             }
             if(GetAsyncKeyState(VK_MBUTTON) != 0){//USO LA ROTELLA PERCHE IL TASTO DESTRO è SCOMODO :)
                                             textbackground(0);
                                             system("CLS");
                                             gotoxy(1,1);
                                             printf("COLORI:  ");
                                             textbackground(12);
                                             printf(" ");
                                             textbackground(0);
                                             printf(" ");
                                             textbackground(13);
                                             printf(" ");
                                             textbackground(0);
                                             printf(" ");
                                             textbackground(14);
                                             printf(" ");
                                             textbackground(0);
                                             printf(" ");
                                             textbackground(11);
                                             printf(" ");
                                             textbackground(0);
                                             printf(" ");
                                             textbackground(10);
                                             printf(" ");
                                             textbackground(0);
                                             printf(" ");
                                             textbackground(9);
                                             printf(" ");
                                             textbackground(0);
                                             printf(" ");
                                             textbackground(8);
                                             printf(" ");
                                             textbackground(12);                 
             }
    }
}

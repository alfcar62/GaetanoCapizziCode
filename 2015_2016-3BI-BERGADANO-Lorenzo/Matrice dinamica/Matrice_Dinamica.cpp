#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>

int main(){
    POINT mouse;
    int x,y,x1,y1,c,r,numeroCol,numeroRiga;
    bool premuto = false;
    
    while(1){
             GetCursorPos(&mouse);
             
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
                                                   textbackground(12);
                                                   numeroCol = 0;
                                                   numeroRiga = 0;
                                                   for(r = y;r < y1;r = r + 1){
                                                         
                                                         for(c = x;c < x1;c = c + 3){
                                                               gotoxy(c,r);
                                                               numeroCol++;
                                                               printf("%d  ",numeroCol);
                                                         }
                                                   }
                                                   textbackground(0);
                                                   premuto = false;
                                              }                  
             }
    }
}

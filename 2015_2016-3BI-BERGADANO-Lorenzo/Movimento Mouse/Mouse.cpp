#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<conio2.h>


int main(){
    /*handler hwnd;
    RECT rect;
    GetWindowRect(hwnd, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;*/
     
    POINT mouse;
    //int x,y;
    gotoxy(10,10);
    printf("CIAO  ");
    while(1){
             GetCursorPos(&mouse);
             //x = mouse.x; / (1000/112)
             //y = mouse.y; / (10000/768)
             gotoxy(1,1);
             printf("X: %ld - y: %ld                ", mouse.x, mouse.y);
             if(mouse.x > 157 &&  mouse.y > 186 && mouse.x < 213 && mouse.y < 219){
                        gotoxy(10,10);
                        printf("SOPRA  ");                      
             }
             else{
                  gotoxy(10,10);
                  printf("CIAO  ");
             }
             
             if(GetAsyncKeyState(VK_LBUTTON) != 0){
                                             gotoxy(20,20);
                                             printf("CLICK");
             }
             else{
                  gotoxy(20,20);
                  printf("         ");
             }
    }
}

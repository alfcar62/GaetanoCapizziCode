#include <iostream>
#include <graphics.h>


int main(int argc, char *argv[])
{
	int gd = DETECT, gm, x, y, color, angle = 90;
   struct arccoordstype a, b;
   
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   delay(2000);
   
   while(angle<=450)
   {
      setcolor(BLACK);
      arc(getmaxx() / 2, getmaxy() / 2, angle,a ngle + 2,100);
      setcolor(RED);
      getarccoords(&a);
      circle(a.xstart, a.ystart, 25);
      setcolor(BLACK);
      arc(getmaxx() / 2,getmaxy() / 2, angle, angle + 2, 150);
      getarccoords(&a);
      setcolor(GREEN);
      circle(a.xstart, a.ystart, 25);
      angle = angle + 5;
      delay(50);
   }
   
   getch();
   closegraph();
}

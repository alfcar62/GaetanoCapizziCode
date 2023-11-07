 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #include<conio.h>
int main()
 {
   int a,pos,neg,cont;
   system ("cls");
   pos=0;
   neg=0;
   cont=0;
  srand (time(0));
  for (pos=0; pos<10;pos++)
  {

  cont=rand()%10;
  printf("%d\n",cont);
     getch();
 } }


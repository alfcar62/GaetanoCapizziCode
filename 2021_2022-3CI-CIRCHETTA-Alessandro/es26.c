/**
ALUNNO: Pansini Guglielmo & Circhetta Alessandro
DATA:   22/12/2021   
CLASSE: 3C INFORMATICA  
CONSEGNA: Scrivere un programma  in C language  che sia in grado di disegnare nel piano e nello spazio delle figure geometriche  su un piano cartesiano (in 2 Dimensioni :x,y) 
**/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <windows.h>
#include<math.h>
#define MAXR 24
#define MAXC 80
#define PI 3,14
       
void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

typedef unsigned char color_t;

enum
{
Black,
Red,
Green,
Yellow,
Blue,
Magenta,
Cyan,
LightGray,
Gray,
LightRed,
LightGreen,
LightYellow,
LightBlue,
LightMagenta,
LightCyan,
White
};

void textcolor(color_t fgcolor, color_t bgcolor)
{
printf(
// \003 indica una sequenza
// 38 è colore testo
// 48 è colore sfondo
// 5 indica modalità a 256 colori (Profondità 8 bit)
// %d è il colore
"\033[38;5;%dm\033[48;5;%dm",
fgcolor, bgcolor
);}

int orx, ory;

int traslax(int x)
{
    return x+orx;
}

int traslay(int y)
{
    return (-1*y)+ory;
}

void pixel(int x, int y, int fgcolor, int bgcolor, char ch)
{
    int absox=traslax(x), absoy=traslay(y);
    if (absox < 0 || absox >=80 || absoy < 0 || absoy >=24)
        return;
    gotoxy(absox,absoy);
    textcolor(Black,White);
    printf("%c",ch);
}

void pixelab(int x, int y, int fgcolor, int bgcolor, char ch)
{
    if (x < 0 || x >=80 || y < 0 || y >=24)
        return;
    gotoxy(x,y);
    textcolor(fgcolor,bgcolor);
    printf("%c",ch);
}

void assi()
{
int centrox = 40, centroy = 12, y=0, x= 0;
    for(x=0; x<80; x++) //IMPOSTA LA CONSOLE DOVE ANDREMO A DISEGNARE BIANCA
        for(y=0; y<24; y++)
            pixelab(x,y, White, White, ' ');


    // DISEGNA L'ASSE Y
    for (y=0; y < 12; y++)
        pixelab(centrox, y, Black, White, '|');
    
    for (y=0; y < 24; y++)
        pixelab(centrox, y, Black, White, '|');

    // DISEGNA L'ASSE X
    for (x=0; x < 40; x++)
        pixelab(x, centroy, Black, White, '-');

    for (x=0; x < 80; x++)
        pixelab(x, centroy, Black, White, '-');
    

    pixelab(centrox, centroy, Black, White,'+'); //DISEGNO DELL'INTERSEZIONE DEGLI ASSI X E Y
    orx=centrox;
    ory=centroy;


}

void punto()
{
    int xp,yp;
    printf("inserisci la x del punto che vuoi disegnare: ");
    scanf("%d",&xp);
    printf("inserisci la y del punto che vuoi disegnare: ");
    scanf("%d",&yp);
    assi();
    pixel(traslax(xp),traslay(yp), Black, White, '*');
}

void disegnaretta(int x1,int  y1,int  x2,int  y2)
{

    int x;
    float m = (float) (y2 - y1) / (x2 - x1);

    for (x=-1*orx; x<orx; x++)
    {
        // y - y0 = m(x - x0)
        int y = round(m * x);
        pixel(x, y, Black, White, '=');
    }

    gotoxy(0,0);
    printf("Coefficiente angolare: %f\n", m);
}

void retta()
{
    int x1,y1,x2,y2;
    
    printf("inserire la x del primo punto ");
    scanf("%d", &x1);
    printf("inserire la y del primo punto ");
    scanf("%d", &y1);
    printf("inserire la x del secondo punto ");
    scanf("%d", &x2);
    printf("inserire la y del secondo punto ");
    scanf("%d", &y2);
    assi();
    disegnaretta(x1, y1, x2, y2);
}

void disegnarettangolo(int x, int y, int larg, int h)
{
    int inx = x - larg / 2,
        iny = y - h / 2;

    larg=larg* 2;
    h=h-1;
    larg=larg-1;

    int xp, yp;

    for (xp = inx; xp < inx + larg; xp++)
        pixel(xp , iny, Black, White, '-');

    for (xp = inx; xp < inx + larg; xp++)
        pixel(xp, iny+h, Black, White, '-');

    for (yp = iny; yp < iny + h; yp++)
        pixel(inx, yp, Black, White, '|');

    for (yp = iny; yp < iny + h; yp++)
        pixel(inx + larg, yp, Black, White, '|');

    pixel(inx, iny, Black, White, '+');
    pixel(inx + larg, iny, Black, White, '+');
    pixel(inx, iny + h, Black, White, '+');
    pixel(inx + larg, iny + h, Black, White, '+');

    gotoxy(0, 0);
    printf("Larghezza: %d\n", (larg + 1) / 2);
    printf("Altezza: %d\n", h + 1);
    printf("Perimetro: %d\n", ((larg + 1) / 2) * 2 + (h + 1) * 2);
    printf("Area: %d\n", ((larg + 1) / 2) * (h + 1));
}

void rettangolo()
{
    int xce, yce, larg, h;

    printf("inserire la x del centro ");
    scanf("%d",&xce);
    printf("inserire la y del centro ");
    scanf("%d",&yce);
    printf("inserire la larghezza della figura ");
    scanf("%d",&larg);
    printf("inserire l'altezza della figura ");
    scanf("%d",&h);
    assi();
    disegnarettangolo(xce, yce, larg, h);
}

void disegnacerchio(int x, int y, int raggio)
{

    int i, j;
    for (i = 0; i < raggio * 2; i++)
    {
        for (j = 0; j < raggio * 2; j++)
        {
            double distance = sqrt((double)(i - raggio) * (i - raggio) + (j - raggio) * (j - raggio));
            if (distance > raggio - 0.5 && distance < raggio + 0.5)
                pixel(i * 2, j, Black, White, '*');
        }
    }

    gotoxy(0, 0);
    printf("Raggio: %hd\n", raggio);
    printf("Circonferenza: %f\n", PI * 2 * raggio);
    printf("Area: %f\n", PI * raggio * raggio);
}

void cerchio()
{  
    int x, y, raggio;
    printf("Inserire X -> ");
    scanf("%d", &x);

    printf("Inserire Y -> ");
    scanf("%d", &y);

    printf("Inserire Raggio -> ");
    scanf("%d", &raggio);
    assi();
    disegnacerchio(x,y,raggio);
}

int main()
{
    int ans, x, y;

    do
    {
        system("cls");
        printf("1) disegno di un punto sul piano cartesiano \n");
        printf("2) disegno di una retta sul piano cartesiano\n");
        printf("3) disegno di un quadrato sul piano cartesiano\n");
        printf("4) disegno di un rettangolo sul piano cartesiano\n");
        printf("5) disegno di un cerchio sul piano cartesiano\n");
        printf("6) esci\n");
        printf("cosa vuoi disegnare? ");
        scanf("%d",&ans);

        switch (ans)
        {
            case 1:{punto();      }break;
            case 2:{retta();      }break;
            case 3:{rettangolo(); }break;
            case 4:{rettangolo(); }break;
            case 5:{cerchio();    }break;
        };
    } while (ans<0 || ans>6);
    while (1){}
    
}
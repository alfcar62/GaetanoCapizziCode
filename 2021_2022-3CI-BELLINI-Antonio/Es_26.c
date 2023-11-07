/*
Autore: Bellini Antonio 
Data: 21/12/2021
Classe: 3C INFORMATICA
Programma che è in grado di disegnare, date in input le opportune misure, diverse figure geometriche su un piano cartesiano, 
calcolando inoltre la loro area e il loro perimetro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define ASSE_X 130
#define ASSE_Y 70
#define MAX_LUNGHEZZA 15

//Dichiarazione variabili globali	 
int x,		//Varabile per x
	y,		//Variabile per y
	scelta;	//Variabile per la scelta del programma	
	
//Void per comando GotoXY.
void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);}

//Void per menù generale.
void menu()
	{
	 do	
	   {
	   	system("cls");
	 	GotoXY(80,2);
	 	printf("Benvenuto!");
	 	GotoXY(65,4);
	 	printf("Quale figura geometrica vuoi disegnare?");
	 	GotoXY(70,6);
	 	printf("1) Punto nel piano cartesiano");
	 	GotoXY(70,7);
	 	printf("2) Retta nel piano cartesiano");
	 	GotoXY(70,8);
	 	printf("3) Quadrato");
	 	GotoXY(70,9);
	 	printf("4) Rettangolo");
		GotoXY(70,10);
	 	printf("5) Parallelogramma");
		GotoXY(70,11);
	 	printf("6) Esci");	
	 	GotoXY(70,13);
	 	printf("Scelta-->");
	 	scanf("%d",&scelta);
	   }while(scelta<1||scelta>6);
	}
	
//Void per piano cartesiano.
void piano_cartesiano()
	{
	 int contX,	//Contatore per disegnare asse x
	 	 contY,	//Contatore per disegnare asse y
		 x1=80,	//Metà asse x
		 y2=35, //Metà asse y
		 y1=1,	//Distanza asse y dal bordo
		 x2=15;	//DIstanza asse x dal bordo
		 
	 //Asse y
	 GotoXY(80,0);
	 printf("^");		//Indicatore del verso dell'asse y
	 for(contY=0;contY<ASSE_Y;contY++)
	 	{
	 	 GotoXY(x1,y1);
	 	 printf("|");
		 y1++;	
		}
	 //Asse x	
	 for(contX=0;contX<ASSE_X;contX++)
	 	{
	 	 GotoXY(x2,y2);
	 	 printf("--");
		 x2++;
		}
		printf(">");	//Indicatore del verso dell'asse x	
	}	
	
//Void per il controllo del quadrante di appartenenza nel piano
void controllo_quadrante()
	{
	 //I qudrante	
	 if(x>0&&y>0)		 		
	  {
	   x=80+x;
	   y=35-y;
	   GotoXY(x,y);
	   printf("*");
	   GotoXY(100,100);	
	  }
	 //II qudrante 
	 if(y>0&&x<0)
	  {
	   x=80+x;	
	   y=35-y;
	   GotoXY(x,y);
       printf("*");	
	   GotoXY(100,100);	
	  }
	 //III quadrante
 	 if(x<0&&y<0)
	  {
	   x=80+x;
	   y=35-y;	
	   GotoXY(x,y);
	   printf("*");	
	   GotoXY(100,100);	
	  } 
	 //IV quadrante 
	 if(x>0&&y<0)
	  {
	   x=80+x;
	   y=35-y;
	   GotoXY(x,y);
	   printf("*");	
	   GotoXY(100,100);
	  }
	 //Centro del piano cartesiano (0,0)
	 if(x==0&&y==0)
	  {
	   x=80;
	   y=35;	
	   GotoXY(x,y);
	   printf("*");
	   GotoXY(100,100);	
	  }		 	
	}
		




int main() 
	{	
	 menu();
	 
	 switch(scelta)
	 	{
	 	 //Punto nel piano	
	 	 case 1:
		  	{	
		  	 //Inserimento dati
		  	 system("cls");
			 GotoXY(5,5);
			 printf("Inserisci il valore di x del punto-->");
			 scanf("%d",&x);
			 GotoXY(5,6);
			 printf("Inserisci il valore di y del punto-->");
	 		 scanf("%d",&y);
			 GotoXY(5,8);
	  		 printf("Il punto ha coordinate (%d,%d)",x,y); 			 
			 //Disegno del piano cartesiano e controllo quadrante di appartenenza nel piano
			 piano_cartesiano();		
			 controllo_quadrante();
			 GotoXY(100,100);
			}break;
		 
		 
		 
		 
		 
		 //Retta nel piano	
		 case 2:
		   {
		   	int xA,			//Valori di x per il primo punto (A) della retta
		   		yA,			//Valori di y per il primo punto (A) della retta
		   		xB,			//Valori di x per il secondo punto (B) della retta
		   		yB,			//Valori di y per il secondo punto (B) della retta
		   		m,			//Variabile per il coefficente angolare della retta
				q,			//Variabiler per il termine noto della retta
		   		l;			//Variabile usata per disegnare la retta
		   	 //Inserimento dati	
		   	 system("cls");
		     GotoXY(5,2);
		 	 printf("Inserisci il primo valore di x (xA)-->");
			 scanf("%d",&xA);
			 GotoXY(5,3);
			 printf("Inserisci il primo valore di y (yA)-->");
			 scanf("%d",&yA);
			 GotoXY(5,4);
			 printf("Inserisci il secondo valore di x (xB)-->");
			 scanf("%d",&xB);
			 GotoXY(5,5);
			 printf("Inserisci il secondo valore di y (yB)-->");
			 scanf("%d",&yB);
			 GotoXY(5,6);
			 printf("Inserisci il valore di q (termine noto)-->");
			 scanf("%d",&q);
			 GotoXY(5,7);
			 //Calcolo del coefficente angolare della retta e stampa dell'equazione della retta
			 m=(yB-yA)/(xB-xA);
			 GotoXY(5,9);
			 printf("L'equazione della retta e' y=%dx+%d",m,q);
			 //Disegno del piano cartesiano 
			 piano_cartesiano();
			 //Posizionamento dei punti alle coordinate opportune
			 x=xB;
			 y=yB;
			 controllo_quadrante();
			 x=xA;
			 y=yA;
			 controllo_quadrante();	
			 //Disegno Retta se m>0
			 if(m>0)
			   {
			 	for(l=0;l<MAX_LUNGHEZZA;l++)
			 	  {
			 	   GotoXY(x,y);
				   printf("*");
				   x++;
				   y-=m;	
				  }
				 GotoXY(150,150);  
			   }break;
			 //Disegno retta se m<0  
			 if(m<0)
			   {
			   	for(l=0;l<MAX_LUNGHEZZA;l++)
			 	  {
			 	   GotoXY(x,y);
				   printf("*");
				   x++;
				   y+=m; 	
				  }
			   }  
		     	 GotoXY(100,100);
		   }break;	
		
		
		
		
		
		 //Quadrato 
		 case 3:
		   {
			int xQ,			//valore di x dal centro (xQ=xQuadrato per distinguere dalla x delle coordinate)
		   	 	yQ,			//valore di y dal centro (yQ=yQuadrato per distinguere dalla y delle coordinate)
		   	 	l,			//lunghezza di un lato
		   	 	L1,			//lato superiore del quadrato
		   	 	L2,			//lato inferiore del quadrato
		   	 	L3,			//lato destro del quadrato
		   	 	L4,			//lato sinistro del quadrato
		   	 	area,		//Variabile per il calcolo dell'area del quadrato
		   	 	perimetro;	//Variabile per il calcolo del perimetro del quadrato
			 //Inserimento dati		 		   	
		   	 system("cls");
		   	 GotoXY(5,2);
		   	 printf("Indica il valore di x del centro del quadrato-->");
		   	 scanf("%d",&x);
		   	 GotoXY(5,3);
		   	 printf("Indica il valore di y del centro del quadrato-->");
		   	 scanf("%d",&y);
		   	 GotoXY(5,4);
		   	 printf("Indica la lunghezza in centimetri di un lato del quadrato-->");
		   	 scanf("%d",&l);
		   	 //Disegno del piano cartesiano e controllo del quadrante di appartenenza nel piano 
		   	 piano_cartesiano();
			 controllo_quadrante();
			 //Posizionamento valori x, y dal centro per disegnare il quadrato
			 xQ=x-l;
			 yQ=y-(l/2);
			 //Lato sinistro del quadrato.
	  		  for(L1=0;L1<l;L1++)
	  		  	{	 	
	  		  	 GotoXY(xQ,yQ);
				 printf("*");
				 yQ++;
				}
	  		 //Lato superiore del quadrato.
	  		  for(L3=0;L3<l;L3++)
	  		  	{	  		  			 					
	  		  	 GotoXY(xQ,yQ);
				 printf("*");
				 xQ+=2;		
				}					
			 //Lato destro del quadrato.
			  for(L2=0;L2<l;L2++)
			  	{
				 GotoXY(xQ,yQ);
				 printf("*");
				 yQ--;
				}
			 //Lato inferiore del quadrato.	
			  for(L4=0;L4<l;L4++)
			  	{
				 GotoXY(xQ,yQ);
				 printf("*");
				 xQ-=2;			
				}
			 //Calcolo area e primetro del quadrato	
			 area=l*l;
			 perimetro=l+l+l+l;
			 GotoXY(5,6);
			 printf("Il quadrato in questione ha un area di %d cm^2",area);
			 GotoXY(5,7);
			 printf("Il quadrato in questione ha un perimetro di %d cm",perimetro);
			 GotoXY(100,100);
		   }break;
		
		
		
		
		
		 //Rettangolo
		 case 4:
		   {
			 int xR,		//valore di x dal centro (xR=xRettangolo per distinguere dalla x delle coordinate)
		   	 	 yR,		//valore di y dal centro (yR=xRettangolo per distinguere dalla y delle coordinate)
		   	 	 lMag,		//lato maggiore del rettangolo (altezza)
		   	 	 lMin,		//lato minore del rettangolo (base)
		   	 	 L1,		//lato superiore del rettangolo
		   	 	 L2,		//lato inferiore del rettangolo
		   	 	 L3,		//lato destro del rettangolo
		   	 	 L4,		//lato sinistro del rettangolo
		   	 	 area,		//Variabile per il calcolo dell'area del rettangolo
		   	 	 perimetro;	//Variabile per il calcolo del perimetro del rettangolo
		   	 //Inserimento dati	 
		   	 system("cls");
		   	 GotoXY(5,2);
		   	 printf("Indica il valore di x del centro del rettangolo-->");
		   	 scanf("%d",&x);
		   	 GotoXY(5,3);
		   	 printf("Indica il valore di y del centro del rettangolo-->");
		   	 scanf("%d",&y);
		   	 GotoXY(5,4);
		   	 printf("Indica la lunghezza in centimetri del lato maggiore del rettangolo-->");
		   	 scanf("%d",&lMag);
		   	 GotoXY(5,5);
		   	 printf("Indica la lunghezza in centimentri del lato minore del rettangolo-->");
		   	 scanf("%d",&lMin);
		   	 //Disegno del piano cartesiano e controllo del quadrante di appartenenza nel piano 
		   	 piano_cartesiano();
		   	 controllo_quadrante();
		   	 //Posizionamento valori di x,y dal centro per disegnare il rettangolo
			 xR=x-lMag;
			 yR=y-(lMin/2);
		   	 //Lato superiore del rettangolo.
	  		  for(L1=0;L1<lMin;L1++)
	  		  	{	 	
	  		  	 GotoXY(xR,yR);
				 printf("*");
				 yR++;
				}
			 //Lato destro del rettangolo.
	  		  for(L3=0;L3<lMag;L3++)
	  		  	{	  		  			 					
	  		  	 GotoXY(xR,yR);
				 printf("*");
				 xR+=2;			
				}			 
			 //Lato inferiore del rettangolo.
			  for(L2=0;L2<lMin;L2++)
			  	{
				 GotoXY(xR,yR);
				 printf("*");
				 yR--;
				}
			 //Lato sinistro del rettangolo.
			  for(L4=0;L4<lMag;L4++)
			  	{
				 GotoXY(xR,yR);
				 printf("*");
				 xR-=2;			
				}
			 //Calcolo area e perimetro
			 area=lMin*lMag;
			 perimetro=2*(lMin+lMag);
			 GotoXY(5,7);
			 printf("Il rettangolo in questione ha un area di %d cm^2",area);
			 GotoXY(5,8);
			 printf("Il rettangolo in questione ha un perimetro di %d cm",perimetro);
			 GotoXY(100,100);			 				 		   	
		   }break;
		
		
		
		
		
		 //Parallelogramma
		 case 5:
		   {
		   	 int xP,		//xP=xParallelogramma (per distinguere dalle altre x)
		   		 yP,		//yP=xParallelogramma (per distinguere dalle altre y)
		   		 l, 		//l=lunghezza del lato obliquo del parallelograma 
				 base,		//Variabile per la base del parallelogramma
				 h,			//Variabile per l'altezza del parallelogramma
				 LOS,		//LOS=Lato Obliquo Sinistro (variabile usata per disegnare il lato obliquo sinistro)
				 LBS,		//LBS=Lato base Superiore (variabile usata per disegnare il lato di base superiore)
				 LOD,		//LOD=Lato Obliquo Destro (variabile usata per disegnare il lato obliquo destro)
				 LBI,		//LBI=Lato Base Inferiore (variabile usata per disegnare il lato di base inferiore)
				 area,		//Variabile per calcolo dell'area del parallelogramma
		   		 perimetro; //Variabile per il calcolo del perimetro del parallelogramma
			 //Inserimento dati		  	
			 system("cls");
		   	 GotoXY(5,5);
			 printf("Indica il valore di x del centro del parallelogramma-->");
		   	 scanf("%d",&x);
		   	 GotoXY(5,6);
		   	 printf("Indica il valore di y del centro del parallelogramma-->");
		   	 scanf("%d",&y);
		   	 GotoXY(5,7);
		   	 printf("Indica la lunghezza del lato obliquo del parallelogramma-->");
		   	 scanf("%d",&l);
		   	 GotoXY(5,8);
		   	 printf("Indica il valore della base del parallelogramma-->");
		   	 scanf("%d",&base);
		   	 GotoXY(5,9);
		   	 printf("Inserisci il valore dell'altezza del parallelogramma-->");
		   	 scanf("%d",&h);
		   	 //Disegno del piano cartesiano e controllo del quadrante di appartenenza nel piano 
		   	 piano_cartesiano();
		   	 controllo_quadrante();
			 //Posizionamento di x, y per iniziare a disegnare il parallelogramma		   	 
			 xP=x-base;
		   	 yP=y+(l/2);
			 //Lato obliquo sinistro 
	  		  for(LOS=0;LOS<l;LOS++)
	  		  	{	 	
	  		  	 GotoXY(xP,yP);
				 printf("*");
				 xP++;
				 yP--; 				 
				}
			 //Base superiore
	  		  for(LBS=0;LBS<base;LBS++)
	  		  	{	  		  			 					
	  		  	 GotoXY(xP,yP);
				 printf("*");
				 xP+=2;			
				}			 
			 //Lato obliquo destro
			  for(LOD=0;LOD<l;LOD++)
			  	{
				 GotoXY(xP,yP);
				 printf("*");
				 xP--;
				 yP++;
				}
			 //Base inferiore
			  for(LBI=0;LBI<base;LBI++)
			  	{
				 GotoXY(xP,yP);
				 printf("*");
				 xP-=2;			
				}
		   	 //Calcolo area e perimetro
			 area=base*h;
			 perimetro=(l+base)*2;
			 GotoXY(5,11);
			 printf("Il parallelogramma in questione ha un'area di %d cm^2",area);
			 GotoXY(5,12);
			 printf("Il parallelogramma in questione ha un perimetro di %d",perimetro);
		   	 GotoXY(100,100);
		   }break;
		 
		 
		 
		 
		 
		 //Fine del programma  
		 case 6:
		   {
		   	system("cls");
		   	GotoXY(70,20);
		   	printf("Fine del programma");
		   	GotoXY(100,100);
		   }break;  
		}
		
	 return 0;
	}

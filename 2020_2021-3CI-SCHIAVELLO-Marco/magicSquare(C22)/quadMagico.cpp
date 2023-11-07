/*
    Marco Schiavello 3^CI 15/08/2021

    Scrivere un programma che genera e stampa una matrice quadrata (di dimensione =9) corrispondente ad un quadrato Magico.
    Si tratta di una matrice quadrata di dimensione N = 9

    Un quadrato magico è una disposizione di numeri interi in forma di tabella quadrata in cui siano rispettate due condizioni:
    -i valori siano tutti distinti tra loro
    - la somma dei numeri presenti in ogni riga, in ogni colonna, e in entrambe le diagonali, dia sempre lo stesso risultato;
*/
#include <stdio.h>
#include <stdlib.h>

#define RIGHE 9
#define COLONNE 9

void caricaMat(int mat[][COLONNE]);
void stampaMat(int mat[RIGHE][COLONNE]);

/*____________Main___________*/
int main()
{
  int mat[RIGHE][COLONNE];

  caricaMat(mat);
  stampaMat(mat);

  return 0;
}

/**
*   riempe una matrice creando un quadrato magico
*   params:
*       @param int mat[][COLONNE] : output : matrice dove verra messo il quadrato magico
*       @return void
*/
void caricaMat(int mat[][COLONNE])
{
  int c = COLONNE/2,r = 0;
  for(int i = 0;i<(RIGHE*COLONNE);i++)
  {
    if(r == -1)
      r = RIGHE-1;
    if(c == COLONNE)
      c = 0;
    mat[r][c] = i+1;

    if((i+1)%9 != 0)
    {
      c = c+1;
      r = r-1;
    }
    else
      r = r+1;
  }
}

/**
*   stampa la matrice con il quadrato magico
*   params:
*       @param int mat[][COLONNE] : input : matrice da stampare
*       @return void
*/
void stampaMat(int mat[][COLONNE])
{
  	int r, c;
   	printf("Il quadrato magico 9x9 è:\n");
    for(r = 0; r < RIGHE; r++)
	  {
      printf("\n");
      for(c = 0; c < COLONNE; c++)
      	printf(" %3d ", mat[r][c]);
    }
    printf("\n");
}


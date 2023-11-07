/*************************
Alunno:		Adam Eloksch
Classe:		3C INF
Data:		05/04/2022

Consegna: 	BATTAGLIA NAVALE
**************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>    
#include <string.h>
#include <time.h>

#define R 10
#define C 10


void azzmat(int mat[R][C]) 	// azzera la matrice
{
	int rig,col;
	for(rig=0; rig<R; rig++)
	
        for (col=0; col<C; col++)
        
        	{
        		mat[rig][col]=0;	//metto la matrice a zero
			}
     
}
void stampa(int mat[R][C])	// stampa la matrice 
{
	int rig,col;
	for(rig=0; rig<R; rig++)	// genera le righe
	
        for (col=0; col<C; col++)		// genera le colonne 
        
        	{
        		printf(" %01d", mat[rig][col]); 
				
				if(col == (R-1))	// va a capo dopo la fine della riga
				printf("\n");
			}

}

void quattronavi(int mat[R][C], int *rig, int *col){
	do{
		srand(time(0));
		rig=rand()%9;
		col=rand()%9;
	}while(rig <= 2 || rig >= 7 || col <= 2 || col >=7);
	mat[rig][col]=4;
	printf("%d", mat[rig][col]);
	
}

/*void trenavi(int mat[R][C])
{
	
}

void duenavi(int mat[R][C])
{
	
}

void unanave(int mat[R][C]])
{
	
}*/


int main()
{
	int mat[R][C];
	int rig,col;
   	azzmat(mat);	// procedura che azzera la matrice
   	quattronavi(mat);
    stampa(mat);
    
    return 0;
}

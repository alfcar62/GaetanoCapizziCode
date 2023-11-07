/**
*   stampa il sudoku
*   params:
*       @param int sudoku[][] : input : matrice da stamapre
*       @return void
*/
void stampaSudoku(int sudoku[][DIM])
{
    for(int i = -1;i < DIM;i++)
    {
        if(i == -1)
        {
            printf("  ");
            for(int x = 1;x < 10;x++)
            {
                if((x-1) % 3 == 0 && (x-1) != 0 && (x-1) != DIM-1)
                    printf("  ");

                printf("  %d ",x);
            }
            printf("\n");
        }
        else
        {
            linea(DIM);
            for(int j = -1;j < DIM;j++)
            {
                if(j == -1)
                    printf("%d ",i+1);
                else
                {
                    if(sudoku[i][j] == 0)
                        printf("| - ",sudoku[i][j]);
                    else if(sudoku[i][j] > 100)
                        printf("|   ",sudoku[i][j]);
                    else
                        printf("| %d ",sudoku[i][j]);

                    if(j % 3 == 2 && j != 0 && j != DIM-1)
                        printf("| ");
                }
            }
            printf("|\n");

            if(i % 3 == 2 && i != 0 && i != DIM-1)
                linea(DIM);
        }
    }
    linea(DIM);

    printf("\n");
}

/**
*   score ogni cella del sudoku finche non ritorna la sua posione nei suoi parametri ria e col
*   se non specificati gli indirizzi delle variabili riga e colonna esso servia a controllare la presenza di celle oscurate
*   params:
*       @param int sudoku[][] : input : sudoku da controllare per caselle oscurate
*       @param int * riga = NULL: input : puntatore che punterà alla variabile che dovrà contenere la riga della cella vuota
*       @param int * col = NULL: input : puntatore che punterà alla variabile che dovrà contenere la colonna della cella vuota
*       @return bool : se e stata trovata una cella vuota
*/
bool getBlankCell(int sudoku[][DIM],int * riga,int * col)
{
    for(int i = 0;i < DIM;i++)
        for(int j = 0;j < DIM;j++)
            if(sudoku[i][j] == 0)// <----------- METTRE QUI ESPRESSIONE PER TORVARE CELLE OSCURATE
            {
                if(riga != NULL && col != NULL)
                {
                    *riga = i;
                    *col = j;
                }
                return true;
            }

    return false;
}

/**
*   fa tre controlli per verificare che quel numero in quella posizione rispetti le regole del sudoku
*   params:
*       @param int sudoku[][DIM] : input : matrice par fare il controllo
*       @param int num : input : numero da controllare
*       @param int riga : input : riga in cui si trova il numero da controlare
*       @param int quad : input : quadrante da controllare
*       @return bool : se vero rispeta i criteri del sudoku altrimenti no
*/
bool checkNum(int sudoku[][DIM],int num,int riga,int col,int quad)
{
    for(int i= 0;i<DIM;i++)
        if(sudoku[riga][i] == num)
            return false;

    for(int i= 0;i<DIM;i++)
        if(sudoku[i][col] == num)
            return false;

    for(int i = (quad/3) * 3;i < ((quad/3)* 3) + 3;i++)
        for(int j = (quad%3) * 3;j < ((quad%3)* 3) + 3;j++)
            if(sudoku[i][j] == num)
                return false;

    return true;
}

/**
*   calcola tutte le soluzioni di un sudoku
*   params:
*       @param int sudoku[][] : input : sudoku con caselle oscurate da controllare per vedere se ci sono più soluzioni
*       @param int solved = 0: / : parametro ausiliare per la ricorsione che indica quante soluzioni sono state trovate
*       @return bool : se vero il sudoku avra piu soluzioni altrimenti se falso significa che ne ha solo una
*/
bool sudokuSolver(int sudoku[][DIM],int solved = 0)
{
    int riga,col;

    if(!getBlankCell(sudoku,&riga,&col)) // condizione in cui abbiamo una soluzione o non ci sono celle oscurate
    {
        if(solved == 0) // questo caso si avverà ci sono 0 posti dove mettere i numeri percio non si riesce ad arrivare nemmeno a una soluzione
            return true;
        else
        {
            stampaSudoku(sudoku);
            getch();
            return false;
        }

        // qua ci si segna ce ne abbiamo trovato una soluzione, ma ritorniamo falso per forzare l'algortmo a trovarne altre
        //ma se non trovera altre soluzioni andra sempre piu in alto nell'albero delle chiamate per cercare strade che portino alla soluzione
        //fino ad arrivare alla prima chiamata che se fallira indicherà che non ci sono strade per altre soluzioni e quindi c'è solo una soluzione
    }

    for(int i = 1;i < 10;i++) // numeri da 1 a 9 da provare
    {
        if(checkNum(sudoku,i,riga,col,((riga/3) * 3) + (col / 3)))
        {
            int tmp = sudoku[riga][col]; // salva il numero in caso nel futuro si rivelasse una posizione inadeguata per quel numero
            sudoku[riga][col] = i; // mete il numero scelto dentro il sudoku una volta controllato da checkNum()

            if(!getBlankCell(sudoku)) // controlla se in questa chiamata e la fine del sudoku se si segna che ha trovato una soluzione del sudoku
                solved ++;

            // RICORSIONE: se il risultato dato dalla sua chiamata e falso significa che tuttas la sua ramificazione di sotto chiamate e andata
            //in un vicolo ceco percio torna indietro per cercare una nuova strada dove po trovare la soluzione
            //altrimenti se vero percio la strada presa dalle chiamate successive a portato a una soluzione
            //ritorna vero per dire al chiamante iniziale che ha trovato una soluzione
            if(sudokuSolver(sudoku,solved))
                return true;

            //_______________QUESTA PARTE SI AVVERA SOLO SE LA CHIAMATA RICORSIVA RITORNA FALSO__________________
            //ed essa resettera il valore della cella come oscurato per dare altre possiilita di combinazioni
            sudoku[riga][col] = tmp;
            //____________________________________________________________________________________________________
        }
    }
    return false;
}

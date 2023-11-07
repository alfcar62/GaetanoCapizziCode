/*
    Marco Schaivello 3/4 ^CI 24/08/2021

    Realizzare un programma che produca lo schema del gioco del Sudoku che è una matrice 9x9,
    suddivisa in 9 matrici di 3x3. Ogni sottomatrice contiene i numeri da 1 a 9, ogni riga e ogni colonna
    della matrice 9x9 contiene i numeri da 1 a 9.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 9
#define CELLE_OSCU 10

void pulisciSudoku(int sudoku[][DIM]);
bool generaSudoku(int sudoku[][DIM],int riga = 0,int col = 0);
void oscuraCelle(int sudoku[][DIM]);
bool isSolvable(int sudoku[][DIM],int riga,int col);
int pickRand(int nums[],int availableNum,int * index);
void sortSele(int arr[],int len);
bool checkNum(int sudoku[][DIM],int num,int riga,int col,int quad);
void stampaSudoku(int sudoku[][DIM]);
void chiediInput(int sudoku[][DIM]);
bool contrSudoku(int sudoku[][DIM]);
void pulisciScermo();
void linea(int len,bool lineBreak = true);
bool getBlankCell(int sudoku[][DIM],int * riga = NULL,int * col = NULL);
bool HasMoreSolu(int sudoku[][DIM],int solved = 0);
void matrixCopy(int src[][DIM],int dest[][DIM]);
int countNumAvai(int nums[],int len);
void clearTriedNums(int nums[],int len);

/*___________Main___________*/
int main()
{

    int sudoku[DIM][DIM];
    pulisciSudoku(sudoku);
    generaSudoku(sudoku);
    oscuraCelle(sudoku);

    do
    {
        pulisciScermo();
        stampaSudoku(sudoku);
        chiediInput(sudoku);
        getch();
    }
    while(getBlankCell(sudoku));

    stampaSudoku(sudoku);

    printf("\nHai vinto!\n\n");

    return 0;
}

/**
*   pulisce l'area di gioco inizializzando tutte le celle a zero
*   params:
*       @param int sudoku[][] : output : matrice da pulire
*       @return void
*/
void pulisciSudoku(int sudoku[][DIM])
{
    for(int i = 0;i < DIM;i++)
        for(int j = 0;j < DIM;j++)
            sudoku[i][j] = 0;
}

/**
*   genera le soluzioni del sudoku e oscura alcune caselle che dovranno essere indovinate dall'utente
*   params:
*       @param int sudoku[][] : output : matrice su cui mettere il sudoku creato
*       @return void
*/
bool generaSudoku(int sudoku[][DIM],int riga,int col)
{
    if(riga >= 9)//fine generazione sudoku
        return true;

    srand(time(0));
    int nums[9] = {1,2,3,4,5,6,7,8,9};
    bool giusto = false;
    int num = 1, numAvai,index;

    giusto = false;

    while(giusto == false)
    {
        numAvai = countNumAvai(nums,sizeof(nums)/4);

        if(numAvai == 0)
            return false;

        num = pickRand(nums,numAvai,&index); //prende numero casuale tra quelli non ancora provati
        giusto = checkNum(sudoku,num,riga,col,((riga/3) * 3) + (col / 3));

        if(giusto)
        {
            sudoku[riga][col] = num; // mete il numero scelto dentro il sudoku una volta controllato da checkNum()

            int col_ = col+1;
            int riga_ = riga;
            if(col_ == 9)
            {
                col_ = 0;
                riga_ = riga + 1;
            }

            // RICORSIONE: se il risultato dato dalla sua chiamata e falso significa che tuttas la sua ramificazione di sotto chiamate e andata
            //in un vicolo ceco percio torna indietro per cercare una nuova strada dove po trovare la soluzione
            //altrimenti se vero percio la strada presa dalle chiamate successive a portato a una soluzione
            //ritorna vero per dire al chiamante iniziale che ha trovato una soluzion
            if(generaSudoku(sudoku,riga_,col_))
                return true;

            //_______________QUESTA PARTE SI AVVERA SOLO SE LA CHIAMATA RICORSIVA RITORNA FALSO__________________
            //ed essa resettera il valore della cella a vuoto per dare altre possiilita di combinazioni
            sudoku[riga][col] = 0;
            giusto = false;
            //____________________________________________________________________________________________________

        }

        if(giusto == false) // marchia come non valido il numero per questa posizione cosi quando dovrà prendere il prossimo numero casuale in questa posizione sarà diverso da questo
            nums[index] += 100;

        //ordina l'array in modo crescente per avere i numeri provati da una parte e quelli non dall'altra
        sortSele(nums,sizeof(nums)/4);
    }
}

/**
*   oscura delle in modo che l'utente metta il suo contenuto per finire il quiz per ogni spazio verra controllata la unicita della soluzione
*   params:
*       @param int sudoku[][] : output : matrice dove verrano oscurate le celle
*       @return void
*/
void oscuraCelle(int sudoku[][DIM])
{
    srand(time(0));
    int riga,col;

    for(int i = 0;i < CELLE_OSCU;i++)
    {
        do
        {
            riga = rand()%9;
            col = rand()%9;
        }
        while(sudoku[riga][col] == 0 || sudoku[riga][col] > 100  || !isSolvable(sudoku,riga,col));

        sudoku[riga][col] += 100;
    }
}

/**
*   clona in una matrice temporanea e calcola se e risolvibile risolvendolo
*   oscurando la casella che si vuole oscurare prima che venga oscurata
*   params:
*       @param int sudoku[][] : input : matrice dove verrano oscurate le celle
*       @param int riga: input : riga nella quale si vuole oscurare la cella
*       @param int col: input : colonna nella quale si vuole oscurare la cella
*       @return bool : fattibilità o meno del sudoku
*/
bool isSolvable(int sudoku[][DIM],int riga,int col)
{
    int sudokuCopy[DIM][DIM];
    matrixCopy(sudoku,sudokuCopy);
    sudokuCopy[riga][col] +=100;

    if(HasMoreSolu(sudokuCopy))
        return false;

    return true;

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
            if(sudoku[i][j] > 100)
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
*   vede se ci sono piu soluzioni, se il sudoku non presenta celle vuote esso lo considererà come un sudoku con piu soluzioni
*   params:
*       @param int sudoku[][] : input : sudoku con caselle oscurate da controllare per vedere se ci sono più soluzioni
*       @param int solved = 0: / : parametro ausiliare per la ricorsione che indica quante soluzioni sono state trovate
*       @return bool : se vero il sudoku avra piu soluzioni altrimenti se falso significa che ne ha solo una
*/
bool HasMoreSolu(int sudoku[][DIM],int solved)
{
    int riga,col;

    if(!getBlankCell(sudoku,&riga,&col)) // condizione in cui abbiamo una soluzione o non ci sono celle oscurate
    {
        if(solved == 0) // questo caso si avverà ci sono 0 posti dove mettere i numeri percio non si riesce ad arrivare nemmeno a una soluzione
            return true;
        // qua ci si segna ce ne abbiamo trovato una soluzione, ma ritorniamo falso per forzare l'algortmo a trovarne altre
        //ma se non trovera altre soluzioni andra sempre piu in alto nell'albero delle chiamate per cercare strade che portino alla soluzione
        //fino ad arrivare alla prima chiamata che se fallira indicherà che non ci sono strade per altre soluzioni e quindi c'è solo una soluzione
        if(solved == 1)
            return false;
        //invece se tornando indietro nell'albero delle chiamate trovera una altra strada per una soluzione incrementerà il numero di soluzioni trovare indicando la presenza di piu soluzioni
        //percio avremo che tutte le sotto chiamate ritorneranno true fino alla chiamata originale dando come risultato vero
        if(solved == 2)
            return true;
    }

    for(int i = 1;i < 10;i++) // numeri da 1 a 9 da provare
    {
        if(checkNum(sudoku,i,riga,col,((riga/3) * 3) + (col / 3)))
        {
            int tmp = sudoku[riga][col]; // salva il numero in caso nel futuro si rivelasse una posizione inadeguata per quel numero
            sudoku[riga][col] = i; // mete il numero scelto dentro il sudoku una volta controllato da checkNum()

            if(!getBlankCell(sudoku)) // controlla se in questa chiamata e la fine del sudoku se si segna che ha trovato una soluzione del sudoku
                solved ++;

            // RICORSIONE: se il risultato dato dalla sua chiamata e falso significa che tuttas la sua ramificazione di chiamate e andata
            //in un vicolo ceco percio torna indietro altrimenti se vero percio la strada presa dalle chiamate successive a portato a una soluzione
            //percio ritorna vero per dire al chiamante iniziale che ha trovato una soluzione
            if(HasMoreSolu(sudoku,solved))
                return true;

            //_______________QUESTA PARTE SI AVVERA SOLO SE LA CHIAMATA RICORSIVA RITORNA FALSO__________________
            //ed essa resettera il valora della cella come oscurato per dare altre possiilita di combinazioni
            sudoku[riga][col] = tmp;
            //____________________________________________________________________________________________________
        }
    }
    return false;
}

/**
*   copia una matrice dentro una altra
*   params:
*       @param int src[][DIM] : input : matrice da copiare
*       @param int dest[][DIM]: output : matrice su cui verra copiata quella sorgente
*       @return void
*/
void matrixCopy(int src[][DIM],int dest[][DIM])
{
    for(int i = 0;i < DIM;i++)
        for(int j = 0;j < DIM;j++)
            dest[i][j] = src[i][j];
}

/**
*   conta quanti numeri non ancora provati per quella posizione e non ancora messi da altre parti nel quadrante ci sono
*   tra i numeri forniti come parametro
*   params:
*       @param int nums[] : input : vettore di numeri
*       @param int len : input : lunghezza dell'array che corrispondi all'numero di meri totali
*       @return int : numero di numeri non provati
*/
int countNumAvai(int nums[],int len)
{
    int numAve = len;
    for(int i = 0;i < len;i++)
         if(nums[i] > 100)
            numAve--;
    return numAve;
}

/**
*   pulisce tutti i numeri provati per una cella una volta messo un numero al suo interno
*   params:
*       @param int nums[] : input : vettore di numeri
*       @param int len : input : lunghezza dell'array
*       @return void
*/
void clearTriedNums(int nums[],int len)
{
     for(int i = 0;i < len;i++)
        if(nums[i] > 10 && nums[i] < 200)
            nums[i] -= 100;
}

/**
*   ordina l'array in modo crescente per avere i numeri provati su una cella o numeri gia messi in un quadrante
*   spostati da una parte rispetto a quelli non ancora messi/provati
*   params:
*       @param int arr[] : input/output : array da ordinare
*       @param int len : input : lunghezza dell'array
*       @return void
*/
void sortSele(int arr[],int len)
{
    for(int i = 0;i < len-1;i++)
        for(int j = i+1;j < len;j++)
            if(arr[j] < arr[i])
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
}

/**
*   sceglie da un array di numeri uno a caso, non dando lo stesso di prima
*   params:
*       @param int nums[] : input : array di numeri tra cui scegliere
*       @return int : numero scelto a caso
*/
int pickRand(int nums[],int availableNum,int * index)
{
    int num;
    int random = rand()%availableNum;

    num = nums[random];
    *index = random;

    return num;
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
*   sottoprogramma ausiliare per la stampa del sudoku che stampa una linea lunga len
*   dove len e deciso dall'utente
*   params:
*       @return int len : input : lunghezza della linea
*       @return bool lineBreak = false : input : parametro volontario che indica se mettere uno spazio tra una righa e l'altra
*       @return void
*/
void linea(int len,bool lineBreak)
{
    printf("  ");
    for(int i = 0;i< len;i++)
    {
        if(lineBreak && i % 3 == 2)
            printf("o---o ");
        else
            printf("o---");
    }

    printf("\n");

}

/**
*   sottoprogramma che pulisce lo schermo
*   params:
*       @return void
*/
void pulisciScermo()
{
    system("cls");
}

/**
*   chiede dove mettere il numero scelto dall'utente e il valore da assegnare a quella cella
*   params:
*       @param int sudoku[][] : output : dove verrà applicata la scelta
*       @return void
*/
void chiediInput(int sudoku[][DIM])
{
    int riga,col,val;
    bool err;
    do
    {
        err = false;
        printf("In quale posizione vuoi mettere il numero: \n");
        printf("riga: ");
        scanf("%d",&riga);
        printf("colonna: ");
        scanf("%d",&col);
        if((col < 1 || col > 9) || (riga < 1 || riga > 9))
        {
            printf("cordinate sbagliate mettere una colonna e riga tra 1 e 9\n");
            err = true;
        }
    }
    while(err == true);

    do
    {
        err = false;
        printf("mettere numero a cordinate riga:%d colonna:%d  : ",riga,col);
        scanf("%d",&val);
        if(val < 1 || val > 9)
        {
            printf("il numero da inserire deve essere tra 1 e 9\n");
            err = true;
        }
    }
    while(err == true);

    printf("\n");
    if((sudoku[riga-1][col-1] - 100) == val)
    {
        sudoku[riga-1][col-1] -=100;
        printf("il numero e' giusto!\n");
    }
    else
        printf("il numero e' sbagliato\n");
}

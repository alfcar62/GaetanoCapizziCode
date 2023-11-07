/************************************************
CONSEGNA:
Scrivere un programma in C language che raccoglie
in un menu tutti i programmi svolti da Es.12 a
Es.16. Utilizzare l'istruzione switch case

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    09 Novembre 2021
*************************************************/


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int programma;

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    do
    {
        printf("1. Esercizio 12 (Moltiplicazione)\n");
        printf("2. Esercizio 13 (Divisione)\n");
        printf("3. Esercizio 14 (Quadrato)\n");
        printf("4. Esercizio 15 (Fibonacci)\n");
        printf("5. Esercizio 16 (Numeri primi)\n");
        printf("6. Esci\n");
        printf("\nInserire codice programma -> ");
        scanf("%d", &programma);

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        switch (programma)
        {
            case 1: {
                // Dichirazione variabili
                int n1 = 0,
                    n2 = 0,
                    r  = 0,
                    i  = 0;

                // Output iniziale
                printf("Esercizio 12: Moltiplicazione con addizioni successive \n");

                // Input del primo fattore
                do
                {
                    printf("Inserire primo numero -> ");
                    scanf("%d", &n1);
                } while (n1 < 1);

                // Input del secondo fattore
                do
                {
                    printf("Inserire secondo numero -> ");
                    scanf("%d", &n2);
                } while (n2 < 1);

                // Calcolo del prodotto attraverso le addizioni successive
                for (i = 0; i < n2; i++)
                    r += n1;
                
                // Output risultato
                printf("Il risultato e': %d\n", r);
            } break;

            case 2: {
                // Dichiaraizone variabili
                int n1 = 0,
                    n2 = 0,
                    r  = 0;
                
                // Output iniziale
                printf("Esercizio 13: Divisione con sottrazioni successive \n");
                
                // Input del primo numero
                do
                {
                    printf("Inserire primo numero -> ");
                    scanf("%d", &n1);
                } while (n1 < 1);

                // Input del secondo numero
                do
                {
                    printf("Inserire secondo numero -> ");
                    scanf("%d", &n2);
                } while (n2 < 1);

                // Effettua la divisione per sottrazioni successive
                for (r = 0; n1 - n2 >= 0; r++)
                    n1 -= n2;

                // Output risultato
                printf("Il quoziente e': %d\n", r);
            } break;

            case 3: {
                // Dichirazione variabili
                int n   =  0,
                    i   =  0,
                    r   =  0,
                    odd = -1;

                // Output iniziale
                printf("Esercizio 14: Quadrato di un numero n usando i primi n numeri dispari \n");

                // Input del numero
                do
                {
                    printf("Inserire numero -> ");
                    scanf("%d", &n);
                } while (n < 1);

                // Somma dei primi n numeri dispari
                for (i = 0; i < n; i++)
                {
                    odd += 2;
                    r   += odd;
                }
                
                // Output finale
                printf("Il quadrato di %d e': %d\n", n, r);
            } break;

            case 4: {
                // Dichirazione variabili
                int n  = 0,
                    n1 = 0,
                    n2 = 1,
                    r  = 0,
                    i  = 0;

                // Output iniziale
                printf("Esercizio 15: Sequenza di Fibonacci dei i primi n numeri\n");

                // Input del numero
                do
                {
                    printf("Inserire numero -> ");
                    scanf("%d", &n);
                } while (n < 3);

                // Stampare 0 ed 1 (Fissi)
                printf("%d\n%d\n", n1, n2);

                // Stampare tutti gli altri numeri della sequenza
                for (i = 2; i < n; i++)
                {
                    r  = n1 + n2;
                    n1 = n2;
                    n2 = r;

                    printf("%d \n", r);
                }
            } break;

            case 5: {
                int n     = 1,
                    i     = 0,
                    resti = 0,
                    jump  = 0,
                    div   = 0, 
                    primi = 0;

                // Output iniziale
                printf("Esercizio 16: Dato un numero n in input, stampare i primi n numeri primi\n");

                do
                {
                    printf("Inserire quantita' di valori primi che si vogliono generare -> ");
                    scanf("%d", &primi);
                } while (primi < 1);

                for (i = 0; i < primi; i += !resti)
                {
                    jump  = !resti * ((n > 2) + (jump == 2 && n >= 7) * 2) + 1 + !!resti;
                    resti = 0;

                    for (div = 2; div < n && div < 4; div++)
                        resti += n % div == 0;
                    
                    for (div = 5; div < n && !resti; div += 2)
                        resti += n % div == 0;
                    
                    (!resti) ? printf("%d ", n) : 0;
                    
                    jump -= !!resti * 2 * (jump == 4);
                    n    += jump;
                }
            } break;

            default:
                break;
        }

        printf("\n\n");
    } while (programma != 6);

    return 0;
}

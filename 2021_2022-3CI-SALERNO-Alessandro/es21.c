/************************************************
CONSEGNA:
Leggere in input un numero intero
compreso tra 0 e 10.000.
Trasformare il numero in lettere e stamparlo
in output.

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    24 Novembre 2021
*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
    #define wait(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define CLEAR "clear"
    #define wait(ms) usleep(ms * 1000)
#endif


void gotoxy(int x, int y)
{
    #if defined (_WIN32) && defined (LEGACY_WINDOWS)
        COORD pos     = { x + 1, y + 1 };
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handle, pos);
    #else
        printf("\033[%d;%dH", y + 1, x + 1);
    #endif
}


int main()
{
    int  n = 0,  // Numero in cifre iniziale (Intero compreso tra 0 e 9999)
         m = 0, // Migliaia (Intero compreso tra 0 e 9)
         c = 0, // Centinaia (Intero compreso tra 0 e 9)
         d = 0, // Decine (INtero compreso tra 0 e 9)
         u = 0; // Unità (Intero compreso tra 0 e 9)

    char ans;   // Risposta dell'utente alla domanda: "Vuoi ripetere?"

    do
    {
        do
        {
            system(CLEAR);

            gotoxy(19, 0);
            printf("CONVERTITORE DI NUMERI DA CIFRE A LETTERE");

            gotoxy(21, 10);
            printf("Inserire il numero da convertire");
            gotoxy(38, 11);
            printf("....");
            
            gotoxy(38, 11);
            scanf("%d", &n);

            if (n < 0 || n > 9999)
            {
                gotoxy(23, 14);
                printf("%d non e' un numero valido\n\n", n);
                wait(1500);
            }
        } while (n < 0 || n > 9999);
        
        // Calcoli
        m = n / 1000;
        c = (n - (m * 1000)) / 100; 
        d = (n - (m * 1000) - (c * 100)) / 10;
        u = n - (m * 1000) - (c * 100) - (d * 10);

        gotoxy(25, 14);

        switch (m)
        {
            case 0:                            break;
            case 1: { printf("Mille");       } break;
            case 2: { printf("Duemila");     } break;
            case 3: { printf("Tremila");     } break;
            case 4: { printf("Quattromila"); } break;
            case 5: { printf("Cinquemila");  } break;
            case 6: { printf("Seimila");     } break;
            case 7: { printf("Settemila");   } break;
            case 8: { printf("Ottomila");    } break;
            case 9: { printf("Novemila");    } break;
        }

        switch (c)
        {
            case 0:                             break;
            case 1: { printf("Cento");        } break;
            case 2: { printf("Duecento");     } break;
            case 3: { printf("Trecento");     } break;
            case 4: { printf("Quattrocento"); } break;
            case 5: { printf("Cinquecento");  } break;
            case 6: { printf("Seicento");     } break;
            case 7: { printf("Settecento");   } break;
            case 8: { printf("Ottocento");    } break;
            case 9: { printf("Novecento");    } break;
        }

        switch (d)
        {
            case 0:
                break;
            
            case 1: {
                switch (u)
                {
                    case 0: { printf("Dieci");       } break;
                    case 1: { printf("Undici");      } break;
                    case 2: { printf("Dodici");      } break;
                    case 3: { printf("Tredici");     } break;
                    case 4: { printf("Quattordici"); } break;
                    case 5: { printf("Quindici");    } break;
                    case 6: { printf("Sedici");      } break;
                    case 7: { printf("Diciassette"); } break;
                    case 8: { printf("Diciotto");    } break;
                    case 9: { printf("Diciannove");  } break;
                }
            } break;
            
            default: {
                if (u == 1 || u == 8)
                {
                    switch (d)
                    {
                        case 2: { printf("Vent");     } break;
                        case 3: { printf("Trent");    } break;
                        case 4: { printf("Quarant");  } break;
                        case 5: { printf("Cinquant"); } break;
                        case 6: { printf("Sessant");  } break;
                        case 7: { printf("Settant");  } break;
                        case 8: { printf("Ottant");   } break;
                        case 9: { printf("Novant");   } break;
                    }
                }
                else
                {
                    switch (d)
                    {
                        case 2: { printf("Venti");     } break;
                        case 3: { printf("Trenta");    } break;
                        case 4: { printf("Quaranta");  } break;
                        case 5: { printf("Cinquanta"); } break;
                        case 6: { printf("Sessanta");  } break;
                        case 7: { printf("Settanta");  } break;
                        case 8: { printf("Ottanta");   } break;
                        case 9: { printf("Novanta");   } break;
                    }
                }

                switch (u)
                {
                    case 0: {
                        if (m + c + d == 0)
                            printf("Zero");
                    } break;
                    
                    case 1: { printf("Uno");     } break;
                    case 2: { printf("Due");     } break;
                    case 3: { printf("Tre");     } break;
                    case 4: { printf("Quattro"); } break;
                    case 5: { printf("Cinque");  } break;
                    case 6: { printf("Sei");     } break;
                    case 7: { printf("Sette");   } break;
                    case 8: { printf("Otto");    } break;
                    case 9: { printf("Nove");    } break;
                }
            } break;
        }

        do
        {
            gotoxy(0, 16);
            printf("Continuare? [S/n] ");
            scanf("%c", &ans);
            ans = toupper(ans);
        } while (ans != 'S' && ans != 'N');
        
    } while (ans != 'N');
    
    system(CLEAR);
    return 0;
}

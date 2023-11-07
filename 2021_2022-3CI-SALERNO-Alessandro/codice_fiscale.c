/************************************************
CONSEGNA:
Calcolare il codice fiscale: step 1: Calcolo
del cognome

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    16 Febbraio 2022
*************************************************/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FIRSTNAME_LEN 16    /* Lunghezza del nome    */
#define LASTNAME_LEN  30    /* Lunghezza del cognome */
#define TERMINATOR     0    /* Terminatore stringhe  */

// Alternative più sicure a gets e puts
// ZSH (La CLI Shell di macOS) da warning se si usano gets e puts e danno altri problemi su Windows
#define GETS(__str) scanf("%[^\n]%*c", __str)
#define PUTS(__str) printf("%s", __str)


// Restituisce true se il carattere __chr è una consonante e false se è na vocale
bool Consonante(char __chr)
{
    char _toup_chr = toupper(__chr);

    return _toup_chr != 'A' &&
           _toup_chr != 'E' &&
           _toup_chr != 'I' &&
           _toup_chr != 'O' &&
           _toup_chr != 'U' &&
           !isspace(_toup_chr);
}

void DividiVocaliConsonanti(char __stringa[], char __vocali[], char __consonanti[])
{
    unsigned int _consonanti_idx = 0,   /* Indice nell'array consonanti   */
                 _vocali_idx     = 0;   /* Indice nell'array delle vocali */

    char* _chr;
    for (
         _chr = __stringa /* Il puntatore viene impostato alla base dell'array           */ ;
        *_chr             /* Fin quando non si raggiunge lo 0                            */ ;
         _chr++           /* Si incrementa il puntatore per assare al prossimo carattere */
    )
    {
        // Il puntatore _elemento assume valore pari all'indirizzo del successivo elemento nell'array richiesto
        // L'array da utilizzare è determinato dal valore restituito da Consonante
        // NOTA: L'indice _idx viene anche incrementato
        char* _elemento = (Consonante(*_chr)) ? &(__consonanti[_consonanti_idx++]) :
                                                &(__vocali[_vocali_idx++]);

        // Il carattere viene inserito nell'array corretto alla posizione corretta
        *_elemento = *_chr;
    }

    // Per sicurezza, viene aggiunto il Null Terminator agli array, in modo che possano essere trattati come stringhe
    __consonanti[_consonanti_idx] = TERMINATOR;
    __vocali[_vocali_idx]         = TERMINATOR;
}

// Genera il cognome usando le prime 3 consonanti
void CognomeDaConsonanti(char __consonanti[], char __cognome[])
{
    __cognome[3] = TERMINATOR; /* Viene inserito il terminator nell'array per "renderlo" una stringa */
    int _i;                    /* Indice nell'array                                                  */

    // Vengono copiate le prime 3 consonanti
    // Se le consonanti sono più di 3, il ciclo si ferma alla terza
    // Se le consonanti sono meno di 3, il ciclo si ferma alla fine dell'array
    for (_i = 0; __consonanti[_i] && _i < 3; _i++)
        __cognome[_i] = toupper(__consonanti[_i]);

    // Utilizzando l'ultimo indice del for precedente, si riempiono tutte le altre posizioni con X
    for (; _i < 3; _i++)
        __cognome[_i] = 'X';
}

int main()
{
    char _cognome    [LASTNAME_LEN];    /* Contiene il cognome                      */

    char _consonanti [LASTNAME_LEN];    /* Contiene tutte le consonanti del cognome */
    char _vocali     [LASTNAME_LEN];    /* Contiene tutte le vocali del cognome     */

    char _cognome_corto[4];             /* Contiene il cognome abbreviato           */

    // Input del cognome
    printf("Inserire cognome -> ");
    GETS(_cognome);

    DividiVocaliConsonanti(_cognome, _vocali, _consonanti);
    CognomeDaConsonanti(_consonanti, _cognome_corto);

    printf("Cognome codice fiscale: %s\n", _cognome_corto);

    return 0;
}

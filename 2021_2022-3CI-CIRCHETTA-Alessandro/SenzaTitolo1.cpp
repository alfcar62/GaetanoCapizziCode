/************************************************
Verifica di laboratorio

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    23 marzo 2022
*************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

// Limiti
#define MAX_STR_LEN 200
#define MIN_MENU_OPT  1
#define MAX_MENU_OPT  6

// Opzioni per continuare
#define OPT_OK 'S'
#define OPT_NO 'N'

// ID Menu'
#define ENT_COUNT           1
#define ENT_COUNT_NO_SPACDE 2
#define ENT_COUNT_VOC_CONS  3
#define ENT_COUNT_WORDS     4
#define ENT_CHECKSUM        5
#define ENT_EXIT            6

#define SPACE ' '

#define CLEAR() system(CLEAR_STR)

#ifdef _WIN32
    #define CLEAR_STR "cls"
#else
    #define CLEAR_STR "clear"
#endif


// Restituisce true se il carattere è 'S', false altrimenti
bool __isok__(char __chr)
{
    return toupper(__chr) == OPT_OK;
}

// Restituisce true se il carattere è una possibile risposta a "Continuare?", altrimenti false
bool __isopt__(char __chr)
{
    return toupper(__chr) == OPT_OK ||
           toupper(__chr) == OPT_NO;
}

// Restituisce il numero di volte che un carattere si trova in una stringa
unsigned int __strcount__(char __str[], char __chr)
{
    unsigned int _count = 0;    // Contatore del numero di volta che il carattere __chr si trova nella stringa
    char* _chr;                 // Puntatore al carattere dentro la stringa

    // Per ogni carattere nella stringa, fin quando non si incontra il NULL terminator
    for (_chr = __str; *_chr; _chr++)
        _count += *_chr == __chr;

    return _count;
}

// Restituisce true se il carattere passato è una vocale, altrimenti false
bool __voc__(char __chr)
{
    return toupper(__chr) == 'A' ||
           toupper(__chr) == 'E' ||
           toupper(__chr) == 'I' ||
           toupper(__chr) == 'O' ||
           toupper(__chr) == 'U';
}

// Restituisce l'opposto di __voc__
bool __cons__(char __chr)
{
    return !__voc__(__chr);
}

// Prima entry nel menu
void ent_count_chars(char __str[])
{
    CLEAR();
    printf("Scelta %u --- Contare caratteri\n\n", ENT_COUNT);

    // Sottraggo 1 per tener conto del terminatore
    printf("Numero totale di caratteri: %lu", strlen(__str));
}

// Seconda entry nel menu
void ent_count_char_nospace(char __str[])
{
    CLEAR();
    printf("Scelta %u --- Contare caratteri (No spazi)\n\n", ENT_COUNT_NO_SPACDE);

    // Si sottrae il numero di spazi 
    printf("Numero totale di caratteri: %lu", strlen(__str) - __strcount__(__str, SPACE));
}

// Terza entry nel menu
void ent_count_voc_cons(char __str[])
{
    CLEAR();
    printf("Scelta %u --- Contare vocali e consonanti\n\n", ENT_COUNT_VOC_CONS);

    unsigned int _voc  = 0,
                 _cons = 0;

    char* _chr;
    for (_chr = __str; *_chr; _chr++)
    {
        if (!isalpha(*_chr))
            continue;

        _voc  += __voc__(*_chr);
        _cons += __cons__(*_chr);
    }

    printf("Numero di vocali: %u\n", _voc);
    printf("Numero di consonanti: %u", _cons);
}

// Quarta entry nel menu
void ent_count_words(char __str[])
{
    CLEAR();
    printf("Scelta %u --- Contare parole\n\n", ENT_COUNT_WORDS);

    // Si aggiunge 1 al conto degli spazi per tener conto del fatto che dopo l'ultima parola, solitamente, non ci sono spazi
    printf("Numero di parole: %u", __strcount__(__str, SPACE) + 1);
}

// Quinta entry nel menu
void ent_checksum(char __str[])
{
    CLEAR();
    printf("Scelta %u --- Checksum\n\n", ENT_CHECKSUM);

    unsigned long int _checksum;    // Intero a 64 bit senza segno per contenere la checksum
    
    char* _chr;
    for (_chr = __str; *_chr; _chr++)
        _checksum += *_chr;

    printf("Checksum del testo: %lu", _checksum);
}

void menu()
{
    printf("1. Contare numero di caratteri (Spazi inclusi)\n");
    printf("2. Contare numero di caratteri (Spazi esclusi)\n");
    printf("3. Contare numero di vocali e consonanti\n");
    printf("4. Contare numero di parole\n");
    printf("5. Checksum dei caratteri\n");
    printf("6. Esci\n");
}

bool repeat()
{
    bool _choice;
    char _input;

    do
    {
        printf("\n\nContnuare? [S/n] ");

        // Prende la conferma di voler continuare
        // Assert fa in modo che solo caratteri possano essere inseriti
        // Lo spazio in " %c" evita che l'operazione fallisca su alcuni sistemi, ignorando il carattere "caret" della console
        assert(1 == scanf(" %c", &_input));

        _choice = __isok__(_input);

        CLEAR();
    } while (!__isopt__(_input));

    return _choice;
}

void menuhandle(char __str[], unsigned int __choice)
{
    switch (__choice)
    {
        case ENT_COUNT:             ent_count_chars(__str);          break;
        case ENT_COUNT_NO_SPACDE:   ent_count_char_nospace(__str);   break;
        case ENT_COUNT_VOC_CONS:    ent_count_voc_cons(__str);       break;
        case ENT_COUNT_WORDS:       ent_count_words(__str);          break;
        case ENT_CHECKSUM:          ent_checksum(__str);             break;
        case ENT_EXIT:              exit(0);                         break;
    }
}

unsigned int menuin()
{
    unsigned int _input;

    do
    {
        menu();
        printf("\n\nOpzione --> ");
        assert(1 == scanf("%u", &_input));  // Prende numero in input assicurandosi che sia un intero. Se non lo è, termina il programma
        CLEAR();
    } while (_input < MIN_MENU_OPT || _input > MAX_MENU_OPT);

    return _input;
}

int main()
{
    char _testo[MAX_STR_LEN];   // Buffer del testo preso in input

    CLEAR();
    printf("Verifica di Laboratorio di Informatica:\nAutore: A. Salerno\nData: 23 marzo 2022\n\n");
    
    printf("Testo --> ");
    gets(_testo); 

    do
        menuhandle(_testo, menuin());
    while (repeat());

    return 0;
}

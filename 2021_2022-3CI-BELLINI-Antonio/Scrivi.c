#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct book {
    char bookCode[12],      // Codice ISBN del libro
         bookTitle[32],     // Titolo del libro
         bookAutor[32];     // Autore del libro
    int bookPage;           // Numero totale di pagina del libro
    float bookCost;         // Costo del libro
} book_t;

void uploadBook(book_t library[]) {
    int i;

    for (i = 0; i < MAX; i++) {
        printf("Dati del libro %d\n",(i+1));
        // Input del codice ISBN del libro
        printf("Inserisci il codice ISBN del libro che vuoi aggiungere-->");
        scanf("%s", library[i].bookCode);
        printf("\n");

        // Input del titolo del libro
        printf("Inserisci il titolo del libro-->");
        scanf("%s", library[i].bookTitle);
        printf("\n");

        // Input dell'autore del libro
        printf("Inserisci il cognome dell'autore del libro-->");
        scanf("%s", library[i].bookAutor);
        printf("\n");

        // Input del numero massimo di pagine
        printf("Inserisci il numero totali di pagine del libro-->");
        scanf("%d", &library[i].bookPage);
        printf("\n");

        // Input del costo del libro
        printf("Inserisci il costo del libro-->");
        scanf("%f", &library[i].bookCost);
        printf("\n");
    }
}

int main() {
    // Dichiaro la bibblioteca
    book_t library[MAX];

    // Chiamo la procedura per scrivere i vari libri
    uploadBook(library);

    // Apro il file contenente tutti i libri
    FILE *fp = fopen("biblioteca.dat", "w");

    return 0;
}
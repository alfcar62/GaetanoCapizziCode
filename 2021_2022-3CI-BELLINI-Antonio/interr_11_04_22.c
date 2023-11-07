#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CHAR 4

int main(){
    char string[CHAR];
    int i,
        somma = 0;

    printf("Inserisci la parola-->");
    gets(string);

    for (i = 0; i < strlen(string); i++)
        somma += string[i];

    printf("La somma vale %d",somma);

    return 0;
}
/*****************************************************************************************************
Consegna: 
Programma che è in grado di calcolare il codice fiscale di una persona 


Nome:Antonio		Cognome:Bellini 
Classe: 3C INFO		Data: 16/02/2022
********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#define MAX_CHAR    16
#define MAX_COGNOME 30
#define MAX_NOME    30
#define MAX_CONS    30
#define MAX_VOC     30


// PROCEDURA CHE CHIEDE IN INPUT:
// COGNOME
// NOME
void Cognome_Nome(char surname[], char name[]){
    bool error_surname  = FALSE,    // Segna un eventuale errore nel cognome
         error_name     = FALSE;    // Segna un eventuale errore nel nome
    int c,                          // Usata nei cicli for per il cognome
        n;                          // Usata nei cicli for per il nome
        
// COGNOME
    do{
        // Input cognome
        system("cls");
        printf("Inserisci il tuo cognome-->");
        scanf("%s",surname);

        // Trasformo il cognome in maiuscolo
        for (c = 0; c < strlen(surname); c++){
            surname[c] = toupper(surname[c]);
            printf("%c",surname[c]);
        }

        // Controllo il cognome inserito 
        for (c = 0; c < strlen(surname); c++){
            if ((surname[c] < 'A' || surname[c] > 'Z') && surname[c] != ' ' && surname[c] != '\'')
                error_surname = true;
        }

    }while(error_surname == true);


// NOME
    do{
        // Input nome 
        printf("\nInserisci il tuo nome-->");
        scanf("%s",name);

        // Trasformo il nome in maiuscolo
        for(n = 0; n < strlen(name); n++){
            name[n] = toupper(name[n]);
            printf("%c",name[n]);
        }

        // Controllo il nome inserito 
        for (n = 0; n < strlen(name); n++){
            if ((name[n] < 'A' || name[n] > 'Z') && name[n] != ' ' && name[n] != '\'')
                error_name = true;
        }

    }while(error_name == true);
}

// PROCEDURA CHE SELEZIONA TUTTE LE VOCALI DEL NOME E DEL COGNOME
void selezione_vocali(char surname[], char name[], char voc_surname[], char voc_name[]){
    int c,
        n;

    // Selezione delle vocali del cognome 
    for (c = 0; c < strlen(surname); c++){
        if (surname[c] == 'A' || surname[c] == 'E' || surname[c] == 'I' || surname[c] == 'O' || surname[c] == 'U')
            voc_surname[c] = surname[c];
    }

    // Selezione delle vocali del nome 
    for (n = 0; n < strlen(surname); n++){
        if (name[n] == 'A' || name[n] == 'E' || name[n] == 'I' || name[n] == 'O' || name[n]  == 'U')
            voc_name[n] = name[n];
    }
}

// PROCEDURA CHE SELEZIONA LE PRIMA 3 CONSONANTI DEL COGNOME E DEL NOME
void selezione_consonanti(char surname[], char name[], char cons_surname[], char cons_name[], char voc_surname[], char voc_name[]){
    char extra_char = 'X';
    int c,
        n,
        ct_surname,
        ct_name;

// COGNOME
    // Selezione delle 3 consonanti del cognome 
    for (c = 0; c < strlen(surname); c++){
        if (surname[c] != 'A' && surname[c] != 'E' && surname[c] != 'I' && surname[c] != 'O' && surname[c] != 'U'){
            cons_surname[c] = surname[c];
            ct_surname++;
        }
        else{
        }
    }
    // Casi in cui il cognome ha meno di 3 consonanti 
    if (ct_surname < 3){
        // Caso con 0 consonanti 
        if (ct_surname == 0){
            printf("%c\n%c\n%c",voc_surname[0], voc_surname[1], extra_char);
        }
        // Caso con 1 consonante 
        if (ct_surname == 1){
            printf("%c\n%c\n%c",cons_surname[0], voc_surname[0], voc_surname[1]);
        }
        // Caso con 2 consonanti
        if (ct_surname == 2){
            printf("%c\n%c\n%c",cons_surname[0], cons_surname[1], voc_surname[0]);
        }
    }

    // Caso in cui il cognome ha 3 consonanti o piu
    if (ct_surname >= 3)
        printf("%c%c%c",cons_surname[0], cons_surname[1], cons_surname[2]);


// NOME
    // Selezione delle 3 consonanti del nome 
    for (n = 0; n < strlen(name); n++){
        if (name[c] != 'A' && name[c] != 'E' && name[c] != 'I' && name[c] != 'O' && name[c] != 'U'){
            cons_name[c] = name[c];
            ct_name++;
        }
        else{
        }
    }
}

int main(){
     char codice_fiscale        [MAX_CHAR]   ,
          cognome               [MAX_COGNOME],
          nome                  [MAX_NOME]   ,
          consonanti_cognome    [MAX_CONS]   ,
          consonanti_nome       [MAX_CONS]   ,
          vocali_cognome        [MAX_VOC]    ,
          vocali_nome           [MAX_VOC]    ;

    // INSERIMENTO COGNOME E NOME DA PARTE DELL'UTENTE
    Cognome_Nome(cognome, nome);

    // SELEZIONE DELLE 3 CONSONANTI DEL NOME E DEL COGNOME
    selezione_consonanti(cognome, nome, consonanti_cognome, consonanti_nome, vocali_cognome, vocali_nome);

    // SALVATAGGIO DELLE VOCALI PRESENTI NEL NOME E NEL COGNOME  
    selezione_vocali(cognome, nome, vocali_cognome, vocali_nome);


	return 0;
}
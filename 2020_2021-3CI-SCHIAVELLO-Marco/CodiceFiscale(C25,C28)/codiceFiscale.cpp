/*
    Marco Schiavello, Alberto Benedicenti 3^CI 25/03/2021

    Realizzare  con il linguaggio C il programma che effettua il calcolo del codice fiscale,
    in base a quanto spiegato nel documento allegato.
    Il programma deve chiedere in input i dati per calcolare il codice fiscale ed infine
    visualizzare il codice calcolato.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define LUOGO_LEN 30
#define COD_lEN 17
#define NOME_COGN_LEN 30
#define MAX_STR_LEN 60
#define OK 1
#define ERR 0
const char vocali[5] = {'A','E','I','O','U'};
const unsigned char accentate[10] = {133,138,161,149,151,183,212,222,227,235};// � � � � � ...

void toUpStr(char str[]);
bool isAcent(char c);
int valPari(char c);
int valDisp(char c);
bool AcenToChar(char arr[],int index);
bool isVocale(char c);
void insertCons(char str[],char codice[],int len,int start,bool nome = false);
bool checkCognome(char cognome[]);
void getCognome(char cognome[]);
bool checkNome(char nome[]);
void getNome(char nome[]);
void getDataNasci(int data[]);
void getGender(bool *femmina);
void insertData(int data[],char codice[], bool femmina);
void getluogoNasci(char luogoNasci[]);
int getCodiceByNome(char * nome, char * codice);
void insertLuogoNasci(char luogoNascita[],char codice[]);
void insertCIN(char codice[]);


int main()
{
    char nome[NOME_COGN_LEN],cognome[NOME_COGN_LEN],codice[COD_lEN], luogoNascita[LUOGO_LEN];
    int dataNasci[3];
    bool femmina;

    getCognome(cognome);
    getNome(nome);
    getluogoNasci(luogoNascita);
    getGender(&femmina);
    getDataNasci(dataNasci);

    insertCons(cognome,codice,3,0);
    insertCons(nome,codice,3,3,true);
    insertData(dataNasci,codice,femmina);
    insertLuogoNasci(luogoNascita,codice);
    insertCIN(codice);


    printf("%s",codice);

    return 0;
}

/**
*    fa un toupper() su ogni singolo
*    carattere della stringa.
*    Facendo cosi risurtare come un toupper
*    su tutta la stringa
*    Params:
*       @param char str[] : input/output : stringa da far diventare tutta maiuscola
*       @return void
*/
void toUpStr(char str[])
{
    for(int i = 0;i<strlen(str);i++)
        str[i] = toupper(str[i]);
}

/**
*    va a verificare se il carattere � accentato o no
*    Params:
*       @param char c : input : carattere da controllare
*       @return bool : il risulatato del controllo
*/
bool isAcent(char c)
{
    for(int i = 0;i<strlen((char*)accentate);i++)
        if((unsigned char)c == accentate[i])
            return true;
    return false;
}

/**
*    dato un carattere alfanumerico restituiste il suo valore secondo la tabella di associazione
*    caratteri valori in posizione pari per il calcolo del CIN
*    Params:
*       @param char c : input : cartattere di cui bisogna trovare valore nella tabella
*       @return int : valore numerico della lettera in posizione pari
*/
int valPari(char c)
{
  if(c <= '9')
    return c-48;
  else
    return c-65;
}

/**
*    dato un carattere alfanumerico
*    restituiste il suo valore
*    secondo la tabella di associazione
*    caratteri valori in posizione dispari
*    per il calcolo del CIN
*    Params:
*       @param char c : input : cartattere di cui bisogna trovare valore nella tabella
*       @return int : valore numerico della lettera in posizione dispari
*/
int valDisp(char c)
{
  int val;
  switch(c)
  {
    case '0':
      val = 1;
    break;
    case '1':
      val = 0;
    break;
    case '2':
      val = 5;
    break;
    case '3':
      val = 7;
    break;
    case '4':
      val = 9;
    break;
    case '5':
      val = 13;
    break;
    case '6':
      val = 15;
    break;
    case '7':
      val = 17;
    break;
    case '8':
      val = 19;
    break;
    case '9':
      val = 21;
    break;
    case 'A':
      val = 1;
    break;
    case 'B':
      val = 0;
    break;
    case 'C':
      val = 5;
    break;
    case 'D':
      val = 7;
    break;
    case 'E':
      val = 9;
    break;
    case 'F':
      val = 13;
    break;
    case 'G':
      val = 15;
    break;
    case 'H':
      val = 17;
    break;
    case 'I':
      val = 19;
    break;
    case 'J':
      val = 21;
    break;
    case 'K':
      val = 2;
    break;
    case 'L':
      val = 4;
    break;
    case 'M':
      val = 18;
    break;
    case 'N':
      val = 20;
    break;
    case 'O':
      val = 11;
    break;
    case 'P':
      val = 3;
    break;
    case 'Q':
      val = 6;
    break;
    case 'R':
      val = 8;
    break;
    case 'S':
      val = 12;
    break;
    case 'T':
      val = 14;
    break;
    case 'U':
      val = 16;
    break;
    case 'V':
      val = 10;
    break;
    case 'W':
      val = 22;
    break;
    case 'X':
      val = 25;
    break;
    case 'Y':
      val = 24;
    break;
    case 'Z':
      val = 23;
    break;
  }
  return val;
}

/**
*    prende un carattere accentato e lo trasforma
*    nella sua forma normale
*    Params:
*       @param char arr[] : input/output : la stringa in cui si trova la lettara accentata
*       @param int index : input : indice di dove si trova dentro la stringa
*       @return bool : dice se la lettera selezionata e accentata o no
*/
bool AcenToChar(char arr[],int index)
{
    if(isAcent(arr[index]))
    {
        switch((unsigned char)arr[index])
        {
            case 133:
                arr[index] = 'a';
            break;
            case 138:
                arr[index] = 'e';
            break;
            case 161:
                arr[index] = 'i';
            break;
            case 149:
                arr[index] = 'o';
            break;
            case 151:
                arr[index] = 'u';
            break;
        }
        return true;
    }

    return false;
}

/**
*    dato un carattere controlla se � nell'array delle vocali
*    ovvero se il carattere e un carattere
*    Params:
*       @param char c : input : lettera da controllare per vedere se � una vocale
*       @return bool : dice se la lettera � una vocale
*/
bool isVocale(char c)
{
    for(int i = 0;i<strlen(vocali);i++)
        if(toupper(c) == vocali[i])
            return true;
    return false;
}

/**
*    data un lunghezza del codice lo creer�
*    mettendo prima le consonanti della stringa
*    finite prende le vocali se finiscono pure quelle
*    mette le X come "cuscinetto"
*    Params:
*       @param char str[] : input : stringa immessa di cui si vuole estrapolare le lettere per il CF
*       @param char codice[] : ouput : dove andranno messe le lettere estrapolate dalla stringa
*       @param int len : input : quante lettere mettere nel CF
*       @param int start : input : da dove parte a immetere lettere nel CF
*       @param bool nome = false : input : chiede se la stringa e un nome o cognome poich� cambier� il comportamento della funzione
*       @return void
*/
void insertCons(char str[],char codice[],int len,int start,bool nome)
{
    int nItera = 0,i = 0,letTrov = 0;
    bool skip = false;
    toUpStr(str);

    while(letTrov < len)
    {
        if(i == strlen(str))
        {
            i = 0;
            nItera++;
        }
        switch(nItera)
        {
            case 0:
            {
                if( (str[i]>='A'&&str[i]<='Z') && !isVocale(str[i]) )
                {
                    if(letTrov == 1 && nome == true && skip == false)
                    {
                        int trov = 0;

                        for(int j = i+1;j<strlen(str) && trov < 2;j++)
                            if( (str[j]>='A'&&str[j]<='Z') && !isVocale(str[j]) )
                                trov++;

                        if(trov >= 2)
                            skip = true;
                    }
                    else
                        skip = false;

                    if(skip == false)
                    {
                        codice[start+letTrov] = str[i];
                        letTrov++;
                    }
                }
                break;
            }
            case 1:
            {
                if( (str[i]>='A'&&str[i]<='Z') && isVocale(str[i]) )
                {
                    codice[start+letTrov] = str[i];
                    letTrov++;
                }
                break;
            }
            case 2:
            {
                codice[start+letTrov] = 'X';
                letTrov++;
                break;
            }
        }
        i++;
    }
    codice[start+letTrov] = 0;
}

/**
*    data una stringa controlla che tutti
*    i caratteri siano contemplati per un cognome.
*    controlla se il nuemro di caratteri consentiti
*    e minore della lunghezza della stringa se si
*    ritorna lo stato della stringa invalida
*    Params:
*       @param char cognome[] : input : cognome da controllare
*       @return bool : dice se il cognome e valido o meno
*/
bool checkCognome(char cognome[])
{
    int checked = 0;
	while(
           cognome[checked] &&
           ( (toupper(cognome[checked])>='A' && toupper(cognome[checked])<='Z') || cognome[checked] == ' ' || (cognome[checked] == '\'' && checked !=0) || AcenToChar(cognome,checked) )
         )
		checked++;
    if(checked < strlen(cognome))
    {
        printf("non e un cognome corretto rimetti\n\n");
        return true;
    }
    else
        return false;
}

/**
*    chiede il cognome dell'utente e lo controlla, chiede finche non � valido
*    Params:
*       @param char cognome[] : output : dove verra messo il cognome chiesto
*       @return void
*/
void getCognome(char cognome[])
{
    bool err = false;
    do
    {
        printf("metti il tuo cognome: ");
        gets(cognome);
        err = checkCognome(cognome);
    }
    while(err);

}

/**
*    data una stringa controlla che tutti
*    i caratteri siano contemplati per un nome.
*    controlla se il nuemro di caratteri consentiti
*    e minore della lunghezza della stringa se si
*    ritorna lo stato della stringa invalida
*    Params:
*       @param char nome[] : input : nome da controllare
*       @return bool : dice se il nome e valido o meno
*/
bool checkNome(char nome[])
{
    int checked = 0;
	while( nome[checked] && ((toupper(nome[checked])>='A' && toupper(nome[checked])<='Z')))
		checked++;
    if(checked < strlen(nome))
    {
        printf("non e un nome corretto rimetti\n\n");
        return true;
    }
    else
        return false;
}

/**
*    chiede il nome dell'utente e lo controlla, chiede finche non � valido
*    Params:
*       @param char nome[] : output : dove verra messo il nome chiesto
*       @return void
*/
void getNome(char nome[])
{
    bool err = false;
    do
    {
        printf("metti il tuo nome: ");
        gets(nome);
        err = checkNome(nome);
    }
    while(err);
}

/**
*    chiede quando e nato l'utente
*    in formato gg/mm/aaaa
*    in un array [gg, mm, aaaa]
*    Params:
*       @param int data[] : output : dove verra messo la data chiesta
*       @return void
*/
void getDataNasci(int data[])
{
    int gg,mm,aaaa;
	  bool rep=false;
    do
    {
        do
        {
            do
            {
                printf("immettere data:\n");
                printf("    inserisci il giorno  --> ");
                scanf("%d",&gg);
            }
            while(gg<1||gg>31);
            do
            {
                printf("    inserisci il mese    --> ");
                scanf("%d",&mm);
            }
            while(mm<1||mm>12);
        }
        while((mm==4||mm==6||mm==9||mm==11)&&gg==31);

        do
        {
            printf("    inserisci l'anno     --> ");
            scanf("%d",&aaaa);
        }
        while(aaaa<1);

        if(mm==2&&gg>28)
            if((aaaa%4==0&&aaaa<=1917)||(((aaaa%4==0&&aaaa%100!=0)||aaaa%400==0)&&aaaa>1917))
                if(gg==29)
                    rep=false;
                else
                    rep=true;
            else
                rep=true;
        else
            rep=false;

    }
    while(rep==true);

    data[0] = gg;
    data[1] = mm;
    data[2] = aaaa;

}

/**
*    chiede il sesso del utente per sapere se aggiungere
*    40 al giorno di nascita o no
*    Params:
*       @param bool * femmina : output : dove verra messo il sesso chiesto
*       @return void
*/
void getGender(bool *femmina)
{
    char scelta;
    do
    {
        printf("inserisci il tuo sesso (M o F): ");
        scanf(" %c",&scelta);
        fflush(stdin);
    }while(toupper(scelta) != 'M' && toupper(scelta) != 'F');
    if(toupper(scelta) == 'F')
      *femmina = true;
    else
      *femmina = false;
}

/**
*    prende la data di nascita dell'utente
*    e il sesso per cacolare il codice da mettere
*    nell'array del codice fiscale
*    Params:
*       @param int data[] : input : date che serviranno per mettere altre cifre nel CF
*       @param char codice[] : output : dove verranno messe le cifre della data di nascita
*       @param bool femmina : input : dice se femminna o meno
*       @return void
*/
void insertData(int data[],char codice[], bool femmina)
{
    codice[6] = (data[2] % 100 / 10) + '0';
    codice[7] = data[2] % 10 + '0';

    if(data[1] < 6)
        codice[8] = data[1] + 'A';
    else
      switch(data[1])
        {
            case 6:
                codice[8] = 'H';
            break;
            case 7:
                codice[8] = 'L';
            break;
            case 8:
                codice[8] = 'M';
            break;
            case 9:
                codice[8] = 'P';
            break;
            case 10:
                codice[8] = 'R';
            break;
            case 11:
                codice[8] = 'S';
            break;
            case 12:
                codice[8] = 'T';
            break;
        }

    if(femmina == true)
        data[0] += 40;

    codice[9] = data[0] / 10 + '0';
    codice[10] = data[0] % 10 + '0';

    codice[11] = 0;
}

/**
*    prende in input una stringa che sarebbe
*    il codice della nazzione o provincia di provenienza
*    dentro a un array
*    Params:
*       @param char luogoNasci[] : output : dove merttera il luogo di nascita una volta chiesto
*       @return void
*/
void getluogoNasci(char luogoNasci[])
{
  printf("inserisci nome luogo di nascita: ");
  gets(luogoNasci);
  for(int i = 0;i<strlen(luogoNasci);i++)
    luogoNasci[i] = toupper(luogoNasci[i]);
}

/**
*    prende un nome di un comune e lo cerca in una lista comune/codice
*    dando come risultato il codice associato al nome incollandolo
*    all'array del codice fiscale
*    Params:
*       @param char * nome : input : nome del comune
*       @param char * codice : output : array del CF
*       @return int : status code
*/
int getCodiceByNome(char * nome, char * codice)
{
    toUpStr(nome);

    system("clear");
    FILE * f;
    char str[MAX_STR_LEN], str1[MAX_STR_LEN];
    int virg = MAX_STR_LEN, posvir = MAX_STR_LEN;
    bool exit = false, start = false;

    f = fopen("province.csv","r");

    if(f == NULL)
        return ERR;

    while(!feof(f) && !exit)
    {
        int i,j;
        fgets(str,MAX_STR_LEN,f);
        if(toupper(str[0]) == nome[0])
        {
            for(i=0;str[i]!=',';i++)
            {
                str[i] = toupper(str[i]);
                str1[i]=str[i];
            }

            str1[i]=0;

            if(strcmp(str1,nome) == 0)
            {

                for(int j=0;j<4;j++)
                {
                    i++;
                    str1[j]=str[i];

                }
                str1[4]=0;
                strcat(codice,str1);
                exit = true;
            }
            start = true;
        }
        else if(start == true)
            exit = true;
    }

    fclose (f);

    return OK;
}

/**
*    inserisce dentro l'array del codice fiscale
*    la stringha che contiene il codice del comuno o
*    nazzione di provenienza
*    Params:
*       @param char luogoNascita[] : input : nome del comune
*       @param char codice[] : output : codice fiscale
*       @return void
*/
void insertLuogoNasci(char luogoNascita[],char codice[])
{
    getCodiceByNome(luogoNascita,codice);
}

/**
*    calcola e inserisce dentro l'array del codice fiscale
*    il CIN nelll'ultiuma posizione
*    la stringha che contiene il codice del comuno o
*    nazzione di provenienza
*    Params:
*       @param char codice[] : output : codice fiscale
*       @return void
*/
void insertCIN(char codice[])
{
  int cin = 0,calc;
  for(int i = 0;i<15;i++)
  {
    if((i+1)%2 == 0)
      calc = valPari(codice[i]);
    else
      calc = valDisp(codice[i]);

    cin += calc;
  }

  codice[15] = (cin%26) + 65;
  codice[16] = 0;
}


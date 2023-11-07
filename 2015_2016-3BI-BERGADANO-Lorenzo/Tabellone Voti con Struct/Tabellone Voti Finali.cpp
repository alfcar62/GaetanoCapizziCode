#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio2.h>
#include<windows.h>
/*
Progettare e realizzare l'algoritmo che permetta di gestire
il "Tabellone dei Voti" degli alunni della 3BInformatica, e precisamente:
1.	caricare il Tabellone con le informazioni di ogni Alunno, cioè:
    Cognome, Nome, Voti Finali delle materie di studio;
2.	ordinare il Tabellone dei Voti, in ordine alfabetico, con il metodo del Bubble Sort;
3.	visualizzare il contenuto del Tabellone.
*/
int main()                    // V 1.01
{
 int const NA=33, NV=11, LS=21;
 struct alunno
  {
   char co[LS], no[LS]; // Cognome, Nome
   int vf[NV];         // Voti Finali
   int media;
  };
 alunno Tabellone[NA], comodo;
 char Materie[NV][LS]={"Religione\0", "Italiano\0", "Storia\0", "Lingua Inglese\0", "Matematica\0", "Informatica\0", "Tecn.Prog.Sist.Inf.\0", "Sistemi Automatici\0", "Telecomunicazioni\0", "Educazione Fisica\0", "Condotta\0"};
 int scelta;    // opzione scelta del menù
 int na;        // numero effettivo degli alunni
 int it;        // indice per le scansioni del Tabellone
 int iv;        // indice per la scansione del vettore Voti Finali
 int j;         // indice per la gestione delle stringhe
 int voto;      // voto finale singola materia
 int c;         // valore di ritorno dal confronto tra 2 stringhe
 int caricato;  // variabile di stato del Tabellone: 0 --> non caricato
                //                                   1 --> caricato
 int ordinato;  // variabile di stato del Tabellone: 0 --> non ordinato
                //                                   1 --> ordinato
 char risp;     // risposta per la gestione dell'uscita dal programma
 char s[LS];    // stringa di comodo per caricare cognome e nome di ogni alunno
 char S[LS];    // stringa di comodo per trasformare in maiuscolo
 int nc;        // numero caratteri delle stringhe cognome o nome
 int errore;    // variabile di stato dell'input: 0 --> nessun errore
                //                                1 --> errore
 int scel;      // scelta tipo visualizzazione: 1-singolo alunno, 2-elenco completo
 scelta=na=it=iv=j=voto=c=caricato=ordinato=nc=errore=0;
 risp=' ';
 system("CLS");
 printf("\n *** Programma Gestione Tabellone Finale Alunni 3BInf ***\n");
 getch();
 do{ // Inizio ciclo di ripetizione del programma
       // Presentazione del Menù e input della scelta
       system("CLS");
       printf("\n\n ***** ---- Menu' di gestione ---- *****\n\n");
       printf("\n\n 1 - Caricamento Tabellone dei Voti");
       printf("\n\n 2 - Ordinamento Tabellone dei Voti");
       printf("\n\n 3 - Visualizzazione Tabellone dei Voti");
       printf("\n\n 4 - Uscita dal programma");
       do{                             // Input della scelta...
          printf("\n\n\n Scelta --> ");
          scanf("%d", &scelta);
       }while(scelta<1||scelta>4);     // ...con controllo
    switch(scelta)
    {
     case 1:
     {  //  Caricamento Tabellone dei Voti
      do{
         printf("\n Immetti il numero degli alunni della classe (Massimo %d):  ", NA);
         scanf("%d", &na);
      }while(na<1||na>NA);
      for(it=0;it<na;it++)
      {
       system("CLS");
       printf("\n  Immetti i dati del %d^ alunno\n", it+1);
       // Input Cognome
       do{
          fflush(stdin);
          for(j=0;j<LS;j++)
          {
           s[j]=' ';  // Pulizia stringhe
           S[j]=' ';
          }
          do{
             printf("\n          Cognome -->   ");
             gets(s);
             nc=strlen(s);
          }while(nc<=0||nc>LS-1);
          for(j=0;j<nc;j++)
          {
           S[j]=toupper(s[j]);  // Caratteri del cognome in maiuscolo
          }
          errore=0;
          for(j=0;j<nc&&errore==0;j++)
          {                         // Supponiamo che non ci siano vocali accentate
           if(!((S[j]>='A'&&S[j]<='Z')||S[j]==' '||S[j]=='\'')) 
           {
            errore=1;
            printf("\n CARATTERI NON VALIDI ! ! !  ");
            puts(s);
            getch();
           }
          }
         }while(errore==1);
       strcpy(Tabellone[it].co, S);
       Tabellone[it].co[nc]='\0';   // Inserimento Fine Stringa del Cognome
       // Input Nome
       do{
          fflush(stdin);
          for(j=0;j<LS;j++)
          {
           s[j]=' ';  // Pulizia stringhe
           S[j]=' ';
          }
          do{
             printf("\n             Nome -->   ");
             gets(s);
             nc=strlen(s);
          }while(nc<=0||nc>LS-1);
          for(j=0;j<nc;j++)
          {
           S[j]=toupper(s[j]);
          }
          errore=0;
          for(j=0;j<nc&&errore==0;j++)
          {
           if(!((S[j]>='A'&&S[j]<='Z')||S[j]==' '||S[j]=='\''))
           {
            errore=1;
            printf("\n CARATTERI NON VALIDI ! ! !  ");
            puts(s);
            getch();
           }
          }
         }while(errore==1);
       strcpy(Tabellone[it].no, S);
       Tabellone[it].no[nc]='\0';
       // Input Voti Finali
       printf("\n  Immissione dei voti delle %d materie\n", NV);
       for(iv=0;iv<NV;iv++)
       {
        do{
           gotoxy(2,iv+10);
           printf("  %s -->   ", Materie[iv]);
           fflush(stdin);
           gotoxy(30,iv+10);
           scanf("%d", &voto);
        }while(voto<1||voto>10);
        Tabellone[it].vf[iv]=voto;
       }
      } // Fine ciclo for di caricamento del Tabellone dei Voti
      caricato=1;
      ordinato=0;
      system("CLS");
      printf("\n Termine caricamento dei dati dei %d alunni\n", na);
      getch();
     }
     break;       

     case 2:
     {  //  Ordinamento Tabellone dei Voti
      if(caricato==0)
      {
       system("CLS");
       printf("\n\n Ordinamento Tabellone impossibile\n\n Caricamento dati non effettuato ! ! !\n");
       getch();
      }
      else
      {
       system("CLS");
       printf("\n\n Ordinamento Tabellone dei Voti in corso...\n");
       getch();
       int s;
       for(s=0,ordinato=0;s<na-1&&ordinato==0;s++)
       {
        for(it=0,ordinato=1;it<(na-s-1);it++)
        {
         c=strcmp(Tabellone[it].co,Tabellone[it+1].co);
         if(c>0)
         {                          // Scambio
          comodo=Tabellone[it];
/*
          strcpy(comodo.co,Tabellone[it].co);
          strcpy(comodo.no,Tabellone[it].no);
          for(iv=0;iv<NV;iv++)
          {
           comodo.vf[iv]=Tabellone[it].vf[iv];
          }
*/
          Tabellone[it]=Tabellone[it+1];
/*
          strcpy(Tabellone[it].co,Tabellone[it+1].co);
          strcpy(Tabellone[it].no,Tabellone[it+1].no);
          for(iv=0;iv<NV;iv++)
          {
           Tabellone[it].vf[iv]=Tabellone[it+1].vf[iv];
          }
*/
          Tabellone[it+1]=comodo;
/*
          strcpy(Tabellone[i+1].co,comodo.co);
          strcpy(Tabellone[i+1].no,comodo.no);
          for(iv=0;iv<NV;iv++)
          {
           Tabellone[it+1].vf[iv]=comodo.vf[iv];
          }
*/
          ordinato=0;
         }
        }
       }
       ordinato=1;
       printf("\n\n ...ordinamento terminato\n");
       getch();
      }
     }
     break;       

     case 3:
     {  //  Visualizzazione Tabellone dei Voti
      if(caricato==0)
      {
       system("CLS");
       printf("\n\n Visualizzazione Tabellone impossibile\n\n Caricamento dati non effettuato ! ! !\n");
       getch();
      }
      else
      {
       if(ordinato==0)
       {
        system("CLS");
        printf("\n Tabellone dei Voti  NON Ordinato (%d alunni)\n", na);
        getch();
       }
       else
       {
        system("CLS");
        printf("\n Tabellone dei Voti  Ordinato (%d alunni)\n", na);
        getch();
       }

       //system("CLS");
       printf("\n\n 1 - Visualizzazione per singolo alunno");
       printf("\n\n 2 - Visualizzazione elenco completo");

       do{
          printf("\n\n\n     Scegli -->  ");
          scanf("%d", &scel);
       }while(scel<1||scel>2);
       
       switch(scel)
       {
       case 1:
       {
       for(it=0;it<na;it++)
       {
        system("CLS");
        gotoxy(2,3);
        printf(" %d^  Alunno  -------------------------\n", it+1);
        gotoxy(2,5);
        printf("             Cognome:  ", it+1);
        puts(Tabellone[it].co);
        gotoxy(2,6);
        printf("                Nome:  ", it+1);
        puts(Tabellone[it].no);
        for(iv=0;iv<NV;iv++)
        {
         gotoxy(2,8+iv);
         printf("     %s:  ", Materie[iv]);
         gotoxy(30,8+iv);
/*         nc=strlen(Materie[iv]);
         c=LS-nc;
         for(j=1;j<=c;j++) printf(" "); */
         printf("%2d", Tabellone[it].vf[iv]);
        }
        gotoxy(2,8+iv+1);
        printf(" -------------------------------------\n");
        getch();
       }
       } break;
       case 2:
       {
        system("CLS");
        gotoxy(2,2);
        printf(" Nr  Cognome      Nome       Rel Ita Sto Ing Mat Inf Tps Sis Tel EFi Cnd");
        gotoxy(2,3);
        printf("-------------------------------------------------------------------------");
       for(it=0;it<na;it++)
       {
        gotoxy(2,4+it);
        printf(" %2d  ", it+1);
        gotoxy(7,4+it);
        puts(Tabellone[it].co);
        gotoxy(20,4+it);
        puts(Tabellone[it].no);
        for(iv=0;iv<NV;iv++)
        {
         gotoxy(30+4*iv,4+it);
         printf(" %2d",Tabellone[it].vf[iv]);
        }
       }
       gotoxy(2,4+it);        
       printf("-------------------------------------------------------------------------\n");
       getch(); 
       }
       }
       system("CLS");
       printf("\n\n\n ------- Fine Visualizzazione -------\n");
       getch();
      }
     }
     break;       

     case 4:
     {  //  Gestione uscita dal programma
      do{                       // Domanda con input della risposta...
         system("CLS");
         printf("\n\n Sei sicuro? (s/n S/N) ");
         fflush(stdin);
         scanf("%c", &risp);
      }while(risp!='s'&&risp!='n'&&risp!='S'&&risp!='N');  // ...con controllo
      if(risp=='n'||risp=='N')  // Se non si conferma l'uscita dal
      {                         // programma nella variabile scelta
       scelta=0;                // si "forza" un valore che permetta
      }                         // di restare nel programma
     }
    } //    Fine switch
 }while(scelta!=4);
} // Fine main

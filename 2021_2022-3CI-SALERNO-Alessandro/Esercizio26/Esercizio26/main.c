/************************************************
CONSEGNA:
Scrivere un programma  in C language  che sia
in grado di disegnare nel piano e nello spazio
delle figure geometriche  su un piano
cartesiano (in 2 Dimensioni :x,y) 

WARNING:
Funzionamento verificato solo con l'ultima
versione del compilatore GNU (MinGW/GCC).

NOME:   Alessandro      COGNOME: Salerno
CLASSE: 3C Informatica  DATA:    03 Gennaio 2022
*************************************************/


#ifdef _WIN32
    // Verificata compatibilità totale con Windows 10 64 bit
    #define sysclear() system("cls")

    #define PLATFORM_XSCALE 2
    #define PLATFORM_YSCALE 1
    #define PLATFORM_SCALERATIO 2
#else
    // Verificata compatibilità **PARZIALE** con macOS Monterey, Ubuntu Linux 21.10 KDE Plasma e Manjaro KDE
    #define sysclear() system("clear")

    #define PLATFORM_XSCALE 4
    #define PLATFORM_YSCALE 2
    #define PLATFORM_SCALERATIO 2
#endif

// Toggle di asciiGL
// asciiGL è una libreria da me sviluppata per la grafica da Console
// Il programma la supporta, ma per completezza (E per garantire il funzionamento), è possibile disattivarla
// Per attivarla, basta lasciare la seguente riga, per disattivarla basta rimuoverla o commentarla
// asciiGL offre funzionalità aggiuntive ed ottimizzazioni, dunque, bisogna aspettarsi una riduzione della qualità e della velocità in caso di disattivazione
// Per maggiori informazioni: https://github.com/tzyvoski/asciiGL
#define USE_LIBRARY

// Inclusione header standard
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


// Costanti
#define MENU_MIN 1
#define MENU_MAX 6
#define PI       3.142857

#define SCALEX (1.0f / xscale)
#define SCALEY (1.0f / yscale)

#define INCX(x) x += (1.0f / xscale)
#define INCY(y) y += (1.0f / yscale)

#define DECX(x) x -= (1.0f / xscale)
#define DECY(y) y -= (1.0f / yscale)

// Prototipi delle funzioni
// Sono inclusi solo quelli per funzioni disponibili in tutto il programma
// Mentre sono esclusi simboli il cui significato varia in base all'implementazione scelta

/*********************************************************************************************************
TIPO             NOME                           ARGOMENTI
*********************************************************************************************************/
void             Initialize                     ();
void             Refresh                        ();
void             SetAbsolutePlaneCell           (int x, int y, char chr);
void             SetWindowTitle                 (const char* title);
void             GotoXY                         (int x, int y);
void             UniversalSetCellSolidColor     (unsigned short x, unsigned short y, unsigned int color);
void             UniversalClear                 ();
unsigned int     TranslateX                     (double x);
unsigned int     TranslateY                     (double y);
void             SetPlaneCell                   (double x, double y, char chr);
void             Axis                           ();
void             Update                         ();
void             DrawDot                        (double x, double y);
void             Dot                            ();
void             DrawSegment                    (double x0, double y0, double x1, double y1);
void             DrawLine                       (double x0, double y0, double x1, double y1);
void             Segment                        ();
void             Line                           ();
void             Rect                           ();
void             DrawCircle                     (double x, double y, unsigned short radius);
void             Circle                         ();
void             Square                         ();
void             DrawRectangle                  (double x, double y, double width, double height);
unsigned int     UnsignedInput                  ();
int              MenuInput                      ();
int              main                           ();

// Centro degli assi
short centerX,
      centerY;

// Scala X ed Y
unsigned short xscale     = PLATFORM_XSCALE,
               yscale     = PLATFORM_YSCALE,
               scaleratio = PLATFORM_SCALERATIO;

// Offset centro degli assi
short xoff, yoff;


#ifdef USE_LIBRARY
    #warning "La libreria asciiGL e' ancora in beta, potrebbero, dunque, verificarsi chiusure improvvise, errori di segmentazione ecc"

    #define FGCOLOR   Black
    #define BGCOLOR   White
    
    #ifdef _WIN32
        #define KEY_ESC   0x1B
        #define KEY_END   0x23
        #define KEY_DEL   0x2E
        #define KEY_ENTER 0x0D
        #define KEY_W     0x57
        #define KEY_A     0x41
        #define KEY_S     0x53
        #define KEY_D     0x44
        #define KEY_I     0x49
        #define KEY_J     0x4A
        #define KEY_K     0x4B
        #define KEY_L     0x4C
        #define KEY_UP    0x26
        #define KEY_DOWN  0x28
        #define KEY_LEFT  0x25
        #define KEY_RIGHT 0x27
    #else
        #define KEY_ESC   0x1B
        #define KEY_END   0xCF
        #define KEY_DEL   0xCF
        #define KEY_ENTER 13
        #define KEY_W     119
        #define KEY_A     97
        #define KEY_S     115
        #define KEY_D     100
        #define KEY_I     105
        #define KEY_J     106
        #define KEY_K     107
        #define KEY_L     108
        #define KEY_UP    0x41
        #define KEY_DOWN  0x42
        #define KEY_LEFT  0x44
        #define KEY_RIGHT 0x43
    #endif

    // Se viene definito EXPERIMENTAL_FEATURES, asciiGL esporrà anche le funzionalità sperimentali, come l'input da tastiera asincrono
    // Queste funzionalità sono sperimentali in quanto disponibili solo su una piattaforma (MS Windows) e non su tutte
    // Future versioni della libreria implementeranno pieno supporto per le funzionalità sperimentali anche su Linux e macOS
     #define EXPERIMENTAL_FEATURES

    // asciiGL presenta anche un toggle per le sue ottimizzazioni
    // Per disattivare le ottimizzazioni, basta "scommentare" la seguente riga
    // ATTENZIONE: Disattivare le ottimizzazioni di refresh riduce visibilmente le prestazioni, soprattutto nel Prompt dei Comandi di Windows
    // #define NO_REFRESH_OPTIMIZATION

    // Inclusione header per asciiGL
    #include "asciiGl/src/asciigl.h"
    #include "asciiGl/atk/utils.h"

    // asciiGL si basa su dei framebuffer dinamicamente allocati
    // Qui il puntatore al framebuffer è salvato globalmente per semplicità
    // Il tipo framebuffer è definito come un puntatore allo struct _Framebuffer
    framebuffer buffer = NULL;

    void Initialize()
    {
        // Se si sta compilando su Microsoft WIndows, è necessario eseguire il comando "" all'avvio del programma
        // Dunque viene integrato in questa procedura
        #ifdef _WIN32
            system("");
        #endif

         // Viene creato un nuovo framebuffer asciiGL ed il puntatore viene assegnato alla variabile globale
        // La procedura `atkSetup` dell'asciiGL Toolkit crea un framebuffer di dimensioni pari a quelle della finestra
        framebuffer initBuffer = atkSetup();
                    buffer     = initBuffer;
    }

    void InitializeScreen()
    {
        // Se esiste già un contesto asciiGL, viene semplicemente reimpostato come principale
        if (buffer == NULL)
            return;
    
        aglEndContext();
        aglDeleteFramebuffer(buffer);

        framebuffer newBuffer = atkSetup();
        buffer = newBuffer;
    
        aglInitContext(buffer);
        atkInit(buffer);
    }

    void Refresh()
    {
        // Se non esiste un contesto asciiGL, la procedura ritorna per evitare danni
        if (buffer == NULL)
            return;

        #ifdef EXPERIMENTAL_FEATURES
            // Premendo i tasti IJKL è possibile muovere il piano
            // Mentre premendo i tasti DEL o END, è possibile terminare il programma
            // Questo funziona solo se sono attivate le funzionalità sperimentali
            if (atkGetKeyState(KEY_END) || atkGetKeyState(KEY_DEL)) atkEnd(buffer);
            if (atkGetKeyState(KEY_I)) yoff += 1;
            if (atkGetKeyState(KEY_J)) xoff += 1;
            if (atkGetKeyState(KEY_L)) xoff -= 1;
            if (atkGetKeyState(KEY_K)) yoff -= 1;

            if (atkGetKeyState(KEY_UP))
            {
                xscale *= 2;
                atkWaitMills(200);
            }

            if (atkGetKeyState(KEY_DOWN))
            {
                if (xscale >= 2) xscale /= 2;
                atkWaitMills(200);
            }

            if (atkGetKeyState(KEY_ENTER))
            {
                xscale = PLATFORM_XSCALE;
                xoff = 0;
                yoff = 0;
            }

            // Si assicura che il rapporto sia sempre mantenuto
            yscale = xscale / scaleratio;
        #endif

        // Pulisce il framebuffer
        aglClear(buffer, AGL_EMPTY_CHAR, BGCOLOR, BGCOLOR);

        // Ridimensinoe automaticamente il framebuffer se la finestra è ridimensionata
        atkAutoResize(buffer);
    }

    void EndDraw()
    {
        // Se non esiste un contesto asciiGL, la procedura ritorna per evitare danni
        if (buffer == NULL)
            return;

        // La procedura `aglSwapBuffers` stampa il contenuto del framebuffer sulla console
        // Se le ottimizzazioni sono attive, questa procedura ristampa solo le celle che sono cambiate, mentre ignora quelle uguali
        // In questo modo è possibile ridurre di molto i tempi di rendering
        aglSwapBuffers(buffer);
        atkWaitMills(16);
    }

    unsigned int GetWidth()
    {
        // Lo struct `_Framebuffer` contiene un membro `width` il cui valore equivale alla larghezza della fienstra
        return buffer->width;
    }

    unsigned int GetHeight()
    {
        // Lo struct `_Framebuffer` contiene un membro `height` il cui valore equivale all'altezza della fienstra
        return buffer->height;
    }

    void SetAbsolutePlaneCell(int x, int y, char chr)
    {
        // Se la x o la y specificate sono invalide, la procedura ritorna in modo da evitare danni grafici
        if (x < 0 || x >= GetWidth() || y < 0 || y >= GetHeight())
            return;

        // La procedura `aglSetCell` permette di settare una cella di un framebuffer
        // Gli effetti di questa procedura non sono immediatamente visibili, in quanto è prima necessario disegnare il framebuffer sulla console
        aglSetCell(buffer, x, y, chr, FGCOLOR, BGCOLOR);
    }

    void Exit()
    {
        // Se non esiste un contesto asciiGL, la procedura ritorna per evitare danni
        if (buffer == NULL)
            return;

        // La procedura `atkEnd` dell'asciiGL TOolkit gestisce le operazioni di terminazione del contesto asciiGL
        atkEnd(buffer);
    }

    void SetWindowTitle(const char* title)
    {
        // La procedura `atkSetWindowTitle` dell'asciiGL Toolkit permette di impostare il titolo della finestra della console
        atkSetWindowTitle(title);
    }

    void GotoXY(int x, int y)
    {
        // La procedura `consoleMoveCursor` di asciiGL utilizza una ANSI Escape Sequence per spostare il curosre
        consoleMoveCursor(x, y);
    }

    void EndContext()
    {
        // Se esiste un contesto asciiGL, viene terminato
        if (buffer != NULL)
            aglEndContext();
    }
#else
    #warning "Disabilitare asciiGL potrebbe comportare perdite di qualita', funzionalità e prestazioni"

    #define FGCOLOR  White
    #define BGCOLOR  Black

    #ifdef _WIN32
        #include "windows.h"
    #endif

    #define EndDraw() break;
    #define InitializeScreen()
    #define Exit() while (1) { }
    #define GetWidth() 80
    #define GetHeight() 24
    #define EndContext() break;

    typedef unsigned char color_t;

    enum
    {
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        LightGray,
        Gray,
        LightRed,
        LightGreen,
        LightYellow,
        LightBlue,
        LightMagenta,
        LightCyan,
        White
    };

    void textcolor(color_t fgcolor, color_t bgcolor)
    {
        printf(
            // \003 indica una sequenza
            // 38 è colore testo
            // 48 è colore sfondo
            // 5 indica modalità a 256 colori (Profondità 8 bit)
            // %d è il colore
            "\033[38;5;%dm\033[48;5;%dm",
            fgcolor, bgcolor
        );
    }

    void Initialize()
    {
        system("");
    }

    void SetAbsolutePlaneCell(int x, int y, char chr)
    {
        if (x < 0 || x >= GetWidth() || y < 0 || y >= GetHeight())
            return;

        GotoXY(x, y);
        textcolor(FGCOLOR, BGCOLOR);
        printf("%c", chr);
    }

    void Refresh()
    {
        sysclear();

        int x, y;
        for (y = 0; y < GetHeight(); y++)
        {
            for (x = 0; x < GetWidth(); x++)
            {
                GotoXY(x, y);
                UniversalSetCellSolidColor(x, y, BGCOLOR);
            }
        }
    }

    void SetWindowTitle(const char* title)
    {
        #ifdef _WIN32
            SetConsoleTitle(title);
        #else
            printf("\033]0;%s\007", title);
        #endif
    }

    void GotoXY(int x, int y)
    {
        printf("\033[%d;%dH", y + 1, x + 1);
    }
#endif

// Le procedure marcate come `Universal` funzionano sia con che senza asciiGL
// Questa procedura permette di stampare una cella con un colore solido
void UniversalSetCellSolidColor(unsigned short x, unsigned short y, unsigned int color)
{
    // Si sposta sulla cella richiesta
    GotoXY(x, y);
    
    // Imposta il colore
    printf(
        "\033[38;5;%dm\033[48;5;%dm",
        color, color
    );

    // Stampa la cella colorata
    printf(" ");

    // Resetta il colore
    printf("\033[0m");
}

// Pulisce lo schermo impostando tutti i colori a default
void UniversalClear()
{
    sysclear();

    xoff = 0;
    yoff = 0;
}

// Le funzioni di tralsazione permettono di convertire un valore sul piano, in un valore assoluto sullo schermo
// La funzione di traslazione della X restituisce un valore intero positivo utile ad impostare una cella sullo schermo
// Il valore di X viene preso come un double e moltiplicato per la scala in quanto, nella console, una cella è più alta che larga
// Dunque, la funzione di traslazione vede ogni cella come un incremento di 1/xscale sulla X
// Il risultato non è perfetto (Il rapporto non è perfetto), ma è molto più accurato rispetto ad usare incrementi interi
unsigned int TranslateX(double x)
{
    return (x * xscale) + centerX;
}

// Le funzioni di tralsazione permettono di convertire un valore sul piano, in un valore assoluto sullo schermo
// La funzione di traslazione della Y restituisce un valore intero positivo utile ad impostare una cella sullo schermo
unsigned int TranslateY(double y)
{
    return centerY - (y * yscale);
}

// La procedura `SetPlaneCell` utilizza le funzioni di traslazione per impostare una cella sul piano cartesiano
void SetPlaneCell(double x, double y, char chr)
{
    unsigned int absx = TranslateX(x),
                 absy = TranslateY(y);

    SetAbsolutePlaneCell(absx, absy, chr);
}

// Disegna gli assi cartesiani
void Axis()
{
    unsigned int   width   = GetWidth(),
                   height  = GetHeight();

    unsigned short originX = width / 2 + xoff,
                   originY = height / 2 + yoff,
                   y       = 0,
                   x       = 0;

    // Disegna asse Y
    for (; y < height; y++)
        SetAbsolutePlaneCell(originX, y, '|');

    // Disegna asse X
    for (; x < width; x++)
        SetAbsolutePlaneCell(x, originY, '-');

    // Disegna l'origine 
    SetAbsolutePlaneCell(originX, originY, '+');    
    centerX = originX;
    centerY = originY;
}

// Pulisce lo schermo e disegna gli assi
void Update()
{
    Refresh();
    Axis();
}

// Disegna un punto
void DrawDot(double x, double y)
{
    while (true)
    {
        Update();

        #ifdef EXPERIMENTAL_FEATURES
            if (atkGetKeyState(KEY_ESC))
                break;
        #endif

        SetPlaneCell(x, y, '+'); 
        EndDraw();
    }
}

// Chiede all'utente input per disegnare un punto
void Dot()
{
    double x, y;
    
    printf("Inserire X del punto -> ");
    scanf("%lf", &x);

    printf("Inserire Y del punto -> ");
    scanf("%lf", &y);

    InitializeScreen();
    DrawDot(x, y);
}

// Disegna un segmento
void DrawSegment(double x0, double y0, double x1, double y1)
{
    // (y1 - y0) / (x1 - x0)
    float m = (float)(y1 - y0) / (x1 - x0);

    while (true)
    {
        Update();

        #ifdef EXPERIMENTAL_FEATURES
            if (atkGetKeyState(KEY_ESC))
                break;
        #endif

        double x;
        for (x = x0; x < x1; INCX(x))
        {
            // y - y0 = m(x - x0)
            int y = round(y0 + m * (x - x0));
            SetPlaneCell(x, y, '=');
        }

        GotoXY(0, 0);
        printf("Coefficiente angolare: %f\033[2;1H", m);
        printf("X Iniziale: %lf\033[3;1H", x0);
        printf("Y Iniziale: %lf\033[4;1H", y0);
        printf("X Finale: %lf\033[5;1H", x1);
        printf("Y Finale: %lf\033[6;1H", y1);
        printf("Lunghezza: %f", (float)(sqrt(pow(fabs(x1) - fabs(x0), 2) + pow(fabs(y1) - fabs(y0), 2))));

        EndDraw();
    }
}

// Disegna una retta infinita
void DrawLine(double x0, double y0, double x1, double y1)
{
    // (y1 - y0) / (x1 - x0)
    float m = (float) (y1 - y0) / (x1 - x0);

    while (true)
    {
        Update();

        #ifdef EXPERIMENTAL_FEATURES
            if (atkGetKeyState(KEY_ESC))
                break;
        #endif

        double x;
        if (centerX > 0)
        {
            for (x = -centerX; x < centerX; INCX(x))
            {
                // y - y0 = m(x - x0)
                double y = m * x;
                SetPlaneCell(x, y, '=');
            }
        }
        else
        {
            for (x = 0; x < GetWidth() - centerX; INCX(x))
            {
                // y - y0 = m(x - x0)
                double y = m * x;
                SetPlaneCell(x, y, '=');
            }
        }

        GotoXY(0, 0);
        printf("Coefficiente angolare: %f", m);

        EndDraw();
    }
}

// Chiede input all'utente per disegnare un segmento
void Segment()
{
    double x0, y0, x1, y1;

    printf("Inserire X0 -> ");
    scanf("%lf", &x0);

    printf("Inserire Y0 -> ");
    scanf("%lf", &y0);

    printf("Inserire X1 -> ");
    scanf("%lf", &x1);

    printf("Inserire Y1 -> ");
    scanf("%lf", &y1);

    InitializeScreen();
    DrawSegment(x0, y0, x1, y1);
}

// Chiede input all'utente per disegnare una retta infinita
void Line()
{
    double x0, y0, x1, y1;

    printf("Inserire X0 -> ");
    scanf("%lf", &x0);

    printf("Inserire Y0 -> ");
    scanf("%lf", &y0);

    printf("Inserire X1 -> ");
    scanf("%lf", &x1);

    printf("Inserire Y1 -> ");
    scanf("%lf", &y1);

    InitializeScreen();
    DrawLine(x0, y0, x1, y1);
}

// Disegna un rettangolo
void DrawRectangle(double x, double y, double width, double height)
{
    double startX = (double)(x - (double)(width) / 2),
           xp, yp;

    double startY = y + height / 2;

    while (true)
    {
        Update();

        #ifdef EXPERIMENTAL_FEATURES
            if (atkGetKeyState(KEY_ESC))
                break;
            
            if (atkGetKeyState(KEY_W))
                INCY(startY);

            if (atkGetKeyState(KEY_A))
                DECX(startX);
            
            if (atkGetKeyState(KEY_S))
                DECY(startY);

            if (atkGetKeyState(KEY_D))
                INCX(startX);
        #endif

        for (xp = startX; xp < startX + width; INCX(xp))
            SetPlaneCell(xp, startY, '-');

        for (xp = startX; xp < startX + width; INCX(xp))
            SetPlaneCell(xp, startY - height + SCALEY, '-');

        for (yp = startY; yp > startY - height; DECY(yp))
            SetPlaneCell(startX, yp, '|');

        for (yp = startY; yp > startY - height; DECY(yp))
            SetPlaneCell(startX + width - SCALEX, yp, '|');

        SetPlaneCell(startX, startY, '+');
        SetPlaneCell(startX + width - SCALEX, startY, '+');
        SetPlaneCell(startX, startY - height + SCALEY, '+');
        SetPlaneCell(startX + width - SCALEX, startY - height + SCALEY, '+');

        GotoXY(0, 0);
        printf("Larghezza: %lf\033[2;1H", width);
        printf("Altezza: %lf\033[3;1H", height);
        printf("Perimetro: %lf\033[4;1H", width * 2 + height * 2);
        printf("Area: %lf", width * height);

        EndDraw();
    }
}

// Chiede input all'utente per disegnare un rettangolo 
void Rect()
{
    double x, y, width, height;

    printf("Inserire X del centro -> ");
    scanf("%lf", &x);

    printf("Inserire Y del centro -> ");
    scanf("%lf", &y);

    printf("Inserire larghezza -> ");
    width = (double)(UnsignedInput());

    printf("Inserire altezza -> ");
    height = (double)(UnsignedInput());

    InitializeScreen();
    DrawRectangle(x, y, width, height);
}

// Disegna un cerchio
void DrawCircle(double x, double y, unsigned short radius)
{
    while (true)
    {
        Update();

        #if defined (USE_LIBRARY) && defined (EXPERIMENTAL_FEATURES)
            if (atkGetKeyState(KEY_ESC))
                break;
            
            if (atkGetKeyState(KEY_W))
                INCY(y);

            if (atkGetKeyState(KEY_A))
                DECX(x);
            
            if (atkGetKeyState(KEY_S))
                DECY(y);

            if (atkGetKeyState(KEY_D))
                INCX(x);
        #endif

        double xp, yp;
        for (yp = -radius; yp < radius; INCY(yp))
            for (xp = -radius; xp < radius; INCX(xp))
                if (xp * xp + yp * yp <= radius * radius)
                    SetPlaneCell(x + xp, y + yp, '*');

        GotoXY(0, 0);
        printf("Raggio: %hu\033[2;1H", radius);
        printf("Circonferenza: %f\033[3;1H", PI * 2 * radius);
        printf("Area: %f", PI * radius * radius);

        EndDraw();
    }
}

// Chiede input all'utente per disegnare un cerchio
void Circle()
{
    double x, y;
    unsigned short radius;

    printf("Inserire X -> ");
    scanf("%lf", &x);

    printf("Inserire Y -> ");
    scanf("%lf", &y);

    printf("Inserire Raggio -> ");
    radius = (unsigned short)(UnsignedInput());

    InitializeScreen();
    DrawCircle(x, y, radius);
}

// Chide input all'utente per disegnare un quadrato
void Square()
{
    double x, y;
    unsigned short side;

    printf("Inserire X del centro -> ");
    scanf("%lf", &x);

    printf("Inserire Y del centro -> ");
    scanf("%lf", &y);

    printf("Inserire il lato -> ");
    side = (unsigned short)(UnsignedInput());

    // Utilizza la funzione per i rettangoli in modo da risparmiare codice
    InitializeScreen();
    DrawRectangle(x, y, side, side);
}

// Questa procedura prende in input dalla tastiera un valore positivo
// Se il valore inserito non è positivo, richiede l'input
// ATTENZIONE: La procedura richiede un valore intero positivo, non nullo, dunque maggiore o uguale ad 1
unsigned int UnsignedInput()
{
    int input;

    do
    {
        scanf("%d", &input);
        fflush(stdin);

        if (input < 1)
            printf("Input non valido. Ripetere -> ");

        fflush(stdout);
    } while (input < 1);

    return input;
}

// Chieede input per il menù
int MenuInput()
{
    int option;

    do
    {
        printf("\nScelta -> ");
	    scanf("%d", &option);
    } while (option < MENU_MIN || option > MENU_MAX);

    return option;
}

int main()
{
    Initialize();

    // Imposta titolo della finestra della console
    SetWindowTitle("Esercizio 26: Piano cartesiano");

    while (1)
    {
        UniversalClear();

        // Disegna il logo del programma
        unsigned char i, j;
        for (i = 0; i < GetHeight() / 5 * 3; i++)
            for (j = 0; j < GetWidth() / 3 * 2; j++)
                UniversalSetCellSolidColor(
                    GetWidth() / 6 + j, i + 1,
                    i + j + 1
                );

        GotoXY(0, GetHeight() / 5 * 3 + 3);

        #ifdef EXPERIMENTAL_FEATURES
            printf("Controlli:\n");
            printf("WASD: Muovere le figure sul piano cartesiano\n");
            printf("IJKL: Muovere il piano cartesiano\n");
            printf("Frecce Su/Giu': Aumentare/Diminuire la scala del piano\n");
            printf("Enter: Reimposta posizione e scala del piano\n");
            printf("DEL/END: Termina il programma\n");
            printf("ESC: Torna a questo menu'\n\n");
        #endif

        // Stampa il menù
        printf("1. Disegna un punto date le coordinate sul piano cartesiano\n");
        printf("2. Disegna un segmento dati gli estremi\n");
        printf("3. Disegna una retta (Infinita) dati due punti\n");
        printf("4. Disegna un rettangolo dato il centro, la larghezza e l'altezza\n");
        printf("5. Disegna un quadrato dato il centro ed il lato\n");
        printf("6. Disegna un cerchio dato il centro ed il raggio\n");

        int choice = MenuInput();

        switch (choice)
        {
            case 1: { Dot();     } break;
            case 2: { Segment(); } break;
            case 3: { Line();    } break;
            case 4: { Rect();    } break;
            case 5: { Square();  } break;
            case 6: { Circle();  } break;
        }

        EndContext();
    }

    Exit();
}

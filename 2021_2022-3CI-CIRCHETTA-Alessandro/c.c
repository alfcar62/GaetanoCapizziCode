/* 
nome 
cognome
titolo
data
*/
#include <stdio.h>


int main()
{
    int a = 777,
        b = 123, 
        c, 
        d;
        
    char carattere1 = 'y', carattere2 = 'x';

    if (a > b)
    {
        d = a - b;   // se vero 
    } 
    else
    {
        d = a - c;  // se falso 
    }

    if (a > b)
        d = a - b;
    else
        d = a - c; /* senza graffe solo se si ha una sola riga di condizioni*/

    do
    {
        if (a > b)
            d = a - b;
        else
            d = a - c;  // if in più
    } while (a<c);
    
    while (c<b)
    {
        if (a > b)
            d = a - b;
        else
            d = a - c;  // if in più
    }
    
    for ( d = 69; a <= d; b++)
    {
         if (a > b)
            d = a - b;
        else
            d = a - c;  // if in più
    }

    return 0;
}
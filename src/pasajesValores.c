#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void CambiaVariableA(int ** b);

typedef struct Producto
{
   int precio;
   char * Nombre; // direccion
}Producto;

int main()
{
    Producto * a = (Producto *)malloc(sizeof(Producto));
    a->precio = 10;
    (a->Nombre) = (char *) malloc(sizeof(char)*10);
    printf("%d", a->precio); // que veo aquí *
    a = (Producto *)malloc(sizeof(Producto));

    return 0;
}


void CambiaVariableA(int ** b)
{
    *b = (int *) malloc(sizeof(int)); 
    *(*b) = 20;
    printf("%d", *(*b)); // que veo aquí <- 
}


 //Null - 20 - 10 



//10 - 20 - Null renference exception
//-   

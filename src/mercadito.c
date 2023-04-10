#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Producto
{
   int precio;
   char Nombre[20];
}Producto;


  char Nombres[3][20] =  {"Leche serenisima 1l", 
    "Frutilla 500 Gr", "Arándano 125 Gr"};

void MostrarProducto(Producto producto);
void ListadoDeProductos(Producto * producto);
void CargarProductos(Producto producto[]);


int main()
{
    srand(time(NULL));
    Producto Productos[20];

    CargarProductos(Productos);
    ListadoDeProductos(Productos);

}

void CargarProductos(Producto productos[])
{
    for (int i = 0; i < 20; i++)
    {
        productos[i].precio = 100 + rand() % 3000;
        int indice = rand() % 3; 
        strcpy(productos[i].Nombre,Nombres[indice]);   
    }
}


void MostrarProducto(Producto producto)
{           
     printf ("%s - %d", producto.Nombre, producto.precio);
}

void ListadoDeProductos(Producto * productos)
{
    for (int i = 0; i < 20; i++)
    {
        MostrarProducto(productos[i]);
        printf("\n\r");
    }
}
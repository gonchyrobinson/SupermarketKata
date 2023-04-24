#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CANTIDAD 30

typedef struct Producto
{
   int id;
   int precio;
   char Nombre[20];
}Producto;

typedef struct Nodo
{
    Producto * producto;
    Nodo * siguiente;
}Nodo;


  char Nombres[3][20] =  {"Leche serenisima 1l", 
    "Frutilla 500 Gr", "Arándano 125 Gr"};

// lista
Nodo * ListaVacia();


// uso de la listas
void MostrarProducto(Producto producto);
void ListadoDeProductos(Nodo * producto);
Producto * CargarProducto(char Nombre[],int precio, int id);
Nodo * CrearNodo(Producto * producto);
void InsertarNodo(Nodo ** Lista, Nodo * nuevoNodo);
Nodo * QuitarNodo(Nodo ** Lista, int id);
void EliminarNodo(Nodo * nodo);

int main()
{

    // MOVER NODO IMPLICA MOVER REFERENCIAS Y NO CLONAR EL NODO
    // QUITAR NODO DE UNA LISTA Y MOVER A OTRA NUEVA
    // REFENCIA Y VALOR - REPASAR     
    // FREE() COMO HACERLA CORRECTAMENTE 
    Nodo * nodoQuitado;
    srand(time(NULL));
    Nodo * ProductosALaVenta = ListaVacia();
    Nodo * ProductosDadosDeBaja = ListaVacia(); 
    
    Producto * producto_1 = CargarProducto(Nombres[rand() % 3],100 + rand() % 3000, 1);
    Producto * producto_2 = CargarProducto(Nombres[rand() % 3],100 + rand() % 3000, 2);
    Producto * producto_3 = CargarProducto(Nombres[rand() % 3],100 + rand() % 3000, 3);
    
    Nodo * Nodo = CrearNodo(producto_1);
    InsertarNodo(&ProductosALaVenta,CrearNodo(producto_1));
    InsertarNodo(&ProductosALaVenta,CrearNodo(producto_2));
    InsertarNodo(&ProductosALaVenta,CrearNodo(producto_3));
    printf("\n\r ---------------\n\r");
    ListadoDeProductos(ProductosALaVenta);
    nodoQuitado = QuitarNodo(&ProductosALaVenta, 1);
    printf("\n\r ---------------\n\r");
    ListadoDeProductos(ProductosALaVenta);
    printf("\n\r ---------------\n\r");
    EliminarNodo(nodoQuitado);
}

void EliminarNodo(Nodo * nodo)
{
    free(nodo->producto);
    free(nodo);
}

Nodo * QuitarNodo(Nodo ** Lista, int id)
{
    Nodo* Aux = *Lista;
    Nodo* AnteriorAux = *Lista;

   while (Aux != NULL && Aux->producto->id != id)
   {
        AnteriorAux = Aux;
        Aux = Aux->siguiente;
   }
   /// AUX -> null O AUX -> dir
    if(Aux)
    {
        // Primero
        if(Aux == *Lista)
        {
            *Lista = Aux->siguiente;
        } 
        else
        {
            AnteriorAux->siguiente = Aux->siguiente;   
        }
        // cualquier otro

        Aux->siguiente = NULL;
    }
    return Aux;
 
}


Producto * CargarProducto(char Nombre[],int precio, int id)
{
    Producto * producto = (Producto *) malloc(sizeof(Producto));
    producto->precio = precio;
    producto->id = id; 
    strcpy(producto->Nombre,Nombre);
    return producto;   
}

void InsertarNodo(Nodo ** Lista, Nodo * nuevoNodo)
{
    nuevoNodo->siguiente = *Lista; 
    *Lista = nuevoNodo; 
}


Nodo * CrearNodo(Producto * producto)
{
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->producto = producto;
    nodo->siguiente = NULL;
    return nodo;
}

Nodo * ListaVacia()
{
    return NULL;
}


void MostrarProducto(Producto producto)
{           
     printf ("%s - %d", producto.Nombre, producto.precio);
}

void ListadoDeProductos(Nodo * lista)
{
    for (; lista != NULL; lista = lista->siguiente)
    {
        MostrarProducto(*(lista->producto));
        printf("\n\r");
    }
}
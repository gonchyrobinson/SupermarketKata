#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>



char Nombre[3][20]={"Gonzalo", "Ricardo", "Tomas"};
char Categorias[3][20]={"Perfumeria","Limpieza","Perfumeria"};
struct Producto{
    char* Nombre;
    float precio;
    int stock;
    char* categorias;
};
typedef struct Producto item;
struct Tnodo
{
    item dato;
    struct Tnodo* siguiente;
};
typedef struct Tnodo Tnodo;
item CrearProducto();
void MostrarProducto(item prod);
Tnodo* CrearListaVacia();
bool EsListaVacia(Tnodo* cabecera);
Tnodo* CrearNodo(item dato);
void InsertarNodo(Tnodo** cabecera, Tnodo* nodo);
void MostrarLista(Tnodo* cabecera);
Tnodo* DesenlazarPrimerNodo(Tnodo** cabecera);
void EliminaPrimerElemento(Tnodo** cabecera);
void MoverNodo(Tnodo* seleccionado, Tnodo** lista, Tnodo** pendientes, Tnodo** realizadas, Tnodo** enProceso);



int main(){
    Tnodo* listaProductos=CrearListaVacia();
    Tnodo* nodoAInsertar;
    item prod;
    int cantProd=rand()%10+1;
    printf("Cantidad de produtctos cargados:  %d", cantProd);
    for (int i = 0; i < cantProd; i++)
    {
        prod=CrearProducto();
        nodoAInsertar=CrearNodo(prod);
        InsertarNodo(&listaProductos,nodoAInsertar);
    }
    MostrarLista(listaProductos);
}

void MostrarProducto(item prod){
    printf("\n========================MUESTRA PRODUCTO=============================\n");
    printf("Nombre: %s\nCategoria: %s\nPrecio: %.2f\nStock: %d",prod.Nombre,prod.categorias,prod.precio,prod.stock);
}
item CrearProducto(){
    item prod;
    prod.categorias=Categorias[rand()%3];
    prod.Nombre=Nombre[rand()%3];
    prod.stock=rand()%101;
    prod.precio=(float)0.5+(rand()%10000)*100/100;
    return(prod);
}

Tnodo* CrearListaVacia(){
    return(NULL);
}

bool EsListaVacia(Tnodo* cabecera){
    if(cabecera==NULL){
        return(true);
    }else
    {
        return(false);
    }
    
}

Tnodo* CrearNodo(item dato){
    Tnodo* nodo=(Tnodo*)malloc(sizeof(struct Tnodo*));
    nodo->dato=dato;
    nodo->siguiente=NULL;
    return(nodo);
}

void InsertarNodo(Tnodo** cabecera, Tnodo* nodo){
    nodo->siguiente=*cabecera;
    *cabecera=nodo;
}


void MostrarLista(Tnodo* cabecera){
    printf("\n==================================MUESTRA LISTA===================================\n");
    while (!EsListaVacia(cabecera))
    {
        printf("\n---------NODO -----------------\n");
        MostrarProducto(cabecera->dato);
        cabecera=cabecera->siguiente;
    }
    
}

Tnodo* DesenlazarPrimerNodo(Tnodo** cabecera){
    Tnodo* nodoSacado=NULL;
    if (!EsListaVacia(*cabecera))
    {
        nodoSacado=*cabecera;
        *cabecera=(*cabecera)->siguiente;
        nodoSacado->siguiente=NULL;
    }
    return(nodoSacado);
    
}


void EliminaPrimerElemento(Tnodo** cabecera){
    Tnodo* nodoAux;
    if(!EsListaVacia(*cabecera)){
        nodoAux=(*cabecera);
        (*cabecera)=(*cabecera)->siguiente;
        free(nodoAux);
    }else
    {
        printf("\nNo se puede eliminar un nodo de una lista vacia\n");
    }
    
}




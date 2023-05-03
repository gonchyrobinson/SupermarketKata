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
    int id;
};
typedef struct Producto item;
struct Tnodo
{
    item dato;
    struct Tnodo* siguiente;
};
typedef struct Tnodo Tnodo;
item CrearProducto(int i);
void MostrarProducto(item prod);
Tnodo* CrearListaVacia();
bool EsListaVacia(Tnodo* cabecera);
Tnodo* CrearNodo(item dato);
void InsertarNodo(Tnodo** cabecera, Tnodo* nodo);
void MostrarLista(Tnodo* cabecera);
Tnodo* DesenlazarPrimerNodo(Tnodo** cabecera);
void EliminaPrimerElemento(Tnodo** cabecera);
void MoverNodo(Tnodo* seleccionado, Tnodo** lista, Tnodo** pendientes, Tnodo** realizadas, Tnodo** enProceso);
bool PerteneceIdALaLista(Tnodo* lista, int id);
Tnodo* DesenlazarNodoPorId(Tnodo**lista, int id);
Tnodo* BuscarPorId(Tnodo* lista, int id);
void MenuDeBusqueda(Tnodo* lista);


int main(){
    Tnodo* listaProductos=CrearListaVacia();
    Tnodo* nodoAInsertar;
    item prod;
    int cantProd=20;
    printf("Cantidad de produtctos cargados:  %d", cantProd);
    for (int i = 0; i < cantProd; i++)
    {
        prod=CrearProducto(i);
        nodoAInsertar=CrearNodo(prod);
        InsertarNodo(&listaProductos,nodoAInsertar);
    }
    MostrarLista(listaProductos);
    MenuDeBusqueda(listaProductos);
    
    
    
}

void MostrarProducto(item prod){
    printf("\n========================MUESTRA PRODUCTO=============================\n");
    printf("Nombre: %s\nCategoria: %s\nPrecio: %.2f\nStock: %d",prod.Nombre,prod.categorias,prod.precio,prod.stock);
    printf("\nid: %d", prod.id);
}
item CrearProducto(int i){
    item prod;
    prod.categorias=Categorias[rand()%3];
    prod.Nombre=Nombre[rand()%3];
    prod.stock=rand()%101;
    prod.precio=(float)0.5+(rand()%10000)*100/100;
    prod.id=i;
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

Tnodo* DesenlazarNodoPorId(Tnodo**lista, int id){
    Tnodo* seleccionado=NULL;
    Tnodo* aux;
    Tnodo* anterior;
    if (!EsListaVacia(*lista))
    {
        if ((*lista)->dato.id==id)
        {
            seleccionado=*lista;
            *lista=(*lista)->siguiente;
            seleccionado->siguiente=NULL;
        }else
        {
            aux=*lista;
            while (!EsListaVacia(aux)  && aux->dato.id!=id)
            {
                anterior=aux;
                aux=aux->siguiente;
            }
            if (!EsListaVacia(aux))
            {
                seleccionado=aux;
                anterior->siguiente=aux->siguiente;
                seleccionado->siguiente=NULL;
            }
            
            
        }
        return(seleccionado);
        
        
    }
    
}

bool PerteneceIdALaLista(Tnodo* lista, int id){
    int pertenece=false;
    while (!EsListaVacia(lista) && lista->dato.id!=id)
    {
        lista=lista->siguiente;
    }
    if (!EsListaVacia(lista))
    {
        pertenece=true;
    }
    return(pertenece);
 
}

Tnodo* BuscarPorId(Tnodo* lista, int id){
    Tnodo* buscado=NULL;
    while (!EsListaVacia(lista) && lista->dato.id!=id)
    {
        lista=lista->siguiente;
    }
    if (!EsListaVacia(lista))
    {
        buscado=lista;
    }
    return(buscado);
    
    
}

void MenuDeBusqueda(Tnodo* lista){
    Tnodo* buscado;
    int id;
    printf("\n==================================BUSCAR NODO POR ID=================================\n");
    printf("Ingrese el id que busca:  ");
    scanf("%d", &id);
    buscado=BuscarPorId(lista,id);
    if (buscado)
    {
        MostrarProducto(buscado->dato);
    }
}
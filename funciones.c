#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int item;
struct Lista{
    item dato;
    struct Lista* siguiente;
};typedef struct Lista* Lista;

Lista CrearListaVacia();
bool EsListaVacia(Lista cabecera);
Lista CrearNodo(item dato);
void InsertarNodo(Lista* cabecera, Lista nodo);
void InsertarNodoFinal(Lista *cabecera, Lista nodo);
bool PerteneceNodoALaLista(Lista cabecera, Lista nodo);
void EliminaPrimerElemento(Lista* cabecera);
void EliminaUltimoElemento(Lista* cabecera);
Lista DesenlazarNodo(Lista* cabecerea, Lista dato);
void MostrarLista(Lista cabecera);
Lista DesenlazarPrimerNodo(Lista* cabecera);
int ContarLaCantidadDeNodos(Lista cabecera);

Lista CrearListaVacia(){
    return(NULL);
}
bool EsListaVacia(Lista cabecera){
    if(cabecera==NULL){
        return(true);
    }else
    {
        return(false);
    }
    
}

Lista CrearNodo(item dato){
    Lista nodo=(Lista)malloc(sizeof(struct Lista));
    nodo->dato=dato;
    nodo->siguiente=NULL;
}

void InsertarNodo(Lista* cabecera, Lista nodo){
    nodo->siguiente=*cabecera;
    *cabecera=nodo;
}

void InsertarNodoFinal(Lista *cabecera, Lista nodo){
    if(EsListaVacia(*cabecera)){
        nodo->siguiente=*cabecera;
        (*cabecera)=nodo;
    }else{
        Lista aux=*cabecera;
        while (!EsListaVacia((aux)->siguiente))
        {
            aux=(aux)->siguiente;

        }
        (aux)->siguiente=nodo;
    }
}

bool PerteneceNodoALaLista(Lista cabecera, Lista nodo){
    int pertenece=false;
    if(!EsListaVacia(cabecera)){
        while (!EsListaVacia(cabecera) && cabecera!=nodo)
        {
           cabecera=cabecera->siguiente;
        }
        if (cabecera==nodo)
        {
            pertenece=1;
        }
        
    }
    return(pertenece);
    
}

void EliminaPrimerElemento(Lista* cabecera){
    Lista nodoAux;
    if(!EsListaVacia(*cabecera)){
        nodoAux=(*cabecera);
        (*cabecera)=(*cabecera)->siguiente;
        free(nodoAux);
    }else
    {
        printf("\nNo se puede eliminar un nodo de una lista vacia\n");
    }
    
}

void EliminaUltimoElemento(Lista* cabecera){
    Lista anterior;
    Lista nodoAux;
    if (!EsListaVacia(*cabecera))
    {
        if (EsListaVacia((*cabecera)->siguiente))
        {
            nodoAux=*cabecera;
            *cabecera=(*cabecera)->siguiente;
            free(nodoAux);
        }else
        {
            nodoAux=*cabecera;
            while (!EsListaVacia((nodoAux)->siguiente))
            {
                anterior=nodoAux;
                nodoAux=(nodoAux)->siguiente;
            }
            free(nodoAux);
            anterior->siguiente=NULL;         
        }  
    }
    
}

Lista DesenlazarNodo(Lista* cabecera, Lista dato){
    Lista aux;
    Lista anterior;
    Lista nodoBuscado=NULL;
    if (!EsListaVacia(*cabecera))
    {
        if(*cabecera==dato)
        {
            nodoBuscado=*cabecera;
            *cabecera=(*cabecera)->siguiente;
            nodoBuscado->siguiente=NULL;
        }else{
            aux=*cabecera;
            while (!EsListaVacia(aux) && (aux==dato))
            {
                anterior=aux;
                aux=aux->siguiente;
            }
            if (!EsListaVacia(aux))
            {
                nodoBuscado=aux;
                anterior->siguiente=aux->siguiente;
                nodoBuscado->siguiente=NULL;
            }
        }
    }
    return(nodoBuscado); 
}
void MostrarLista(Lista cabecera){
    while (!EsListaVacia(cabecera))
    {
        printf("\n---------NODO -----------------");
        printf("%d", cabecera->dato);
    }
    
}
Lista DesenlazarPrimerNodo(Lista* cabecera){
    Lista nodoSacado=NULL;
    if (!EsListaVacia(*cabecera))
    {
        nodoSacado=*cabecera;
        *cabecera=(*cabecera)->siguiente;
        nodoSacado->siguiente=NULL;
    }
    return(nodoSacado);
    
}

int ContarLaCantidadDeNodos(Lista cabecera){
    int cantidad=0;
    while (!EsListaVacia(cabecera))
    {
        cantidad+=1;
        cabecera=cabecera->siguiente;
    }
    return(cantidad);
}
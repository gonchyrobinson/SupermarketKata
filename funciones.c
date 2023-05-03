#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int item;
typedef struct {
    item dato;
    Tnodo* siguiente;
} Tnodo;

Tnodo* CrearListaVacia();
bool EsListaVacia(Tnodo* cabecera);
Tnodo* CrearNodo(item dato);
void InsertarNodo(Tnodo** cabecera, Tnodo* nodo);
void InsertarNodoFinal(Tnodo* *cabecera, Tnodo* nodo);
bool PerteneceNodoALaLista(Tnodo* cabecera, Tnodo* nodo);
void EliminaPrimerElemento(Tnodo** cabecera);
void EliminaUltimoElemento(Tnodo** cabecera);
Tnodo* DesenlazarNodo(Tnodo** cabecerea, Tnodo* dato);
void MostrarLista(Tnodo* cabecera);
Tnodo* DesenlazarPrimerNodo(Tnodo** cabecera);
int ContarLaCantidadDeNodos(Tnodo* cabecera);

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
}

void InsertarNodo(Tnodo** cabecera, Tnodo* nodo){
    nodo->siguiente=*cabecera;
    *cabecera=nodo;
}

void InsertarNodoFinal(Tnodo* *cabecera, Tnodo* nodo){
    if(EsListaVacia(*cabecera)){
        nodo->siguiente=*cabecera;
        (*cabecera)=nodo;
    }else{
        Tnodo* aux=*cabecera;
        while (!EsListaVacia((aux)->siguiente))
        {
            aux=(aux)->siguiente;

        }
        (aux)->siguiente=nodo;
    }
}

bool PerteneceNodoALaLista(Tnodo* cabecera, Tnodo* nodo){
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

void EliminaUltimoElemento(Tnodo** cabecera){
    Tnodo* anterior;
    Tnodo* nodoAux;
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

Tnodo* DesenlazarNodo(Tnodo** cabecera, Tnodo* dato){
    Tnodo* aux;
    Tnodo* anterior;
    Tnodo* nodoBuscado=NULL;
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
void MostrarLista(Tnodo* cabecera){
    while (!EsListaVacia(cabecera))
    {
        printf("\n---------NODO -----------------");
        printf("%d", cabecera->dato);
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

int ContarLaCantidadDeNodos(Tnodo* cabecera){
    int cantidad=0;
    while (!EsListaVacia(cabecera))
    {
        cantidad+=1;
        cabecera=cabecera->siguiente;
    }
    return(cantidad);
}
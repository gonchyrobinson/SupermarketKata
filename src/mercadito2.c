#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define TAMA 10

typedef struct Producto
{
    float precio;
    char Nombre[50];
}Producto;
typedef struct nodo{
    Producto producto;
    struct nodo * siguiente;
}Lista;

Producto CargaEstructura();
void CargaVector(Producto vector[]);
void Mostrar(Producto vector[]);
void MuestraEstructura(Producto estructura);
Lista* CrearListaVacia();
Lista* CrearNodo();
Lista* InsertarNodo(Lista* lista);
bool EsListaVacia(Lista* lista);
Lista* LlenarLista(Lista* lista);
void MostrarLista(Lista* lista);

int main(){
    srand(time(NULL));
    int cantProductos;
    printf("\n-Ingrese la cantidad de productos que va a ingresar: ");
    scanf("%d", &cantProductos);
    Lista* listaEnlazada=CrearListaVacia();
    listaEnlazada=LlenarLista(listaEnlazada);
    

}

Producto CargaEstructura(){
    char Nombres[3][50]={"Leche UAT la Serenisima 1l","Frutillas En Cubetas 500 gr","Arandanos 125 gr"};
    Producto estructura;
    estructura.precio= 100 +rand()%3000;
    int indice=rand()%3;
    strcpy(estructura.Nombre,Nombres[indice]);
    return(estructura);
}
void CargaVector(Producto vector[]){
    for (int i=0;i<TAMA;i++){
        vector[i]=CargaEstructura();
    }
}
void Mostrar(Producto vector[]){
    for(int i=0;i<TAMA;i++){
        printf("\n==================================PRODUCTO %d=================================", i+1);
        MuestraEstructura(vector[i]);
        printf("\n\r");
    }
}
void MuestraEstructura(Producto estructura){
    printf("\nNOMBRE:  %s", estructura.Nombre);
    printf("\nPRECIO:  %.2f", estructura.precio);
}
Lista* CrearListaVacia(){
    return(NULL);
}
Lista* InsertarNodo(Lista* lista){
    CargaEstructura(nodo->producto);
    nodo->siguiente=lista;
    lista=nodo;
    return(lista);
}
bool EsListaVacia(Lista* lista){
    if(lista==NULL){
        return(true);
    }else{
        return(false);
    }
}
Lista* LlenarLista(Lista* lista){
    int otroNodo=1;
    while(otroNodo=1){
        printf("\n Ingrese 1 si desea agregar otro nodo, 0 si no desea: ");
        scanf("%d", &otroNodo);
        lista=InsertarNodo(lista);
    }
    return(lista);
}
void MostrarLista(Lista* lista){
    while(!EsListaVacia(lista))
}
Lista* CrearNodo(){
    Lista* nodo=(Lista*)malloc(sizeof(Lista*));
}
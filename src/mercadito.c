#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define TAMA 10

typedef struct Producto
{
    float precio;
    char Nombre[50];
}Producto;

Producto CargaEstructura();
void CargaVector(Producto vector[]);
void Mostrar(Producto vector[]);
void MuestraEstructura(Producto estructura);

int main(){
    srand(time(NULL));
    Producto vector[3];
    CargaVector(vector);
    Mostrar(vector);

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
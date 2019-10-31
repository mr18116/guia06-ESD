#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};


struct nodo *raiz = NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    printf("Lista completa.\n");
    while (reco!=NULL){
        printf("%i ",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

int extraer(){
    if(raiz!=NULL){
        int informacion = raiz->info;
        struct nodo *bor =raiz;
        raiz = raiz->sig;
        free(bor);
        return informacion;
    }else{
        return -1;
    }
}

void liberar(){
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco!=NULL){
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

void cantidad(){
    printf("\nMétodo para saber el tamaño de la pila\n");
    struct nodo *cantidad=raiz;
    if(cantidad==NULL){
        printf("La pila es vacia");
    }else{
        int contador=0;
        while (cantidad!=NULL){
            contador=contador+1;
            cantidad=cantidad->sig;
        }
        printf("El número de nodos es: %d \n",contador);
    }
}

int main(){
    insertar(10);
    insertar(40);
    insertar(3);
    cantidad();
    imprimir();

    printf("Extraemos de la pila: %i\n",extraer());
    imprimir();
    liberar();
    cantidad();
    return 0;
}

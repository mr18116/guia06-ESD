#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo *sig;
};
struct nodoInvertido{
    int info;
    struct nodoInvertido *sig;
};

struct nodo *raiz=NULL;
struct nodoInvertido *raizInvertida=NULL;

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
void insertarInvertido(int x){
    struct nodoInvertido *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raizInvertida==NULL){
        raizInvertida=nuevo;
        nuevo->sig=NULL;
    } else{
        nuevo->sig=raizInvertida;
        raizInvertida=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    printf("Pila original.\n");
    while (reco!=NULL){
        printf("%i\n",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}
void imprimirInvertido(){
    struct nodoInvertido *reco=raizInvertida;
    printf("Pila invertida.\n");
    while (reco!=NULL){
        printf("%i\n",reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

int invertir(){
    if(raiz!=NULL){
        while (raiz!=NULL){
            struct nodo *bor=raiz;
            insertarInvertido(bor->info);
            raiz=raiz->sig;
            free(bor);
        }
    } else{
        return -1;
    }
}

int main() {
    insertar(33);
    insertar(46);
    insertar(86);
    imprimir();
    invertir();
    imprimirInvertido();
    return 0;
}
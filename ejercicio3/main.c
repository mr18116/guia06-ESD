#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int info;
    struct nodo *sig;
};

struct nodo *raiz=NULL;

void insertar(int x){
    struct nodo *nuevo;
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
        nuevo->sig = raiz;
        raiz=nuevo;
    }
}

void imprimir(){
    struct nodo *reco=raiz;
    if(reco!=NULL)
        printf("Elementos de la pila\n");
    while(reco!=NULL){
        printf("%i ", reco->info);
        reco=reco->sig;
    }
    printf("\n");
}

void reemplazar(struct nodo *pila, int viejo, int nuevo ){
    int bool = 0;
    if(pila != NULL){
        while(pila!=NULL){
            if(pila->info == viejo){
                pila->info = nuevo;
                printf("Se cambió el número %d por %d\n",viejo,nuevo);
                bool = 1;
                break;
            }
            pila = pila->sig;
        }
        if(bool==0){
            printf("No se encontro el numero %d en la pila\n",viejo);
        }

    }else{
        printf("La pila esta vacia");
    }
}

int main(){
    int viejo,nuevo;
    insertar(10);
    insertar(40);
    insertar(3);
    insertar(35);
    insertar(22);
    imprimir();
    printf("\nIngrese el numero que desea reemplazar en la pila:\n");
    scanf("%d", &viejo);
    printf("Ingrese el numero nuevo que desea cambiar:\n");
    scanf("%d", &nuevo);
    reemplazar(raiz,viejo, nuevo);
    imprimir();

    return 0;
}
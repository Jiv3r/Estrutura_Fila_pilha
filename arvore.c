#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;


void adicionarNo(No *raiz, int valor) {
    No *no = malloc(sizeof(No));
    no->valor = valor;
    if (raiz->valor > valor) {
        if(raiz->esq != NULL) {
            adicionarNo(raiz->esq, valor);
        } else {
            raiz->esq = no;
            //printf("Inseriu Esq: %d - %d \n ", valor, raiz->valor);    
        }
    }
    if (raiz->valor < valor) {
        if(raiz->dir != NULL) {
            adicionarNo(raiz->dir, valor);
        } else {
            raiz->dir = no;
            //printf("Inseriu Dir: %d - %d \n ", valor, raiz->valor);    
        }
    }
}

void exibirArvoreEmOrdem(No* raiz) {
    //printf("DEBUG: %d\n", raiz->valor);
    if(raiz->esq != NULL) {
        exibirArvoreEmOrdem(raiz->esq);
    }
    printf("Valor do Nó: %d\n", raiz->valor);
    if(raiz->dir != NULL) {
        exibirArvoreEmOrdem(raiz->dir);
    }
}

void exibirArvoreEmPreOrdem(No* raiz) {
    //printf("DEBUG: %d\n", raiz->valor);
    printf("Valor do Nó: %d\n", raiz->valor);
    if(raiz->esq != NULL) {
        exibirArvoreEmPreOrdem(raiz->esq);
    }
    if(raiz->dir != NULL) {
        exibirArvoreEmPreOrdem(raiz->dir);
    }
}

void exibirArvorePosOrdem(No* raiz) {
    //printf("DEBUG: %d\n", raiz->valor);
    if(raiz->esq != NULL) {
        exibirArvorePosOrdem(raiz->esq);
    }
    if(raiz->dir != NULL) {
        exibirArvorePosOrdem(raiz->dir);
    }
    printf("Valor do Nó: %d\n", raiz->valor);

}



int main()
{
    No *raiz = malloc(sizeof(No));
    raiz->valor = 5;
    adicionarNo(raiz, 2);
    adicionarNo(raiz, 10);
    adicionarNo(raiz, 3);
    adicionarNo(raiz, 1);
    
    printf("-------------EM ORDEM-------------\n");
    exibirArvoreEmOrdem(raiz);
    printf("\n-------------POS ORDEM-------------\n");
    exibirArvorePosOrdem(raiz);
    printf("-------------PRE ORDEM-------------\n");
    exibirArvoreEmPreOrdem(raiz);
}
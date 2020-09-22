#include<stdio.h>
#include<stdlib.h>
#include "AbB.h"

struct NO{
    int dados;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* criar(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL) *raiz = NULL;
    return raiz;
}

void liberarNO(struct NO* no){
    if(no == NULL) return;
    else{
        liberarNO(no->esq);
        liberarNO(no->dir);
        free(no);
        no = NULL;
    }
}
void liberar(ArvBin* raiz){
    if(raiz == NULL) return;
    liberarNO(*raiz); //libera no por no
    free(raiz); //libera a raiz
}

int vazia(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL) return 1;
    else return 0; 
}

int altura(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL) return 0;
    int alt_esq = altura(&((*raiz)->esq));
    int alt_dir = altura(&((*raiz)->dir));

    if(alt_esq > alt_dir) return (alt_esq + 1);
    else return (alt_dir + 1);
}

int totalNO(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL) return 0;
    else{
        int alt_esq = totalNO(&((*raiz)->esq));
        int alt_dir = totalNO(&((*raiz)->dir));

        return (alt_esq + alt_dir + 1);
    }
}

void preOrdem(ArvBin *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        printf("%i\n", (*raiz)->dados);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}

void emOrdem(ArvBin *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        emOrdem(&((*raiz)->esq));
        printf("%i\n", (*raiz)->dados); 
        emOrdem(&((*raiz)->dir));       
    }
}

void posOrdem(ArvBin *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));            
        printf("%i\n", (*raiz)->dados); 
    }
}

int inserir(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* new = (struct NO*) malloc(sizeof(struct NO));

    if(new == NULL) return 0;
    else{
        new->dados = valor;
        new->esq = NULL;
        new->dir = NULL;

        if(*raiz == NULL) *raiz = new;
        else{
            struct NO* atual = *raiz;
            struct NO* ant = NULL;

            while(atual != NULL){
                ant = atual;
                if(valor == atual->dados){
                    free(new);
                    return 0; // pois o elemento já existe
                }
                if(valor > atual->dados) atual = atual->dir;
                else atual = atual->esq;
            }

            if(valor > ant->dados) ant->dir = new;
            else ant->esq = new;
        }
        return 1;
    }
}   


struct NO* removeAtual(struct NO* atual){ //TRATA OS 3 TIPOS DE REMOÇÕES
    struct NO *nox1, *nox2;
    if(atual->esq == NULL){
        nox2 = atual->dir;
        free(atual);
        return nox2;
    }
    nox1 = atual;
    nox2 = atual->esq;

    while(nox2->dir != NULL){
        nox1 = nox2;
        nox2 = nox2->dir;
    }

    if(nox1 != atual){
        nox1->dir = nox2->esq;
        nox2->esq = atual->esq;
    }

    nox2->dir = atual->dir;
    free(atual);
    return nox2;
} 

int remover(ArvBin *raiz, int valor){ //busca o NO a ser removido
    if(raiz == NULL) return 0;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;  

        while(atual != NULL){
            if(valor == atual->dados){
                if(atual == *raiz) {
                    *raiz = removeAtual(atual);
                }
                else{
                    if(ant->dir == atual) ant->dir = removeAtual(atual);
                    else ant->esq = removeAtual(atual);
                }
                return 1;
            }
            ant = atual;
            if(valor > atual->dados) atual = atual->dir;
            else atual = atual->esq;
        }
    }
}



int consultar(ArvBin *raiz, int value){
    if(raiz == NULL) return 0;
    else{
        struct NO* nox = *raiz;
        while(nox != NULL){
            if(value == nox->dados) return 1;

            if(value > nox->dados) nox = nox->dir;
            else nox = nox->esq;
        }
        return 0;
    }
}
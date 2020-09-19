#include<stdio.h>
#include<stdlib.h>
#include "ArvBin.h"

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
#include "PilhaDin.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* criar(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if(p != NULL) *p = NULL;
    return p;
}

void liberar(Pilha* p){
    if(p != NULL){
        Elem* no;
        while (*p != NULL){
            no = *p;
            *p = (*p)->prox;
            free(no);
        }
        free(p);
    }
}

int tamanho(Pilha* p){
    if(p != NULL) {
        int cont = 0;
        Elem* no = *p;
        while (no != NULL){
            cont++;
            no = no->prox;
        }
        return cont;
    }else return -1;
}

int cheia(Pilha* p) {return 0;}

int vazia(Pilha* p){
    if(*p == NULL || p == NULL) return 1;
    else return 0;
}

int inserir(Pilha* p, struct aluno alu){
    if(p == NULL) return 0;
    else{
        Elem* no = (Elem*) malloc(sizeof(Elem));
        if(no != NULL){
            no->dados = alu;
            no->prox = (*p);
            (*p) = no;
            return 1;
        }else return 0;
    }
}

int remover(Pilha* p){ 
    if(vazia(p)) return 0;
    else{
        Elem* no = (*p);
        (*p) = no->prox;
        free(no);
        return 1;
    }
}

int consultar(Pilha* p, struct aluno *alu){
    if(vazia(p)) return 0;
    else{
        *alu = (*p)->dados;
        return 1;
    }
}
#include "Estatic.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100

struct pilha{
    int qtd;
    struct aluno dados[MAX];
};

Pilha* criar(){
    Pilha *p = (Pilha*) malloc(sizeof(struct pilha));

    if(p != NULL) p->qtd = 0;
    return p;
}

void liberar(Pilha* p){
    free(p);
}

int tamanho(Pilha* p){
    if(p != NULL) return p->qtd;
    else return -1;
}

/*int vazia(Pilha* p){
    if(p == NULL || p->qtd == 0) return 1;
    else return 0;
}*/

int vazia(Pilha* p){
    if(p == NULL) return -1;
    return p->qtd == 0;
}

int cheia(Pilha* p){
    if(p != NULL && p->qtd == MAX) return 1;
    else return 0;
}

int inserir(Pilha* p, struct aluno alu){
    if(p == NULL) return 0;
    if(cheia(p)) return 0;
    else{
        p->dados [p->qtd] = alu;
        p->qtd++;
        return 1;
    }
}

int remover(Pilha* p){
    if(p == NULL) return 0;
    if(vazia(p)) return 0;
    else {
        p->qtd--;
        return 1;
    }
}

int consultar(Pilha* p, struct aluno *alu){
    if(p == NULL || vazia(p)) return 0;
    else{
        *alu = p->dados [p->qtd-1];
        return 1;
    }
}
#include "FilaEstat.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

Fila* criar(){
    Fila *f = (Fila*) malloc (sizeof(struct fila));

    if(f != NULL){
        f->inicio = 0;
        f->final = 0;
        f->qtd = 0;
    }
    return f;
}

void liberar(Fila* f){free(f);}

int tamanho(Fila* f){
    if(f == NULL) return -1; //não retornamos 0 pq pode ser que a fila exista e que tenha 0 elementos.
    else return f->qtd;
}

int cheia(Fila* f){
    if(f == NULL) return -1;
    if(f->qtd == MAX) return 1;
    else return 0;
}

int vazia(Fila* f){
    if(f == NULL) return -1;
    if(f->qtd == 0) return 1;
    else return 0;
}

int inserir(Fila* f, struct aluno alu){
    if(f == NULL) return 0;
    if(cheia(f)) return 0;
    else{
        f->dados [f->final] = alu;
        f->final = (f->final + 1) % MAX;
        f->qtd++;
        return 1;
    }
}

int remover(Fila* f){
    if(f == NULL) return 0;
    if (vazia(f)) return 0;
    else{
        f->inicio = (f->inicio + 1) % MAX;
        f->qtd--;
        return 1;
    }
}

int consultar(Fila* f, struct aluno *alu){
    if(f == NULL) return 0;
    if(vazia(f)) return 0;
    else{
        *alu = f->dados[f->inicio];
        return 1;
    }
}
#include "Dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct fila{
    struct elemento *ini;
    struct elemento *fim;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;


Fila* criar(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }
    return f;
}

void liberar(Fila* f){
    if(f != NULL){
        Elem *no;
        while(f->ini != NULL){
            no = f->ini;
            f->ini = f->ini->prox;
            free(no);
        }
        free(f);
    }
}

int tamanho(Fila* f){
    if(f == NULL) return 0;
    else{
        Elem *no = f->ini;
        int cont = 0;

        while(no != NULL){
            cont++;
            no = no->prox;
        }
        return cont;
    }
}

int vazia(Fila* f){
    if(f == NULL) return 1;
    if(f->ini == NULL) return 1;
    else return 0;
}

int cheia(Fila *f) {return 0;}

int inserir(Fila* f, struct aluno alu){
    if(f == NULL) return 0;
    else{
        Elem *no = (Elem*) malloc(sizeof(Elem));
        if(no == NULL) return 0;
        else{
            no->dados = alu;
            no->prox = NULL;

            if(f->fim == NULL) f->ini = no; //se a fila tiver vazia
            else f->fim->prox = no;

            f->fim = no;
            return 1;
        }
    }
}

int remover(Fila* f){
    if(vazia(f)) return 0;
    else{
        Elem *no = f->ini;
        f->ini = f->ini->prox;
        if(f->ini == NULL) f->fim = NULL; //fila ficou vazia, ele era o unico elemento
        else free(no);
        return 1;
    }
}

int consultar(Fila* f, struct aluno *alu){
    if(vazia(f)) return 0;
    else *alu = f->ini->dados;
    return 1;
}
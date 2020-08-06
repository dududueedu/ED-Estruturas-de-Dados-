#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncDup.h"

typedef struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    struct aluno dados;
}Elem;

Lista *criar(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l != NULL) *l = NULL;
    return l;
}

void liberar(Lista* l){
    if(l != NULL){
        Elem* no;
        while ((*l) != NULL){   
            no = *l;
            *l = (*l)->prox;
            free(no);
        }
        free(l);
    }
}

int tamanho_lista(Lista* l){
    if(l == NULL) return 0;
    int cont = 0;
    Elem *no = *l;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista *l){
    return 0;
}

int lista_vazia(Lista *l){
    if(l == NULL) return 1;
    else if(*l == NULL) return 1;
    else return 0;
}

//inserções
int insere_inicio(Lista *l, struct aluno alu){
    if(l == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    else{
        no->dados = alu;
        no->prox = (*l);
        no->ant = NULL;

        if((*l) != NULL) (*l)->ant = no;
        *l = no;
        return 1;
    }

}

int insere_fim(Lista* l, struct aluno alu){
    if(l == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    else{
        no->dados = alu;
        no->prox = NULL;
        if((*l) == NULL){
            no->ant = NULL;
            *l = no;
        }else{
            Elem *noAux = *l;
            while (noAux->prox != NULL){
                noAux = noAux->prox;
            }
            noAux->prox = no;
            no->ant = noAux;
        }
        return 1;
    }
}

//remoções
int remover_inicio(Lista *l){
    if(l == NULL) return 0;
    if((*l) == NULL) return 0;
    else{
        Elem *no = *l;
        *l = no->prox;
        if(no->prox != NULL) no->prox->ant = NULL;
        free(no);
        return 1;
    }
}

int remover_final(Lista *l){
    if(l == NULL) return 0;
    if((*l) == NULL) return 0;
    else{
        Elem *no = *l;
        while (no->prox != NULL) no = no->prox;
        if(no->ant == NULL) *l = no->prox;
        else no->ant->prox = NULL;
        free(no);
        return 1;
    }
}

int remover_qualquer(Lista* l, int matricula){
    if(l == NULL) return 0;
    else if((*l) == NULL) return 0;
    else{
        Elem *no = *l;
        while (no->prox != NULL){
            no = no->prox;
        }
        if(no->ant == NULL) *l = no->prox;
        else no->ant->prox = NULL;
        free(no);
        return 1;
    }
}

//consultas
int buscar_posicao(Lista *l, int posicao, struct aluno *alu){
    if(l == NULL && posicao <= 0) return 0;
    else{
        Elem *no = *l;
        int cont_busca = 1;
        while (no != NULL && posicao > cont_busca){
            no = no->prox;
            cont_busca++;
        }
        if(no == NULL) return 0;
        else{
            *alu = no->dados;
            return 1;
        }
    }
}

int buscar_conteudo(Lista *l, int matricula, struct aluno *alu){
    if(l == NULL) return 0;
    else{
        Elem *no = *l;
        while (no != NULL && no->dados.matricula != matricula){
            no = no->prox;
        }
        if(no == NULL) return 0;
        else {
            *alu = no->dados;
            return 1;
        }
    }
}
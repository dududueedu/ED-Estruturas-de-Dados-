#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

typedef struct elemento{
    struct aluno dados;
    struct elemento *prox; 
}Elem;

Lista *criarLista(){
  Lista *l = (Lista*) malloc(sizeof(Lista));
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

int insere_fim(Lista* l, struct aluno alu){
    if(l == NULL) return 0;
    else {
        Elem *no = (Elem* ) malloc(sizeof(Elem));
        if(no == NULL) return 0;
        else{
            no->dados = alu;
            no->prox = NULL;
            if((*l) == NULL) *l = no;
            
            else{
                Elem *noAux = *l;
                while (noAux->prox != NULL){
                    noAux = noAux->prox;
                }            
                noAux = no;
            }          
        }
    }
    return 1;
}

int buscar_posicao(Lista *l, int pos, struct aluno *alu){
    if(l == NULL) return 0;
    else{
        Elem* no = *l;
        int contador = 1;

        while (no != NULL && contador < pos) {
            no = no->prox; 
            contador++;
        }
        if(no == NULL) return 0;
        else {
            *alu = no->dados;
            return 1;
        }
    }
}

int remover_qualquer(Lista* l, int matricula){
    if(l == NULL) return 0;
    else {
        Elem *non, *anterior = *l; 

        while (non != NULL && non->dados.matricula != matricula){
            anterior = non;
            non = non->prox;
        }
        if(non == NULL) return 0;
        else if(non == *l){
            *l = non->prox;
        }else{
            anterior->prox = non->prox;
        }
        free(non);
        return 1;
    }
}

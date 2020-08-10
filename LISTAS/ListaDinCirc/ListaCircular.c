#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

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
    if(l != NULL && *l != NULL){
        Elem *noAux, *no = *l;
        while (no != (*l)){
            noAux = no;
            no = no->prox;
            free(noAux);
        }
        free(no);
        free(l); 
    }
}

int tamanho_lista(Lista *l){
    if(l == NULL || (*l) == NULL) return 0;
    else{
        int tam = 0;
        Elem *no = (*l);
        do{
            tam++;
            no = no->prox;
        } while (no != (*l));
        return tam;
    }
} 

int lista_cheia(Lista *l){
    return 0;
}

int lista_vazia(Lista *l){
    if(l == NULL || (*l) == NULL) return 1;
    else return 0;
}

//inserções
int insere_inicio(Lista *l, struct aluno alu){
    if(l == NULL) return 0;
    else{
        Elem *no = (Elem*) malloc (sizeof(Elem));
        if(no == NULL) return 0;
        else no->dados = alu;
        if((*l) == NULL){
            (*l) = no;
            no->prox = no;
        }else{
            Elem *noAux = (*l);
            while (noAux->prox != (*l)){
                noAux = noAux->prox;
            }
            noAux->prox = no;
            no->prox = (*l);
            (*l) = no;
        }
        return 1;
    }
}

int insere_fim(Lista* l, struct aluno alu){
    if(l == NULL) return 0;
    else{
        Elem *no = (Elem*) malloc(sizeof(Elem));
        if(no == NULL) return 0;
        no->dados = alu;
        if((*l) == NULL){
            (*l) = no;
            no->prox = no;
        }else{
            Elem *noAux = (*l);
            while (noAux->prox != (*l)){
                noAux = noAux->prox;
            }
            noAux->prox = no;
            no->prox = (*l);
        }
        return 1;
    }
}

int insere_ordenado(Lista* l, struct aluno alu){
    if(l == NULL) return 0;
    else{
        Elem *no = (Elem*) malloc(sizeof(Elem));
        if(no == NULL) return 0;
        else no->dados = alu;

        if((*l) == NULL){
            (*l) = no;
            no->prox = no;
        }else{
            if((*l)->dados.matricula > alu.matricula){
                Elem *noAtual = (*l);
                while (noAtual->prox != (*l)){
                    noAtual = noAtual->prox;
                }
                no->prox = (*l);
                noAtual = no;
                (*l) = no;
                return 1;
            }else{
                Elem *ante = (*l), *noAtual = (*l)->prox;
                while (noAtual != (*l) && noAtual->dados.matricula < alu.matricula){
                    ante = noAtual;
                    noAtual = noAtual->prox;
                }
                ante->prox = no;
                no->prox = noAtual;
            }   
        }
    }
}

//REMOÇÕES
int remover_no_inicio(Lista *l){
    if(l == NULL || (*l) == NULL) return 0;
    if((*l) == (*l)->prox){
        free(*l);
        (*l) = NULL;
        return 1;
    }else{
        Elem *noAtual = (*l);
        while (noAtual->prox != (*l)) noAtual = noAtual->prox;
        Elem *noAux = (*l);
        noAtual->prox = noAux->prox;
        (*l) = noAux->prox;
        free(noAux);
        return 1;
    }
}

int remover_qualquer(Lista *l, int matric){
    if(l == NULL || (*l) == NULL) return 0;
    else{
        Elem *no = (*l);
        if(no->dados.matricula == matric){
            if(no == no->prox){
                free(no);
                (*l) = NULL;
                return 1;
            }else{
                Elem *noAux = (*l);
                while(noAux->prox != (*l)){
                    noAux = noAux->prox;
                }
                noAux->prox = (*l)->prox;
                (*l) = (*l)->prox;
                free(no);
                return 1;
            }
        }
        Elem *ante = (*l);
        no = no->prox;
        while(no != (*l) && no->dados.matricula != matric){
            ante = no;
            no = no->prox;
        }
        if(no == (*l)) return 0;
        else{
            ante->prox = no->prox;
            free(no);
            return 1;
        }
    }
}

int remover_no_final(Lista *l){
    if(l == NULL || (*l) == NULL) return 0;
    else{
        Elem *ante, *no = (*l);
        if((*l) == (*l)->prox){
            free(*l);
            (*l) = NULL;
            return 1;
        }else{
            while(no->prox != (*l)){
                ante = no;
                no = no->prox;
            }
            ante->prox = no->prox;
            free(no);
            return 1;
        }

    }
}

//CONSULTAS
int busca_conteudo(Lista *l, int matric, struct aluno *alu){
    if(l == NULL || (*l) == NULL) return 0;
    else{
        Elem *no = (*l);
        while (no->prox != (*l) && no->dados.matricula != matric){
            no = no->prox;
        }
        if(no->dados.matricula != matric) return 0;
        
        *alu = no->dados;
        return 1;
    }
}

int busca_posicao(Lista *l, int pos, struct aluno *alu){
    if(l == NULL || (*l) == NULL || pos <= 0) return 0;
    else{
        Elem *no = (*l);
        int cont = 1;
        while(no->prox != (*l) && cont < pos){
            no = no->prox;
            cont++;
        }
        if(cont != pos) return 0;
        *alu = no->dados;
        return 1;
    }
}
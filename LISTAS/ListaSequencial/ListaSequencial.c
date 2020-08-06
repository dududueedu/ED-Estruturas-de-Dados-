#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
#define MAX 10

struct lista{
   int v[MAX], qtd;
};

Lista* criar(){
   Lista *l = (Lista*) malloc(sizeof(Lista));
   
   if(l != NULL) l->qtd = 0;
   
   return l;
}

void inserir(Lista *l, int valor, int posicao){
   int i;
   if(lista_cheia(l)) printf("A lista está cheia");
   else if(l == NULL) ("Lista inesistente");
   else if(posicao > l->qtd || posicao<0) printf("A posição é inválida");
      else{
         i = l->qtd;
         while(i>posicao){
            l->v[i] = l->v[i-1];
            i--;
         }
         l->v[posicao] = valor;
         l->qtd += 1;
            
        }
}

int remover(Lista *l, int posicao){
   int i = 0, valor = 0;
   if(lista_vazia(l)){ printf("A lista está vazia, impossivel remover");
      exit(1);
   }
   else if(l == NULL) ("Lista inesistente");
   else if(posicao >= l->qtd || posicao<0) { 
            printf("Posição inválida, impossível remover"); 
            exit(1);
         }else{
            valor = l-> v[posicao];
 	    
	         for(i = posicao+1; i < l->qtd; i++)
	            l->v[i-1] = l->v[i];
 	    
	         l->qtd -= 1;
	         return valor; 
         }
}

int tamanho_lista(Lista *l){
    if(l == NULL) return -1;
    else return l->qtd;
}

int lista_cheia(Lista *l){
   if(l->qtd == MAX) return 1;
   else return 0;
}

int lista_vazia(Lista *l){
   if(l->qtd == 0) return 1;
   else return 0;
}

void liberar(Lista *l) {free(l);}

int busca_conteudo(Lista *l, int conteudo){
     for(int i = 0; i < l->qtd; i++){
        if(conteudo == l->v[i]) return 1;
     }
     return 0;
}
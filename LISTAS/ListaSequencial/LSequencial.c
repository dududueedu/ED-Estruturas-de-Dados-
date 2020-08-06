#include <stdio.h>
#include "ListaSequencial.h"

int main(){
    printf("--- Atividade 1 - Estruturas de Dados ---\n\n");
    int opc, valor, posicao, tam = 0;
    Lista *l;
    do{
	    printf("\nDigite a opção desejada: \n1- Criar Lista \n2- Inserir \n3- Remover \n"
        "4- Buscar conteúdo \n5- Verificar se a Lista está vazia \n6- Verificar se a lista está cheia \n7 - Ver o tamanho da lista \n"
        "8 - Sair\n");    
        scanf("%i", &opc);
	
        switch(opc){
            case 1:
                l = criar();
                printf("Lista criada com sucesso! \n");
                break;
            case 2:
                printf("Digite o valor a ser inserido na Lista: ");
                scanf("%i", &valor);
                printf("Digite a posição a ser inserido: ");
                scanf("%i", &posicao);
                inserir(l, valor, posicao);
                break;
            case 3:
                printf("Digite a posição a ser removido: ");
                scanf("%i", &posicao);
                valor = remover(l, posicao);
                printf("O valor removido foi %i", valor);
                break;
            case 4:
                printf("Digite o conteudo da consulta: ");
                scanf("%i", &valor);
                if(busca_conteudo(l, valor)) printf ("Conteudo é: %i: ", valor);
                else printf ("Conteudo nao encontrado!!!");
                break;
            case 5:
                if(lista_vazia(l)) printf("A lista está vazia. \n");
                else printf("A lista não está vazia. \n");
                break;

            case 6:
                if(lista_cheia(l)) printf("Lista cheia. \n");
                else printf("Lista ainda nao está cheia. \n");
                break;
            case 7:
                tam = tamanho_lista(l);
                printf("O tamanho da lista é: %i", tam);
                break;
            
            case 8:
                liberar(l);
                printf("Programa encerrado com sucesso. \n");
                break;
            default: printf("Opção Inválida. \n\n");
        }
    }while(opc != 8);
    return(0);
}

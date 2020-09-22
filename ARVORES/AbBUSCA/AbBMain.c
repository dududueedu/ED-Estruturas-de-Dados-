#include<stdio.h>
#include<stdlib.h>
#include "AbB.h"

int main(){


    printf("------------------");
    printf("\n---- Arvore ----- ");
    printf("\n-- Atividade 11 -- \n");

    ArvBin* raiz = criar();
    printf("Criada com sucesso.\n");
    printf("vazia: ( %i )\n", vazia(raiz));

    int valor = 7;
    int a = inserir(raiz, valor);
    printf("\nA inserção foi realizada? %i\n", a);

    int c = consultar(raiz, valor);
    printf("\nO elemento buscado foi encontrado? %i\n", c);

    int d = consultar(raiz, 9);
    printf("O elemento buscado foi encontrado? %i\n", d);

    printf("\nAltura da Arvore: %i\n", altura(raiz));
    printf("Total de NÓ da Arvore: %i\n", totalNO(raiz));

    int b = remover(raiz, valor);
    printf("\nA remoção foi feita? %i\n", b);

    printf("\nAltura da Arvore: %i\n", altura(raiz));
    printf("Total de NÓ da Arvore: %i\n", totalNO(raiz));

    liberar(raiz);
    return 0;
}
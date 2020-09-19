#include<stdio.h>
#include<stdlib.h>
#include "ArvBin.h"

int main(){


    printf("------------------");
    printf("\n---- Arvore ----- ");
    printf("\n-- Atividade 10 -- \n");
    ArvBin* raiz = criar();
    printf("Criada com sucesso.\n");
    printf("vazia: ( %i )\n", vazia(raiz));

    printf("\nAltura da Arvore: %i\n", altura(raiz));
    printf("\nTotal de NÓ da Arvore: %i\n", totalNO(raiz));

    liberar(raiz);
    return 0;
}
#include <stdio.h>
#include "Buscas.h"
#include <string.h>

int main(void){ 

    int N = 10, elem = 7;
    int vetBinario[] = {-8, -5, 1, 4, 14, 21, 23, 54, 67, 90};
    int vetOrdenado[] = {1, 3, 5, 7, 9,  11, 13, 15, 17, 19};
    int vetLinear[] = {8, 2, 1, 7, 13, 10, 9, 3, 0, 5};

    struct aluno vetor[5] = {{1, "Eduardo", 7.5, 8.6, 8.4},
                            {3, "Dinho", 5.5, 7.6, 9.4},
                            {2, "Lia", 6.5, 3.6, 5.4},
                            {6, "Patty", 9.5, 9.6, 7.4},
                            {8, "Jô", 9.5, 4.6, 2.4}};

    //teste Busca Linear
    printf("Busca Linear: \n");
    if(linear(vetLinear, N, elem) != -1) printf("OK! Elemento encontrado.\n\n");
    else printf("ERRO!!!\n");

    //teste Busca Ordenada
    printf("Busca Ordenada: \n");
    if(ordenada(vetOrdenado, N, elem) != -1) printf("OK! Elemento encontrado.\n\n");
    else printf("ERRO!!!\n");

    //teste Busca Binaria
    printf("Busca binaria: \n");
    if(binaria(vetBinario, N, elem) != -1) printf("OK! Elemento encontrado.\n\n");
    else printf("ERRO!!!\n\n");    

    //teste Busca linearMatricula
    printf("Busca linearMatricula: \n");
    if(linearMatricula(vetor, 5, 2) != -1) printf("OK! Elemento encontrado.\n\n");
    else printf("ERRO!!!\n");

    //teste Busca linearNome
    printf("Busca linearNome: \n");
    if(linearNome(vetor, 5, "Lia") != -1) printf("OK! Elemento encontrado.\n\n");
    else printf("ERRO!!!\n");

    return 0;
}
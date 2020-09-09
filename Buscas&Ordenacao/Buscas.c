#include <stdio.h>
#include "Buscas.h"
#include <string.h>

int linear(int *Vetor, int N, int elem){
    int i = 0;
    for(i; i < N; i++){
        if(Vetor[i] == elem) return i;
    }
    return -1;
}

int ordenada(int *Vetor, int N, int elem){
    int i = 0;
    for(i; i < N; i++){
        if(Vetor[i] == elem) return i;
        else if(Vetor[i] > elem) return -1;
    }
    return -1;
}

int binaria(int *Vetor, int N, int elem){
    int ini = 0, meio, fim = N - 1;

    while(ini <= fim){
        meio = (ini + fim)/2;
        if(elem < Vetor[meio]) fim = meio - 1;
        else if(elem > Vetor[meio]) ini = meio + 1;
        else return meio; 
    }
    return -1;
}

int linearMatricula(struct aluno *Vetor, int N, int elem){
    int i = 0;
    for(i; i < N; i++){
        if(Vetor[i].matricula == elem) return i;
    }
    return -1;
}

int linearNome(struct aluno *Vetor, int N, char* elem){
    int i = 0;
    for(i; i < N; i++){
        if(strcmp(elem, Vetor[i].nome) == 0) return i;
    }
    return -1;
}
#include <stdio.h>
#include "listaDE.h"
#include <string.h>

int main(){

    printf("--- Atividade 2 - Estruturas de Dados ---\n\n");
    Lista *l; // ponteiro p ponteiro
    l = criarLista(); // recebe ponteiro p o primeiro elemento da lista
    printf("Lista criada!\n");
    printf("Tamanho da lista: %i\n", tamanho_lista(l));
    printf("Lista eh vazia: %i\n", lista_vazia(l));
    
    struct aluno dadosAluno1;
    dadosAluno1.matricula = 1;
    dadosAluno1.n1 = 7;
    dadosAluno1.n2 = 8;
    dadosAluno1.n3 = 10;
    strcpy(dadosAluno1.nome, "Eduardo Silva");
    
    struct aluno dadosAluno2;
    dadosAluno2.matricula = 3;
    dadosAluno2.n1 = 3;
    dadosAluno2.n2 = 2;
    dadosAluno2.n3 = 7;
    strcpy(dadosAluno2.nome, "Éderson");
    //inserindo no final da lista
    int x = insere_fim(l, dadosAluno1);
    printf("inseriu 1 aluno? %i\n", x);
    int y = insere_fim(l, dadosAluno2);
    printf("inseriu 2 aluno? %i\n", y);
    //consulta por posição
    int posicao = 1;
    struct aluno dadosAluno;
    int a = buscar_posicao(l, posicao, &dadosAluno);
    printf("Consulta posicao 1: %i\n", a);
    printf("Matricula: %i\nNome: %s\n", dadosAluno.matricula, dadosAluno.nome);

    printf("removido: %i\n nome: %s\n", dadosAluno2.matricula, dadosAluno2.nome);
    int z = remover_qualquer(l, dadosAluno2.matricula = 3);
    
    printf("Tamanho da lista: %i\n", tamanho_lista(l));
    //liberaLista(li);
    //printf("Lista liberada!\n");
    return 0;
}
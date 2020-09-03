#include <stdio.h>
#include "Estatic.h"
#include <string.h>

int main(){

    printf("------------------");
    printf("\n- Pilha  Estática - ");
    printf("\n--- Atividade 7 -- \n");
    Pilha *p; // ponteiro p ponteiro
    p = criar(); // recebe ponteiro p o primeiro elemento da pilha
    
    printf("------------------\n");
    printf("-- Pilha criada! --\n");
    printf("------------------\n\n");

    printf("Tamanho da Pilha:  %i elemento(s)\n", tamanho(p));
    printf("Pilha eh vazia:   ( %i )\n", vazia(p));
    
    //coletando dados dos alunos
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
    
    //inserindo na Pilha
    int a = inserir(p, dadosAluno1);
    printf("inseriu 1 aluno? ( %i )\n", a);
    int b = inserir(p, dadosAluno2);
    printf("inseriu 2 aluno? ( %i )\n", b);
    
    printf("Tamanho da Pilha:  %i elemento(s)\n", tamanho(p)); 
    printf("A Pilha está cheia? ( %i )\n", cheia(p));
    
    //consultando
    struct aluno dadosAluno;
    int c = consultar(p, &dadosAluno);
    printf("\nDeu certo realizar a consulta?: ( %i ) ", c);
    printf("\nSobre a Busca\nMatricula: %i\nNome: %s\n", dadosAluno.matricula, dadosAluno.nome);

    //removendo
    printf("\nRemoveu?: ( %i )\n", remover(p));
    printf("Tamanho da Pilha:  %i elemento(s)\n", tamanho(p));   

    liberar(p);
    printf("\n\nPilha liberada!\n");

    return 0;
}
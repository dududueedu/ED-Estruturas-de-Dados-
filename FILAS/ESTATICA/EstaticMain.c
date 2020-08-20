#include <stdio.h>
#include "FilaEstat.h"
#include <string.h>

int main(){

    printf("------------------");
    printf("\n- Fila  Estática - ");
    printf("\n--- Atividade 5 -- \n");
    Fila *f; // ponteiro p ponteiro
    f = criar(); // recebe ponteiro p o primeiro elemento da fila
    
    printf("------------------\n");
    printf("-- Fila criada! --\n");
    printf("------------------\n\n");

    printf("Tamanho da Fila:  %i elemento(s)\n", tamanho(f));
    printf("Fila eh vazia:   ( %i )\n", vazia(f));
    
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
    
    //inserindo na Fila
    int a = inserir(f, dadosAluno1);
    printf("inseriu 1 aluno? ( %i )\n", a);
    int b = inserir(f, dadosAluno2);
    printf("inseriu 2 aluno? ( %i )\n", b);
    
    printf("Tamanho da Fila:  %i elemento(s)\n", tamanho(f)); 
    printf("A Fila está cheia? ( %i )\n", cheia(f));
    
    //consultando
    struct aluno dadosAluno;
    int c = consultar(f, &dadosAluno);
    printf("\nDeu certo realizar a consulta?: ( %i ) ", c);
    printf("\nSobre a Busca\nMatricula: %i\nNome: %s\n", dadosAluno.matricula, dadosAluno.nome);

    //removendo
    printf("\nRemoveu?: ( %i )\n", remover(f));
    printf("Tamanho da Fila:  %i elemento(s)\n", tamanho(f));   

    liberar(f);
    printf("\n\nFila liberada!\n");

    return 0;
}
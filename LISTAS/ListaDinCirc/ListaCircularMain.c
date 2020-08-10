#include <stdio.h>
#include "ListaCircular.h"
#include <string.h>

int main(){

    printf("--- Atividade 4 - Estruturas de Dados ---\n\n");
    Lista *l; // ponteiro p ponteiro
    l = criarLista(); // recebe ponteiro p o primeiro elemento da lista
    printf("Lista criada!\n");
    printf("Tamanho da lista: %i\n", tamanho_lista(l));
    printf("Lista eh vazia: %i\n", lista_vazia(l));
    
    //colen=tando dados dos alunos
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
    
    //inserindo na lista
    int a = insere_inicio(l, dadosAluno1);
    printf("inseriu 1 aluno? %i\n", a);
    int b = insere_fim(l, dadosAluno2);
    printf("inseriu 2 aluno? %i\n", b);
    
    printf("Tamanho da lista: %i\n", tamanho_lista(l)); 
    
    //consultando
    int matricula = 1;
    struct aluno dadosAlunoBuscaPorConteudo;
    int d = busca_conteudo(l, matricula, &dadosAlunoBuscaPorConteudo);
    printf("\nBusca por Conteudo/Matricula:\nMatricula: %i\nNome: %s\n", dadosAlunoBuscaPorConteudo.matricula, dadosAlunoBuscaPorConteudo.nome);
    
    int posicao = 2;
    struct aluno dadosAlunoBuscaPorPosicao;
    int e = busca_posicao(l, posicao, &dadosAlunoBuscaPorPosicao);
    printf("\nBusca por Posicao:\nPosicao: %i\nNome: %s\n", posicao, dadosAlunoBuscaPorPosicao.nome);    

    //removendo
    printf("\nremoveu do inicio?: %i\n", remover_no_inicio(l));
    printf("Tamanho da lista: %i\n", tamanho_lista(l)); 

    printf("\nremoveu qualquer elemento (pela matricula)?: %i\n", remover_qualquer(l, dadosAlunoBuscaPorConteudo.matricula = dadosAluno2.matricula));
    printf("Tamanho da lista: %i\n", tamanho_lista(l));    

    //liberaLista(li);
    //printf("Lista liberada!\n");

    return 0;
}
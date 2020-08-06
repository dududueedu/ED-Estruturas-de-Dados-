#include <stdio.h>
#include "ListaDinEncDup.h"
#include <string.h>

int main(){

    printf("--- Atividade 3 - Estruturas de Dados ---\n\n");
    Lista *l; // ponteiro p ponteiro
    l = criar(); // recebe ponteiro p o primeiro elemento da lista
    printf("Lista criada!\n");
    printf("Tamanho da lista: %i\n", tamanho_lista(l));
    printf("Lista eh vazia: %i\n", lista_vazia(l));
    
    struct aluno dadosAluno1;
    dadosAluno1.matricula = 1;
    dadosAluno1.n1 = 7;
    dadosAluno1.n2 = 8;
    dadosAluno1.n3 = 10;
    strcpy(dadosAluno1.nome, "Eduardo Silva");
    
    struct aluno dadosAluno3;
    dadosAluno3.matricula = 2;
    dadosAluno3.n1 = 7;
    dadosAluno3.n2 = 7;
    dadosAluno3.n3 = 7;
    strcpy(dadosAluno3.nome, "Jô");
    
    struct aluno dadosAluno2;
    dadosAluno2.matricula = 3;
    dadosAluno2.n1 = 3;
    dadosAluno2.n2 = 2;
    dadosAluno2.n3 = 7;
    strcpy(dadosAluno2.nome, "Éderson"); 

    //inserindo no final da lista
    int x = insere_fim(l, dadosAluno1);
    printf("inseriu o 1º aluno? %i\n", x);
    //inserindo no inicio da lista
    int y = insere_inicio(l, dadosAluno2);
    printf("inseriu o 2º aluno? %i\n", y);
    int p = insere_inicio(l, dadosAluno3);
    printf("inseriu o 3º aluno? %i\n", p); 
    //mostrando o tamanho da lista apõs as inserções
    printf("Tamanho da lista: %i\n\n", tamanho_lista(l));

    //consulta por conteudo
    int matric = 1;
    struct aluno dadosAluno;
    int a = buscar_conteudo(l, matric, &dadosAluno);
    printf("Consulta por conteudo (matricula) 1: %i\n", a);
    printf("Matricula: %i\nNome: %s\n", dadosAluno.matricula, dadosAluno.nome);

    //consulta por posicao
    int posic = 1, b;
    struct aluno dadosAluno4;
    b = buscar_posicao(l, posic, &dadosAluno4);
    printf("Consulta por posição : %i\n", b);
    printf("Matricula: %i\nNome: %s\n\n", dadosAluno4.matricula, dadosAluno4.nome);        

    //removendo elementos da lista de "n" formas
    printf("Removendo qualquer elemento pela (Matricula): %i\nNome: %s\n", dadosAluno2.matricula, dadosAluno2.nome);
    int z = remover_qualquer(l, dadosAluno2.matricula = 3);
    printf("Removeu o elemento do inicio da lista?: %i\n", remover_inicio(l));
    printf("Removeu o elemento do final da lista?: %i\n", remover_final(l));
    
    //mostrando o tamanho da lista após as remoções
    printf("Tamanho da lista: %i\n", tamanho_lista(l));
    //liberaLista(li);
    //printf("Lista liberada!\n");
    return 0;
}
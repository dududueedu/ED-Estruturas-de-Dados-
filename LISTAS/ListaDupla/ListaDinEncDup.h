struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento* Lista;


Lista* criar();

void liberar(Lista* l); 

int tamanho_lista(Lista *l);

int lista_cheia(Lista *l);

int lista_vazia(Lista *l);

int insere_inicio(Lista *l, struct aluno alu);
int insere_fim(Lista* l, struct aluno alu);

int remover_inicio(Lista *l);
int remover_final(Lista *l);
int remover_qualquer(Lista* l, int matricula);

int buscar_posicao(Lista *l, int posicao, struct aluno *alu);
int buscar_conteudo(Lista *l, int matricula, struct aluno *alu);
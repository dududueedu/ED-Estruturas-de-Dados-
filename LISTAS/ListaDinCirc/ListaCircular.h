struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento* Lista;

Lista *criarLista();

void liberar(Lista* l); 

int tamanho_lista(Lista *l);

int lista_cheia(Lista *l);

int lista_vazia(Lista *l);

//INSERÇÕES
int insere_inicio(Lista *l, struct aluno alu);
int insere_fim(Lista* l, struct aluno alu);
int insere_ordenado(Lista* l, struct aluno alu);

//REMOÇÕES
int remover_no_inicio(Lista *l);
int remover_qualquer(Lista *l, int matric);
int remover_no_final(Lista *l);

//CONSULTAS
int busca_conteudo(Lista *l, int matric, struct aluno *alu);
int busca_posicao(Lista *l, int pos, struct aluno *alu);
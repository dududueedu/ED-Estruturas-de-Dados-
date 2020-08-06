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

int insere_fim(Lista* l, struct aluno art);

int buscar_posicao(Lista *l, int pos, struct aluno *alu);

int remover_qualquer(Lista* l, int matricula);
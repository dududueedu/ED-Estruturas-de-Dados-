struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct fila Fila;

Fila* criar();
void liberar(Fila* f);
int tamanho(Fila* f);
int vazia(Fila* f);
int cheia(Fila* f);

int inserir(Fila* f, struct aluno alu);
int remover(Fila* f);
int consultar(Fila* f, struct aluno *alu);
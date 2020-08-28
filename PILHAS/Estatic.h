struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct pilha Pilha;

Pilha* criar();
void liberar(Pilha* p);
int tamanho(Pilha* p);
int vazia(Pilha* p);
int cheia(Pilha* p);

int inserir(Pilha* p, struct aluno alu);
int remover(Pilha* p);
int consultar(Pilha* p, struct aluno *alu);
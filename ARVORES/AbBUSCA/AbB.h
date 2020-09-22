typedef struct NO* ArvBin;

ArvBin* criar();
void liberar(ArvBin* raiz);

int vazia(ArvBin *raiz);
int altura(ArvBin *raiz);
int totalNO(ArvBin *raiz);

void preOrdem(ArvBin *raiz);
void emOrdem(ArvBin *raiz);

int inserir(ArvBin *raiz, int valor);
int remover(ArvBin *raiz, int valor);
int consultar(ArvBin *raiz, int value);
typedef struct NO* ArvBin;

ArvBin* criar();
void liberar(ArvBin* raiz);

int vazia(ArvBin *raiz);
int altura(ArvBin *raiz);
int totalNO(ArvBin *raiz);

void preOrdem(ArvBin *raiz);
void emOrdem(ArvBin *raiz);
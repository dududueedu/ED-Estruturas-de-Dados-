/*
Vocês devem implementar as funções que vimos na aula de Lista Sequencial,  lembrando de criar 
os dois arquivos (.h e .c), além disso implementarão as funções de inserção, remoção e consulta 
que não foram apresentadas na aula:

- Inserção de forma ordenada; colocar um elemento numa posição especifica na lista ok

- Removendo um elemento qualquer; deletar um elemento numa posição especifica na lista ok

- Consulta por conteúdo.
*/

typedef struct lista Lista;

Lista* criar(); //ok

void inserir(Lista *l, int valor, int posicao); //ok

int remover(Lista *li, int pos);

int lista_vazia(Lista *l); //ok

int lista_cheia(Lista *l); //ok

void liberar(Lista *l); //ok

int busca_conteudo(Lista *l, int conteudo); //ok

int tamanho_lista(Lista *l); //ok
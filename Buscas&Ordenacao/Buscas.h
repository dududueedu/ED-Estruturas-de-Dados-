struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};



int linear(int *Vetor, int N, int elem);
int ordenada(int *Vetor, int N, int elem);
int binaria(int *Vetor, int N, int elem);

int linearMatricula(struct aluno *Vetor, int N, int elem);
int linearNome(struct aluno *Vetor, int N, char* elem);
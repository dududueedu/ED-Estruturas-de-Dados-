void bubbleSort(int *vetor, int N){
    int i, continua, aux, fim = N;
    do{
        continua = 0;
        for(i = 0; i < fim-1;i++){
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}

void insertionSort(int *vetor, int N){
    int i, j, aux;
    for(i = 1; i < N; i++){
        aux = vetor[i];
        for(j = i; (j > 0) && (aux < vetor[j - 1]); j--){
            vetor[j] = vetor[j - 1];
        }
        vetor[j] = aux;
    }
}

void selectionSort(int *vetor, int N){
    int i, j, aux, menor;
    for (i = 0; i < N-1; i++){
        menor = i;
        for(j = i+1; j < N; j++){
            if(vetor[j] < vetor[i]) menor = j;
        }
        if(i != menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void merge(int *v, int inicio, int meio, int fim){
    int tam1 = meio - inicio + 1, tam2 = fim - meio;
    int A[tam1], B[tam2]; // definição dos vetores auxiliares
    int i, j, k = inicio;;
    // preenchendo o vetor auxiliar 1
    for (i=0; i<tam1; i++) A[i] = v[k++];//k++
    // preenchendo o vetor auxiliar 2
    for (j=0; j<tam2; j++) B[j] = v[k++];
    i = j = 0;
    k = inicio;
    // preenchendo o vetor v com os valores dos vetores auxiliares A e B, até que um dos vetores auxiliares chegue ao fim.
    while (i<tam1 && j<tam2) {
        if (A[i] < B[j]) v[k++] = A[i++];
        else v[k++] = B[j++];
        //k++;
    }
    // Ao chegar aqui, pelo menos um vetor auxiliar foi totalmente percorrido e estes laços percorrem o restante dos elementos do outro vetor auxiliar
    while (i<tam1) v[k++] = A[i++];
    while (j<tam2) v[k++] = B[j++];
}

void mergesort(int *v, int inicio, int fim){
    // Condição de parada é inicio = fim, ou seja, a divisão chegou em um vetor de tamanho 1.
    if (inicio < fim) { 
       int meio = (inicio+fim)/2;
       // chamadas para o sub-vetor da esquerda
       mergesort(v, inicio, meio);
       // chamadas para o sub-vetor da direita
       mergesort(v, meio+1, fim);
       // Chamada a intercalação entre os dois sub-vetores
       merge(v, inicio, meio, fim);
    }
}
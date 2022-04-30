# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void aloca_vetor(int *vetor, int tamanho){
    int i;

    vetor = (int *) realloc(vetor, tamanho * sizeof(int));

    for (i = 0; i < tamanho - 1; i++){
        vetor[i] = rand();
    }

    return;
}

int main(){
    int *vetor = (int *) malloc(1 * sizeof(int));
    int tamanho, i;

    srand(time(NULL));

    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tamanho);

    aloca_vetor(vetor, tamanho);

    for (i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }

    free(vetor);

    return 0;
}

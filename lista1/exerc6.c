# include <stdio.h>
# include <stdlib.h>

void aloca_vetor(int *vetor, int tamanho){
    int i;

    vetor = realloc(vetor, tamanho * sizeof(int));

    for (i = 0; i < tamanho - 1; i++){
        
    }
    
}

int main(){
    int *vetor = (int *) malloc(1 * sizeof(int));
    int tamanho;

    printf("Insira o tamanho do vetor: ");
    scanf("%d", tamanho);

    aloca_vetor(vetor, tamanho);

    free(vetor);

    return 0;
}

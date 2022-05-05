# include <stdio.h>
# include <stdlib.h>


void merge(int vetor){

}


void merge_sort(int vetor, int comeco, int fim){
    int meio;

    if (comeco < fim){
        meio = ((comeco + fim)/2);

        merge_sort(vetor, comeco, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor);
    }
    else{
        return;
    }
    
    
}


void init_merge_sort(int vetor){
    int comeco = 0, fim = 5;

    merge_sort(vetor, comeco, fim);
}


void init_quick_sort(int vetor){
    
}


int main(){
    int escolha;
    int vetor[] = {1, 4, 7, 9, 14, 17};

    printf("Insira o método de ordenação:\n");
    printf("1) MergeSort");
    printf("2) QuickSort");
    scanf("%d", &escolha);

    if (escolha == 1){
        init_merge_sort(vetor);
    }
    else if (escolha == 2){
        init_quick_sort(vetor);
    }
    
    
    return 0;
}
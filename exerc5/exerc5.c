#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[30];
    int idade;
    float altura;
}pessoa;


int menu();
pessoa *inserepessoa(pessoa *listapessoas, int *tamanho);
void mostrapessoas(pessoa *listapessoas, int *tamanho);


int menu(){
    int escolha;

    printf("Escolha:\n");
    printf("\t1)Inserir nome\n");
    printf("\t2)Listar nomes e sair\n");

    scanf("%d", &escolha);
    setbuf(stdin, NULL);

    return escolha;
}


pessoa *inserepessoa(pessoa *listapessoas, int *tamanho){

    printf("Insira o nome(max. 30 caracteres):\n");
    scanf("%s", &listapessoas[*tamanho].nome);
    setbuf(stdin, NULL);
    printf("Insira a idade:\n");
    scanf("%d", &listapessoas[*tamanho].idade);
    setbuf(stdin, NULL);
    printf("Insira a altura:\n");
    scanf("%f", &listapessoas[*tamanho].altura);
    setbuf(stdin, NULL);
    
    (*tamanho)++;
    listapessoas = (pessoa*) realloc(listapessoas, sizeof(pessoa) * ((*tamanho) + 1));
    
    return listapessoas;
}


void mostrapessoas(pessoa *listapessoas, int *tamanho){
    int i;

    for (i = 0; i <= (*tamanho) - 1; i++)
    {
        printf("\nPessoa %d\n", i + 1);
        printf("\tNome: %s\n", listapessoas[i].nome);
        printf("\tIdade: %d\n", listapessoas[i].idade);
        printf("\tAltura: %f\n", listapessoas[i].altura);
    }
    
}


int main(){
    int escolha, tamanho = 0;
    pessoa *listapessoas = (pessoa*) malloc(sizeof(pessoa));

    for(;;){
        escolha = menu();

        switch (escolha){
        case 1:
            listapessoas = inserepessoa(listapessoas, &tamanho);
            break;
        
        case 2:
            mostrapessoas(listapessoas, &tamanho);
            free(listapessoas);
            exit(0);
            break;

        default:
            printf("Digite uma opcao valida");
            break;
        }
    }
    return 0;
}
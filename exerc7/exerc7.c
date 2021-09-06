#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[30];
    int idade;
    int altura;
}pessoa;

pessoa pessoas[10];

void insere(void *pBuffer);
void lista(void *pBuffer);
void apaga(void *pBuffer);


void insere(void *pBuffer){

    if (*(int *)pBuffer < 10){
        
        printf("Insira o nome(max. 29 caracteres):\n");
        scanf("%s", pessoas[*(int *)pBuffer].nome);
        setbuf(stdin, NULL);
        printf("Insira a idade:\n");
        scanf("%d", &pessoas[*(int *)pBuffer].idade);
        setbuf(stdin, NULL);
        printf("Insira a altura(inteiros apenas):\n");
        scanf("%d", &pessoas[*(int *)pBuffer].altura);
        setbuf(stdin, NULL); 
        
        (*(int *)pBuffer)++;    // incrementa tamanho
    }
    else{
        printf("Lista de nomes cheia");
    }
    
    return;
}


void lista(void *pBuffer){
    *(int *)(pBuffer + (sizeof(int))) = 0;  // int para o for

    for (; (*(int *)(pBuffer + (sizeof(int)))) < (*(int *)pBuffer) ; (*(int *)(pBuffer + (sizeof(int))))++){    // basicamente significa for(; i < tamanho; i++)

        printf("Pessoa %d:\n", *(int *)(pBuffer + (sizeof(int))));
        printf("\tNome: %s\n", pessoas[*(int *)(pBuffer + (sizeof(int)))].nome);
        printf("\tIdade: %d\n", pessoas[*(int *)(pBuffer + (sizeof(int)))].idade);
        printf("\tAltura: %d\n", pessoas[*(int *)(pBuffer + (sizeof(int)))].altura);
    }

    return;
}


void apaga(void *pBuffer){
    int *tamanho = pBuffer;
    int *i = pBuffer + sizeof(int);
    char *nomeapaga = pBuffer + sizeof(int) * 2;

    if (*tamanho > 0){
        printf("Insira o nome que deseja apagar:\n");
        scanf("%s", nomeapaga);
        for (*i = 0; *i < *tamanho; (*i)++){
            if (strcmp(pessoas[*i].nome, nomeapaga) == 0){
                if (*tamanho > 1){
                    for (; *i < (*tamanho - 1); (*i)++){
                        pessoas[*i] = pessoas[*i + 1];
                    }
                }
                (*tamanho)--;
                return;
            }
        }        
    }
    else{
        printf("\nA lista esta vazia\n");
    }
    
    printf("\nNome nao encontrado\n");

    return;
}


int main(){
    void *pBuffer = malloc(sizeof(int) * 2 + sizeof(char) * 10);    // duas ints: tamanho e um numero qualquer para escolha no menu, for e etc, e o nome para apagar, nessa ordem
    *(int *)pBuffer = 0;    // tamanho, inicia em 0

    for (;;){
        printf("Escolha:\n");
        printf("\t1)Inserir nome\n");
        printf("\t2)Listar nomes\n");
        printf("\t3)Apagar nome\n");
        printf("\t4)Sair\n");

        scanf("%d", (int *)(pBuffer + sizeof(int)));
        setbuf(stdin, NULL);

        switch (*(int *)(pBuffer + sizeof(int))){
        case 1:
            insere(pBuffer);
            break;
        
        case 2:
            lista(pBuffer);            
            break;

        case 3:
            apaga(pBuffer);
            break;

        case 4:
            free(pBuffer);
            exit(0);
            break;

        default:
            printf("Digite uma opcao valida");
            break;
        }

    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str;

int menu();
int insereNome(int tamanho);
int deletaNome(int tamanho);
void mostraLista(int tamanho);


int menu(){
    int escolha;

    printf("Escolha:\n");
    printf("\t1)Inserir nome\n");
    printf("\t2)Deletar nome\n");
    printf("\t3)Listar nomes\n");
    printf("\t4)Sair\n");

    scanf("%d", &escolha);
    setbuf(stdin, NULL);

    return escolha;
}


/*  no momento o meu problema eh q preciso verificar se o usuario nao digitou so um '\n' ao inves de um 
    nome de vdd, no momento eu so to ignorando se so foi digitado um '\n'
*/
int insereNome(int tamanho){
    char letra;

    printf("Insira o nome:\n");
   
    if (tamanho == 0){          // se a lista estiver vazia, aloca um espaco pra um caractere
        str = (char * ) malloc(sizeof(char));

        if (str == NULL){
            printf("Erro: falta de memoria\n");
            free(str);
            exit(1);
        }
    }
    else if(tamanho > 0){       // se nao estiver vazia, substitui o '\0' por '#', incrementa tamanho e aloca um espaco para o proximo caractere
        str[tamanho] = '#';     // o '#' eh para identificar onde termina um nome e comeca outro
        tamanho++;
        // str = (char * ) realloc(str, sizeof(char) * (tamanho + 1));
        if (str == NULL){
            printf("Erro: falta de memoria\n");
            free(str);
            exit(1);
        }
    }

    do           // escreve o nome na string, caractere por caractere
    {
        scanf("%c", &letra);

        if (letra != '\n'){
            str = (char*) realloc(str, sizeof(char) * (tamanho + 1));

            if (str == NULL){
                printf("Erro: falta de memoria\n");
                free(str);
                exit(1);
            }

            str[tamanho] = letra;
            tamanho++;
        }
        else{
            printf("Fim da string\n");
        }
    }while ( letra != '\n');

    setbuf(stdin, NULL);
    str[tamanho] = '\0';

    return tamanho;
}


int deletaNome(int tamanho){
    char letra, *deletaNome = (char *) malloc(sizeof(char)), *intermediario = (char *) malloc(sizeof(char));
    int tamanhoDeleta, posStr, tamanhoNome, tamIntermed, posCopianome;
    int i, achouNome = 0;
    
    if (tamanho == 0){
        printf("A lista esta vazia");
        free(deletaNome);
        free(intermediario);
        return tamanho;
    }

    // le o nome que deve ser deletado e escreve ele, caractere por caractere, em uma string especifica para isso
    printf("Insira o nome que deseja deletar:\n");
    do
    {
        tamanhoDeleta = 0;
        scanf("%c", &letra);

        if (letra != '\n'){
            deletaNome = (char * ) realloc(deletaNome, (sizeof(char) * (tamanhoDeleta + 1)));

            if (deletaNome == NULL){
                printf("Erro: falta de memória\n");
                free(deletaNome);
                free(intermediario);
                free(str);
                exit(1);
            }

            deletaNome[tamanhoDeleta] = letra;
            tamanhoDeleta++;
        }
        else{
            printf("Fim da string\n");
        }
    }while (letra != '\n');

    setbuf(stdin, NULL);
    deletaNome[tamanhoDeleta] = '\0';

    /*  minha ideia pra achar a palavra eh: primeiramente pega o tamanho do nome digitado,
        depois procura um nome com o mesmo tamanho e copia para uma string intermediaria,
        e depois compara os caracteres
        senao achar, segue aumentando posStr ate se igualar a tamanho
    */
    // percorrendo a string, posStr eh a posicao no str, tamanhoNome eh o tamanho do nome ate o momento,
    // reseta quando acha um '#', quando tamanhoNome for igual a tamanhoDeleta, checa se o posStr esta
    // em um '#' ou um '\0'


    for (posStr = 0, tamanhoNome = 0; posStr <= tamanho || achouNome == 0 ; posStr++, tamanhoNome++){

        if (tamanhoNome == tamanhoDeleta && (str[posStr] == '#' || str[posStr] == '\0')){

            // achou um nome com tamanho certo, entao copia para uma string intermediaria
            // e compara o intermediario com deletaNome pra ver se os caracteres sao os mesmos
            for (tamIntermed = 0, posCopianome = posStr - tamanhoNome; str[posCopianome] != '#'; tamIntermed++, posCopianome++)
            {
                intermediario = (char * ) realloc(intermediario, (sizeof(char) * (tamIntermed + 1)));

                if (intermediario == NULL){
                    printf("Erro: falta de memória\n");
                    free(deletaNome);
                    free(intermediario);
                    free(str);
                    exit(1);
                }
                intermediario[tamIntermed] = str[posCopianome];
            }
            intermediario[tamIntermed] = '\0';

            // aqui compara as strings
            for(i = 0; intermediario[i] != '\0' && deletaNome[i] != '\0' ; i++){
                if (intermediario[i] == deletaNome[i]){
                    achouNome = 1;
                    break;
                }
            }
        }
        else if (tamanhoNome != tamanhoDeleta && str[posStr] == '#'){
            tamanhoNome = -1;   // eh -1 ao invez de 0 pois vai ser incrementado na proxima iteracao do for
            continue;
        }
        else if (tamanhoNome != tamanhoDeleta && str[posStr] == '\0'){
            printf("Nome nao encontrado\n");
            free(deletaNome);
            free(intermediario);
            return tamanho;
        }
        
    }


    free(deletaNome);
    free(intermediario);
    return tamanho;
}


void mostraLista(int tamanho){
    int i;

    if (tamanho == 0){
        printf("Lista está vazia");
        return;
    }

    for (i = 0; i <= tamanho; i++){
        if(str[i] == '#'){
            printf("\n");
        }
        else{
            printf("%c", str[i]);
        }
    }
    printf("\n");

    return;
}


int main(){
    int escolha, tamanho = 0;

    for(;;){
        escolha = menu();

        switch (escolha){
        case 1:
            tamanho = insereNome(tamanho);
            break;
        
        case 2:
            tamanho = deletaNome(tamanho);
            break;

        case 3:
            mostraLista(tamanho);
            break;

        case 4:
            free(str);
            exit(0);
            break;

        default:
            printf("Digite uma opção válida");
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_def.h"

// NOTA: PROXIMA FUNCAO A FAZER EH O LIST_CLEAR, TODO O RESTO FUNCIONA
// 

Element define_sample(){
    Element sample;
    sample.id = 3;
    strcpy(sample.name, "Soldado 3");
    sample.next = NULL;

    return sample;
}

// list vai sempre apontar pro primeiro elemento da lista
// lista deve ser circular (ultimo elemento aponta p/ o primeiro)
int main()
{
    Element sample = define_sample();

    Element *list = list_create();
    printf("Lista criada: %p\n", list);

    printf("Vazia?: %d\n", list_is_empty(list));

    list_print(list);
    printf("Tamanho: %d\n", list_size(list));

    list = list_insert_start(list, sample);

    list_print(list);
    printf("Tamanho: %d\n", list_size(list));

    list = list_insert_start(list, sample);

    list_print(list);
    printf("Tamanho: %d\n", list_size(list));

    free(list);

    return 0;
}

//printf("%d :: %s :: %p\n", list->id, list->name, list->next); imprime primeiro elemento da lista

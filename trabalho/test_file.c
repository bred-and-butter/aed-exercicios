#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list_def.h"


Element define_sample(){
    Element sample;
    sample.id = rand();
    strcpy(sample.name, "Soldado 3");
    sample.next = NULL;

    return sample;
}

void print_list_and_size(Element *list){
    list_print(list);
    printf("Tamanho: %d\n", list_size(list));

    return;
}

// list vai sempre apontar pro primeiro elemento da lista
// lista deve ser circular (ultimo elemento aponta p/ o primeiro)
int main()
{
    srand(time(NULL));

    Element *list = list_create();
    printf("Lista criada\n");

    printf("Vazia?: %d\n", list_is_empty(list));
    print_list_and_size(list);

    list = list_insert_start(list, define_sample());
    print_list_and_size(list);

    list = list_insert_end(list, define_sample());
    print_list_and_size(list);

    list = list_insert_at(list, define_sample(), 1);
    print_list_and_size(list);

    list = list_insert_at(list, define_sample(), 1);
    print_list_and_size(list);

    list = list_insert_end(list, define_sample());
    print_list_and_size(list);

    list = list_remove_start(list);
    print_list_and_size(list);
/*
    list = list_remove_even(list);
    print_list_and_size(list);
*/
    list = list_remove_highest(list);
    print_list_and_size(list);    

    list = list_remove_at(list, 1);
    print_list_and_size(list);

    list_clear(list);

    return 0;
}

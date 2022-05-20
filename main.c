#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "list_def.h"

unsigned int random_function(unsigned int max, unsigned int min)
{
    return rand() % (max + 1 - min) + min;
}

Element define_soldier(int id)
{
    Element soldier;

    soldier.id = id;
    sprintf(soldier.name, "Soldado %d", id);
    soldier.next = NULL;

    return soldier;
}

Element *fill_list(Element *list, int soldier_amount)
{
    int i;

    for (i = 0; i < soldier_amount; i++)
    {
        list = list_insert_end(list, define_soldier(i));
    }

    return list;
}

Element *begin_removal(Element *list)
{
    int size;
    unsigned int start_position = 0, chosen_position = 0;

    printf("Iniciando remoção de soldados\n");
    for (; list->next != list;)
    {
        size = list_size(list);
        // pega o tamanho da lista, multiplica por list_size * 2 p/ limitar a duas vezes
        // o tamanho maximo da lista, depois arredonda p/ baixo
        chosen_position = floor(random_function(size * 2, 0));

        printf("Numero escolhido: %d\n", chosen_position);
        printf("Posicao inicial: %d\n", start_position);
        printf("Tamanho da lista: %d\n", size);
        if (chosen_position + start_position >= size)
            chosen_position = (chosen_position)-size;
        printf("Posicao resultante: %d\n", chosen_position);

        list = list_remove_at(list, chosen_position);
        start_position = chosen_position;

        list_print(list);
    }

    return list;
}

int main()
{
    srand(time(NULL));
    Element *list;
    int soldier_amount = 0;

    printf("Escolha a quantidade de soldados:\n");
    scanf("%d", &soldier_amount);

    list = list_create();

    printf("Preenchendo lista...\n");
    list = fill_list(list, soldier_amount);

    list_print(list);

    list = begin_removal(list);

    list_clear(list);

    return 0;
}

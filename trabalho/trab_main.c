#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_def.h"

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
    int start_position = 0, count = 0, i;

    for (; list->next == list;)
    {
        // pega o tamanho da lista, multiplica por list_size p/ limitar ao tamanho maximo da lista,
        // depois arredonda p/ baixo, multiplica por 2 e subtrai do tamanho da lista
        //
        count = (2 * (floor(random() * list_size(list)))) - list_size(list);

        for (i = count; ; )
        {
            /* code */
        }
        
    }
    

}

int main()
{
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

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


int main()
{
    Element *list;
    int soldier_amount = 0, i;

    printf("Escolha a quantidade de soldados:\n");
    scanf("%d", &soldier_amount);

    list = list_create();

    for (i = 0; i < soldier_amount; i++)
    {
        list = list_insert_end(list, define_soldier(i + 1));
    }

    list_clear(list);

    return 0;
}

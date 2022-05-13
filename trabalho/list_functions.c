#include <stdio.h>
#include <stdlib.h>
#include "list_def.h"

Element *list_create() // aloca um unico espaco p/ elemento e preenche com NULL
{
    Element *list = (Element *)malloc(sizeof(Element));

    list->id = 0;
    list->name[0] = '(';
    list->next = NULL;

    return list;
}

bool list_is_empty(Element *list)
{
    bool is_empty = (list->id == 0) && (list->name[0] == '(') && (list->next == NULL);

    if (is_empty)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int list_size(Element *list)
{
    Element *list_start = list, *runner;
    int counter = 0;

    if (list_is_empty(list))
    {
        printf("funcao list_size: lista vazia: %p", list);
        return 0;
    }

    for (runner = list_start; runner == list_start; runner = runner->next)
    {
        printf("entrou");
        if (runner == NULL)
        {
            printf("saindo");
            break;
        }
    }
    printf("fora da funcao");
    return 0;
}

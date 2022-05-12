#include <stdio.h>
#include <stdlib.h>
#include "list_def.h"

Element *list_create()  // aloca um unico espaco p/ elemento e preenche com NULL
{
    Element *list = (Element *)malloc(sizeof(Element));

    list = NULL;

    return list;
}

bool list_is_empty(Element *list)
{
    if (list == NULL)
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
    Element *list_start, *runner;

    for (list_start = list; runner == list_start; runner = runner->next)
    {
    }

    return true;
}

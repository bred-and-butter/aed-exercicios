#include <stdio.h>
#include <stdlib.h>
#include "list_def.h"

int main()
{
    Element *list = list_create();
    printf("%p\n", list);

    printf("%d", list_is_empty(list));

    free(list);

    return 0;
}

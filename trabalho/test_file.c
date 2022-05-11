#include <stdio.h>
#include <stdlib.h>
#include "list_def.h"


int main(){
    List *list_pointer = list_create();

    printf("%p\n", list_pointer);

    free(list_pointer);

    return 0;
}

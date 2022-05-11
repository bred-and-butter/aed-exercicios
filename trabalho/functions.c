#include <stdlib.h>
#include "list_def.h"

List *list_create(){
    List *list_pointer = (List*) malloc(sizeof(List));

    return list_pointer;
}


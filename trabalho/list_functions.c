#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_def.h"

Element *list_create() // aloca um unico espaco p/ elemento e preenche com NULL
{
    Element *list = NULL;

    return list;
}

bool list_is_empty(Element *list)
{
    bool is_empty = list==NULL;

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
    Element *runner = list;
    int counter = 0;

    if (list_is_empty(list))
    {
        printf("funcao list_size: lista vazia: %p\n", list);
        return 0;
    }
    
    printf("Contando elementos...\n");
    do
    {
        counter++;
        runner = runner->next;
    } while (runner != list);
    
    return counter;
}


void list_print(Element *list)
{
    Element *runner = list;

    if (list_is_empty(list))
    {
        printf("funcao list_print: lista vazia: %p\n", list);
        return;
    }
    
    printf("Imprimindo lista:\n");
    do
    {
        printf("%d :: %s :: %p\n", runner->id, runner->name, runner->next);
        runner = runner->next;
    } while (runner != list);
    
    return;
}

/*
void list_clear(Element *list)
{
    Element *runner = list, *next;

    if (list_is_empty(list))
    {
        printf("funcao list_clear: lista ja esta vazia: %p\n", list);
        return;
    }

    do
    {
        //code
    } while (next != NULL);
    
}
*/

Element *list_insert_start(Element *list, Element element)
{
    Element *new = (Element*) malloc(sizeof(Element));
    Element *last;

    new->id = element.id;
    strcpy(new->name, element.name);

    //checa se a lista ta vazia, se sim o novo elemento aponta pra ele mesmo, senao
    //percorre toda a lista ate o elemento apontar p/ o comeco oq significa que chegou no final
    if (list_is_empty(list))
        new->next = new;
    else
    {
        new->next = list;
        last = list;
        
        while (last->next != list)
            last = last->next;

        last->next = new;
    }

    return new;
}

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

    printf("Checando se lista esta vazia\n");
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


void list_clear(Element *list)
{
    Element *runner = list, *next = list;

    if (list_is_empty(list))
    {
        printf("funcao list_clear: lista ja esta vazia: %p\n", list);
        return;
    }

    printf("Limpando lista...\n");
    do
    {
        runner = next;
        next = runner->next;
        free(runner);
    } while (next != list);

    printf("Sucesso\n");
    return;
}


Element *list_insert_start(Element *list, Element element)
{
    Element *new = (Element*) malloc(sizeof(Element));
    Element *last;

    new->id = element.id;
    strcpy(new->name, element.name);

    //checa se a lista ta vazia, se sim o novo elemento aponta pra ele mesmo, senao
    //percorre toda a lista ate o elemento apontar p/ o comeco oq significa que chegou no final
    printf("Inserindo elemento no comeco da lista...\n");
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

    printf("Sucesso\n");
    return new;
}


Element *list_insert_at(Element *list, Element element, int position)
{
    Element *new = (Element*) malloc(sizeof(Element));
    Element *runner;
    int counter = 0;

    new->id = element.id;
    strcpy(new->name, element.name);

    printf("Inserindo elemento na posicao %d...\n", position);
    if (list_is_empty(list))
    {
        printf("Lista vazia, inserindo na posicao 0...\n");
        new->next = new;
    }
    else
    {
        runner = list;
        
        do
        {
            if (counter < position)
            {
                /* code */
            }
            
            runner = runner->next;
            counter++;
        } while ((runner->next != list) && (counter < position));

        runner->next = new;
        
    }

    printf("Sucesso\n");
    return list;    
}

Element *list_insert_end(Element *list, Element element)
{
    Element *new = (Element*) malloc(sizeof(Element));
    Element *last;

    new->id = element.id;
    strcpy(new->name, element.name);

    //checa se a lista ta vazia, se sim o novo elemento aponta pra ele mesmo, senao
    //percorre toda a lista ate o elemento apontar p/ o comeco oq significa que chegou no final
    printf("Inserindo elemento no fim da lista...\n");
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

    printf("Sucesso\n");
    return list;    
}

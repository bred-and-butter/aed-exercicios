#include <stdbool.h>

#ifndef struct_list_definition
#define struct_list_definition

typedef struct Element
{
    int id;
    char name[30];
    struct Element *next;
} Element;

#endif

#ifndef struct_list_operations
#define struct_list_operations

Element *list_create();

bool list_is_empty(Element *list);

int list_size(Element *list);

bool list_clear(Element *list);

Element *list_print(Element *list);

Element *list_insert_start(Element *list, Element element);

Element *list_insert_at(Element *list, Element element, int position);

Element *list_insert_end(Element *list, Element element);

Element *list_remove_start(Element *list);

Element *list_remove_at(Element *list, int position);

Element *list_remove_highest(Element *list);

Element *list_remove_even(Element *list);

Element *list_order_selection_sort(Element *list);

Element *list_order_quick_sort(Element *list);

#endif

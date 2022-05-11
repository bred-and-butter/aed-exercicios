#include <stdbool.h>

#ifndef struct_list_definition
#define struct_list_definition

typedef struct List
{
    int id;
    char name[30];
    struct List *next;
} List;

#endif

#ifndef struct_list_operations
#define struct_list_operations

List *list_create();

bool list_is_empty(List *list_pointer);

void list_destroy(List *list_pointer);

List *list_insert_start(List *list_pointer, List element);

List *list_insert_at(List *list_pointer, List element, int position);

List *list_insert_end(List *list_pointer, List element);

List *list_remove_start(List *list_pointer);

List *list_remove_at(List *list_pointer, int position);

List *list_remove_highest(List *list_pointer);

List *list_remove_even(List *list_pointer);

int list_size(List *list_pointer);

bool list_clear(List *list_pointer);

List *list_print(List *list_pointer);

List *list_order_selection_sort(List *list_pointer);

List *list_order_quick_sort(List *list_pointer);

#endif

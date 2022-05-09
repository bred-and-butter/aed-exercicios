#ifndef struct_lista_definition
#define struct_lista_definition

typedef struct List{
    int id;
    char name[30];
    List *next;
} List ;

#endif

// todo: definir o resto dos parametros dos prototipos de funcoes
#ifndef struct_lista_operations
#define struct_lista_operations

List* list_create();

void list_destroy(List* list_pointer);

List* list_insert(List* list_pointer);

List* list_remove(List* list_pointer);

int list_empty(List* list_pointer);

List* list_get(List* list_pointer);

List* list_print(List* list_pointer);

#endif
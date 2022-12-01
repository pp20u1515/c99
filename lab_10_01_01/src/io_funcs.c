#include "io_funcs.h"
#include "return_codes.h"
#include "list_func.h"

size_t read_file(node_t **head, const char *file_name)
{
    node_t *node = NULL; // Структура узела, которого нужно добавить в список
    FILE *f_open = fopen(file_name, "r");
    size_t rc = OK; // код возврата
    int number; // номер посылки
    double weight; // весь посылки

    if (f_open)
    {
        while (fscanf(f_open, "%d%lf", &number, &weight) == 2)
        {
            node = create_node(number, weight);
            *head = push(*head, node);
        }
        
        if (*head == NULL)
            rc = DATA_ERROR;
            
        fclose(f_open);
    }
    else
        rc = FOPEN_ERROR;

    return rc;
}

void print_result(node_t **list, const char *file_name)
{
    node_t *temp_list = *list;
    FILE *f_write = fopen(file_name, "w");

    while (temp_list)
    {
        fprintf(f_write, "%d\n%lf\n", ((package_t *)(temp_list->data))->number, ((package_t *)(temp_list->data))->weight);
        temp_list = temp_list->next;
    }
    fclose(f_write);
}
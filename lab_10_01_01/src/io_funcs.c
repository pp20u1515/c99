#include "io_funcs.h"
#include "return_codes.h"
#include "list_func.h"

node_t *read_package(FILE *f_open)
{
    node_t *node = NULL; // Структура узела, которого нужно добавить в список
    node_t *temp_list = NULL; // Вспомагательный список
    int number = 0; // номер посылки
    double weight = 0.0; // весь посылки

    while (fscanf(f_open, "%d%lf", &number, &weight) == 2)
    {
        node = create_node(number, weight);

        if (node)
            temp_list = push(temp_list, node);
    }
    return temp_list;
}

size_t read_file(node_t **head, const char *file_name)
{
    FILE *f_open = fopen(file_name, "r");
    size_t rc = OK; // код возврата

    if (f_open)
    {
        *head = read_package(f_open);
        
        if (*head == NULL)
            rc = DATA_ERROR;
            
        fclose(f_open);
    }
    else
        rc = FOPEN_ERROR;

    return rc;
}

void print_info_package(const int num, const double weight, FILE *f_write)
{
    fprintf(f_write, "%d\n%.6lf\n", num, weight);
}

void print_result(node_t *list, const char *file_name)
{
    node_t *temp_list = list;
    FILE *f_write = fopen(file_name, "w");

    while (temp_list)
    {
        print_info_package(((package_t *)(temp_list->data))->number, ((package_t *)(temp_list->data))->weight, f_write);
        temp_list = temp_list->next;
    }
    fclose(f_write);
}
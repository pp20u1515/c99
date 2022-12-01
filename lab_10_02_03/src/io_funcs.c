#include "../inc/io_funcs.h"

#include <string.h>

void free_node(node_t *node)
{
    free(node);
}

void free_list(list_t *list)
{
    while (list->head)
        pop_front(list);
    
    free(list);
}

void display_list(const list_t *list)
{
    for (node_t *node = list->head; node; node = node->next)
        printf("%d ", node->data);
    puts("L");
}

error_t get_numbers(int *arr, const size_t count)
{
    for (size_t i = 0; i < count; i++)
        if (fscanf(stdin, "%d", (arr + i)) != 1 || *(arr + i) <= 0)
            return error;
    return ok;
}

p_mode get_mode(FILE *stream)
{
    char buf[256];
    p_mode mode;

    fscanf(stream, "%s", buf);
    if (strcmp(buf, "out") == 0)
        mode = out;
    else if (strcmp(buf, "mul") == 0)
        mode = mul;
    else if (strcmp(buf, "div") == 0)
        mode = dev;
    else if (strcmp(buf, "sqr") == 0)
        mode = sqr;
    else
        mode = none;
    return mode;
}
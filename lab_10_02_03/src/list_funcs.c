#include "list_funcs.h"
#include "additional_funcs.h"

#include <stdlib.h>

#define NOT_PRIME 0

node_t *create_node(const size_t num)
{
    node_t *node = malloc(sizeof(node_t));

    if (node)
    {
        node->data = num;
        node->next = NULL;
    }
    return node;
}

node_t *push(node_t *head, node_t *node)
{
    node_t *temp_head = NULL;

    if (head)
    {
        temp_head = head;
        
        for (; temp_head->next; temp_head = temp_head->next);

        temp_head->next = node;
    }
    else
        return node;

    return head;
}

node_t *create_list(size_t num)
{
    size_t degree = 2, count = 0; // count_dividers
    node_t *temp_list = NULL; // Структура списка
    node_t *node = NULL; // Структура одного узла

    while (degree <= num)
    {
        count = count_dividers(&num, degree);
    
        if (count || count == 0)
        {
            node = create_node(count);

            if (node)
                temp_list = push(temp_list, node);
        }
        while (is_prime(++degree) == NOT_PRIME);
    }
    return temp_list;
}

void free_list(node_t **head)
{
    node_t *temp_head = NULL;

    while (*head)
    {
        temp_head = (*head)->next;
        free(*head);
        *head = temp_head;
    }
}
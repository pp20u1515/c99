#include "../inc/list_funcs.h"

node_t *init_node(data_t val)
{
    node_t *temp = malloc(sizeof(node_t));

    if (temp)
    {
        temp->data = val;
        temp->next = NULL;
    }
    return temp;
}

list_t *init_list(node_t *head, node_t *tail)
{
    list_t *list = malloc(sizeof(list_t));

    if (list)
    {
        list->head = head;
        list->tail = tail;
    }
    return list;
}

error_t push_back(list_t *list, node_t *new_node)
{
    if (new_node == NULL)
        return error;

    if (list->head == NULL)
        list->head = list->tail = new_node;
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    return ok;
}

void pop_front(list_t *list)
{
    node_t *temp = list->head;
    
    list->head = list->head->next;
    free_node(temp);
}
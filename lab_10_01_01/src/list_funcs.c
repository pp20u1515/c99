#include "return_codes.h"
#include "list_func.h"

#include <stdio.h>
#include <stdlib.h>

node_t *create_node(const int number, const double weight)
{
    package_t *package = NULL;
    node_t *node = NULL;
    
    package = malloc(sizeof(package_t));

    if (package)
    {
        node = malloc(sizeof(node_t));

        if (node)
        {
            package->number = number;
            package->weight = weight;

            node->data = (void *)package;
            node->next = NULL;
        }
        else
            free(package);
    }
    
    return node;
}

node_t *push(node_t *head, node_t *node)
{
    if (head != NULL)
    {
        node_t *temp_head = head;

        for (; temp_head->next; temp_head = temp_head->next);

        temp_head->next = node;
    }
    else
        return node;

    return head;
}

void *pop_front(node_t **head)
{
    void *temp_data = NULL;

    if (head && *head && (*head)->data)
    {
        temp_data = (*head)->data;
        *head = (*head)->next;
    }

    return temp_data;
}

void *pop_end(node_t **head)
{
    node_t *temp_list = NULL, *prev_list = NULL;
    void *temp_data = NULL;

    if (*head != NULL)
    {
        temp_list = *head;
        
        for (; temp_list->next; temp_list = temp_list->next)
            prev_list = temp_list;

        temp_data = temp_list;

        if (prev_list)
            prev_list->next = temp_list->next;
        else
            *head = temp_list->next;
    }

    return temp_data;
}

node_t *reverse(node_t *head)
{
    node_t *temp_head = NULL, *next_node = NULL;

    while (head)
    {
        next_node = head->next;
        head->next = temp_head;
        temp_head = head;
        head = next_node;
    }
    return temp_head;
}

void front_back_split(node_t *head, node_t **back)
{
    if (head && back)
    {
        node_t *temp_head = head;

        for (; head->next && head->next->next;)
        {
            temp_head = temp_head->next;
            head = head->next->next;
        }
        *back = temp_head->next;
        temp_head->next = NULL;
    }
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *temp_head = NULL, *buff = NULL; 
    
    if (head_a && head_b && comparator)
    {
        if (*head_a || *head_b)
        {
            if (*head_b == NULL || (*head_a && comparator((*head_a)->data, (*head_b)->data) < 0))
            {
                temp_head = *head_a;
                buff = temp_head;
                *head_a = (*head_a)->next;
            }
            else if (*head_b)
            {
                temp_head = *head_b;
                buff = temp_head;
                *head_b = (*head_b)->next;
            }
        }
        
        while (*head_a && *head_b)
        {
            if (comparator((*head_a)->data, (*head_b)->data) < 0)
            {
                buff->next = *head_a;
                buff = buff->next;
                *head_a = (*head_a)->next;
            }
            else
            {
                buff->next = *head_b;
                buff = buff->next;
                *head_b = (*head_b)->next;
            }
        }
        while (*head_a)
        {
            buff->next = *head_a;
            buff = buff->next;
            *head_a = (*head_a)->next;
        }
        while (*head_b)
        {
            buff->next = *head_b;
            buff = buff->next;
            *head_b = (*head_b)->next;
        }
    }

    return temp_head;
}

int compare_packages(const void *a, const void *b)
{
    return ((package_t *)a)->weight - ((package_t *)b)->weight > 0 ? 1 : -1; 
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *first_sorted = NULL, *second_sorted = NULL;
    node_t *back = NULL, *new_head = NULL;

    if (head && head->next && comparator)
    {
        front_back_split(head, &back);
        first_sorted = sort(head, comparator);
        second_sorted = sort(back, comparator);
        new_head = sorted_merge(&first_sorted, &second_sorted, comparator);
    }
    else
        new_head = head;

    return new_head;
}

void free_list(node_t **head)
{
    node_t *temp_head = NULL;
    
    while (*head)
    {
        temp_head = (*head)->next;
        free((*head)->data);
        free(*head);
        *head = temp_head;
    }
    (*head) = NULL;
}
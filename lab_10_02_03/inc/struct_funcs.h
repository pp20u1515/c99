#ifndef STRUCT_FUNCS_H
#define STRUCT_FUNCS_H

typedef int data_t;

typedef struct node
{
    data_t data;
    struct node *next;
} node_t;

typedef struct list
{
    node_t *head;
    node_t *tail;   
} list_t;

#endif
#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include "../inc/return_codes.h"
#include "../inc/struct_funcs.h"
#include "../inc/list_funcs.h"
#include "../inc/additional_funcs.h"
#include "../inc/io_funcs.h"

#include <stdio.h>

node_t *init_node(data_t val);
list_t *init_list(node_t *head, node_t *tail);
error_t push_back(list_t *list, node_t *new_node);
void pop_front(list_t *list);

#endif

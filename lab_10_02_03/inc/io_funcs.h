#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <stdio.h>

#include "../inc/return_codes.h"
#include "../inc/struct_funcs.h"
#include "../inc/list_funcs.h"
#include "../inc/additional_funcs.h"

void free_node(node_t *node);
void free_list(list_t *list);
void display_list(const list_t *list);
p_mode get_mode(FILE *stream);
error_t get_numbers(int *arr, const size_t count);

#endif
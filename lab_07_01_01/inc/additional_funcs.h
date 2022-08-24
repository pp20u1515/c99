#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H

#include "struct.h"

int compar(const void *first_value, const void *sec_value);
void mysort(void *base, size_t nbase, size_t size, int (*compar)(const void *, const void *));
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void filter(const arr_t arr, arr_t result, const char *filer);
void fill_new_arr(const int *pb_src, const int min_index, const int *pe_src, int **pe_dst);

#endif
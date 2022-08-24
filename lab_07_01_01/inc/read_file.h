#ifndef READ_FILE_H
#define READ_FILE_H

#include "struct.h"

#include <stdio.h>

int count_elems(FILE *f_open);
int fill_array(int *temp_arr, arr_t *arr, FILE *f_open);
int *create_array(arr_t *arr, FILE *f_open);
int read_file(arr_t *arr, FILE *f_open);

#endif
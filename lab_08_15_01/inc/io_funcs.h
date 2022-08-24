#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include "struct.h"

#include <stdio.h>

int read_matrix(matrix_t *matrix, FILE *f_open);
int read_file(matrix_t *matrix, FILE *f_open);
void print_matrix(matrix_t matrix);

#endif
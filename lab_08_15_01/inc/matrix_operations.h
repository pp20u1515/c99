#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "struct.h"

#include <stdio.h>

void matrix_default(matrix_t *matrix);
void free_matrix(double **data, const int size_of_rows);
double **allocate_matrix(const matrix_t *matrix);
int fill_matrix(matrix_t *matrix, FILE *f_open);
void sum(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result);
int sum_matrix(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result);
void fill_single_matrix(double **data, const matrix_t *matrix);
void multiply(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result);
int mult_matrix(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result);
int inversion(const matrix_t *matrix);

#endif
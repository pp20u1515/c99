#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>

typedef struct matrix_t
{
    double **data; // матрица
    size_t rows; // количество строк матрицы
    size_t columns; // количество столбцов матрицы
}matrix_t;

#endif // STRUCT_H
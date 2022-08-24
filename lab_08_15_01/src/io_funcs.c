#include "../inc/io_funcs.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"
#include "../inc/matrix_operations.h"

#include <stdio.h>
#include <stdlib.h>

int read_matrix(matrix_t *matrix, FILE *f_open)
{
    int rc = OK;

    if (fscanf(f_open, "%d %d\n", &matrix->n, &matrix->m) == 2)
    {
        matrix->data = allocate_matrix(matrix);

        if (matrix->data)
            rc = fill_matrix(matrix, f_open);
        else
            rc = ALLOCATE_ERROR;  
    }
    else 
        rc = DATA_ERROR;

    return rc;
}

int read_file(matrix_t *matrix, FILE *f_open)
{
    matrix_default(matrix);
    
    int rc = OK;

    rc = read_matrix(matrix, f_open);
    
    return rc;
}

void print_matrix(matrix_t matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {    
        for (int j = 0; j < matrix.n; j++)
            printf("%lf ", matrix.data[i][j]);

        printf("\n");
    }
}
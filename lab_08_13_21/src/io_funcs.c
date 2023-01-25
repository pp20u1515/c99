#include "io_funcs.h"
#include "return_codes.h"
#include "struct.h"
#include "matrix_operations.h"

#define EPS 0.00000001

int read_dimension(matrix_t *matrix, FILE *f_open, size_t *number_nonzero_elems)
{
    int rc = OK;

    if (fscanf(f_open, "%zu", &matrix->rows) == 1 && matrix->rows > 0)
    {
        if (fscanf(f_open, "%zu", &matrix->columns) == 1 && matrix->columns > 0)
        {
            if (fscanf(f_open, "%zu", number_nonzero_elems) != 1 || *number_nonzero_elems > matrix->rows * matrix->columns)
                rc = DIMENSIONS_ERROR;
        }
        else
            rc = DIMENSIONS_ERROR;
    }
    else
        rc = DIMENSIONS_ERROR;

    return rc;        
}

int read_data(matrix_t *matrix, FILE *f_open, const size_t *number_nonzero_elems)
{
    int rc = OK; // код возврата
    size_t temp_row, temp_column; // временная строка, и временный столбец
    
    for (size_t index_i = 0; rc == OK && index_i < *number_nonzero_elems; index_i++)
    {
        if (fscanf(f_open, "%zu%zu", &temp_row, &temp_column) == 2 && temp_row <= matrix->rows && temp_row > 0 && temp_column <= matrix->columns && temp_column > 0)
        {
            if (fscanf(f_open, "%lf", &matrix->data[temp_row - 1][temp_column - 1]) != 1)
                rc = DATA_ERROR;
        }
        else
            rc = DATA_ERROR;
    }
    
    return rc;
}

int read_matrix(matrix_t *matrix, FILE *f_open, size_t *number_nonzero_elems)
{
    int rc = read_dimension(matrix, f_open, number_nonzero_elems);
    
    if (rc == OK)
    {
        matrix->data = allocate_matrix(matrix->rows, matrix->columns);

        if (matrix->data)
        {
            rc = read_data(matrix, f_open, number_nonzero_elems);
            
            if (rc != OK)
                free_matrix(matrix->data, matrix->rows);
        }
        else
            rc = ALLOCATE_ERROR;
    }

    return rc;
}

void print_matrix(const matrix_t matrix, FILE *f_output)
{
    fprintf(f_output, "%zu %zu\n", matrix.rows, matrix.columns);
    
    for (size_t index_i = 0; index_i < matrix.rows; index_i++)
    {
        for (size_t index_j = 0; index_j < matrix.columns; index_j++)
            fprintf(f_output, "%.6lf ", matrix.data[index_i][index_j]);
    
        fprintf(f_output, "\n");
    }
}

#include "../inc/matrix_operations.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"
#include "../inc/io_funcs.h"

#include <stdlib.h>
#include <stdio.h>

#define ERROR 1

void free_matrix(double **data, const size_t rows)
{
    for (size_t index = 0; index < rows; index++)
        free(data[index]);

    free(data);
}

double **allocate_matrix(const size_t rows, const size_t columns)
{
    size_t flag = OK;

    double **data = calloc(rows, sizeof(double *));

    if (data)
    {
        for (size_t index = 0; flag == OK && index < rows; index++)
        {
            data[index] = calloc(columns, sizeof(double));

            if (data[index] == NULL)
            {
                flag = ERROR;
                free_matrix(data, rows);
                data = NULL;
            }
        }
    }
    return data;
}

int sum(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result)
{
    int rc = OK; // код возврата
    
    result->rows = first_matrix->rows;
    result->columns = first_matrix->columns;
    
    result->data = allocate_matrix(result->rows, result->columns);

    if (result->data)
        for (size_t index_i = 0; index_i < first_matrix->rows; index_i++)
            for (size_t index_j = 0; index_j < first_matrix->columns; index_j++)
                result->data[index_i][index_j] = first_matrix->data[index_i][index_j] + second_matrix->data[index_i][index_j];
    else
        rc = ALLOCATE_ERROR;

    return rc;
}

int sum_matrix(matrix_t *first_matrix, matrix_t *second_matrix, matrix_t *result, const char *first_file_name, const char *second_file_name, size_t *first_nonzero_elems, size_t *second_nonzero_elems)
{
    FILE *first_file = fopen(first_file_name, "r"); // готовые данные для первой матрицы
    FILE *second_file = fopen(second_file_name, "r"); // готовые данные для второй матрицы
    int rc = OK; // код возврата

    if (first_file && second_file)
    {
        rc = read_matrix(first_matrix, first_file, first_nonzero_elems);
        
        if (rc == OK)
        {
            rc = read_matrix(second_matrix, second_file, second_nonzero_elems);

            if (rc == OK && first_matrix->rows == second_matrix->rows && first_matrix->columns == second_matrix->columns)
            {    
                rc = sum(first_matrix, second_matrix, result);

                free_matrix(second_matrix->data, second_matrix->rows);
                free_matrix(first_matrix->data, first_matrix->rows);
            }
            else if (rc == OK && (first_matrix->rows != second_matrix->rows || first_matrix->columns != second_matrix->columns))
            {
                rc = DIMENSIONS_ERROR;
                free_matrix(first_matrix->data, first_matrix->rows);
                free_matrix(second_matrix->data, second_matrix->rows);
            }
            else
                free_matrix(first_matrix->data, first_matrix->rows);
        }
        fclose(first_file);
        fclose(second_file);
    }
    else
        rc = FOPEN_ERROR;

    return rc;
}

int multiply(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result)
{
    double data = 0.0;

    result->rows = first_matrix->rows;
    result->columns = second_matrix->columns;
    result->data = allocate_matrix(result->rows, result->columns);

    if (result->data == NULL)
        return ALLOCATE_ERROR;
    
    for (size_t index_i = 0; index_i < first_matrix->rows; index_i++)
    {
        for (size_t index_j = 0; index_j < second_matrix->columns; index_j++)
        {
            for (size_t index_k = 0; index_k < first_matrix->columns; index_k++)
            {
                data += first_matrix->data[index_i][index_k] * second_matrix->data[index_k][index_j];
            }
            
            result->data[index_i][index_j] = data;
            data = 0;
        }
    }
    return OK;
}

int multiply_matrix(matrix_t *first_matrix, matrix_t *second_matrix, matrix_t *result, const char *first_file_name, const char *second_file_name, size_t *first_nonzero_elems, size_t *second_nonzero_elems)
{
    FILE *first_file = fopen(first_file_name, "r");
    FILE *second_file = fopen(second_file_name, "r");
    int rc = OK; // код возврата

    if (first_file && second_file)
    {
        rc = read_matrix(first_matrix, first_file, first_nonzero_elems);
        
        if (rc == OK)
        {
            rc = read_matrix(second_matrix, second_file, second_nonzero_elems);
            
            if (rc == OK && first_matrix->columns == second_matrix->rows)
            {
                rc = multiply(first_matrix, second_matrix, result);

                free_matrix(second_matrix->data, second_matrix->rows);
                free_matrix(first_matrix->data, first_matrix->rows);
            }
            else if (rc == OK && first_matrix->columns != second_matrix->rows)
            {
                rc = DIMENSIONS_ERROR;
                free_matrix(second_matrix->data, second_matrix->rows);
                free_matrix(first_matrix->data, first_matrix->rows);
            }
            else
                free_matrix(first_matrix->data, first_matrix->rows);
        }
        fclose(first_file);
        fclose(second_file);
    }
    else
        rc = FOPEN_ERROR;

    return rc;
}

void delete_matrix_row(matrix_t *matrix, const size_t row)
{
    free(matrix->data[row]);

    for (size_t index = row; index < matrix->rows - 1; index++)
        matrix->data[index] = matrix->data[index + 1];

    matrix->rows--;
}

void delete_matrix_col(matrix_t *matrix, const size_t column)
{
    for (size_t index_i = 0; index_i < matrix->rows; index_i++)
    {
        for (size_t index_j = column; index_j < matrix->columns - 1; index_j++)
            matrix->data[index_i][index_j] = matrix->data[index_i][index_j + 1];

        matrix->data[index_i] = realloc(matrix->data[index_i], sizeof(double) * matrix->columns - 1);
    }

    matrix->columns--;
}

void matrix_cpy(matrix_t *temp_matrix, const matrix_t *matrix)
{
    temp_matrix->rows = matrix->rows;
    temp_matrix->columns = matrix->columns;

    for (size_t index_i = 0; index_i < matrix->rows; index_i++)
        for (size_t index_j = 0; index_j < matrix->columns; index_j++)
            temp_matrix->data[index_i][index_j] = matrix->data[index_i][index_j];
}

int matrix_det(const matrix_t *matrix, double *determ)
{
    if (matrix->rows != matrix->columns)
        return DIMENSIONS_ERROR;

    if (matrix->rows == 1)
    {
        *determ = matrix->data[0][0];
        return OK;
    }

    double result = 0.0;
    int sign = 1;

    for (size_t index_i = 0; index_i < matrix->rows; index_i++)
    {
        matrix_t temp_matrix;
        temp_matrix.data = allocate_matrix(matrix->rows, matrix->columns);

        if (temp_matrix.data == NULL)
        {
            return ALLOCATE_ERROR;
        }

        matrix_cpy(&temp_matrix, matrix);
        delete_matrix_row(&temp_matrix, 0);
        delete_matrix_col(&temp_matrix, index_i);

        double temp_det;

        if (matrix_det(&temp_matrix, &temp_det) != OK)
        {
            free_matrix(temp_matrix.data, temp_matrix.rows);
            return DATA_ERROR;
        }
        result += temp_det * matrix->data[0][index_i] * sign;
        free_matrix(temp_matrix.data, temp_matrix.rows);
        sign *= -1;
    }

    *determ = result;

    return OK;
}

int find_determ(const char *file_name, matrix_t *matrix, double *determ, size_t *number_nonzero_elems)
{
    int rc = OK; // код возврата
    FILE *f_open = fopen(file_name, "r");

    if (f_open)
    {
        rc = read_matrix(matrix, f_open, number_nonzero_elems);
        
        if (rc == OK)
        {
            rc = matrix_det(matrix, determ);

            free_matrix(matrix->data, matrix->rows);
        }

        fclose(f_open);
    }
    else
        rc = FOPEN_ERROR;

    return rc;
}

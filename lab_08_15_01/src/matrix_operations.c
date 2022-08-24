#include "../inc/matrix_operations.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"

#include <stdio.h>
#include <stdlib.h>

void matrix_default(matrix_t *matrix)
{
    matrix->data = NULL;
    matrix->m = 0;
    matrix->n = 0;
}

void free_matrix(double **data, const int size_of_rows)
{
    for (int i = 0; i < size_of_rows; i++)
        free(data[i]);

    free(data);
}

double **allocate_matrix(const matrix_t *matrix)
{
    double **data = malloc(matrix->n * sizeof(int));

    if (data)
        for (int i = 0; i < matrix->n; i++)
        {
            data[i] = malloc(matrix->m * sizeof(int));

            if (data[i] == NULL)
            {
                free_matrix(data, matrix->n);
                return NULL;
            }
        }

    return data;
}

int fill_matrix(matrix_t *matrix, FILE *f_open)
{
    int rc = OK;
    
    for (int i = 0; rc == OK && i < matrix->n; i++)
        for (int j = 0; rc == OK && j < matrix->m; j++)
            if (fscanf(f_open, "%lf", &matrix->data[i][j]) != 1)
                rc = DATA_ERROR;

    return rc;
}

void sum(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result)
{
    for (int i = 0; i < first_matrix->n; i++)
        for (int j = 0; j < first_matrix->m; j++)
            result->data[i][j] = first_matrix->data[i][j] + second_matrix->data[i][j]; 
}

int sum_matrix(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result)
{
    int rc = OK;

    if (first_matrix->n == second_matrix->n && first_matrix->m == second_matrix->m)
    {
        result->n = first_matrix->n;
        result->m = first_matrix->m;
        result->data = allocate_matrix(first_matrix);

        if (result->data)
            sum(first_matrix, second_matrix, result);
    }
    else
        rc = DIMENSION_ERROR;

    return rc; 
}

void multiply(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result)
{
    for (int i = 0; i < first_matrix->n; i++)
        for (int j = 0; j < first_matrix->m; j++)
        {
            double data = 0;

            for (int k = 0; k < first_matrix->m; k++)
                data += first_matrix->data[k][j] * second_matrix->data[k][j];

            result->data[i][j] = data;
        }
}

int mult_matrix(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result)
{
    int rc = OK;

    if (first_matrix->n == second_matrix->n && first_matrix->m == second_matrix->m)
    {
        result->n = first_matrix->n;
        result->m = first_matrix->m;
        result->data = allocate_matrix(first_matrix);

        if (result->data)
            multiply(first_matrix, second_matrix, result);
    }
    else 
        rc = DIMENSION_ERROR;

    return rc;
}

void fill_single_matrix(double **data, const matrix_t *matrix)
{
    for (int i = 0; i < matrix->n; i++)
        for (int j = 0; j < matrix->m; j++)
        {
            data[i][j] = 0.0;

            if (i == j)
                data[i][j] = 1.0;
        }
}

int inversion(const matrix_t *matrix)
{
    double **data = allocate_matrix(matrix);
    double temp;
    int rc = OK;

    if (data)
    {
        fill_single_matrix(data, matrix);
        
        for (int i = 0; i < matrix->n; i++)
        {
            temp = matrix->data[i][i];
            
            for (int j = 0; j < matrix->m; j++)
            {
                matrix->data[i][j] /= temp;
                data[i][j] /= temp;
            }

            for (int k = i + 1; k < matrix->n; k++)
            {
                temp = matrix->data[k][i];
                
                for (int m = 0; m < matrix->m; m++)
                {
                    matrix->data[k][m] -= matrix->data[i][m] * temp;
                    data[k][m] -= data[i][m] * temp;
                }
            }
        }

        for (int i = matrix->n - 1; i > 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                temp = matrix->data[j][i];

                for (int k = 0; k < matrix->n; k++)
                {
                    matrix->data[j][k] -= matrix->data[i][k] * temp;
                    data[j][k] -= matrix->data[i][k] * temp;
                }
            }
        }

        for (int i = 0; i < matrix->n; i++)
            for (int j = 0; j < matrix->m; j++)
                matrix->data[i][j] = data[i][j];
    }
    else
        rc = ALLOCATE_ERROR;

    return rc;
}
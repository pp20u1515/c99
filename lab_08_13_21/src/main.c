#include "struct.h"
#include "io_funcs.h"
#include "return_codes.h"
#include "matrix_operations.h"

#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 4 && argc != 5)
        return ARGS_ERROR;
    
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матрицы и результирующей м
    size_t first_nonzero_elems, second_nonzero_elems; // количество ненулевых элементов первой и второй матрицы
    int rc = OK; // код возврата
    
    if (argc == 4 && strcmp(argv[1], "o") == 0)
    {
        FILE *f_output = fopen(argv[3], "w"); // файл для записи  результата
        double determ = 0.0; // детерминанта матрицы
        
        if (f_output != NULL)
        {
            rc = find_determ(argv[2], &first_matrix, &determ, &first_nonzero_elems);
            
            if (rc == OK)
            {
                fprintf(f_output, "%.6lf\n", determ);
            }
            fclose(f_output);
        }
        else
            rc = FOPEN_ERROR;
    }
    else
    {
        if (argc == 4 && strcmp(argv[1], "o") != 0)
            rc = ARGS_ERROR;
    }
    
    if (rc == OK && argc == 5)
    {
        FILE *f_output = fopen(argv[4], "w");

        if (f_output && strcmp(argv[1], "a") == 0)
        {
            rc = sum_matrix(&first_matrix, &second_matrix, &result, argv[2], argv[3], &first_nonzero_elems, &second_nonzero_elems);

            if (rc == OK)
            {
                print_matrix(result, f_output);
                free_matrix(result.data, result.rows);
            }
        }
        else if (f_output && strcmp(argv[1], "m") == 0)
        {
            rc = multiply_matrix(&first_matrix, &second_matrix, &result, argv[2], argv[3], &first_nonzero_elems, &second_nonzero_elems);
            
            if (rc == OK)
            {
                print_matrix(result, f_output);
                free_matrix(result.data, result.rows);
            }
        }
        else 
            rc = ARGS_ERROR;
    
        if (f_output)
            fclose(f_output);
        else
            rc = FOPEN_ERROR;
    }
    
    return rc;
}

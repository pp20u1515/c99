#include "../inc/return_codes.h"
#include "../inc/struct.h"
#include "../inc/io_funcs.h"
#include "../inc/matrix_operations.h"

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    
    int rc = OK;
    //printf("argc == %d\n", argc);
    if (argc == 5)
    {
        FILE *f_open = fopen(argv[2], "r");
        matrix_t first_matrix, second_matrix, result;

        if (f_open)
        {
            rc = read_file(&first_matrix, f_open);

            fclose(f_open);
        }
        else
            rc = FOPEN_ERROR;

        if (rc == OK)
        {
            f_open = fopen(argv[3], "r");

            if (f_open)
            {
                rc = read_file(&second_matrix, f_open);

                fclose(f_open);
            }
            else
                rc = FOPEN_ERROR;
        }

        if (rc == OK && strcmp(argv[1], "a") == 0)
        {
            rc = sum_matrix(&first_matrix, &second_matrix, &result);
            
            if (rc == OK)
                print_matrix(result);
        }
        else if (rc == OK && strcmp(argv[1], "m") == 0)
        {
            rc = mult_matrix(&first_matrix, &second_matrix, &result);
            
            if (rc == OK)
                print_matrix(result);
        }
        else 
            rc = ARGS_ERROR;

    }
    else if (argc == 4)
    {
        FILE *f_open = fopen(argv[2], "r");
        matrix_t matrix;

        if (f_open)
        {
            rc = read_file(&matrix, f_open);

            fclose(f_open);
        }
        else
            rc = FOPEN_ERROR;

        if (rc == OK && strcmp(argv[1], "o") == 0)
        {
            rc = inversion(&matrix);

            if (rc == OK)
                print_matrix(matrix);
        }
        else
            rc = ARGS_ERROR;
    }
    else 
        rc = ARGS_ERROR;

    return rc;
}
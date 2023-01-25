#include "io_funcs.h"
#include "return_codes.h"
#include "additional_funcs.h"

#include <string.h>

int main(int argc, char **argv)
{
    int *arr = NULL; // динамический массив
    size_t size; // количество элементов массива
    int *new_arr = NULL, *new_size = NULL; 
    int rc = OK; // код возврата

    if (argc == 3 || argc == 4)
    {
        FILE *f_input = fopen(argv[1], "r");

        if (f_input)
        {
            arr = create_arr(&size, f_input);
             
            if (arr)
                mysort(arr, size, sizeof(int), compare);
            else
                rc = ALLOCATE_ERROR;
            
            fclose(f_input);
        }
        else
            rc = FOPEN_ERROR;
    }
    else 
        rc = ARGS_ERROR;
    
    if (rc == OK)
    {
        FILE *f_output = fopen(argv[2], "w");

        if (f_output && argc == 3)
        {
            print_result(arr, arr + size, f_output);
            fclose(f_output);
        }
        else if (argc == 4 && f_output && strcmp(argv[3], "f") == 0)
        {
            rc = key(arr, arr + size, &new_arr, &new_size);

            if (rc == OK)
                print_result(new_arr, new_size, f_output);
            
            free(new_arr);
            fclose(f_output);
        }
        else
            rc = ARGS_ERROR;
        
        free(arr);
    }

    return rc;
}
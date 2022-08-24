#include "../inc/io_funcs.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"
#include "../inc/read_file.h"
#include "../inc/additional_funcs.h"

#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    arr_t arr, result;
    int *new_size = NULL;
    int rc;

    if (argc == 3 || argc == 4)
    {
        FILE *f_open = fopen(argv[1], "r");

        if (f_open)
        {
            rc = read_file(&arr, f_open);

            fclose(f_open);
        }
        else
            rc = FREAD_ERROR;
    }
    else
        rc = ARGS_ERROR;
    
    if (argc == 4 && rc == OK)
    {
        FILE *f_output = fopen(argv[2], "w");

        if (strcmp(argv[3], "f") == 0)
        {
            rc = key(arr.arr, arr.arr + arr.size, &result.arr, &new_size); 

            if (rc == OK)
            {
                result.size = new_size - result.arr;

                mysort(result.arr, result.size, sizeof(int), (int (*)(const void *, const void *))compar);
                print_array(result.arr, new_size, f_output);

                free(result.arr);
            }

            free(arr.arr);
        }
        else
            rc = KEY_PARAM_ERROR;

        fclose(f_output);
    }
    else if (rc == OK)
    {
        FILE *f_output = fopen(argv[2], "w");

        mysort(arr.arr, arr.size, sizeof(int), (int (*)(const void *, const void *))compar);
        print_array(arr.arr, arr.arr + arr.size, f_output);

        fclose(f_output);
    }

    return rc;
}
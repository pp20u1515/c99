#include "../inc/read_file.h"
#include "../inc/struct.h"
#include "../inc/return_codes.h"

#include <stdlib.h>

int count_elems(FILE *f_open)
{
    int count = 0;
    int elem;

    while (fscanf(f_open, "%d", &elem) == 1)
        count++;

    rewind(f_open);

    return count;
}

int fill_array(int *temp_arr, arr_t *arr, FILE *f_open)
{
    int rc = OK;

    for (int *i = temp_arr; *i < arr->size && rc == OK; i++)
        if (fscanf(f_open, "%d", i) != 1)
            rc = DATA_ERROR;

    return rc;
}

int *create_array(arr_t *arr, FILE *f_open)
{
    int *temp_arr = (int *)malloc((unsigned long)arr->size * sizeof(int));

    if (temp_arr)
    {
        if (fill_array(temp_arr, arr, f_open) != OK)
        {
            free(temp_arr);
            temp_arr = NULL;
        }
    }

    return temp_arr;
}

int read_file(arr_t *arr, FILE *f_open)
{
    int rc = OK;

    arr->size = count_elems(f_open);
    
    if (arr->size)
    {
        arr->arr = create_array(arr, f_open);

        if (arr->arr == NULL)
            rc = ALLOCATE_ERROR;
    }
    else
        rc = DATA_ERROR;

    return rc;
}

#include "io_funcs.h"
#include "return_codes.h"

#include <stdlib.h>

int read_arr(FILE *f_open, int *arr, int *pe_src)
{
    int rc = OK; // код возврата

    for (int *pb_src = arr; rc == OK && pb_src < pe_src; pb_src++)
        if (fscanf(f_open, "%d", pb_src) != 1)
            rc = DATA_ERROR; 
        
    return rc;
}

int *create_arr(size_t *size, FILE *f_open)
{
    int *temp_arr = NULL; // вспомагательная переменная
    int *pe_src = NULL; // вспомагательная переменная, указывающая на конец массива
    int rc = OK; // код возврата
    *size = count_elems(f_open); // кочилество элементов массива
    
    if (*size > 0)
    {
        temp_arr = malloc(*size * sizeof(int));
        
        if (temp_arr)
        {
            rewind(f_open);
            pe_src = temp_arr + *size;
            rc = read_arr(f_open, temp_arr, pe_src);
            
            if (rc != OK)
            {
                free(temp_arr);
                temp_arr = NULL;
            }
        }
    }
    
    return temp_arr;
}

size_t count_elems(FILE *f_open)
{
    size_t count = 0; // счетчик
    int elem; // текущий элемент

    while (fscanf(f_open, "%d", &elem) == 1)
        count++;

    return count;
}

void print_result(const int *ptr_start, const int *ptr_end, FILE *f_output)
{
    for (const int *i = ptr_start; i < ptr_end; i++)
        fprintf(f_output, "%d ", *i);
    fprintf(f_output, "\n");
}
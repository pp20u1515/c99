#include "../inc/io_funcs.h"
#include "../inc/struct.h"

void print_array(const int *arr, int *size, FILE *f_output)
{
    for (int *i = (int *)arr; i < size; i++)
        fprintf(f_output, "%d ", *i);

    fprintf(f_output, "\n");
}
#include "../inc/additional_funcs.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"
#include "../inc/io_funcs.h"

#include <string.h>
#include <stdlib.h>

int compar(const void *first_value, const void *sec_value)
{
    return *((int *)first_value) - *((int *)sec_value);
}

void swap(char *first_elem, char *sec_elem, const size_t size)
{
    char temp;

    for (size_t i = 0; i < size; i++)
    {
        temp = *first_elem;
        *(first_elem++) = *sec_elem;
        *(sec_elem++) = temp;
    }
}

void mysort(void *base, size_t nbase, size_t size, int (*compar)(const void *, const void *))
{   
    const size_t max_indx = size * nbase;
    int res;

    for (char *a = base; a < (char *)base + max_indx; a += size)
    {
        char *min_elem = a;
        
        for (char *b = a; b < (char *)base + max_indx; b += size)
            if (compar(min_elem, b) > 0)
                min_elem = b;
        
        if (compar(a, min_elem) > 0)
            swap(a, min_elem, size);
    }
}

void get_min_and_max_indexes(const int *pb_src, const int *pe_src, int *min_index, int *max_index)
{
    int *elem = (int *)pb_src;
    int index = 1;

    for (int *i = (int *)(pb_src + 1); i < (int *)pe_src; i++)
    {
        if (*elem > *i)
        {
            *min_index = index;
            *elem = *i;
        }
        index++;
    }

    index = 1;

    for (int *i = (int *)(pb_src + 1); i < (int *)pe_src; i++)
    {
        if (*elem < *i)
        {
            *max_index = index;
            *elem = *i;
        }
        index++;
    }
}

void swap_indexes(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int new_length(const int min_index, const int max_index)
{
    int count = 0;

    if (min_index + 1 != max_index && max_index + 1 != min_index)
        if (min_index < max_index)
            while (count < max_index)
                count++;
        else
            while (count < min_index)
                count++;

    return count;
}

void fill_new_arr(const int *pb_src, const int min_index, const int *pe_src, int **pe_dst)
{
    for (int *i = (int *)(pb_src + (min_index + 1)); i < (int *)pe_src - 1; i++)
    {
        **pe_dst = *i;
        *pe_dst += 1;
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK;

    if (pb_src < pe_src)
    {
        int min_index, max_index;
        int index = 0;

        get_min_and_max_indexes(pb_src, pe_src, &min_index, &max_index);

        if (min_index > max_index)
            swap_indexes(&min_index, &max_index);

        int length = new_length(min_index, max_index) - 2;
        
        if (length)
        {
            *pb_dst = malloc(length * sizeof(int));

            if (*pb_dst)
            {
                *pe_dst = *pb_dst;

                fill_new_arr(pb_src, min_index, pe_src, pe_dst);
            }
            else
                rc = ALLOCATE_ERROR;
        }
        else
            rc = DATA_ERROR;
    }
    else 
        rc = DATA_ERROR;

    return rc;
}
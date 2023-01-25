#include "additional_funcs.h"
#include "return_codes.h"
#include "io_funcs.h"

#define EPS 0.0000001

void fill_new_arr(const int *pb_src, const int *pe_src, const double avg, int **pe_dst)
{
    for (const int *i = pb_src; i < pe_src; i++)
        if (*i - avg > EPS)
        {
            **pe_dst = *i;
            *pe_dst += 1;
        }
}

int sum_elems(const int *pb_src, const int *pe_src)
{
    int sum = 0; // сумма из всех элементов

    for (const int *ptr = pb_src; ptr < pe_src; ptr++)
        sum += *ptr;

    return sum;
}

size_t get_new_size(const int *pb_src, const int *pe_src, const double avg)
{
    size_t size = 0; // длина массива

    for (const int *ptr = pb_src; ptr < pe_src; ptr++)
        if (*ptr - avg > EPS)
            size++;

    return size;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = OK; // код возврата
    int sum = 0; // сумма всех элементов массива
    double avg = 0.0; // среднее значение из всех элементов массива
    size_t new_size = 0; // новая длинна 
    
    if (pb_src < pe_src)
    {
        sum = sum_elems(pb_src, pe_src);
        avg = sum / (pe_src - pb_src);
        
        if ((avg * (pe_src - pb_src)) - sum > 0 && sum < 0)
            avg -= 1;

        new_size = get_new_size(pb_src, pe_src, avg);
        
        if (new_size)
        {
            *pe_dst = malloc(new_size * sizeof(int));
            
            if (*pe_dst)
            {
                *pb_dst = *pe_dst;
                fill_new_arr(pb_src, pe_src, avg, pe_dst);
            }
            else
                rc = ALLOCATE_ERROR;
        }
        else
            rc = DATA_ERROR;
    }
    else
        rc = KEY_ERROR;
    
    return rc;
}

void swap(char *a, char *b, size_t size)
{
    char temp; // временная вспомагательная переменная

    while (size > 0)
    {
        temp = *a;
        *(a++) = *b;
        *(b++) = temp;
        size--;
    }
}

int compare(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

void mysort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *))
{
    char *start = base; // указатель на начало массива
    char *end = (char *)base + ((nitems - 1) * size); // указатель на конец массива
    
    for (char *first_ptr = start; first_ptr < end;)
    {      
        for (char *second_ptr = first_ptr + size; second_ptr < end + size;)
        {
            if (compare(first_ptr, second_ptr) > 0)
                swap(first_ptr, second_ptr, size);

            second_ptr += size;
        }
        first_ptr += size;
    }
}

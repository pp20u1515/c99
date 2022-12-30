#include "additional_funcs.h"

#define EPS 0.0000001
#define OK 0
#define ALLOCATE_ERROR 2
#define DATA_ERROR 4
#define KEY_ERROR 5

ARR_DLL void ARR_DECL fill_new_arr(const int *pb_src, const int *pe_src, const double avg, int **pe_dst)
{
    for (const int *i = pb_src; i < pe_src; i++)
        if (*i - avg > EPS)
        {
            **pe_dst = *i;
            *pe_dst += 1;
        }
}

ARR_DLL int ARR_DECL sum_elems(const int *pb_src, const int *pe_src)
{
    int sum = 0; // сумма из всех элементов

    for (const int *ptr = pb_src; ptr < pe_src; ptr++)
        sum += *ptr;

    return sum;
}

ARR_DLL size_t ARR_DECL get_new_size(const int *pb_src, const int *pe_src, const double avg)
{
    size_t size = 0; // длина массива

    for (const int *ptr = pb_src; ptr < pe_src; ptr++)
        if (*ptr - avg > EPS)
            size++;

    return size;
}

ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
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

ARR_DLL void ARR_DECL swap(char *a, char *b, size_t size)
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

ARR_DLL int ARR_DECL compare(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

ARR_DLL void ARR_DECL mysort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *))
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

ARR_DLL int ARR_DECL read_arr(FILE *f_open, int *arr, int *pe_src)
{
    int rc = OK; // код возврата

    for (int *pb_src = arr; rc == OK && pb_src < pe_src; pb_src++)
        if (fscanf(f_open, "%d", pb_src) != 1)
            rc = DATA_ERROR; 
        
    return rc;
}

ARR_DLL int ARR_DECL *create_arr(size_t *size, FILE *f_open)
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

ARR_DLL size_t ARR_DECL count_elems(FILE *f_open)
{
    size_t count = 0; // счетчик
    int elem; // текущий элемент

    while (fscanf(f_open, "%d", &elem) == 1)
        count++;

    return count;
}

ARR_DLL void ARR_DECL print_result(const int *ptr_start, const int *ptr_end, FILE *f_output)
{
    for (const int *i = ptr_start; i < ptr_end; i++)
        fprintf(f_output, "%d ", *i);
    fprintf(f_output, "\n");
}

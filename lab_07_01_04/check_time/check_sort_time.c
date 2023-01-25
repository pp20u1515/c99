#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    char *end = (char *)base + nitems; // указатель на конец массива
    
    for (char *first_ptr = start; first_ptr < end; first_ptr++)
    {
        char *ptr_next = start + size; // указатель на следующий элемент
        
        for (char *second_ptr = first_ptr + 1; second_ptr < end; second_ptr++)
        {
            if (compare(start, ptr_next) > 0)
                swap(start, ptr_next, size);
            
            ptr_next += size;
        }
        start += size;
    }
}

void fill_arr(int *arr, const size_t size)
{
    int elem; // случайное число

    for (size_t index = 0; index < size; index++)
    {
        elem = rand();
        arr[index] = elem;
    }
}

int *create_arr(const size_t size)
{
    int *temp_arr = malloc(size * sizeof(int));

    if (temp_arr)
    {
        fill_arr(temp_arr, size);
    }
    else
        temp_arr = NULL;

    return temp_arr;
}

int main()
{
    int *arr = NULL;
    size_t size = 1;
    clock_t start, end;
    double arr_time[26] = { 0 };

    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[0] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[1] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 10;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[2] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    size = 10;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[3] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 50;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[4] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 50;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[5] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 100;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[6] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 100;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[7] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 200;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[8] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 200;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[9] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 300;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[10] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 300;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[11] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    size = 400;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[12] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 400;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[13] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 500;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[14] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 500;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[15] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 600;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[16] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 600;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[17] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 700;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[18] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 700;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[19] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 800;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[20] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 800;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[21] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 900;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[22] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 900;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[23] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 1000;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[24] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 1000;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), compare);
        end = clock();
        arr_time[25] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%f\n", arr_time[i]);
    }
    return 0;
}

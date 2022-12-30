#include "library.h"

ARR_DLL int ARR_DECL fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

ARR_DLL void ARR_DECL fill_array(int *arr, const int size)
{
    for (int index = 0; index < size; index++)
    {
        arr[index] = fibonacci(index + 1);
    }
} 

ARR_DLL void ARR_DECL filter(int *src, const int src_size, int *dest, int *dest_size)
{
    int count = 0;
    int flag = 0;

    for (int index_i = 0; index_i < src_size; index_i++)
    {
        flag = 0;

        for (int index_j = 0; flag == 0 && index_j < index_i; index_j++)
            if (src[index_i] == src[index_j])
                flag = 1;

        if (flag == 0)
        {
            dest[count] = src[index_i];
            count++;
        }
    }
    *dest_size = count;
}
#include "library.h"

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fill_array(int *arr, const int size)
{
    for (int index = 0; index < size; index++)
    {
        arr[index] = fibonacci(index + 1);
    }
} 

int filter(int *src, const int size, int *dest)
{
    int count = 0;
    int flag = 0;

    for (int index_i = 0; index_i < size; index_i++)
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
    return count;
}

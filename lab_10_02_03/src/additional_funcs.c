#include "../inc/additional_funcs.h"
#include "../inc/return_codes.h"
#include "../inc/struct_funcs.h"
#include "../inc/list_funcs.h"
#include "../inc/io_funcs.h"

#include <math.h>

error_t is_prime(int num)
{  
    for (int i = 2; i < num; i++)
    {
        if(num % i == 0)
            return error;
    }
    return ok;
}

list_t *make_list(int number)
{
    list_t *list = init_list(NULL, NULL);
    
    if (number == 1)
    {
        printf("1 ");
        return list;
    }

    int d = 2;
    while (d * d <= number)
    {
        if (is_prime(d) == ok)
        {
            if (push_back(list, init_node(0)) == error)
            {
                free_list(list);
                return NULL;
            }
        }
        while (number % d == 0)
        {
            list->tail->data++;
            number = (int)floor(number / (double)d);
        }

        d += 1;
    }

    if (number > 1)
    {
        int push_num;
        for (; d <= number; d++)
        {
            push_num = d == number ? 1 : 0;
            if (is_prime(d) == ok)
            {
                if (push_back(list, init_node(push_num)) == error)
                {
                    free_list(list);
                    return NULL;
                }
            }
        }
    }
    return list;
}
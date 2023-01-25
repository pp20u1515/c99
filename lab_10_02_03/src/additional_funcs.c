#include "additional_funcs.h"
#include "return_codes.h"

#include <stdlib.h>

#define IS_PRIME 1
#define NOT_PRIME 0

size_t count_dividers(size_t *num, const size_t degree)
{
    size_t count = 0; // счетчик степеней

    while (*num % degree == 0)
    {
        count++;
        *num /= degree;
    }
    return count;
}

void sqr_num(node_t *head)
{
    while (head)
    {
        head->data *= 2;
        head = head->next;
    }
}

unsigned int is_prime(size_t num)
{
    unsigned int rc = IS_PRIME; // код возврата

    for (size_t i = 2; rc == IS_PRIME && i < num; i++)
        if (num % i == 0)
            rc = NOT_PRIME;
    
    return rc;
}
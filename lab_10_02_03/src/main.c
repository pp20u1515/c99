#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/additional_funcs.h"
#include "../inc/io_funcs.h"
#include "../inc/list_funcs.h"
#include "../inc/return_codes.h"
#include "../inc/struct_funcs.h"

int main()
{
    list_t *fst;
    p_mode mode = get_mode(stdin);
    int numbers[2];

    switch (mode)
    {
        case out:
            if (get_numbers(numbers, 1) == ok)
            {
                fst = make_list(numbers[0]);
                display_list(fst);
            }
            else
                return error;
            break;
        case mul:
            if (get_numbers(numbers, 2) == ok)
            {
                int res = numbers[0] * numbers[1];
                if (res == 0)
                    return error;
                else
                {
                    fst = make_list(res);
                    display_list(fst);
                }
            }
            else
                return error;
            break;
        case dev:
            if (get_numbers(numbers, 2) == ok)
            {
                if (numbers[0] < numbers[1] || numbers[1] == 0)
                    return error;
                else
                {
                    fst = make_list((int) (numbers[0] / (double) numbers[1]));
                    display_list(fst);
                }
            }
            else
                return error;
            break;
        case sqr:
            if (get_numbers(numbers, 1) == ok)
            {
                fst = make_list((int) sqrt((double) numbers[0]));
                display_list(fst);
            }
            else
                return error;
            break;
        default:
            return error;
    }
    return ok;
}
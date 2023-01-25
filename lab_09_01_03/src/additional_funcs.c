#include "additional_funcs.h"
#include "return_codes.h"
#include "product.h"

#include <string.h>
#include <stdlib.h>

int is_digit(const char symb)
{
    return (symb >= '0' && symb <= '9');
}

int char_to_int(const char sym)
{
    return sym - '0';
}

int my_atoi(const char *argv)
{
    int flag = OK; // флаг
    int key = 0; // ключ
    size_t index = 0; // индекс
    
    if (argv != NULL)
    {
        if (is_digit(argv[index]) != 0)
        {
            key = char_to_int(argv[index]);
            index++;
        }
        else
        {
            key = KEY_ERROR;
            flag = KEY_ERROR;
        }

        for (; flag == OK && index < strlen(argv); index++)
        {
            if (is_digit(argv[index]) != 0)
                key = (key * 10) + char_to_int(argv[index]);
            else
            {
                key = KEY_ERROR;
                flag = KEY_ERROR;
            }
        }
    }
    else
        key = CORRECT_KEY;
    
    return key;
}

void free_data(products_t *products, size_t len)
{
    for (size_t index = 0; index < len; index++)
        free(products[index].product_name);

    free(products);
}
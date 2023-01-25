#include "additional_funcs.h"
#include "return_codes.h"
#include "struct.h"

#include <string.h>

// Функция, проверяющая является ли данный сумвол числом
int is_digit(const char symb)
{
    return (symb >= '0' && symb <= '9');
}

// Функция, превращающая элемент из char в int
int char_to_int(const char sym)
{
    return sym - '0';
}

// Функция, превращающая элемент из char * в int
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

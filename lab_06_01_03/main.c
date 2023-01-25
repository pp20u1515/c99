#include "return_codes.h"
#include "additional_funcs.h"
#include "struct.h"
#include "io_funcs.h"

#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

int main(int argc, char **argv)
{
    read_products_t read_product[NAME_LEN]; // структура для чтения информацию о продуктах
    print_products_t print_product[NAME_LEN]; // структура для вывода информацию о продуктах
    FILE *f_open; // файл для чтения
    int size; // количество продуктов
    int rc; // код возврата

    if (argc == 2 || argc == 3)
    {
        f_open = fopen(argv[1], "r");
        
        if (f_open)
        {
            int key; // ключ

            rc = read_data(f_open, read_product, &size);
            key = my_atoi(argv[2]);
            
            if (rc == OK && argc == 3 && key > 0)
            {
                memcpy(print_product, read_product, sizeof(print_product));
                print_products(print_product, key, size);
            }
            else if (rc == OK && argc == 2 && key == CORRECT_KEY)
            {
                memcpy(print_product, read_product, sizeof(print_product));
                print_products(print_product, key, size);
            }
            else
                rc = DATA_ERROR;
            
            fclose(f_open);
        }
        else
            rc = FREAD_ERROR;
    }
    else
        rc = ARG_ERROR;
        
    return rc;
}

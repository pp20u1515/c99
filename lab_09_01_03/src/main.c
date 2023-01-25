#include "return_codes.h"
#include "additional_funcs.h"
#include "product.h"
#include "arr_product.h"

int main(int argc, char **argv)
{
    products_t *product = NULL; // структура для чтения информацию о продуктах
    FILE *f_open; // файл для чтения
    size_t size; // количество продуктов
    size_t rc = OK; // код возврата

    if (argc == 2 || argc == 3)
    {
        f_open = fopen(argv[1], "r");
        
        if (f_open)
        {
            int key; // ключ

            product = read_data(f_open, &size);
            key = my_atoi(argv[2]);
            
            if (product && argc == 3 && key > 0)
            {
                print_arr_products(product, key, size);
                free_data(product, size);
            }
            else if (product && argc == 2 && key == CORRECT_KEY)
            {
                print_arr_products(product, key, size);
                free_data(product, size);
            }
            else if (product && key != CORRECT_KEY)
            {
                free_data(product, size);
                rc = DATA_ERROR;
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

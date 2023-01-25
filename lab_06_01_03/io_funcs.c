#include "io_funcs.h"
#include "return_codes.h"
#include "struct.h"

#define NAME_LEN 25

#include <string.h>

// Функция, читающая, проверяющая и записывающая данные из файла в структуру
int read_data(FILE *f_open, read_products_t *products, int *size)
{
    int count = 0; // счетчик
    int rc = OK; // код возврата

    if (fscanf(f_open, "%d\n", size) == 1 && *size > 0 && *size <= 15)
    {    
        while (count != *size && rc == OK && fscanf(f_open, "%s", products[count].product_name))
        {
            if (strlen(products[count].product_name) < NAME_LEN && \
            fscanf(f_open, "%d\n", &(products[count].prize)) == 1 && products[count].prize > 0)
                count++;
            else
                rc = DATA_ERROR;
        }
        *size = count;
    }
    else
        rc = DATA_ERROR;
    
    rewind(f_open);

    return rc;
}

// Вывод результата
void print_products(const print_products_t *products, const int key, const int size)
{
    int index = 0; // индекс

    while (index < size)
    {
        int price = products[index].prize; // цена продукта
        
        if (key > 0 && price < key)
        {
            printf("%s\n", products[index].product_name);
            printf("%d\n", price);
        }
        else if (key == CORRECT_KEY)
        {
            printf("%s\n", products[index].product_name);
            printf("%d\n", products[index].prize);
        }
        index++;
    }
}
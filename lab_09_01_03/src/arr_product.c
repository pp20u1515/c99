#define _GNU_SOURCE

#include "arr_product.h"
#include "return_codes.h"
#include "product.h"
#include "additional_funcs.h"

#include <stdlib.h>
#include <string.h>

products_t *allocate_place(size_t *size, FILE *f_open)
{
    products_t *temp_products = NULL;

    if (fscanf(f_open, "%zu\n", size) == 1 && *size > 0)
        temp_products = malloc(*size * sizeof(products_t));

    return temp_products;
}

products_t *read_data(FILE *f_open, size_t *size)
{
    products_t *temp_products = NULL; // вспомагательная структура продуктов
    
    size_t count = 0; // счетчик
    size_t rc = OK; // код возврата

    temp_products = allocate_place(size, f_open); 
    
    if (temp_products)
    {    
        while (count != *size && rc == OK)
        {
            rc = product_read(temp_products, count, f_open);

            if (rc != OK)
            {
                free_data(temp_products, count);
                temp_products = NULL;
            }
            
            count++;
        }
        *size = count;
    }

    return temp_products;
}

void print_arr_products(const products_t *products, const int key, const size_t size)
{
    size_t index = 0; // индекс
    
    while (index < size)
    {
        int price = products[index].prize; // цена продукта
          
        if (key > 0 && price < key)
            product_print(products[index].product_name, products[index].prize);
        else if (key == CORRECT_KEY)
            product_print(products[index].product_name, products[index].prize);
        
        index++;
    }
}
#include "product.h"
#include "return_codes.h"

#include <stdlib.h>
#include <string.h>

size_t product_read(products_t *products, const size_t index, FILE *f_open)
{
    size_t len = 0; // размер в байтах блока памяти, на который указывает первый параметр
    char *product_name = NULL; // буффер, где будем сохранять название продуктов 
    ssize_t read = getline(&product_name, &len, f_open);
    size_t rc = OK; // код возврата
    
    if (read != -1 && fscanf(f_open, "%d\n", &products[index].prize) == 1 && products[index].prize > 0)
    {
        product_name[strlen(product_name) - 1] = '\0';
        products[index].product_name = product_name;
    }
    else
    {
        rc = DATA_ERROR;
        free(product_name);
    }
    
    return rc;
}

void product_print(const char *product_name, const int price)
{
    printf("%s\n", product_name);
    printf("%d\n", price);
}
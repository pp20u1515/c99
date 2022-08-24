#include "../inc/io_funcs.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"

void prod_less_price(products_t *products, const int key)
{
    int index = 0;
    int objects = products->size;
    
    while (index < objects)
    {
        int price = products[index].prize;
        
        if (price < key)
        {
            printf("%s", products[index].product_name);
            printf("%d\n", price);
        }
        index++;
    }
}

void print_products(products_t *products)
{
    int index = 0;
    int max_objects = products->size;
    
    while (index < max_objects)
    {
        printf("%s", products[index].product_name);
        printf("%d\n", products[index].prize);

        index++;
    }
}
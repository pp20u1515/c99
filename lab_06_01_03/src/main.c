#include "../inc/return_codes.h"
#include "../inc/read_file.h"
#include "../inc/struct.h"
#include "../inc/io_funcs.h"

#include <stdlib.h>

int main(int argc, char **argv)
{
    products_t products[NAME_LEN];
    FILE *f_open;
    int rc;

    if (argc == 2 || argc == 3)
    {
        f_open = fopen(argv[1], "r");
        
        if (f_open)
        {
            int key;

            rc = check_data(f_open, products);
            if (rc == OK && argc == 3 && (key = atoi(argv[2])) != OVERFLOW_ERROR)
                prod_less_price(products, key);
            else if (rc == OK && key != OVERFLOW_ERROR)
                print_products(products);
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
#include "../inc/read_file.h"
#include "../inc/return_codes.h"
#include "../inc/struct.h"

#include <string.h>

int check_data(FILE *f_open, products_t *products)
{
    int count = 0;
    int rc = OK;

    if (fscanf(f_open, "%d\n", &(products[count].size)) == 1 && products[count].size > 0)
        while (count != products->size && rc == OK && fgets(products[count].product_name, NAME_LEN + 1, f_open) != NULL)
        {
            if (fscanf(f_open, "%d\n", &(products[count].prize)) != 1 || products[count].prize <= 0)
                rc = DATA_ERROR;
            else
                count++;
        }
    else
        rc = DATA_ERROR;

    products->size = count;
    rewind(f_open);
    
    return rc;
}
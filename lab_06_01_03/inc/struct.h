#ifndef STRUCT_H
#define STRUCT_H

#include "return_codes.h"

typedef struct products
{
    char product_name[NAME_LEN + 1];
    int prize;
    int size;
}products_t;

#endif
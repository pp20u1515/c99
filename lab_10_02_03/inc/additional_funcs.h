#ifndef ADDITIONAL_STRUCT_H
#define ADDITIONAL_STRUCT_H

#include "struct_funcs.h"
#include "return_codes.h"

#include <stdio.h>
#include <stdlib.h>

error_t is_prime(int num);
list_t *make_list(int number);

#endif
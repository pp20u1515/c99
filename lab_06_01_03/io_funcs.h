#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <stdio.h>

#include "struct.h"

// Функция, читающая данные из файлаи , проверяющая корректность данных
int read_data(FILE *f_open, read_products_t *products, int *size);

// Вывод результата
void print_products(const print_products_t *products, const int key, const int size);

#endif // IO_FUNCS_H

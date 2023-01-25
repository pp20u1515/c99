#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H

#include <stdio.h>

#include "struct.h"

// Функция, проверяющая корректность ключа программы
int my_atoi(const char *argv);

// Функция, проверяющая является ли данный сумвол числом
int is_digit(const char symb);

// Функция, превращающая элемент из char в int
int char_to_int(const char sym);

#endif // ADDITIONAL_FUNCS_H

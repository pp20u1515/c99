#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H

#include <stdio.h>

#include "product.h"

/**
 * \brief my_atoi - Функция, проверяющая корректность ключа программы
 * 
 * \param argv Аргумент командной строки
 * \return Код ошибки или значение ключа
 */
int my_atoi(const char *argv);

/**
 * \brief is_digit - Функция, проверяющая является ли данный сумвол числом
 * 
 * \param symb Сумвол
 * \return Число от 0 до 9
 */
int is_digit(const char symb);

/**
 * \brief char_to_int - Функция, превращающая элемент из char в int
 * 
 * \param sym Сумвол
 * \return Полученое целое число из char
 */
int char_to_int(const char sym);

/**
 * \brief free_data - Функция, которая освобождает память под структурой
 * 
 * \param products Структура продуктов
 * \param len Количество продуктов
 */
void free_data(products_t *products, const size_t len);

#endif // ADDITIONAL_FUNCS_H

#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H

#include <stdio.h>

#include <struct.h>

/**
 * \brief count_dividers - Функция, которая считает количество степеней
 * \param num Указатель на входное число
 * \param degree Степень числа
 * \return Количество степеней
 */
size_t count_dividers(size_t *num, const size_t degree);

/**
 * \brief sqr_num - Функция, которая возводит число в квадрат
 * \param head Структура списка
 */
void sqr_num(node_t *head);

/**
 * \brief is_prime - Функция, которая проверяет является ли число простым
 * \param num Входное число
 * \return Результат сравнения(true/false)
 */
unsigned int is_prime(size_t num);

#endif // ADDITIONAL_FUNCS_H
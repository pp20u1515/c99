#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <stdio.h>

#include "struct.h"

/**
 * \brief get_mode - Функция, которая получает операцию для выполнения программы
 * \param mode Операцию выполнения программы
 */
void get_mode(get_mode_t *mode);

/**
 * \brief process_out - Функция, которая выводит в виде списка степени разложения целого положительного числа 
 * \return Код успеха или код ошибки
 */
int process_out();

/**
 * \brief process_mul - Функция, которая умножает две целые положительный числа и выводит в виде 
 * списка степени разложения результата умножения
 * \return Код успеха или код ошибки
 */
int process_mul();

/**
 * \brief process_div - Функция, которая делит две целые положительный числа без остатка
 * \return Код успеха или код ошибки
 */
int process_div();

/**
 * \brief process_sqr - Функция, возведения числа в квадрат 
 * \return Код успеха или код ошибки
 */
int process_sqr();

/**
 * \brief print_result - Функция, которая выводит список 
 * \param head Структура списка
 */
void print_result(node_t **head);

#endif // IO_FUNCS_H
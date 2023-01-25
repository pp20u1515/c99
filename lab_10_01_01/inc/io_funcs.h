#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include "struct.h"

#include <stdio.h>

/**
 * \brief read_file - Функция, которая читает данные из файла и добавляeт их в список
 * \param head Структура списка
 * \param file_name Название входного файла
 * \return Код успеха или код ошибки
 */
size_t read_file(node_t **head, const char *file_name);

/**
 * \brief print_result - Функция, которая печатает список
 * \param list Структура списка
 * \param file_name Название выходного файла
 */
void print_result(node_t *list, const char *file_name);

/**
 * \brief print_info_package - Функция, которая выводит информацию о посылке
 * 
 * \param num Номер посылки
 * \param weight Весь посылки
 * \param f_write Выходный файл 
 */
void print_info_package(const int num, const double weight, FILE *f_write);

/**
 * \brief read_package - Функция, которая читает информацию о посылке
 * 
 * \param f_open Входный файл
 * \return Список
 */
node_t *read_package(FILE *f_open);

#endif // IO_FUNCS_H
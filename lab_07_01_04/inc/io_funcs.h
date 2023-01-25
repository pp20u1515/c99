#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <stdio.h>

/**
 * \brief count_elems - Функция, проверяющая количество елементов из файла
 * \param f_open Файл для чтения
 * \return Количесто элементов из файла
 */
size_t count_elems(FILE *f_open);

/**
 * \brief read_arr - Функция, заполняющая массив
 * \param f_open Файл для чтения
 * \param arr Указатель на начало массива
 * \param pe_src Указатель на конец массива
 * \return Kод ошибки или код успеха
 */
int read_arr(FILE *f_open, int *arr, int *pe_src);

/**
 * \brief create_arr - Функция, выделяющая помять массива
 * \param size Количество элементов массива
 * \param f_open Файл для чтения
 * \return Выделеный размера массива
 */
int *create_arr(size_t *size, FILE *f_open);

/**
 * \brief print_result - Вывод результата
 * \param ptr_start Указатель на начало массива
 * \param ptr_end Указатель на конец массива
 * \param f_output Файл для записи ресультата
 */
void print_result(const int *ptr_start, const int *ptr_end, FILE *f_output);

#endif // IO_FUNCS_H

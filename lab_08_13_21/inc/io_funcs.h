#ifndef IO_FUNCS_H
#define IO_FUNCS_H

#include <stdio.h>

#include "struct.h"

/**
 * @brief print_matrix - Функция, которая печатает матрицу в файл
 * 
 * @param matrix Структура матрицы
 * @param f_output Выходный файл
 */
void print_matrix(const matrix_t matrix, FILE *f_output);

/**
 * @brief read_matrix - Функция, которая читает матрицу из файла
 * 
 * @param matrix Структура матрицы
 * @param f_open Входный файл
 * @param number_nonzero_elems Количество ненулевых элементов матрицы 
 * @return Код успеха или код ошибки
 */
int read_matrix(matrix_t *matrix, FILE *f_open, size_t *number_nonzero_elems);

/**
 * @brief read_data - Функция, которая читает элементы матрицы и заполняет ее при успешном чтением
 * 
 * @param matrix Структура матрицы
 * @param f_open Входный файл
 * @param number_nonzero_elems Количество ненулевых элементов 
 * @return Код успеха или код ошибки
 */
int read_data(matrix_t *matrix, FILE *f_open, const size_t *number_nonzero_elems);

/**
 * @brief read_dimension - Функция, которая читает размер матрицы из файла
 * 
 * @param matrix Структура матрицы
 * @param f_open Входный файл
 * @param number_nonzero_elems Количество ненулевых элементов 
 * @return Код успеха или код ошибки
 */
int read_dimension(matrix_t *matrix, FILE *f_open, size_t *number_nonzero_elems);

#endif // IO_FUNCS_H
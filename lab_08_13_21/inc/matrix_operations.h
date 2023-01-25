#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "struct.h"

#include <stdio.h>

/**
 * @brief multiply_matrix - Функция, проверяющая правильность всех входных данных при умножении двух матриц
 * 
 * @param first_matrix Структура первой матрицы
 * @param second_matrix Структура второй матрицы
 * @param result Структура результата
 * @param first_file_name Файл с входными данными для первой матрицы
 * @param second_file_name Файл с входными данными для второй матрицы
 * @param first_nonzero_elems Количество ненулевых элементов первой матрицы
 * @param second_nonzero_elems Количество ненулевых элементов второй матрицы
 * @return Код успеха или код ошибки
 */
int multiply_matrix(matrix_t *first_matrix, matrix_t *second_matrix, matrix_t *result, const char *first_file_name, const char *second_file_name, size_t *first_nonzero_elems, size_t *second_nonzero_elems);

/**
 * @brief multiply - Функция умножения двух матриц
 * 
 * @param first_matrix Структура первой матрицы
 * @param second_matrix Структура второй матрицы
 * @param result Структура результата
 * @return Код ошибки или код успеха
 */
int multiply(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result);

/**
 * @brief  sum_matrix - Функция, проверяющая правильность всех входных данных при сложении двух матриц
 * 
 * @param first_matrix Структура первой матрицы
 * @param second_matrix Структура второй матрицы
 * @param result Структура результата
 * @param first_file_name Файл с входными данными для первой матрицы
 * @param second_file_name Файл с входными данными для второй матрицы
 * @param first_nonzero_elems Количество ненулевых элементов первой матрицы
 * @param second_nonzero_elems Количество ненулевых элементов второй матрицы
 * @return Код успеха или код ошибки
 */
int sum_matrix(matrix_t *first_matrix, matrix_t *second_matrix, matrix_t *result, const char *first_file_name, const char *second_file_name, size_t *first_nonzero_elems, size_t *second_nonzero_elems);

/**
 * @brief sum - Функция сложения двух матриц
 * 
 * @param first_matrix Структура первой матрицы
 * @param second_matrix Структура второй матрицы
 * @param result Структура результата
 * @return Код ошибки или код успеха
 */
int sum(const matrix_t *first_matrix, const matrix_t *second_matrix, matrix_t *result);

/**
 * @brief find_determ - Функция, проверяющая правильность всех входных данных при нахождении определителя матрицы
 * 
 * @param file_name Название входого файла
 * @param matrix Структура матрицы
 * @param determ Значение определителя матрицы
 * @param number_nonzero_elems Количество ненулевых элементов
 * @return Код успеха или код ошибки
 */
int find_determ(const char *file_name, matrix_t *matrix, double *determ, size_t *number_nonzero_elems);

/**
 * @brief allocate_matrix - Функция, которая выделяет память под матрицей
 * 
 * @param rows Количество строк матрицы
 * @param columns Количество столбцов матрицы
 * @return Выделенную память матрицы
 */
double **allocate_matrix(const size_t rows, const size_t columns);

/**
 * @brief free_matrix - Функция, которая освобождает выделенную память 
 * 
 * @param data Выделенная память матрицы
 * @param rows Количество строк матрицы
 */
void free_matrix(double **data, const size_t rows);

/**
 * @brief matrix_det - Функция, нахождения определитель матрицы
 * 
 * @param matrix Структура матрицы
 * @param determ Значение определителя матрицы
 * @return Код успеха или код ошибки
 */
int matrix_det(const matrix_t *matrix, double *determ);

#endif // MATRIX_OPERATIONS_H
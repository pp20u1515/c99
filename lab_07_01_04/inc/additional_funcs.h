#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief fill_new_arr - Функция, заполняющая новый массива элементами
 * \param pb_src Указатель на начало исходного массива
 * \param pe_src Указатель на конец исходного массива
 * \param avg Среднее значение всех элементов массива
 * \param pe_dst Указатель на новый массива
 */
void fill_new_arr(const int *pb_src, const int *pe_src, const double avg, int **pe_dst);

/**
 * \brief key - Функция - фильтер
 * \param pb_src Указатель на начало исходного массива
 * \param pe_src Указатель на конец исходного массива
 * \param pb_dst Указатель на начало нового массива
 * \param pe_dst Указатель на конец нового массива
 * \return Код ошибки или код успеха
 */
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

/**
 * \brief compare - Функция, сравнивающая два элемента
 * \param a Первый элемент
 * \param b Второй элемент
 * \return Разность между двумя элементами
 */
int compare(const void *a, const void *b);

/**
 * \brief mysort - Функция, сортирующая элементы массива по возрастанию
 * \param base Указатель на массив
 * \param nitems Количество элементов массива
 * \param size Размер элемента в байтах
 * \param compare Функция, сравнивающая два элемента
 */
void mysort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *));

/**
 * \brief swap - Функция, меняющая места двух элементов
 * \param a Первый элемент
 * \param b Второй элемент
 * \param size Длина элементов в байтах
 */
void swap(char *a, char *b, size_t size);

/**
 * \brief sum_elems - Функция, которая суммирует элементы массива
 * \param pb_src Указатель на начало массива
 * \param pe_src Указатель на конец массива
 * \return Сумма из всех элементов
 */
int sum_elems(const int *pb_src, const int *pe_src);

/**
 * \brief get_new_size - Функция, получающая новый размер массива
 * \param pb_src Указатель на начало массива
 * \param pe_src Указатель на конец массива
 * \param avg Среднее значение
 * \return Количество элементов массива
 */
size_t get_new_size(const int *pb_src, const int *pe_src, const double avg);

#endif // ADDITIONAL_FUNCS_H

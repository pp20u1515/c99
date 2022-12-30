#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H

#include <stdio.h>
#include <stdlib.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

// Соглашение о вызовах
#define ARR_DECL __cdecl

/**
 * \brief fill_new_arr - Функция, заполняющая новый массива элементами
 * \param pb_src Указатель на начало исходного массива
 * \param pe_src Указатель на конец исходного массива
 * \param avg Среднее значение всех элементов массива
 * \param pe_dst Указатель на новый массива
 */
ARR_DLL void ARR_DECL fill_new_arr(const int *pb_src, const int *pe_src, const double avg, int **pe_dst);

/**
 * \brief key - Функция - фильтер
 * \param pb_src Указатель на начало исходного массива
 * \param pe_src Указатель на конец исходного массива
 * \param pb_dst Указатель на начало нового массива
 * \param pe_dst Указатель на конец нового массива
 * \return Код ошибки или код успеха
 */
ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

/**
 * \brief compare - Функция, сравнивающая два элемента
 * \param a Первый элемент
 * \param b Второй элемент
 * \return Разность между двумя элементами
 */
ARR_DLL int ARR_DECL compare(const void *a, const void *b);

/**
 * \brief mysort - Функция, сортирующая элементы массива по возрастанию
 * \param base Указатель на массив
 * \param nitems Количество элементов массива
 * \param size Размер элемента в байтах
 * \param compare Функция, сравнивающая два элемента
 */
ARR_DLL void ARR_DECL mysort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *));

/**
 * \brief swap - Функция, меняющая места двух элементов
 * \param a Первый элемент
 * \param b Второй элемент
 * \param size Длина элементов в байтах
 */
ARR_DLL void ARR_DECL swap(char *a, char *b, size_t size);

/**
 * \brief sum_elems - Функция, которая суммирует элементы массива
 * \param pb_src Указатель на начало массива
 * \param pe_src Указатель на конец массива
 * \return Сумма из всех элементов
 */
ARR_DLL int ARR_DECL sum_elems(const int *pb_src, const int *pe_src);

/**
 * \brief get_new_size - Функция, получающая новый размер массива
 * \param pb_src Указатель на начало массива
 * \param pe_src Указатель на конец массива
 * \param avg Среднее значение
 * \return Количество элементов массива
 */
ARR_DLL size_t ARR_DECL get_new_size(const int *pb_src, const int *pe_src, const double avg);

/**
 * \brief count_elems - Функция, проверяющая количество елементов из файла
 * \param f_open Файл для чтения
 * \return Количесто элементов из файла
 */
ARR_DLL size_t ARR_DECL count_elems(FILE *f_open);

/**
 * \brief read_arr - Функция, заполняющая массив
 * \param f_open Файл для чтения
 * \param arr Указатель на начало массива
 * \param pe_src Указатель на конец массива
 * \return Kод ошибки или код успеха
 */
ARR_DLL int ARR_DECL read_arr(FILE *f_open, int *arr, int *pe_src);

/**
 * \brief create_arr - Функция, выделяющая помять массива
 * \param size Количество элементов массива
 * \param f_open Файл для чтения
 * \return Выделеный размера массива
 */
ARR_DLL int ARR_DECL *create_arr(size_t *size, FILE *f_open);

/**
 * \brief print_result - Вывод результата
 * \param ptr_start Указатель на начало массива
 * \param ptr_end Указатель на конец массива
 * \param f_output Файл для записи ресультата
 */
ARR_DLL void ARR_DECL print_result(const int *ptr_start, const int *ptr_end, FILE *f_output);

#endif // ADDITIONAL_FUNCS_H

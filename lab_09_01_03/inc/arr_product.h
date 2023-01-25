#ifndef ARR_PRODUCT_H
#define ARR_PRODUCT_H

#include <stdio.h>

#include "product.h"

/**
 * \brief read_data - Функция, читающая данные из файла и, проверяющая корректность данных
 * 
 * \param f_open Файл с данными
 * \param products Структура продуктов
 * \param size Количество продуктов 
 * \return Код успеха или код ошибки
 */
products_t *read_data(FILE *f_open, size_t *size);

/**
 * \brief print_products - Функция, которая выводит массив продуктов
 * 
 * \param products Структура продуктов
 * \param key Ключ
 * \param size Количество продуктов
 */
void print_arr_products(const products_t *products, const int key, const size_t size);

/**
 * \brief allocate_place - Функция, которая выделяет память под структурой
 * 
 * \param size Количество продуктов
 * \param f_open Файл с данными
 * \return Выделеная память структуры
 */
products_t *allocate_place(size_t *size, FILE *f_open);

#endif // ARR_PRODUCT_H
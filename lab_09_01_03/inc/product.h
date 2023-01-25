#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>

// Структура, храняющая информацию о продуктах
typedef struct products_t
{
    char *product_name; // название продукта
    int prize; // цена продукта
}products_t;

/**
 * \brief product_read - Функция, которая заполняет структуру данными
 * 
 * \param products Структура продуктов
 * \param index Индекс элемента структуры
 * \param f_open Файл с данными
 * \return Код успеха или код ошибки
 */
size_t product_read(products_t *products, const size_t index, FILE *f_open);

/**
 * \brief product_print - Функция, которая печатает название продукта и цену
 * 
 * \param product_name Название продукта
 * \param price Цена продукта
 */
void product_print(const char *product_name, const int price);

#endif // PRODUCT_H
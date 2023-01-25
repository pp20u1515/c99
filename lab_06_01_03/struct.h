#ifndef STRUCT_H
#define STRUCT_H

#define NAME_LEN 25

// Структура, храняющая информацию о продуктах
typedef struct read_products
{
    char product_name[NAME_LEN + 1]; // название продукта
    int prize; // цена продукта
}read_products_t;

// Структура, которая выдает информацию о продуктах
typedef struct print_products
{
    char product_name[NAME_LEN + 1]; // название продукта
    int prize; // цена продукта
}print_products_t;

#endif // STRUCT_H

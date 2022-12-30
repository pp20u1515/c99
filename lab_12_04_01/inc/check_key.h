#ifndef CHECK_KEY_H
#define CHECK_KEY_H

#include <check.h>

/**
 * \brief key_suite - Функция, тестирующая функцию key
 * \return Результат тестирования
 */
Suite* key_suite(void);

/**
 * \brief cmp - Функция, сравнивающая два массива
 * \param ptr_start Указатель на массива
 * \param ptr_end Указатель на конец массива
 * \param arr Массив
 * \param size Количество элементов массива
 * \return Код успеха или код ошибки
 */
int cmp(const int *ptr_start, const int *ptr_end, const int *arr, const size_t size);

#endif // CHECK_KEY_H

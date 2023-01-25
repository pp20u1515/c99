#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdio.h>

/**
 * \brief unsigned_num_to_str - Функция, которая переводит данное число в шестнадцатеричную систему
 * 
 * \param num Число, которое должно быть переведено в систему base
 * \param base Система, в которой должно данное число быть переведено
 * \param Буфер
 */
void unsigned_num_to_str(unsigned long num, long unsigned base, char *str);

/**
 * \brief num_to_str - Функция, которая записивает число в буфере
 * 
 * \param num Число, которое должно быть переведено в систему base
 * \param base Система, в которой должно данное число быть переведено
 * \return Десятичное число переведено в char
 */
char *num_to_str(long num, long unsigned base);

/**
 * \brief 
 * 
 * \param buf Буфер символьной строки
 * \param count Счетчик
 * \param size Размер буфера
 * \param number Число, которое должно быть переведено в систему base
 * \param base Система, в которой должно данное число быть переведено
 * \return Количество символов сохранено в буфере
 */
int digit_copy(char *buf, int count, size_t size, long number, long unsigned base);

/**
 * \brief copy_string - Функция, которая копирует введеную строку и записивает ее в буфер
 * 
 * \param dest Буфер где будет записана данная строка
 * \param src Строка
 * \param src_index Количество символов данной строки
 * \param dest_size Размер буфера
 * \return Количество символов сохранено в буфере
 */
size_t copy_string(char *dest, const char *src, size_t src_index, const size_t dest_size);

/**
 * \brief my_snprintf - Функция, которая используется для записи в форматированной
 *  строки в буфер символьной строки
 * 
 * \param buf Буфер символьной строки
 * \param n Размер буфера
 * \param format Спецификатор
 * \return Количество символов записано в буфере 
 */
int my_snprintf(char *buf, size_t n, const char *format, ...);

#endif // MY_SNPRINTF_H

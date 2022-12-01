#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include "struct.h"

/**
 * \brief create_node - Функция, которая создает узель
 * \param number Номер посылки 
 * \param weight Весь посылки
 * \return Созданый узель 
 */
node_t *create_node(const int number, const double weight);

/**
 * \brief push - Функция, которая добавляет элементы в список
 * \param head Структура списка
 * \param node Стуктура узла, которого хотим добавить
 * \return Список с добавленым элементом
 */
node_t *push(node_t *head, node_t *node);

/**
 * \brief pop_end - Функция, которая удаляет элемент, который расположен в хвосте списка
 * \param list Структура списка 
 * \return Указатель на данные из элемента, который расположен в хвосте списка 
 */
void *pop_end(node_t **list);

/**
 * \brief pop_front - Функция, которая удаляет элемент, который расположен в голове списка
 * \param list Структура списка 
 * \return Указатель на данные из элемента, который расположен в голове списка 
 */
void *pop_front(node_t **head);

/**
 * \brief reverse - Функция, которая обращает список
 * \param head Структура списка
 * \return reversed список
 */
node_t *reverse(node_t *head);

/**
 * \brief sort - Функция, которая сортирует список
 * \param head Структура списка
 * \param comparator Указатель на функцию
 * \return Отсортированный список
 */
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

/**
 * \brief compare_packages - Функция, которая сравнивает два числа
 * \param a Первый элемент
 * \param b Вторый элемент
 * \return Результат сравнивания
 */
int compare_packages(const void *a, const void *b);

/**
 * \brief sorted_merge - Сортировка слиянием
 * \param head_a Структура первого списка
 * \param head_b Структура второго списка
 * \param comparator Указатель на функцию
 * \return Отсортированный список
 */
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));

/**
 * \brief front_back_split - Функция, которая разделяет список на две части
 * \param head Структура исходного списка
 * \param back Структура нового списка
 */
void front_back_split(node_t *head, node_t **back);

/**
 * \brief free_list - Функция, которая свобождает память под списком
 * \param head Структура списка
 */
void free_list(node_t **head);

#endif // LIST_FUNCS_H
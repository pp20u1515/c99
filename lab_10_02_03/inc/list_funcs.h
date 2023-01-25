#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <stdio.h>

#include "struct.h"

/**
 * \brief free_list - Функция, которая освобождает память под списком
 * \param head Структура списка 
 */
void free_list(node_t **head);

/**
 * \brief create_list - Функция, которая создает список
 * \param num Входное число
 * \return Новый список
 */
node_t *create_list(size_t num);

/**
 * \brief push - Функция, которая добавляет новый узел в список
 * \param head Структура списка
 * \param node Структура одного узла
 * \return Новый список 
 */
node_t *push(node_t *head, node_t *node);

/**
 * \brief create_node - Функция, которая создает новый узел
 * \param num Входно число
 * \return Новый узел
 */
node_t *create_node(const size_t num);

#endif // LIST_FUNCS_H

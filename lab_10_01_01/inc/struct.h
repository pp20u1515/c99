#ifndef STRUCT_H
#define STRUCT_H

typedef struct node_t
{
    void *data; // список
    struct node_t *next; // указатель на следующий элемент списка
}node_t;

typedef struct package_t
{
    int number; // номер посылки
    double weight; // весь посылки
}package_t;

#endif // STRUCT_H
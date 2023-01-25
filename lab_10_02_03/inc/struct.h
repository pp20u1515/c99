#ifndef MY_STRUCT_H
#define MY_STRUCT_H

typedef enum
{
    OUT,
    MUL,
    DIVIDE,
    SQR,
    NONE
}get_mode_t;

typedef struct node_t
{
    int data;
    struct node_t *next;
}node_t;

#endif // MY_STRUCT_H
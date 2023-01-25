#include "io_funcs.h"
#include "return_codes.h"
#include "list_funcs.h"
#include "additional_funcs.h"

#include <string.h>
#include <math.h>

void get_mode(get_mode_t *mode)
{
    char buf[256]; // буффер

    scanf("%s", buf);
    
    if (strcmp(buf, "out") == 0)
        *mode = OUT;
    else if (strcmp(buf, "mul") == 0)
        *mode = MUL;
    else if (strcmp(buf, "div") == 0)
        *mode = DIVIDE;
    else if (strcmp(buf, "sqr") == 0)
        *mode = SQR;
    else
        *mode = NONE;
}

int process_out()
{
    size_t num; // входное число
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура списка

    if (scanf("%zu", &num) == 1)
    {
        list = create_list(num);

        if (list)
        {
            print_result(&list);
            free_list(&list);
        }
        else
            rc = ALLOCATE_ERROR;
    }
    else
        rc = DATA_ERROR;

    return rc;
}

void print_result(node_t **head)
{
    for (node_t *node = *head; node; node = node->next)
        printf("%d ", node->data);
    printf("L\n");
}

int process_mul()
{
    size_t first_num, second_num; // две входные числа
    size_t result; // результат деления двух чисел
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура списка
    
    if (scanf("%zu%zu", &first_num, &second_num) == 2)
    {
        result = first_num * second_num;
        list = create_list(result);

        if (list)
        {
            print_result(&list);
            free_list(&list);
        }
        else
            rc = ALLOCATE_ERROR;
    }
    else
        rc = DATA_ERROR;

    return rc;
}

int process_div()
{
    size_t first_num, second_num; // две входные числа
    size_t result; // результат деления двух чисел
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура списка
    
    if (scanf("%zu%zu", &first_num, &second_num) == 2 && second_num > 0 && first_num > second_num)
    {
        result = first_num / second_num;
        
        list = create_list(result);

        if (list)
        {
            print_result(&list);
            free_list(&list);
        }
        else
            rc = ALLOCATE_ERROR;
    }
    else
        rc = DATA_ERROR;

    return rc;
}

int process_sqr()
{
    size_t num; // входное число
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура списка

    if (scanf("%zu", &num) == 1)
    {   
        list = create_list(num);

        if (list)
        {
            sqr_num(list);
            print_result(&list);
            free_list(&list);
        }
        else
            rc = ALLOCATE_ERROR;
    }
    else
        rc = DATA_ERROR;

    return rc;
}
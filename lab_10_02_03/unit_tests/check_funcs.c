#include "check_funcs.h"
#include "io_funcs.h"
#include "return_codes.h"
#include "list_funcs.h"
#include "additional_funcs.h"

#define NOT_EQUAL 1

/**
 * \brief compare_lists - Функция, которая сравнивает элементы двух списков
 * \param list Структура списка
 * \param arr Результат исходного списка
 * \return Код успеха или код ошибки 
 */
int compare_lists(node_t **list, int *arr)
{
    int index = 0; // индекс элемента массива
    int rc = OK; // код возврата

    while (*list && rc == OK)
    {
        if ((*list)->data != arr[index])
            rc = NOT_EQUAL;

        *list = (*list)->next;
        index++;
    }
    return rc;
}

#define ARR_LEN 50

/**
 * \brief test_process_out - Обычный тест для функции process_out
 * 
 */
START_TEST(test_process_out)
{
    size_t num = 24; // входное число
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    node_t *temp_list = NULL; // Вспомагательная структура списка
    int result[ARR_LEN] = {3, 1}; // ожидаемый результат
    
    list = create_list(num);

    if (list)
    {
        temp_list = list;
        rc = compare_lists(&temp_list, result);
    
        free_list(&list);
    }
    else
        rc = ALLOCATE_ERROR;

    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_process_sqr - Обычный тест для функции process_sqr
 * 
 */
START_TEST(test_process_sqr)
{
    size_t num = 121; // входное число
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    node_t *temp_list = NULL; // Вспомагательная структура списка
    int result[ARR_LEN] = {0, 0, 0, 0, 4}; // ожидаемый результат
    
    list = create_list(num);

    if (list)
    {
        sqr_num(list);
        temp_list = list;
        rc = compare_lists(&temp_list, result);
        free_list(&list);
    }
    else
        rc = ALLOCATE_ERROR;

    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_process_mul - Обычный тест для функции process_mul
 * 
 */
START_TEST(test_process_mul)
{
    size_t first_num = 16, second_num = 3, result; // входные числа
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    node_t *temp_list = NULL; // Вспомагательная структура списка
    int temp_result[ARR_LEN] = {4, 1}; // ожидаемый результат
    
    result = first_num * second_num;
    list = create_list(result);

    if (list)
    {
        temp_list = list;
        rc = compare_lists(&temp_list, temp_result);
        free_list(&list);
    }
    else
        rc = ALLOCATE_ERROR;

    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_process_div - Обычный тест для функции process_div
 * 
 */
START_TEST(test_process_div)
{
    size_t first_num = 36, second_num = 6, result; // входные числа
    int rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    node_t *temp_list = NULL; // Вспомагательная структура списка
    int temp_result[ARR_LEN] = {3, 3}; // ожидаемый результат
    
    result = first_num * second_num;
    list = create_list(result);

    if (list)
    {
        temp_list = list;
        rc = compare_lists(&temp_list, temp_result);
        free_list(&list);
    }
    else
        rc = ALLOCATE_ERROR;

    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief neg_test_mul - Негативный тест для функции process_mul(умножение на ноль)
 * 
 */
START_TEST(neg_test_mul)
{
    size_t first_num = 16, second_num = 0, result; // входные числа
    size_t rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    
    result = first_num * second_num;
    list = create_list(result);

    if (list == NULL)
        rc = ALLOCATE_ERROR;

    ck_assert_uint_eq(rc, ALLOCATE_ERROR);
}
END_TEST

/**
 * \brief first_neg_test_div - Негативный тест для функции process_div (деление на ноль)
 * 
 */
START_TEST(first_neg_test_div)
{
    size_t first_num = 16, second_num = 0, result; // входные числа
    size_t rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    
    if (second_num == 0)
        rc = DATA_ERROR;
    else
    {
        result = first_num / second_num;
        list = create_list(result);

        if (list == NULL)
            rc = ALLOCATE_ERROR;
    }

    ck_assert_uint_eq(rc, DATA_ERROR);
}
END_TEST

/**
 * \brief second_neg_test_div - Негативный тест для функции process_div (маленькое число деленое на большое)
 * 
 */
START_TEST(second_neg_test_div)
{
    size_t first_num = 4, second_num = 9, result; // входные числа
    size_t rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    
    if (first_num < second_num)
    {
        rc = DATA_ERROR;
    }
    else
    {
        result = first_num / second_num;
        list = create_list(result);

        if (list == NULL)
        {
            rc = ALLOCATE_ERROR;
        }
    }

    ck_assert_uint_ne(rc, OK);
}
END_TEST

/**
 * \brief third_neg_test_div - Негативный тест для функции process_div (ноль деленое на число)
 * 
 */
START_TEST(third_neg_test_div)
{
    size_t first_num = 0, second_num = 9, result; // входные числа
    size_t rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    
    result = first_num / second_num;
    list = create_list(result);

    if (list == NULL)
        rc = ALLOCATE_ERROR;

    ck_assert_uint_eq(rc, ALLOCATE_ERROR);
}
END_TEST

/**
 * \brief neg_test_out - Негативный тест для функции process_out(входное число равно нулю)
 * 
 */
START_TEST(neg_test_out)
{
    size_t num = 0; // входные числа
    size_t rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    
    list = create_list(num);

    if (list == NULL)
        rc = ALLOCATE_ERROR;

    ck_assert_uint_eq(rc, ALLOCATE_ERROR);
}
END_TEST

/**
 * \brief neg_test_sqr - Негативный тест для функции process_sqr(входное число равно нулю)
 * 
 */
START_TEST(neg_test_sqr)
{
    size_t num = 0; // входные числа
    size_t rc = OK; // код возврата
    node_t *list = NULL; // Структура исходного списка
    
    list = create_list(num);

    if (list == NULL)
        rc = ALLOCATE_ERROR;

    ck_assert_uint_eq(rc, ALLOCATE_ERROR);
}
END_TEST

Suite *check_funcs_suite()
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("CHECK_FUNCS");
    tc_pos = tcase_create("POSITIVE TESTS");

    tcase_add_test(tc_pos, test_process_out);
    tcase_add_test(tc_pos, test_process_mul);
    tcase_add_test(tc_pos, test_process_div);
    tcase_add_test(tc_pos, test_process_sqr);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("NEGATIVE TESTS");
    tcase_add_test(tc_neg, neg_test_mul);
    tcase_add_test(tc_neg, first_neg_test_div);
    tcase_add_test(tc_neg, second_neg_test_div);
    tcase_add_test(tc_neg, third_neg_test_div);
    tcase_add_test(tc_neg, neg_test_out);
    tcase_add_test(tc_neg, neg_test_sqr);
    suite_add_tcase(s, tc_neg);

    return s;
}
#include "check_funcs.h"
#include "return_codes.h"
#include "struct.h"
#include "io_funcs.h"
#include "list_func.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief test_pop_end - Обычный тест для функции pop_end, которая удаляет элемент, который
 * находится в хвосте списка
 * 
 */
START_TEST(test_pop_end)
{
    node_t *head = NULL, *result = NULL;
    const char *input_file_name = "./func_tests/data/pos_04_in.txt";
    const char *output_file_name = "./func_tests/data/pos_04_out.txt";
    node_t *temp_head = NULL, *temp_result = NULL, *node = NULL;
    int rc = OK;
    
    rc = read_file(&head, input_file_name);
    
    if (rc == OK)
    {
        node = pop_end(&head);
        free_list(&node);
        rc = read_file(&result, output_file_name);

        if (rc == OK)
        {
            temp_head = head;
            temp_result = result;

            while (temp_head)
            {
                ck_assert_int_eq(((package_t *)(temp_head->data))->number, ((package_t *)(temp_result->data))->number);
                ck_assert_double_eq(((package_t *)(temp_head->data))->weight, ((package_t *)(temp_result->data))->weight);
                temp_head = temp_head->next;
                temp_result = temp_result->next;
            }
            if (result)
                free_list(&result);
            
            if (head)
                free_list(&head);
        }
        else
            free_list(&head);
    }
    
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_pop_front - Обычный тест для функции pop_front, которая удаляет элемент, который
 * находится в голове списка
 * 
 */
START_TEST(test_pop_front)
{
    node_t *head = NULL, *result = NULL;
    const char *input_file_name = "./func_tests/data/pos_03_in.txt";
    const char *output_file_name = "./func_tests/data/pos_03_out.txt";
    node_t *temp_head = NULL, *temp_result = NULL, *node = NULL;
    package_t *temp_node = NULL;
    int rc = OK;

    rc = read_file(&head, input_file_name);

    if (rc == OK)
    {
        node = head;
        temp_node = pop_front(&head);
        free(temp_node);
        free(node);
        
        rc = read_file(&result, output_file_name);

        if (rc == OK)
        {
            temp_head = head;
            temp_result = result;

            while (temp_head)
            {
                ck_assert_int_eq(((package_t *)(temp_head->data))->number, ((package_t *)(temp_result->data))->number);
                ck_assert_double_eq(((package_t *)(temp_head->data))->weight, ((package_t *)(temp_result->data))->weight);
                temp_head = temp_head->next;
                temp_result = temp_result->next;
            }
            if (result)
                free_list(&result);

            if (head)
                free_list(&head);
        }
        else
            free_list(&head);
    }
    
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_sort - Обычный тест для функции sort, которая сортирует список по возрастанию
 * 
 */
START_TEST(test_sort)
{
    node_t *head = NULL, *result = NULL;
    node_t *temp_head = NULL, *temp_result = NULL;
    const char *input_file_name = "./func_tests/data/pos_01_in.txt";
    const char *output_file_name = "./func_tests/data/pos_01_out.txt";
    int rc = OK;

    rc = read_file(&head, input_file_name);
    
    if (rc == OK)
    {
        head = sort(head, compare_packages);
        rc = read_file(&result, output_file_name);
        
        if (rc == OK)
        {
            temp_head = head;
            temp_result = result;

            while (temp_head)
            {
                ck_assert_int_eq(((package_t *)(temp_head->data))->number, ((package_t *)(temp_result->data))->number);
                ck_assert_double_eq(((package_t *)(temp_head->data))->weight, ((package_t *)(temp_result->data))->weight);
                temp_head = temp_head->next;
                temp_result = temp_result->next;
            }
            if (result)
            {
                free_list(&result);
            }

            if (head)
            {
                free_list(&head);
            }
        }
        else
            free_list(&head);
    }
    
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_reverse - Обычный тест для функции reverse, которая переварачивает элементы списока в обратном порядке
 * 
 */
START_TEST(test_reverse)
{
    node_t *head = NULL, *result = NULL;
    node_t *temp_head = NULL, *temp_result = NULL;
    const char *input_file_name = "./func_tests/data/pos_02_in.txt";
    const char *output_file_name = "./func_tests/data/pos_02_out.txt";
    int rc = OK;

    rc = read_file(&head, input_file_name);
    
    if (rc == OK)
    {
        head = reverse(head);
        rc = read_file(&result, output_file_name);

        if (rc == OK)
        {
            temp_head = head;
            temp_result = result;

            while (temp_head)
            {
                ck_assert_int_eq(((package_t *)(temp_head->data))->number, ((package_t *)(temp_result->data))->number);
                ck_assert_double_eq(((package_t *)(temp_head->data))->weight, ((package_t *)(temp_result->data))->weight);
                temp_head = temp_head->next;
                temp_result = temp_result->next;
            }
            if (result)
                free_list(&result);
            
            if (head)
                free_list(&head);
        }
        else
            free_list(&head);
    }
    
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief test_empty_file - Тест, который тестирует программу, когда входный файл пустой
 * 
 */
START_TEST(test_empty_file)
{
    node_t *head = NULL;
    const char *input_file_name = "./func_tests/data/neg_01_in.txt";
    int rc = OK;

    rc = read_file(&head, input_file_name);
    
    ck_assert_int_ne(rc, OK);
}
END_TEST

/**
 * \brief test_wrong_file - Тест, который тестирует программу, когда входный файл не существует
 * 
 */
START_TEST(test_wrong_file)
{
    node_t *head = NULL;
    const char *input_file_name = "./func_tests/data/neg_01asd_in.txt";
    int rc = OK;

    rc = read_file(&head, input_file_name);
    
    ck_assert_int_ne(rc, OK);
}
END_TEST

/**
 * \brief test_wrong_data - Тест, который тестирует программу, когда входный файл содержит неправильные данные
 * 
 */
START_TEST(test_wrong_data)
{
    node_t *head = NULL;
    const char *input_file_name = "./func_tests/data/neg_04_in.txt";
    int rc = OK;

    rc = read_file(&head, input_file_name);

    if (head)
        free_list(&head);
    
    ck_assert_int_ne(rc, OK);
}
END_TEST

Suite *check_funcs_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("CHECK_FUNCS");
    tc_pos = tcase_create("POSITIVE TESTS");

    tcase_add_test(tc_pos, test_sort);
    tcase_add_test(tc_pos, test_reverse);
    tcase_add_test(tc_pos, test_pop_end);
    tcase_add_test(tc_pos, test_pop_front);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("NEGATIVE TESTS");
    tcase_add_test(tc_neg, test_empty_file);
    tcase_add_test(tc_neg, test_wrong_file);
    tcase_add_test(tc_neg, test_wrong_data);
    suite_add_tcase(s, tc_neg);

    return s;
}
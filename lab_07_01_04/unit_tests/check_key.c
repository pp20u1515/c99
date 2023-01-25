#include "check_key.h"
#include "additional_funcs.h"
#include "return_codes.h"

#include <stdlib.h>

#define ERROR 1

int cmp(const int *ptr_start, const int *ptr_end, const int *arr, const size_t size)
{
    int rc = OK;

    if (ptr_start < ptr_end)
    {
        for (size_t i = 0; rc == OK && i < size; i++)
            if (arr[i] != *(ptr_start + i))
                rc = ERROR;
    }
    else 
        rc = ERROR;

    return rc;
}

/**
 * \brief Негативный тест, где в массиве нет элементов
 */
START_TEST(key_test_no_elem)
{
    int arr[] = {1};
    size_t size = 0;
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr, arr + size, &new_arr, &new_size);
    ck_assert_int_eq(rc, KEY_ERROR);
}
END_TEST

/**
 * \brief Негативный тест, где указатели на начало и конец исходного массива указаны неправильно
 */
START_TEST(key_test_invalid_src_order)
{
    int arr[] = {1, 2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr + size, arr, &new_arr, &new_size);
    ck_assert_int_eq(rc, KEY_ERROR);
}   
END_TEST

/**
 * \brief Негативный тест, где в массиве только один элемент
 */
START_TEST(key_test_one_elem)
{
    int arr[] = {1};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr, arr + size, &new_arr, &new_size);
    free(new_arr);
    ck_assert_int_eq(rc, DATA_ERROR);
}   
END_TEST

/**
 * \brief Негативный тест, где в массиве все элементы одинаковые
 */
START_TEST(key_test_all_eq_elem)
{
    int arr[] = {7, 7, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr, arr + size, &new_arr, &new_size);
    free(new_arr);
    ck_assert_int_eq(rc, DATA_ERROR);
}   
END_TEST

/**
 * \brief Положительный тест, где в массиве только два элемента
 */
START_TEST(key_test_two_different_elem)
{
    int arr[] = {1, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr, arr + size, &new_arr, &new_size);
    int result[] = { 7 };
    rc += cmp(new_arr, new_size, result, sizeof(result) / sizeof(result[0]));
    free(new_arr);
    ck_assert_int_eq(rc, OK);
}   
END_TEST

/**
 * \nbrief Положительный тест, где в массиве только отрицательные числа
 */
START_TEST(key_test_two_different_neg_elem)
{
    int arr[] = {-1, -7};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr, arr + size, &new_arr, &new_size);
    int result[] = {-1};
    rc += cmp(new_arr, new_size, result, sizeof(result) / sizeof(result[0]));
    free(new_arr);
    ck_assert_int_eq(rc, OK);
}   
END_TEST

/**
 * \brief Положительный тест, где некоторые элементы массива одинаковы
 */
START_TEST (key_test_some_same_elems)
{
    int arr[] = {-1, -7, 2, 2, 9, 1, 0, 5, 5, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int *new_arr = NULL, *new_size = NULL;
    int rc = key(arr, arr + size, &new_arr, &new_size);
    int result[] = {9, 5, 5, 5};
    rc += cmp(new_arr, new_size, result, sizeof(result) / sizeof(result[0]));
    free(new_arr);
    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("key");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, key_test_no_elem);
    tcase_add_test(tc_neg, key_test_invalid_src_order);
    tcase_add_test(tc_neg, key_test_one_elem);
    tcase_add_test(tc_neg, key_test_all_eq_elem);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, key_test_two_different_elem);
    tcase_add_test(tc_pos, key_test_two_different_neg_elem);
    tcase_add_test(tc_pos, key_test_some_same_elems);
    suite_add_tcase(s, tc_pos);
    
    return s;
}

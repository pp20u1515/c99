#include "check_mysort.h"
#include "check_key.h"
#include "additional_funcs.h"
#include "return_codes.h"

#include <check.h>

#define ERROR 1

/**
 * \brief Тест, где в массиве только один элемент
 */
START_TEST(test_one_elem)
{
    int arr[] = {7};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {7};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}   
END_TEST

/**
 * \brief Тест, где в массиве два разные числа
 */
START_TEST(test_two_different_elem)
{
    int arr[] = {5, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {3, 5};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}
END_TEST

/**
 * \brief Тест, где массив состоит из несколько одинаковых элементов
 */
START_TEST(test_with_some_eq_elem)
{
    int arr[] = {3, 1, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {1, 3, 3};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}
END_TEST

/**
 * \brief Тест, где элементы массива уже упорядочены по возрастанию
 */
START_TEST(test_different_elem)
{
    int arr[] = {1, 2, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {1, 2, 3};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}
END_TEST

/**
 * \brief Тест, в котором массив состоит из положительниых и отрицательных элементов
 */
START_TEST(test_with_neg_elem)
{
    int arr[] = {1, -3, 22};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {-3, 1, 22};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}
END_TEST

/**
 * \brief Тест, где все элементы массива упорядочены по убыванию
 */
START_TEST(test_with_reverse_sequence)
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}
END_TEST

/**
 * \brief Тест, где в элементы массива одинаковые
 */
START_TEST(test_with_same_elems)
{
    int arr[] = {5, 5, 5, 5, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int new_arr[] = {5, 5, 5, 5, 5};
    mysort(arr, size, sizeof(int), compare);
    ck_assert_int_eq(cmp(arr, arr + size, new_arr, size), OK);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");
    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_two_different_elem);
    tcase_add_test(tc_pos, test_with_some_eq_elem);
    tcase_add_test(tc_pos,test_different_elem);
    tcase_add_test(tc_pos, test_with_neg_elem);
    tcase_add_test(tc_pos, test_with_reverse_sequence);
    tcase_add_test(tc_pos, test_with_same_elems);
    suite_add_tcase(s, tc_pos);
    return s;
}

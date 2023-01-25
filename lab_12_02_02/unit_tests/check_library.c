#include "library.h"
#include "check_library.h"

int compare_result(int *src, int *result, const int size)
{
    int flag = 1;
    
    for (int index = 0; flag == 1 && index < size; index++)
        if (src[index] != result[index])
            flag = 0;
            
    return flag;
}

/**
 * \brief Обычный тест, где печатаются 5 чисел Фибоначчи
 */
START_TEST(first_test_fibonacci)
{
    int src[5];
    int result[5] = {1, 1, 2, 3, 5};
    int size = 5;
    
    fill_array(src, size);
    
    int flag = compare_result(src, result, size);
    
    ck_assert_int_eq(flag, 1);
}
END_TEST

/**
 * \brief Обычный тест, где печатаются 20 чисел Фибоначчи
 */
START_TEST(second_test_fibonacci)
{
    int src[20];
    int result[20] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};
    int size = 20;
    
    fill_array(src, size);
    
    int flag = compare_result(src, result, size);
    
    ck_assert_int_eq(flag, 1);
}
END_TEST

/**
 * \brief Обычный тест, где печатаются 3 чисел Фибоначчи
 */
START_TEST(third_test_fibonacci)
{
    int src[1];
    int result[1] = {1};
    int size = 1;
    
    fill_array(src, size);
    
    int flag = compare_result(src, result, size);
    
    ck_assert_int_eq(flag, 1);
}
END_TEST

/**
 * \brief Обычный тест, где в массиве некоторые элементы повторяются
 */
START_TEST(first_filter_test)
{
    int src[10] = {1, 1, 2, 2, 3, 3, 4, 4, 3, 4};
    int dst[4];
    int result[4] = {1, 2, 3, 4};
    int size = 10, new_size = 0;
    
    new_size = filter(src, size, dst);
    
    int flag = compare_result(dst, result, new_size);
    
    ck_assert_int_eq(flag, 1);
}
END_TEST

/**
 * \brief Обычный тест, где в массиве все элементы различные
 */
START_TEST(second_filter_test)
{
    int src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dst[10];
    int result[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10, new_size = 0;
    
    new_size = filter(src, size, dst);
    
    int flag = compare_result(dst, result, new_size);
    
    ck_assert_int_eq(flag, 1);
}
END_TEST

Suite *library_suite()
{
    Suite *s;
    TCase *tc_pos;
    
    s = suite_create("TEST LIBRARY");
    tc_pos = tcase_create("positive tests");
    
    tcase_add_test(tc_pos, first_test_fibonacci);
    tcase_add_test(tc_pos, second_test_fibonacci);
    tcase_add_test(tc_pos, third_test_fibonacci);
    tcase_add_test(tc_pos, first_filter_test);
    tcase_add_test(tc_pos, second_filter_test);
    suite_add_tcase(s, tc_pos);
    
    return s;
}

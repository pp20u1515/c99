#include "product.h"
#include "arr_product.h"
#include "return_codes.h"
#include "check_additional_funcs.h"
#include "additional_funcs.h"

#include <stdio.h>

/**
 * @brief normal_tes - Положительный тест, при чтением данных из файла
 * 
 */
START_TEST(normal_test)
{
    products_t *products = NULL;
    size_t size = 0;
    FILE *f_open = fopen("./func_tests/data/pos_02_in.txt", "r");
    size_t rc = OK;
    
    if (f_open)
    {
        products = read_data(f_open, &size);

        if (products == NULL)
            rc = ALLOCATE_ERROR;
        else
            free_data(products, size);

        fclose(f_open);
    }

    ck_assert_uint_eq(rc, OK);
}
END_TEST

/**
 * @brief negative_price - Тест, в котором цена продукта отрицательная
 * 
 */
START_TEST(negative_price)
{
    products_t *products = NULL;
    size_t size = 0;
    FILE *f_open = fopen("./func_tests/data/neg_06_in.txt", "r");
    size_t rc = OK;

    products = read_data(f_open, &size);

    if (products == NULL)
        rc = ALLOCATE_ERROR;

    fclose(f_open);
    
    ck_assert_uint_ne(rc, OK);
}
END_TEST

/**
 * @brief price_string - Тест, в котором цена продукта является символом
 * 
 */
START_TEST(price_string)
{
    products_t *products = NULL;
    size_t size = 0;
    FILE *f_open = fopen("./func_tests/data/neg_07_in.txt", "r");
    size_t rc = OK;

    products = read_data(f_open, &size);

    if (products == NULL)
        rc = ALLOCATE_ERROR;

    fclose(f_open);
    
    ck_assert_uint_ne(rc, OK);
}
END_TEST

/**
 * @brief wrong_file - Тест, в котором файл с данными не существует
 * 
 */
START_TEST(wrong_file)
{
    FILE *f_open = fopen("./func_tests/data/neg_07777_in.txt", "r");
    size_t rc = OK;

    if (f_open == NULL)
        rc = FREAD_ERROR;    
    else
        fclose(f_open);
    
    ck_assert_uint_ne(rc, OK);
}
END_TEST

/**
 * @brief no_products - Тест, в котором указано 0 продуктов
 * 
 */
START_TEST(no_products)
{
    products_t *products = NULL;
    size_t size = 0;
    FILE *f_open = fopen("./func_tests/data/neg_05_in.txt", "r");
    size_t rc = OK;

    products = read_data(f_open, &size);

    if (products == NULL)
        rc = ALLOCATE_ERROR;

    fclose(f_open);

    ck_assert_uint_ne(rc, OK);
}
END_TEST

Suite *test_additional_funcs_suite()
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("TESTS");
    
    tc_pos = tcase_create("Positive Tests");
    tcase_add_test(tc_pos, normal_test);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("Negative Tests");
    tcase_add_test(tc_neg, negative_price);
    tcase_add_test(tc_neg, price_string);
    tcase_add_test(tc_neg, wrong_file);
    tcase_add_test(tc_neg, no_products);
    suite_add_tcase(s, tc_neg);

    return s;
}
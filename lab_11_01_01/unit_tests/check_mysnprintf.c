#include "my_snprintf.h"
#include "check_mysnprintf.h"

#define MAX_SIZE 500
#define OK 0
#define ERROR 1

#include <string.h>
#include <stdint.h>
#include <limits.h>

/**
 * \brief Обычный тест для спецификатора %s 
 * 
 */
START_TEST(normal_string_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    char *string = "game";
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%s", string);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%s", string);
    
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Tест для спецификатора %s, который содержит больше слов 
 * 
 */
START_TEST(normal_many_string_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    char *first_string = "game llk 23";
    char *second_string = "llk 23";
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%s%s%s", first_string, second_string, first_string);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%s%s%s", first_string, second_string, first_string);
    
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_str_eq(my_buf, lib_buf);
    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);

}
END_TEST

/**
 * \brief Тест для спецификатора %s, где записано символ размер максималного размера массива 
 * 
 */
START_TEST(second_normal_string_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    char *num = "gameegameegameegameegameegameegameegameegameegamee";
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%s", num);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%s", num);
    
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Тест для спецификатора %х, где записано маленькое число
 * 
 */
START_TEST(normal_hex_num_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    int num = 59;
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Тест для спецификатора %х, где записано среднее число
 * 
 */
START_TEST(second_normal_hex_num_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    int num = 1897; 
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Тест для спецификатора %х, где записано большое число
 * 
 */
START_TEST(third_normal_hex_num_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    int num = 189721123; 
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Тест для спецификатора %х, количество спецификатороф больше одного
 * 
 */
START_TEST(normal_hex_many_num_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    unsigned int first_num = 189721123, second_num = 0; 
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%x%x", first_num, second_num);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%x%x", first_num, second_num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_str_eq(my_buf, lib_buf);
    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Тест для спецификатора %х, в котором целое число имеет максимальное значение
 * 
 */
START_TEST(normal_hex_max_num_test)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    unsigned int num = UINT_MAX;
    int flag = 0;
    int first_rc, second_rc;

    first_rc = snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    second_rc = my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
    ck_assert_int_eq(first_rc, second_rc);
}
END_TEST

/**
 * \brief Негативный тест для спецификатора %s, где буффер равен NULL
 * 
 */
START_TEST(first_test_null_buf)
{
    char *string = "31754"; 
	
    ck_assert_int_eq(my_snprintf(NULL, 0, "%s", string), snprintf(NULL, 0, "%s", string));
}
END_TEST

/**
 * \brief Негативный тест для спецификатора %x, где буффер равен NULL
 * 
 */
START_TEST(second_test_null_buf)
{
    int num = 31754; 
	
    ck_assert_int_eq(my_snprintf(NULL, 0, "%x", num), snprintf(NULL, 0, "%x", num));
}
END_TEST

/**
 * \brief Негативный тест для спецификатора %s, где размер буффера равен 0
 * 
 */
START_TEST(first_test_zero_len)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    char *string = "31754"; 
	
    ck_assert_int_eq(my_snprintf(my_buf, 0, "%s", string), snprintf(lib_buf, 0, "%s", string));
}
END_TEST

/**
 * \brief Негативный тест для спецификатора %x, где размер буффера равен 0
 * 
 */
START_TEST(second_test_zero_len)
{
    char my_buf[MAX_SIZE + 1] = "\0", lib_buf[MAX_SIZE + 1] = "\0";
    int num = 31754; 
	
    ck_assert_int_eq(my_snprintf(my_buf, 0, "%x", num), snprintf(lib_buf, 0, "%x", num));
    ck_assert_str_eq(my_buf, lib_buf);
}
END_TEST

Suite *snprintf_tests(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("snprintf tests");
    
    tc_pos = tcase_create("Positive tests");
    tcase_add_test(tc_pos, normal_hex_num_test);
    tcase_add_test(tc_pos, second_normal_hex_num_test);
    tcase_add_test(tc_pos, third_normal_hex_num_test);
    tcase_add_test(tc_pos, normal_string_test);
    tcase_add_test(tc_pos, second_normal_string_test);
    tcase_add_test(tc_pos, normal_many_string_test);
    tcase_add_test(tc_pos, normal_hex_many_num_test);
    tcase_add_test(tc_pos, normal_hex_max_num_test);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("Negative tests");
    tcase_add_test(tc_neg, first_test_null_buf);
    tcase_add_test(tc_neg, second_test_null_buf);
    tcase_add_test(tc_neg, first_test_zero_len);
    tcase_add_test(tc_neg, second_test_zero_len);
    suite_add_tcase(s, tc_neg);

    return s;
}

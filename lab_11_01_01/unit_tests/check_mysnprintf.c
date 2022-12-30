#include "my_snprintf.h"
#include "check_mysnprintf.h"

#define MAX_SIZE 50
#define OK 0
#define ERROR 1

#include <string.h>
#include <stdint.h>

START_TEST(normal_string_test)
{
    char my_buf[MAX_SIZE + 1], lib_buf[MAX_SIZE + 1];
    char *num = "game";
    int flag = 0;

    snprintf(lib_buf, MAX_SIZE + 1, "%s", num);
    my_snprintf(my_buf, MAX_SIZE + 1, "%s", num);
    
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(normal_hex_num_test)
{
    char my_buf[MAX_SIZE + 1], lib_buf[MAX_SIZE + 1];
    uint32_t num = 59;
    int flag = 0;

    snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
}
END_TEST

START_TEST(second_normal_hex_num_test)
{
    char my_buf[MAX_SIZE + 1], lib_buf[MAX_SIZE + 1];
    uint32_t num = 1897; 
    int flag = 0;

    snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
}
END_TEST
/*
START_TEST(string_to_hex_num_test)
{
    char my_buf[MAX_SIZE + 1], lib_buf[MAX_SIZE + 1];
    char *num = "1897"; 
    int flag = 0;

    snprintf(lib_buf, MAX_SIZE + 1, "%x", num);
    my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	
	if (strcmp(my_buf, lib_buf) == 0)
		flag = 1;

    ck_assert_int_eq(flag, 1);
}
END_TEST*/

START_TEST(neg_string_test)
{
    char my_buf[MAX_SIZE + 1], lib_buf[MAX_SIZE + 1];
    char *num = "game";
    int rc = OK;
    
    rc = my_snprintf(my_buf, MAX_SIZE + 1, "%d", num);

    if (rc != ERROR)
	{
	    if (strcmp(my_buf, lib_buf) == 0)
		    rc = OK;
        else
            rc = ERROR;
    }
    ck_assert_int_eq(rc, ERROR);
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
    tcase_add_test(tc_pos, normal_string_test);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("Negative tests");
	tcase_add_test(tc_neg, neg_string_test);
    suite_add_tcase(s, tc_neg);

    return s;
}

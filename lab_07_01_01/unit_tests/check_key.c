#include "../inc/check_key.h"
#include "../inc/return_codes.h"
#include "../inc/additional_funcs.h"
#include "../inc/struct.h"

int cmp_key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    for (int i = 0; i < pe_src)
}

START_TEST (key_test_no_elem)
{
    int arr[5] = {3, 2, 0, 1, 5};
    int n = 0;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr, arr + n, pb_dst, pe_dst);
    
    ck_assert_int_eq(rc, DATA_ERROR);
}
END_TEST

START_TEST (key_test_wrong_seq)
{
    int arr[5] = {3, 2, 1, 0, 6};
    int n = 5;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr, arr + n, pb_dst, pe_dst);

    ck_assert_int_eq(rc, DATA_ERROR);
}
END_TEST

START_TEST (key_test_same_elems)
{
    int arr[5] = {5, 5, 5, 5, 5};
    int n = 5;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr, arr + n, pb_dst, pe_dst);

    ck_assert_int_eq(rc, DATA_ERROR);
}
END_TEST

START_TEST (normal_key_test)
{
    int arr[5] = {3, 0, 2, 1, 5};
    int n = 5;
    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int rc = key(arr, arr + n, pb_dst, pe_dst);
    rc += cmp_key(pb_dst, pe_dst, arr, arr + n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite *key_suite()
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("key");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, key_test_no_elem);
    tcase_add_test(tc_neg, key_test_wrong_seq);
    tcase_add_test(tc_neg, key_test_same_elems);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positive");

    tcase_add_test(tc_pos, normal_key_test);
    suite_add_tcase(s, tc_pos);

    return s;
}
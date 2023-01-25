#include "struct.h"
#include "return_codes.h"
#include "matrix_operations.h"
#include "check_matrix_operations.h"

#define N 10
#define EPS 0.0000007

int compare_matrix(double (*temp_data)[N], const matrix_t matrix)
{
    for (size_t index_i = 0; index_i < matrix.rows; index_i++)
        for (size_t index_j = 0; index_j < matrix.columns; index_j++)
            if (temp_data[index_i][index_j] - matrix.data[index_i][index_j] > EPS)
                return DATA_ERROR;

    return OK;
}

/**
 * \brief sum_two_matrix - Обычный тест для сложения двух матриц
 */
START_TEST(sum_two_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    double my_result[N][N]; // ожидаемый результат
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; 
    const char *first_file_name = "./func_tests/data/pos_02_01_in.txt";
    const char *second_file_name = "./func_tests/data/pos_02_02_in.txt";

    rc = sum_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);
    
    my_result[0][0] = 2.000000;
    my_result[0][1] = 5.000000;
    my_result[0][2] = 0.000000;
    my_result[1][0] = 0.000000;
    my_result[1][1] = 4.000000;
    my_result[1][2] = 9.000000;
    my_result[2][0] = 0.000000;
    my_result[2][1] = 0.000000;
    my_result[2][2] = 6.000000;
    
    if (rc == OK)
    {
        rc = compare_matrix(my_result, result);
        free_matrix(result.data, result.rows);
    }
    
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief mult_two_matrix - Обычный тест для умножения двух матриц
 */
START_TEST(mult_two_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    double my_result[N][N]; // ожидаемый результат
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; 
    const char *first_file_name = "./func_tests/data/pos_03_01_in.txt";
    const char *second_file_name = "./func_tests/data/pos_03_02_in.txt";

    rc = multiply_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);
    
    my_result[0][0] = 1.000000;
    my_result[0][1] = 5.000000;
    my_result[0][2] = 0.000000;
    my_result[1][0] = 0.000000;
    my_result[1][1] = 4.000000;
    my_result[1][2] = 18.000000;
    my_result[2][0] = 0.000000;
    my_result[2][1] = 0.000000;
    my_result[2][2] = 9.000000;

    if (rc == OK)
    {
        rc = compare_matrix(my_result, result);
        free_matrix(result.data, result.rows);
    }
    
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief normal_test_determ - Обычный тест для определителя матрицы
 */
START_TEST(normal_test_determ)
{
    matrix_t first_matrix; // Структура матрицы
    int rc = OK; // код возврата
    double determ; // определитель матрицы
    double my_result = 6.000000; // ожидаемый результат
    
    first_matrix.data = allocate_matrix(3, 3);
    first_matrix.rows = 3;
    first_matrix.columns = 3;

    first_matrix.data[0][0] = 1.000000;
    first_matrix.data[0][1] = 0.000000;
    first_matrix.data[0][2] = 0.000000;
    first_matrix.data[1][0] = 0.000000;
    first_matrix.data[1][1] = 2.000000;
    first_matrix.data[1][2] = 0.000000;
    first_matrix.data[2][0] = 0.000000;
    first_matrix.data[2][1] = 0.000000;
    first_matrix.data[2][2] = 3.000000;

    matrix_det(&first_matrix, &determ);

    if (determ - my_result < 0.0000001)
        rc = OK;
    else
        rc = DATA_ERROR;

    free_matrix(first_matrix.data, 3);
    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief first_neg_test_determ - Негативный тест для определителя матрицы(матрица не является квадратной)
 */
START_TEST(first_neg_test_determ)
{
    matrix_t first_matrix; // Структура матрицы
    int rc = OK; // код возврата
    double determ; // определитель матрицы
    
    first_matrix.rows = 2;
    first_matrix.columns = 3;

    rc = matrix_det(&first_matrix, &determ);

    ck_assert_int_eq(rc, DIMENSIONS_ERROR);
}
END_TEST

/**
 * \brief mult_matrix - Обычный тест для умножения матрицы 1х1 на матрицу 1х1
 */
START_TEST(mult_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    double my_result[N][N]; // ожидаемый результат
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; 
    const char *first_file_name = "./func_tests/data/pos_08_01_in.txt";
    const char *second_file_name = "./func_tests/data/pos_08_02_in.txt";

    rc = multiply_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);

    my_result[0][0] = 2.000000;

    if (rc == OK)
    {
        rc = compare_matrix(my_result, result);
        free_matrix(result.data, result.rows);
    }

    ck_assert_int_eq(rc, OK);
}
END_TEST

/**
 * \brief wrong_file_to_sum_matrix - Файлы с входными данными не существуют при сложением двух матриц. (негативный тест)
 */
START_TEST(wrong_file_to_sum_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    const char *first_file_name = "today.txt"; // Файл с входнимы данными для первой матрицы
    const char *second_file_name = "today.txt"; // Файл с входнимы данными для второй матрицы
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; // количество ненулевых элементов первой и
                                                              // второй матрицы
    
    rc = sum_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);

    ck_assert_int_eq(rc, FOPEN_ERROR);
}
END_TEST

/**
 * \brief wrong_file_to_multi_matrix - Файлы с входными данными не существуют при умножением двух матриц. (негативный тест) 
 */
START_TEST(wrong_file_to_multi_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    const char *first_file_name = "today.txt"; // Файл с входнимы данными для первой матрицы
    const char *second_file_name = "today.txt"; // Файл с входнимы данными для второй матрицы
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; // количество ненулевых элементов первой и
                                                              // второй матрицы
    
    rc = multiply_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);

    ck_assert_int_eq(rc, FOPEN_ERROR);
}
END_TEST

/**
 * \brief empty_file_to_sum_matrix - Файлы с входными данными пустой при сложением двух матриц. (негативный тест) 
 */
START_TEST(empty_file_to_sum_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    const char *first_file_name = "./func_tests/data/neg_05_01_in.txt"; // Файл с входнимы данными для первой матрицы
    const char *second_file_name = "./func_tests/data/neg_05_02_in.txt"; // Файл с входнимы данными для второй матрицы
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; // количество ненулевых элементов первой и
                                                              // второй матрицы
    
    rc = sum_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);

    ck_assert_int_ne(rc, OK);
}
END_TEST

/**
 * \brief empty_file_to_multi_matrix - Файлы с входными данными пустой при умножением двух матриц. (негативный тест) 
 */
START_TEST(empty_file_to_multi_matrix)
{
    matrix_t first_matrix, second_matrix, result; // структура первой и второй матриц и результата
    int rc = OK; // код возврата
    const char *first_file_name = "./func_tests/data/neg_05_01_in.txt"; // Файл с входнимы данными для первой матрицы
    const char *second_file_name = "./func_tests/data/neg_05_02_in.txt"; // Файл с входнимы данными для второй матрицы
    size_t first_nonzero_elems = 0, second_nonzero_elems = 0; // количество ненулевых элементов первой и
                                                              // второй матрицы
    
    rc = multiply_matrix(&first_matrix, &second_matrix, &result, first_file_name, second_file_name, &first_nonzero_elems, &second_nonzero_elems);

    ck_assert_int_ne(rc, OK);
}
END_TEST

/**
 * \brief second_neg_test_determ - Указано больше ненулевых элементов чем размер матрицы. (негативный тест) 
 */
START_TEST(second_neg_test_determ)
{
    matrix_t first_matrix; // Структура матрицы
    const char *first_file_name = "./func_tests/data/neg_14_01_in.txt"; // Файл с входнимы данными
    int rc = OK; // код возврата
    double determ; // определитель матрицы
    size_t nonzero_elems = 0; // количество ненулевых элементов матрицы

    rc = find_determ(first_file_name, &first_matrix, &determ, &nonzero_elems);

    ck_assert_int_ne(rc, OK);
}
END_TEST

Suite *test_matrix_funcs_suite()
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("TESTS");
    
    tc_pos = tcase_create("Positive Tests");
    tcase_add_test(tc_pos, sum_two_matrix);
    tcase_add_test(tc_pos, mult_two_matrix);
    tcase_add_test(tc_pos, normal_test_determ);
    tcase_add_test(tc_pos, mult_matrix);
    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("Negative Tests");
    tcase_add_test(tc_neg, first_neg_test_determ);
    tcase_add_test(tc_neg, wrong_file_to_sum_matrix);
    tcase_add_test(tc_neg, wrong_file_to_multi_matrix);
    tcase_add_test(tc_neg, empty_file_to_sum_matrix);
    tcase_add_test(tc_neg, empty_file_to_multi_matrix);
    tcase_add_test(tc_neg, second_neg_test_determ);
    suite_add_tcase(s, tc_neg);

    return s;
}

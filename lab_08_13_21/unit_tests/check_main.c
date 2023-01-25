#include "check_matrix_operations.h"
#include "../src/matrix_operations.c"
#include "../src/io_funcs.c"

int main()
{
    Suite *s;
    SRunner *runner;

    int rc;

    s = test_matrix_funcs_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    rc = srunner_ntests_failed(runner);
    srunner_free(runner);

    return rc;

}

#include "check_additional_funcs.h"
#include "arr_product.c"
#include "additional_funcs.c"
#include "product.c"

int main()
{
    Suite *s;
    SRunner *runner;

    int rc;

    s = test_additional_funcs_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    rc = srunner_ntests_failed(runner);
    srunner_free(runner);

    return rc;

}
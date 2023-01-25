#include "check_mysnprintf.h"
#include "../src/my_snprintf.c"

int main()
{
    Suite *s;
    SRunner *runner;

    int exit;

    s = snprintf_tests();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    exit = srunner_ntests_failed(runner);
    srunner_free(runner);

    return exit;
}

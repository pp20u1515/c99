#include "check_funcs.h"
#include "list_funcs.c"
#include "io_funcs.c"

#define ERROR 1

int main()
{
    int rc = 0;

    Suite *s;
    SRunner *runner;
    
    s = check_funcs_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    rc = srunner_ntests_failed(runner);
    srunner_free(runner);

    return rc;
}

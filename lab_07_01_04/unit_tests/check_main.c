#include "check_key.h"
#include "check_mysort.h"  
#include "return_codes.h"
#include "../src/additional_funcs.c"
#include "../src/io_funcs.c"

#define ERROR 1

int main()
{
    int no_failed_mysort = 0;
    int no_failed_key = 0;

    Suite *s;
    SRunner *runner;
    
    s = mysort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed_mysort = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = key_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed_key = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed_mysort + no_failed_key == 0) ? OK : ERROR;
}

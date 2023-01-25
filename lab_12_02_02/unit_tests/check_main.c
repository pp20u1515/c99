#include "check_library.h"
#include "library.c"

int main()
{
    int rc;
    SRunner *runner;
    
    runner = srunner_create(library_suite());
    
    srunner_run_all(runner, CK_VERBOSE);
    
    rc = srunner_ntests_failed(runner);
    
    srunner_free(runner);
    
    return rc == 0 ? 0 : 1;
}

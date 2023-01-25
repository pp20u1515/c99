#include "io_funcs.h"
#include "return_codes.h"
#include "struct.h"

#define BUFF_LEN 256

int main()
{
    get_mode_t mode; // Операция для выполнения
    int rc = OK; // код возврата

    get_mode(&mode);

    switch (mode)
    {
        case (OUT):
            rc = process_out();
            break;
        case (MUL):
            rc = process_mul();
            break;
        case (DIVIDE):
            rc = process_div();
            break;
        case (SQR):
            rc = process_sqr();
            break;
        default:
            rc = DATA_ERROR;
    }
    return rc;
}
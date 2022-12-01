#include "struct.h"
#include "io_funcs.h"
#include "return_codes.h"
#include "list_func.h"

#include <string.h>

int main(int argc, char **argv)
{
    node_t *node = NULL; // Структура списка
    size_t rc = OK; // код возврата
    
    if (argc == 4)
    {
        rc = read_file(&node, argv[2]);

        if (rc == OK && strcmp(argv[1], "end") == 0)
        {
            pop_end(&node);
            print_result(&node, argv[3]);
        }
        else if (rc == OK && strcmp(argv[1], "front") == 0)
        {
            pop_front(&node);
            print_result(&node, argv[3]);
        }
        else if (rc == OK && strcmp(argv[1], "reverse") == 0)
        {
            node = reverse(node);
            print_result(&node, argv[3]);
        }
        else if (rc == OK && strcmp(argv[1], "sort") == 0)
        {
            node = sort(node, compare_packages);
            print_result(&node, argv[3]);
        }
        else if (rc == OK && node)
        {
            free_list(&node);
            rc = ARGS_ERROR;
        }
    }
    else
        rc = ARGS_ERROR;

    return rc;
}
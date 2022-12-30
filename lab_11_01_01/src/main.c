#include "my_snprintf.h"

#include <stdint.h>

#define MAX_SIZE 50

int main()
{	
	char my_buf[MAX_SIZE + 1];
    //char *num = "game";
	char num = 'a';
    //my_snprintf(my_buf, MAX_SIZE + 1, "%s", num);
	//printf("buf = %s\n", my_buf);
	
	my_snprintf(my_buf, MAX_SIZE + 1, "%x", num);
	printf("buf = %s\n", my_buf);

	return 0;
}

#include "my_snprintf.h"

#include <stdarg.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 50

void fill_buf_string(char *buf, const size_t n, char *string, size_t *index)
{
	while (*string)
	{
		if (buf && n && *index < n)
		{
			*buf = *string;
			buf++;
		}
		
		*index += 1;
		string++;
	}
}

void fill_buf_hex_num(char *buf, uint32_t hex_num, size_t *size)
{
	uint32_t quotion = hex_num;
	int temp;
	char temp_buf[MAX_SIZE];
	int index = 0;
	
	while (quotion)
	{
		temp = quotion % 16;
			
		if (temp < 10)
			temp_buf[index] = 48 + temp;
		else
			temp_buf[index] = 87 + temp;
		
		index++;
		*size += 1;
		quotion /= 16;
	}
	index -= 1;
	
	for (int i = index; i >= 0; i--)
	{
		*buf = temp_buf[i];
		buf++;
	}
}

char *return_pointer(char *buf)
{
	size_t len = strlen(buf);

	while (len)
	{
		buf--;
		len -= 1;
	}
	return buf;
}

int my_snprintf(char *buf, size_t n, const char *format, ...)
{
	va_list vl;
	size_t cur_size = 0;
	
	va_start(vl, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			
			if (*format == 's')
			{
				char *symbol = va_arg(vl, char *);
				
				fill_buf_string(buf, n, symbol, &cur_size);
				format++;
			}
			else if (*format == 'x')
			{
				uint32_t hex_num = va_arg(vl, uint32_t);
				
				fill_buf_hex_num(buf, hex_num, &cur_size);
				format++;
			}
		}
		else
		{
			if (buf && cur_size < n)
				buf[cur_size] = *format;
			
			cur_size++;
			format++;
		}
	}
	if (buf && n)
	{
		if (cur_size < n)
			buf[cur_size] = '\0';
		else
			buf[n - 1] = '\0';
	}
	va_end(vl);
	
	return cur_size;
}

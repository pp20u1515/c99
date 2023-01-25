#include "my_snprintf.h"

#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define NUMBER_OF_DIGITS 32

void unsigned_num_to_str(unsigned long num, long unsigned base, char *str)
{
    unsigned char index = NUMBER_OF_DIGITS;
    char symb;
    char buff[NUMBER_OF_DIGITS];

    do
    {
        symb = num % base;

        if (symb < 10)
            symb += 48;
        else
            symb += 87;

        buff[--index] = symb;
        num /= base;
    }while (num);

    do
    {
        *str++ = buff[index++];
    } while (index < NUMBER_OF_DIGITS);

    *str = '\0';
}

char *num_to_str(long num, long unsigned base)
{
    char *buf = calloc(NUMBER_OF_DIGITS, sizeof(char));
    unsigned_num_to_str((long unsigned int)num, base, buf);

    return buf;
}

int digit_copy(char *buf, int count, size_t size, long number, long unsigned base)
{
    char *temp_buf = num_to_str(number, base);
    int j = 0;

    while (*(temp_buf + j))
    {
        if (buf && size && count < size)
            *(buf + count) = *(temp_buf + j);
            
        count++;
        j++;
    }
    free(temp_buf);

    return count; 
}

size_t copy_string(char *dest, const char *src, size_t src_index, const size_t dest_size)
{
    while (*src)
    {
        if (dest && dest_size && src_index < dest_size)
            *(dest + src_index) = *src;

        src_index++;
        src++;
    }

    return src_index;
}

int my_snprintf(char *buf, size_t n, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    size_t count = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            
            if (*format == 's')
            {
                const char *string = va_arg(args, char *);
                count = copy_string(buf, string, count, n);
            }
            else if (*format == 'x')
            {
                count = (size_t)digit_copy(buf, count, n, va_arg(args, unsigned), 16);
            }
            format++;
        }
        else
        {
            if (buf && n && count < n)
                *(buf + count) = *format;
            
            format++;
            count++;
        }
    }
    if (buf && n)
    {
        if (count < n)
            *(buf + count) = '\0';
        else
            *(buf + (n - 1)) = '\0';
    }

    va_end(args);
    
    return count;
}
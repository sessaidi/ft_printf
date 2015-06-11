#include "libprintf.h"

int ft_print_str(char *str)
{
    int pos;

    if (!str)
        write(2, "(null)", 6);
    else
    {
        pos = 0;
        while (str[pos])
        {
            ft_print_char(str[pos]);
            pos++;
        }
    }
    return ((!str) ? 6 : pos);
}

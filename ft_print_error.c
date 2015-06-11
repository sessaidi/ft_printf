#include "libprintf.h"

void ft_print_error(char *s, char *c)
{
    write(2, "\nerror : ", 9);
    write(2, s, ft_strlen(s));
    if (c)
    {
        write(2, "'", 1);
        write(2, c, (ft_strlen(c) > 1) ? 3 : 1);
        write(2, "’ in format", 11);
    }
    write(2, "\n", 1);
    exit(-1);
}
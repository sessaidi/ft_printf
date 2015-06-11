#include "libprintf.h"

int ft_print_double(double n, int l)
{
    ft_print_int((int)n);
    n -= (int)n;
    if (!n && !l)
        return (0);
    write(1, ".", 1);
    while ((!n && l) || l)
    {
        ft_print_int((int)(n * 10));
        n = n * 10 - ((int)(n * 10));
        l--;
    }
    return (0);
}
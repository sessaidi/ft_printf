#include "libprintf.h"

int     ft_print_wstr(wchar_t *s)
{
    int pos;

    if (!s)
        write(2, "(null)", 6);
    else
    {
        pos = 0;
        while (s[pos])
        {
            ft_print_wchar(s[pos]);
            pos++;
        }
    }
    return ((!s) ? 6 : pos);
}
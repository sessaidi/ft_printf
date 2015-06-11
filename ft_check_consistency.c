#include "libprintf.h"

int ft_check_consistency(const char *s, int pos)
{
    char c[2];

    if (!ft_charexist(FLAGS, s[pos]))
    {
        if (ft_charexist(ID, s[pos]))
        {
            c[0] = s[pos];
            c[1] = 0;
            ft_print_error("unknown conversion type character ", c);
        }
        else
            ft_print_error("unknown conversion type character ", "0xa");
    }
    return (0);
}
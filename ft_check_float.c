#include "libprintf.h"

int ft_check_float(const char *s, int *pos, t_env *e)
{
    int i;

    i = *pos;
    if (s[i] == '-')
    {    
        i++;
        e->padding = PAD_RIGHT;
        if (s[i] == '-')
            ft_print_error("repeated '-' flag in format.", 0);
        if (ft_charexist(&s[i], '-'))
            ft_print_error("unknown conversion type character", "-");
    }
    *pos = i;
    return (0);
}
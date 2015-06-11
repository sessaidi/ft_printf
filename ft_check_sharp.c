#include "libprintf.h"

int ft_check_sharp(const char *s, int *pos, t_env *e)
{
    int i;

    i = *pos;
    if (s[i] == '#')
    {    
        i++;
        e->sharp = 1;
        if (s[i] == '#')
            ft_print_error("repeated '#' flag in format.", 0);
        if (ft_charexist(&s[i], '#'))
            ft_print_error("unknown conversion type character", "#");
    }
    else
        return (0);
    *pos = i;
    return (1); 
}
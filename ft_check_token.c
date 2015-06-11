#include "libprintf.h"

int ft_check_token(const char *s, t_env *e, int *i)
{
    int pos;
    int act;

    pos = *i;
    if (!s[pos])
        return (-1);
    if (s[pos] == '%')
        return (ft_print_char(s[pos]));
    act = ft_check_sharp(s, &pos, e);
    ft_check_float(s, &pos, e);
    if (!act)
        ft_check_sharp(s, &pos, e);
    ft_check_padding(s, &pos, e);
    ft_check_consistency(s, pos);
    *i = pos;
    return (0);
}
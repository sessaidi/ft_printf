#include "libprintf.h"

int ft_check_padding(const char *s, int *pos, t_env *e)
{
    int l;
    int i;

    i = *pos;
    l = 0;
    while (s[i] == '0')
    {
        i++;
        l++;
        e->padding |= PAD_ZERO;
    }
    if (l > 1)
        ft_print_error("repeated '0' flag in format.", 0);
    e->width_l = ft_get_width(s, &i);
    if (s[i] == '.')
    {
        ++i;
        e->width_r = ft_get_width(s, &i);
    }
    *pos = i;
    return (0);
}
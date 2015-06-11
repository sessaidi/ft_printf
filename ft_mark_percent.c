#include "libprintf.h"

int ft_mark_percent(const char *fmt, int *pos, va_list ap)
{
    t_func  *tab_func;
    t_env   e;
    int     i;

    tab_func = ft_getfunc();
    i = *pos;
    ++i;
    ft_init(&e);
    if (ft_check_token(fmt, &e, &i) == 0)
    {
        if (ft_charexist(FLAGS, fmt[i]))
            tab_func[ft_getflag(fmt[i])](ap, e);
        else
            ft_print_char(fmt[i]);
    }
    *pos = i;
    return (1);
}
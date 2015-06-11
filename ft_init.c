#include "libprintf.h"

int ft_init(t_env *e)
{
    e->sharp = 0;
    e->padding = 0;
    e->width_l = 0;
    e->width_r = 0;
    return (1);
}
#include "libprintf.h"

int ft_get_width(const char *s, int *pos)
{
    int width;
    int i;

    i = *pos;
    width = 0;
    while ((s[i] >= '0' && s[i] <= '9') && s[i])
    {
        width *= 10;
        width += s[i] - '0';
        i++;
    }
    *pos = i;
    return (width);
}
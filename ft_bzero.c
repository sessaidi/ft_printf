#include "libprintf.h"

void    *ft_bzero(void *s, unsigned int n)
{
    char	*v_s;

	if (n == 0)
		return (s);
	v_s = (char*)s;
	if (!s)
		return (0);
	while (n-- > 0)
		v_s[n] = 0;
	return (s);
}
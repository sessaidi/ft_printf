#include "libprintf.h"

int	ft_charpos(const char *s, char c)
{
	int	pos;

	pos  = 0;
	if (!s || !c)
		return (-1);
	while (s[pos])
	{
		if (s[pos] == c)
			return (pos);
		pos++;
	}
	return (0);
}

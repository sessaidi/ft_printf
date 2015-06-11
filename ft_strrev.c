#include "libprintf.h"

char	*ft_strrev(char *s)
{
	char	*v_s;
	size_t	pos_s;
	size_t	pos_e;
	size_t	length;

	if (!s)
		return (0);
	length = ft_strlen(s);
	if (!(v_s = (char*)malloc(sizeof(char) * length + 1)))
		return (0);
	pos_s = 0;
	pos_e = length - 1;
	while (pos_s <= length)
		v_s[pos_s++] = s[pos_e--];
	v_s[pos_s] = 0;
	return (v_s);
}
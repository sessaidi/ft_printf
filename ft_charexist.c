#include "libprintf.h"

/*
**	FT_CHAREXIST             Library Functions Manual             FT_CHAREXIST
**	NAME
**		ft_charexist -- check if character exist in string
**	LIBRARY
**		Standard Functions Library (libft, -lft)
**	SYNOPSIS
**		#include "libft.h"
**
**		char *ft_charexist(const char *s, int c);
**
**	DESCRIPTION
**		The ft_charexist() function check if the character c 
**		(converted to a char) exist in the string pointed to by s.
**		The terminating null character is considered to be part of the string;
**
**	RETURN VALUES
**		The functions ft_charexist() return TRUE if the character is 
**		found in the string, or FALSE if the character does not appear in
**		the string.
**
**	SEE ALSO
**		ft_memchr, ft_strchr, ft_strrchr, ft_strstr, ft_strchrrev, ft_charat
*/

int	ft_charexist(const char *s, int c)
{
	size_t	pos;

	if (!s || !c)
		return (0);
	pos = 0;
	while (s[pos] != c)
	{
		if (s[pos] == 0)
			return (0);
		pos++;
	}
	return (1);
}
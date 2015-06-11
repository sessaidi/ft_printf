#include "libprintf.h"

int	ft_getflag(char c)
{
	return ((ft_charpos(FLAGS, c) == - 1) ? -1 : (ft_charpos(FLAGS, c)));
}
#include "libprintf.h"

int	ft_lennum(long long int num)
{
	unsigned long long int	length;

	length = 1;
	if (num < 0)
	{
		length++;
		num = -num;
	}
	while ((num /= 10) > 0)
		length++;
	return (length);
}
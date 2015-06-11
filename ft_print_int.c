#include "libprintf.h"

int ft_print_int(long long int n)
{
    char c;

	if (n == -9223372036854775807)
	{
	    write(1, "-9223372036854775807", 20);
		return (0);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
	    c = n + '0';
	    write(1, &c, 1);
	}
	else
	{
		ft_print_int(n / 10);
		ft_print_int(n % 10);
	}
	return (ft_lennum(n) + 1);
}
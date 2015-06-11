#include "libprintf.h"

int ft_print_num(unsigned long long int n, char *b)
{
    size_t  base;
    char    *nbr_conv;

    base = ft_strlen(b);
    if (n == 0)
    {
    	write(1, "0", 1);
    	return (1);
    }
    else
    {
    	nbr_conv = 0;
		while (n > 0)
    	{
    	    nbr_conv = ft_addchar(nbr_conv, b[n % base]);
    	    n /= base;
		}
		nbr_conv = ft_strrev(nbr_conv);
    	write(1, nbr_conv, ft_strlen(nbr_conv));
    }
    return (ft_strlen(nbr_conv));
}
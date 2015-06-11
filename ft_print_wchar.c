#include "libprintf.h"

unsigned int g_mask0 = 0;
unsigned int g_mask1 = 49280;
unsigned int g_mask2 = 14712960;
unsigned int g_mask3 = 4034953344;

static int ft_size(unsigned long long int n, char *b)
{
    size_t  base;
    char    *nbr_conv;

    base = ft_strlen(b);
    nbr_conv = 0;
    if (n == 0)
    	write(1, "0", 1);
    else
    {
    	while (n > 0)
    	{
    	    nbr_conv = ft_addchar(nbr_conv, b[n % base]);
    	    n /= base;
		}
		nbr_conv = ft_strrev(nbr_conv);
    }
    return (ft_strlen(nbr_conv));
}

static int ft_print_second_parts(unsigned int c, unsigned char octet)
{
    unsigned char o2;
    unsigned char o1;
   
    o2 = (c << 26) >> 26;
    o1 = ((c >> 6) << 27) >> 27;
    octet = (g_mask1 >> 8) | o1;
    write(1, &octet, 1);
    octet = ((g_mask1 << 24) >> 24) | o2;
    write(1, &octet, 1);
    return (1);
}

static int ft_print_third_parts(unsigned int c, unsigned char octet)
{
    unsigned char o3;
    unsigned char o2;
    unsigned char o1;
   
    o3 = (c << 26) >> 26;
    o2 = ((c >> 6) << 26) >> 26;
    o1 = ((c >> 12) << 28) >> 28;
       
    octet = (g_mask2 >> 16) | o1;
    write(1, &octet, 1);
    octet = ((g_mask2 << 16) >> 24) | o2;
    write(1, &octet, 1);
    octet = ((g_mask2 << 24) >> 24) | o3;
    write(1, &octet, 1);
    return (1);
}

static int ft_print_fourth_parts(unsigned int c, unsigned char octet)
{
    unsigned char o4;
    unsigned char o3;
    unsigned char o2;
    unsigned char o1;
      
    o4 = (c << 26) >> 26;
    o3 = ((c >> 6) << 26) >> 26;
    o2 = ((c >> 12) << 26) >> 26;
    o1 = ((c >> 18) << 29) >> 29;
    octet = (g_mask3 >> 24) | o1;
    write(1, &octet, 1);
    octet = ((g_mask3 << 8) >> 24) | o2;
    write(1, &octet, 1);
    octet = ((g_mask3 << 16) >> 24) | o3;
    write(1, &octet, 1);
    octet = ((g_mask3 << 24) >> 24) | o4;
    write(1, &octet, 1);
    return (1);
}

int ft_print_wchar(int c)
{
    unsigned int    v_c;
    int             size;
    unsigned char   octet;

    if (!c)
        return (0);
    v_c = c;
    size = ft_size(c, "01");
    octet = 0;
    if (size <= 7)
    {
        octet = c;
        write(1, &octet, 1);
    }
    else  if (size <= 11)
        ft_print_second_parts(v_c, octet);
    else  if (size <= 16)
        ft_print_third_parts(v_c, octet);
    else
        ft_print_fourth_parts(v_c, octet);
    return (1);
}
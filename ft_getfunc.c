#include "libprintf.h"

t_func 	*ft_getfunc(void)
{
	t_func 	*tab_func;

	tab_func = (t_func*)malloc(sizeof(t_func) * 16);
	if (!tab_func)
		return (0);
	tab_func[0] = ft_put_str;
	tab_func[1] = ft_put_wstr;
	tab_func[2] = ft_put_ptr;
	tab_func[3] = ft_put_signed;
	tab_func[4] = ft_put_signed;
	tab_func[5] = ft_put_signed;
	tab_func[6] = ft_put_oct;
	tab_func[7] = ft_put_oct;
	tab_func[8] = ft_put_unsigned;
	tab_func[9] = ft_put_unsigned;
	tab_func[10] = ft_put_hex_l;
	tab_func[11] = ft_put_hex_u;
	tab_func[12] = ft_put_char;
	tab_func[13] = ft_put_wchar;
	tab_func[14] = ft_put_bin;
	tab_func[15] = ft_put_double;
	return (tab_func);
}
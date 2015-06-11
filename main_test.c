#include "libprintf.h"
#include <stdio.h>
#include <string.h>

void ft_print_env(char *callfun, t_env e)
{
    if (callfun)
        printf("\nfunction : [%s]\n", callfun);
    printf("e.sharp   : [%d]\n", e.sharp);
    printf("e.padding : [%d]\n", e.padding);
    printf("e.width_l : [%d]\n", e.width_l);
    printf("e.width_r : [%d]\n", e.width_r);
}

int ft_put_str(va_list ap, t_env e)
{
    (void)e;
    return (ft_print_str(va_arg(ap, char*)));
}


int ft_put_wstr(va_list ap, t_env e)
{
    (void)e;
	return (ft_print_wstr(va_arg(ap, wchar_t*)));
}

int ft_put_ptr(va_list ap, t_env e)
{
    (void)e;
	write(1, "0x", 2);
	return (ft_print_num(va_arg(ap, unsigned int), HEX_L));	
}

int ft_put_signed(va_list ap, t_env e)
{
    (void)e;
	return (ft_print_int(va_arg(ap, int)));	
}

int ft_put_oct(va_list ap, t_env e)
{
    if (e.sharp)
    	write(1, "0", 1);
	return (ft_print_num(va_arg(ap, unsigned int), OCT));
}

int	ft_put_unsigned(va_list ap, t_env e)
{
    int sp;
    int len;

    sp = e.width_l - ft_lennum(va_arg(ap, unsigned int));
    if (e.padding & PAD_RIGHT)
	    len = ft_print_int(va_arg(ap, unsigned int));
    while (sp-- > 0)
        write(1, " ", 1);
    if (!(e.padding & PAD_RIGHT))
        len = ft_print_int(va_arg(ap, unsigned int));
    return ((e.width_l > len) ? e.width_l : len);
}

int ft_put_hex_l(va_list ap, t_env e)
{
    int sp;
    int len;

    sp = e.width_l - ft_lennum(va_arg(ap, unsigned int));
    if (e.padding & PAD_RIGHT)
    {
        if (e.sharp)
    	    write(1, "0x", 2);
    	len = ft_print_num(va_arg(ap, unsigned int), HEX_L);
    }
    while (sp-- > 0)
        write(1, " ", 1);
    if (!(e.padding & PAD_RIGHT))
    {
        if (e.sharp)
    	    write(1, "0x", 2);
        len = ft_print_num(va_arg(ap, unsigned int), HEX_L);
    }
    return ((e.width_l > len) ? e.width_l : len);
}

int ft_put_hex_u(va_list ap, t_env e)
{
    if (e.sharp)
    	write(1, "0x", 2);
	return (ft_print_num(va_arg(ap, unsigned int), HEX_U));
}

int ft_put_bin(va_list ap, t_env e)
{
    (void)e;
	return (ft_print_num(va_arg(ap, unsigned int), BIN));
}

int ft_put_char(va_list ap, t_env e)
{
    (void)e;
	return (ft_print_char(va_arg(ap, int)));	
}

int ft_put_wchar(va_list ap, t_env e)
{
    (void)e;
	return (ft_print_wchar(va_arg(ap, int)));	
}

int ft_put_double(va_list ap, t_env e)
{
    (void)e;
	return (ft_print_double(va_arg(ap, double), e.width_r));	
}

//int ft_check_token(const char *s, t_env *e, int *i)

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     pos;

    if (!format)
        return (-1);
    va_start(ap, format);
    pos = -1;
    while (format[++pos])
    {
        if (format[pos] == '%')
            ft_mark_percent(format, &pos, ap);
        else
            ft_print_char(format[pos]);    
    }
    va_end(ap);
    return (ft_strlen(format));
}

int main()
{
	char *ptr = "Hello world!";
    wchar_t *p = L"H@llö wòrld";
	char *np = 0;
	int i = 5;
	unsigned int bs = sizeof(int)*8;
	int mi;

	mi = (1 << (bs-1)) + 1;
	ft_printf("%s\n", ptr);
	ft_printf("test\n");
	ft_printf("%s is null pointer\n", np);
    puts("test =================== ");
    ft_printf("%d = 5\n", i);
    puts("test =================== ");
    ft_printf("%S = 5\n", p);
	puts("test =================== ");
	ft_printf("%d = - max int\n", mi);
	puts("test =================== ");
	ft_printf("char %c = 'a'\n", 'a');
	puts("test =================== ");
	ft_printf("hex %x = ff\n", 0xff);
	puts("test =================== ");
	ft_printf("hex %0.2x = 00\n", 0);
	puts("test =================== ");
	ft_printf("signed %d = unsigned [%-24.2u] = hex %x\n", -3, -3, -3);
	puts("test =================== ");
	ft_printf("%d %s(s)%", 0, "message");
	puts("test =================== ");
	ft_printf("\n");
	ft_printf("%4.2d\n", 10215.2014546);
	ft_printf("%d %s(s) with %\n", 0, "message");
    printf("[%-10u]\n", 125);
    printf("[%#f]%%\n", 12.);
    return (0);
}

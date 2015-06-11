#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


# define PAD_RIGHT   1
# define PAD_ZERO   2
# define FLAGS 	"sSpdDioOuUxXcCbf"
# define ID 	"#+-*"
# define HEX_U	"0123456789ABCDEF"
# define HEX_L	"0123456789abcdef"
# define BIN	"01"
# define OCT	"01234567"
# define DEC	"0123456789"

typedef struct  s_env
{
    int sharp;
    int padding;
    int width_l;
    int width_r;
}               t_env;

typedef	int	(*t_func)(va_list, t_env);

int	    ft_charpos(const char *s, char c);
int	    ft_charexist(const char *s, int c);
void    *ft_bzero(void *s, unsigned int n);
int     ft_strlen(const char *s);
char    *ft_addchar(char *s, char c);
char    *ft_strrev(char *s);
int		ft_lennum(long long int num);
int     ft_print_num(unsigned long long int n, char *b);
int     ft_print_int(long long int n);
int     ft_print_double(double n, int l);
int     ft_print_char(int c);
int     ft_print_wchar(int c);
int     ft_print_str(char *str);
int     ft_print_wstr(wchar_t *s);
int 	ft_check_token(const char *s, t_env *e, int *i);
void	ft_print_error(char *s, char *c);
int ft_check_float(const char *s, int *pos, t_env *e);
int ft_check_padding(const char *s, int *pos, t_env *e);
int ft_check_sharp(const char *s, int *pos, t_env *e);
int ft_check_consistency(const char *s, int pos);
t_func 	*ft_getfunc(void);
int	ft_getflag(char c);
int ft_mark_percent(const char *fmt, int *pos, va_list ap);
int ft_init(t_env *e);
int ft_get_width(const char *s, int *pos);
int ft_put_double(va_list ap, t_env e);
int ft_put_wchar(va_list ap, t_env e);
int ft_put_char(va_list ap, t_env e);
int ft_put_bin(va_list ap, t_env e);
int ft_put_hex_u(va_list ap, t_env e);
int ft_put_hex_l(va_list ap, t_env e);
int ft_put_unsigned(va_list ap, t_env e);
int ft_put_oct(va_list ap, t_env e);
int ft_put_signed(va_list ap, t_env e);
int ft_put_ptr(va_list ap, t_env e);
int ft_put_wstr(va_list ap, t_env e);
int ft_put_str(va_list ap, t_env e);
#endif
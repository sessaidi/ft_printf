#include "libprintf.h"

char    *ft_addchar(char *s, char c)
{
    char    *new_str;
    int     pos;
    
    if (!(new_str = (char*)malloc(sizeof(char) * ft_strlen(s) + 2)))
        return (0);
    pos = 0;
    if (s)
    {
        while (s[pos])
        {
            new_str[pos] = s[pos];
            pos++;
        }
    }
    ft_bzero(s, ft_strlen(s));
    free(s);
    new_str[pos++] = (unsigned char)c;
    new_str[pos] = 0;
    return (new_str);
}

#include "ft_printf.h"
#include "libft.h"
int main (int argc, char **argv)
{
    if (argc < 0)
        return (0);
    char *hola = ft_strjoin(argv[1], argv[2]);
    ft_printf("%s\n", hola);
    return (0);
}
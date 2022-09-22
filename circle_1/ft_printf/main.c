#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	main()
{
	char *str = "apple";
	int i = ft_printf("%p\n", str);
	ft_printf("%d\n", i);
	int j = printf("%p\n", str);
	printf("%d\n", j);
	return 0;
}

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main()
{
	int i = ft_printf("10->16 : %x\n", 5278);
	ft_printf("%d\n", i);
	int j = printf("apple%d banana%d%%\nthe thing is %s\n", 3, 4, "that it's sunday");
	printf("%d\n", j);
	return 0;
}

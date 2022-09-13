#include <stdio.h>
//#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	sum(int argc, ...)
{
	va_list ap;
	va_start(ap, argc);
	int	arg = 0;
	int res = 0;
	for (int i = 0; i < argc; i++)
	{
		arg = va_arg(ap, int);
		res += arg;
	}
	va_end(ap);
	return (res);
}

int	main(int argc, char *argv[] __attribute__((unused)))
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);
	int d = atoi(argv[4]);
	int e = atoi(argv[5]);
	printf("%d\n", sum(argc, a, b, c, d, e));
	return 0;
}


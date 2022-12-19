#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_putstr(char *str) {
	int res = 0;
	for (int i = 0; str[i]; i++) {
		res += write(1, &str[i], 1);
	}
	return res;
}

int ft_putnbr_b(int n, int base) {
	char *apb = "0123456789abcdef";
	int res = 0;

	for (int nb = n; nb > 0; nb /= base, res++);

	char *to_print = malloc(res + 1);
	to_print[res] = '\0';
	for (int len = res; len - 1 >= 0; --len) {
		to_print[len - 1] = apb[n % base];
		n /= base;
	}
	for (int i = 0; to_print[i]; i++) {
		write(1, &to_print[i], 1);
	}
	free(to_print);
	return res;
}

int ft_printf(const char *str, ...) {
	va_list ap;
	int len;

	va_start(ap, str);
	len = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] != '%') {
			len += write(1, &str[i], 1);
		}
		else {
			i++;
			if (str[i] == 's') {
				len += ft_putstr((char *)va_arg(ap, char *));
			}
			else if (str[i] == 'd') {
				len += ft_putnbr_b((uintptr_t)va_arg(ap, int), 10);
			}
			else if (str[i] == 'x') {
				len += ft_putnbr_b((uintptr_t)va_arg(ap, int), 16);
			}
		}
	}
	return len;
}

int main(int argc __attribute__((unused)), char *argv[]) {
	int i = atoi(argv[2]);
	printf("printf s : %s\n", argv[1]);
	printf("printf d : %d\n", i);
	printf("printf x : %x\n", i);
	ft_printf("ft_printf s : %s\n", argv[1]);
	ft_printf("ft_printf d : %d\n", i);
	ft_printf("ft_printf x : %x\n", i);
	return 0;
}

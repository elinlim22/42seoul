#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	//ft_isalpha
	printf("----------------------\n");
	printf("ft_isalpha.c\n");
	printf("A returns 1 : %d\n", ft_isalpha('A'));
	printf("a returns 2 : %d\n", ft_isalpha('y'));
	printf("! returns 0 : %d\n", ft_isalpha('!'));
	printf("isalpha : A returns 1 : %d\n", isalpha('A'));
	printf("isalpha : a returns 2 : %d\n", isalpha('y'));
	printf("isalpha : ! returns 0 : %d\n", isalpha('!'));
	printf("----------------------\n");

	//ft_isdigit
	printf("----------------------\n");
	printf("ft_isdigit.c\n");
	printf("A returns 0 : %d\n", ft_isdigit('A'));
	printf("7 returns 0 : %d\n", ft_isdigit(7));
	printf("char 7 returns 1 : %d\n", ft_isdigit('7'));
	printf("----------------------\n");

	//ft_isalnum
	printf("----------------------\n");
	printf("ft_isalnum.c\n");
	printf("A returns 1 : %d\n", ft_isalnum('A'));
	printf("0 returns 0 : %d\n", ft_isalnum(0));
	printf("char 8 returns 1 : %d\n", ft_isalnum('8'));
	printf("! returns 0 : %d\n", ft_isalnum('!'));
	printf("isalnum : A returns 1 : %d\n", isalnum('A'));
	printf("isalnum : 0 returns 0 : %d\n", isalnum(0));
	printf("isalnum : char 8 returns 1 : %d\n", isalnum('8'));
	printf("isalnum : ! returns 0 : %d\n", isalnum('!'));
	printf("----------------------\n");

	//ft_isascii
	printf("----------------------\n");
	printf("ft_isascii.c\n");
	printf("A returns 1 : %d\n", ft_isascii('A'));
	printf("128 returns 0 : %d\n", ft_isascii(128));
	printf("8 returns 1 : %d\n", ft_isascii(8));
	printf("'8' returns 1 : %d\n", ft_isascii('8'));
	printf("! returns 1 : %d\n", ft_isascii('!'));
	printf("isascii : A returns 1 : %d\n", isascii('A'));
	printf("isascii : 128 returns 0 : %d\n", isascii(128));
	printf("isascii : 8 returns 1 : %d\n", isascii(8));
	printf("isascii : '8' returns 1 : %d\n", isascii('8'));
	printf("isascii : ! returns 1 : %d\n", isascii('!'));
	printf("----------------------\n");

	//ft_isprint
	printf("----------------------\n");
	printf("ft_isprint.c\n");
	printf("isprint : NL returns 1 : %d\n", isprint('\n'));
	printf("isprint : DEL returns 0 : %d\n", isprint(127));
	printf("isprint : 1/4 returns 0 : %d\n", isprint(172));
	printf("isprint : SP returns 1 : %d\n", isprint(' '));
	printf("NL returns 1 : %d\n", ft_isprint('\n'));
	printf("DEL returns 0 : %d\n", ft_isprint(127));
	printf("1/4 returns 0 : %d\n", ft_isprint(172));
	printf("SP returns 1 : %d\n", ft_isprint(' '));
	printf("----------------------\n");
}

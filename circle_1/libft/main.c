#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_strlen.c"
#include "ft_memset.c"
#include "ft_bzero.c"
#include "ft_memcpy.c"
// #include "ft_memmove.c"
// #include "ft_strlcpy.c"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

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

	//ft_strlen
	printf("----------------------\n");
	printf("strlen : 11 : %lu\n", strlen("born 2 code"));
	printf("11 : %lu\n", ft_strlen("born 2 code"));
	printf("----------------------\n");

	//ft_memset
	printf("----------------------\n");
	printf("ft_memset.c\n");

	char arr1[] = "born 2 code";
	memset(arr1, 42, 4 * sizeof(char));
	printf("memset : 42 : %s\n", arr1);
	char arr2[] = "born 2 code";
	memset(arr2, 227, 4 * sizeof(char));
	printf("memset : 227 : %s\n", arr2);
	char arr3[] = "born 2 code";
	memset(arr3, '4', 4 * sizeof(char));
	printf("memset : '4' : %s\n", arr3);
	char arr4[] = "born 2 code";
	memset(arr4, 125, 4 * sizeof(char));
	printf("memset : 125 : %s\n", arr4);

	char mem1[] = "born 2 code";
	ft_memset(mem1, 42, 4 * sizeof(char));
	printf("42 : %s\n", mem1);
	char mem2[] = "born 2 code";
	ft_memset(mem2, 227, 4 * sizeof(char));
	printf("227 : %s\n", mem2);
	char mem3[] = "born 2 code";
	ft_memset(mem3, '4', 4 * sizeof(char));
	printf("'4' : %s\n", mem3);
	char mem4[] = "born 2 code";
	ft_memset(mem4, 125, 4 * sizeof(char));
	printf("125 : %s\n", mem4);
	printf("----------------------\n");

	//ft_bzero
	printf("----------------------\n");
	printf("ft_bzero.c\n");

	char str1[] = "born 2 code";
	bzero((str1 + 4), 5);
	printf("bzero : 5 zeros : %s\n", str1);
	printf("%d\n", *(str1 + 4));

	char str2[] = "born 2 code";
	ft_bzero((str2 + 4), 5);
	printf("5 zeros : %s\n", str2);
	printf("%d\n", *(str2 + 4));
	printf("----------------------\n");

	//ft_memcpy
	printf("----------------------\n");
	printf("ft_memcpy.c\n");

	char str3[] = "born 2 code";
	char str4[] = "apple";
	memcpy(str3, str4, 4);
	printf("memcpy : appl 2 code : %s\n", str3);

	char str5[] = "born 2 code";
	ft_memcpy(str5, str4, 4);
	printf("appl 2 code : %s\n", str5);

	printf("----------------------\n");
}

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
#include "ft_strlcpy.c"
#include "ft_strlcat.c"
#include "ft_strncmp.c"
#include "ft_toupper.c"
#include "ft_tolower.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_memchr.c"
#include "ft_memcmp.c"
#include "ft_strnstr.c"
#include "ft_strdup.c"
#include "ft_calloc.c"
#include "ft_substr.c"
#include "ft_strjoin.c"
// #include "ft_split.c"
#include "ft_strtrim.c"
#include "ft_itoa.c"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

int	main(void)
{
	//ft_isalpha
	printf("----------------------\n");
	printf("ft_isalpha.c\n");
	printf("A returns 1 -> %d\n", ft_isalpha('A'));
	printf("a returns 2 -> %d\n", ft_isalpha('y'));
	printf("! returns 0 -> %d\n", ft_isalpha('!'));
	printf("isalpha : A returns 1 -> %d\n", isalpha('A'));
	printf("isalpha : a returns 2 -> %d\n", isalpha('y'));
	printf("isalpha : ! returns 0 -> %d\n", isalpha('!'));
	printf("----------------------\n");

	//ft_isdigit
	printf("----------------------\n");
	printf("ft_isdigit.c\n");
	printf("A returns 0 -> %d\n", ft_isdigit('A'));
	printf("7 returns 0 -> %d\n", ft_isdigit(7));
	printf("char 7 returns 1 -> %d\n", ft_isdigit('7'));
	printf("----------------------\n");

	//ft_isalnum
	printf("----------------------\n");
	printf("ft_isalnum.c\n");
	printf("A returns 1 -> %d\n", ft_isalnum('A'));
	printf("0 returns 0 -> %d\n", ft_isalnum(0));
	printf("char 8 returns 1 -> %d\n", ft_isalnum('8'));
	printf("! returns 0 -> %d\n", ft_isalnum('!'));
	printf("isalnum : A returns 1 -> %d\n", isalnum('A'));
	printf("isalnum : 0 returns 0 -> %d\n", isalnum(0));
	printf("isalnum : char 8 returns 1 -> %d\n", isalnum('8'));
	printf("isalnum : ! returns 0 -> %d\n", isalnum('!'));
	printf("----------------------\n");

	//ft_isascii
	printf("----------------------\n");
	printf("ft_isascii.c\n");
	printf("A returns 1 -> %d\n", ft_isascii('A'));
	printf("128 returns 0 -> %d\n", ft_isascii(128));
	printf("8 returns 1 -> %d\n", ft_isascii(8));
	printf("'8' returns 1 -> %d\n", ft_isascii('8'));
	printf("! returns 1 -> %d\n", ft_isascii('!'));
	printf("isascii : A returns 1 -> %d\n", isascii('A'));
	printf("isascii : 128 returns 0 -> %d\n", isascii(128));
	printf("isascii : 8 returns 1 -> %d\n", isascii(8));
	printf("isascii : '8' returns 1 -> %d\n", isascii('8'));
	printf("isascii : ! returns 1 -> %d\n", isascii('!'));
	printf("----------------------\n");

	//ft_isprint
	printf("----------------------\n");
	printf("ft_isprint.c\n");
	printf("isprint : NL returns 1 -> %d\n", isprint('\n'));
	printf("isprint : DEL returns 0 -> %d\n", isprint(127));
	printf("isprint : 1/4 returns 0 -> %d\n", isprint(172));
	printf("isprint : SP returns 1 -> %d\n", isprint(' '));
	printf("NL returns 1 -> %d\n", ft_isprint('\n'));
	printf("DEL returns 0 -> %d\n", ft_isprint(127));
	printf("1/4 returns 0 -> %d\n", ft_isprint(172));
	printf("SP returns 1 -> %d\n", ft_isprint(' '));
	printf("----------------------\n");

	//ft_strlen
	printf("----------------------\n");
	printf("ft_strlen.c");
	printf("strlen : 11 -> %lu\n", strlen("born 2 code"));
	printf("11 -> %lu\n", ft_strlen("born 2 code"));
	printf("----------------------\n");

	//ft_memset
	printf("----------------------\n");
	printf("ft_memset.c\n");

	char arr1[] = "born 2 code";
	memset(arr1, 42, 4 * sizeof(char));
	printf("memset : 42 -> %s\n", arr1);
	char arr2[] = "born 2 code";
	memset(arr2, 227, 4 * sizeof(char));
	printf("memset : 227 -> %s\n", arr2);
	char arr3[] = "born 2 code";
	memset(arr3, '4', 4 * sizeof(char));
	printf("memset : '4' -> %s\n", arr3);
	char arr4[] = "born 2 code";
	memset(arr4, 125, 4 * sizeof(char));
	printf("memset : 125 -> %s\n", arr4);

	char mem1[] = "born 2 code";
	ft_memset(mem1, 42, 4 * sizeof(char));
	printf("42 -> %s\n", mem1);
	char mem2[] = "born 2 code";
	ft_memset(mem2, 227, 4 * sizeof(char));
	printf("227 -> %s\n", mem2);
	char mem3[] = "born 2 code";
	ft_memset(mem3, '4', 4 * sizeof(char));
	printf("'4' -> %s\n", mem3);
	char mem4[] = "born 2 code";
	ft_memset(mem4, 125, 4 * sizeof(char));
	printf("125 -> %s\n", mem4);
	printf("----------------------\n");

	//ft_bzero
	printf("----------------------\n");
	printf("ft_bzero.c\n");

	char str1[] = "born 2 code";
	bzero((str1 + 4), 5);
	printf("bzero : 5 zeros -> %s\n", str1);
	printf("%d\n", *(str1 + 4));

	char str2[] = "born 2 code";
	ft_bzero((str2 + 4), 5);
	printf("5 zeros -> %s\n", str2);
	printf("%d\n", *(str2 + 4));
	printf("----------------------\n");

	//ft_memcpy
	printf("----------------------\n");
	printf("ft_memcpy.c\n");

	char str3[] = "born 2 code";
	char str4[] = "apple";
	memcpy(str3, str4, 4);
	printf("memcpy : appl 2 code -> %s\n", str3);

	char str5[] = "born 2 code";
	ft_memcpy(str5, str4, 4);
	printf("appl 2 code -> %s\n", str5);

	printf("----------------------\n");

	//ft_memmove
	printf("----------------------\n");
	printf("----------------------\n");

	//ft_strlcpy
	printf("----------------------\n");
	printf("ft_strlcpy.c\n");
	char str6[] = "born 2 code";
	char str7[] = "CODE";
	strlcpy(str6 + 7, str7, 5);
	printf("strlcpy : born 2 CODE -> %s\n", str6);
	char str8[] = "born 2 code";
	ft_strlcpy(str8 + 7, str7, 5);
	printf("born 2 CODE -> %s\n", str8);
	printf("----------------------\n");

	//ft_strlcat
	printf("----------------------\n");
	printf("ft_strlcat.c\n");
	char str9[12] = "born 2";
	char str10[] = " code";
	printf("strlcat : 6 + 5 = 11 -> %lu\n", strlcat(str9, str10, 12));
	printf("concatenated string -> %s\n", str9);
	char str11[12] = "born 2";
	printf("6 + 5 = 11 -> %lu\n", ft_strlcat(str11, str10, 12));
	printf("concatenated string -> %s\n", str11);
	printf("----------------------\n");

	//ft_strncmp
	printf("----------------------\n");
	printf("ft_strncmp.c\n");

	char str12[] = "apple";
	char str13[] = "apple";
	char str14[] = "appla";
	printf("strncmp : a - a = 0 -> %d\n", strncmp(str12, str13, 5));
	printf("strncmp : e - a = 4 -> %d\n", strncmp(str12, str14, 5));
	printf("a - a = 0 -> %d\n", ft_strncmp(str12, str13, 5));
	printf("e - a = 4 -> %d\n ", ft_strncmp(str12, str14, 5));

	printf("----------------------\n");

	//ft_toupper
	printf("----------------------\n");
	printf("ft_toupper.c\n");
	printf("toupper : a becomes A -> %c\n", toupper('a'));
	printf("toupper : 0 becomes nothing -> %c\n", toupper('0'));
	printf("z becomes Z -> %c\n", ft_toupper('z'));
	printf("8 becomes nothing -> %c\n", ft_toupper('8'));
	printf("toupper : int 42 result -> %c\n", toupper(42));
	printf("int 42 result -> %c\n", ft_toupper(42));
	printf("----------------------\n");

	//ft_tolower
	printf("----------------------\n");
	printf("ft_tolower.c\n");
	printf("tolower : A becomes a -> %c\n", tolower('A'));
	printf("tolower : 0 becomes nothing -> %c\n", tolower('0'));
	printf("Z becomes z -> %c\n", ft_tolower('Z'));
	printf("8 becomes nothing -> %c\n", ft_tolower('8'));
	printf("tolower : int 42 result -> %c\n", tolower(42));
	printf("int 42 result -> %c\n", ft_tolower(42));
	printf("----------------------\n");

	//ft_strchr
	printf("----------------------\n");
	printf("ft_strchr.c\n");
	char str15[] = "born 2 code";
	printf("searching 'c' in the str -> %s\n", strchr(str15, 'c'));
	printf("my result -> %s\n", ft_strchr(str15, 'c'));
	printf("----------------------\n");

	//ft_strrchr
	printf("----------------------\n");
	printf("ft_strrchr.c\n");
	char str16[] = "born 2 code";
	printf("searching 'o' in the str -> %s\n", strrchr(str16, 'o'));
	printf("my result -> %s\n", ft_strrchr(str16, 'o'));
	printf("----------------------\n");

	//ft_memchr
	printf("----------------------\n");
	printf("ft_memchr.c\n");
	char str17[] = "born 2 code";
	printf("searching 'c' in the str -> %s\n", memchr(str17, 'c', 12));
	printf("my result -> %s\n", ft_memchr(str17, 'c', 12));
	printf("----------------------\n");

	//ft_memcmp
	printf("----------------------\n");
	printf("ft_memcmp.c\n");
	char str18[] = "born 2 code";
	char str19[] = "born 2 code";
	char str20[] = "born 3 code";
	printf("memcmp : 0 -> %d\n", memcmp(str18, str19, 12));
	printf("memcmp : -1 -> %d\n", memcmp(str18, str20, 12));
	printf("0 -> %d\n", ft_memcmp(str18, str19, 12));
	printf("-1 -> %d\n", ft_memcmp(str18, str20, 12));
	printf("----------------------\n");

	//ft_strnstr
	printf("----------------------\n");
	printf("ft_strnstr.c\n");
	char str21[] = "born 2 code";
	char str22[] = "code";
	char str23[] = "bode";
	char str24[] = "";
	printf("strnstr : code -> %s\n", strnstr(str21, str22, 12));
	printf("strnstr : bode -> %s\n", strnstr(str21, str23, 12));
	printf("strnstr : code : len == 7 -> %s\n", strnstr(str21, str22, 7));
	printf("strnstr : empty needle -> %s\n", strnstr(str21, str24, 12));
	printf("code -> %s\n", ft_strnstr(str21, str22, 12));
	printf("bode -> %s\n", ft_strnstr(str21, str23, 12));
	printf("code : len == 7 -> %s\n", ft_strnstr(str21, str22, 7));
	printf("empty needle -> %s\n", ft_strnstr(str21, str24, 12));
	printf("----------------------\n");

	//ft_atoi
	printf("----------------------\n");
	printf("ft_atoi.c\n");
/*
	#include <stdio.h>
	#include <stdlib.h>

	int	main(int argc __attribute__((unused)), char *argv[])
	{
		if (argc == 1)
		{
			printf("%d\n", atoi("    \v  +35"));
			printf("my result : %d\n", ft_atoi("    \v  +35"));
		}
		else
		{
			printf("%d\n", atoi(argv[1]));
			printf("my result : %d\n", ft_atoi(argv[1]));
		}
		return 0;
	}
*/
	printf("----------------------\n");

	//ft_strdup
	printf("----------------------\n");
	printf("ft_strdup.c\n");
	char str25[] = "born 2 code";
	printf("strdup -> %s\n", strdup(str25));
	printf("my result -> %s\n", ft_strdup(str25));
	printf("----------------------\n");

	//ft_calloc
	printf("----------------------\n");
	printf("ft_calloc.c\n");
/*
	#include <stdio.h>
	#include <stdlib.h>
	#include "libft/ft_calloc.c"

	int	main(void)
	{
		char *str;
		char *str2;

		str = calloc(3, 4);
		str2 = ft_calloc(3, 4);

		printf("calloc ->");
		for (int i = 0; i < 3; i++)
			printf(" %d", str[i]);
		printf("\n");
		printf("my result ->");
		for (int i = 0; i < 3; i++)
			printf(" %d", str2[i]);
		printf("\n");

		return 0;
	}
*/
	printf("----------------------\n");

	//ft_substr
	printf("----------------------\n");
	printf("ft_substr.c\n");
	char str26[] = "born 2 code";
	printf("code -> %s\n", ft_substr(str26, 7, 5));
	printf("----------------------\n");

	//ft_strjoin
	printf("----------------------\n");
	printf("ft_strjoin.c\n");
	char str27[] = "born";
	char str28[] = " 2 code";
	printf("born 2 code -> %s\n", ft_strjoin(str27, str28));
	printf("----------------------\n");

	//ft_strtrim
	printf("----------------------\n");
	printf("ft_strtrim.c\n");
	char str29[] = "born 2 code";
	char str30[] = "boc";
	printf("%s\n", ft_strtrim(str29, str30));
	printf("----------------------\n");

	//ft_split
	printf("----------------------\n");
	printf("ft_split.c\n");

	printf("----------------------\n");

	//ft_itoa
	printf("----------------------\n");
	printf("ft_itoa.c\n");
	printf("-2147483648 -> %s\n", ft_itoa(-2147483648));
	printf("----------------------\n");
}

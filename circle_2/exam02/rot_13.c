#include <unistd.h>

char	change(char c)
{
	if (c >= 'a' + 13 && c <= 'z')
		c -= 13;
	else if (c <= 'a' + 13 && c >= 'a')
		c = 'z' - (13 - (c - 'a')) + 1;
	else if (c <= 'A' + 13 && c >= 'A')
		c = 'Z' - (13 - (c - 'A')) + 1;
	else if (c >= 'A' + 13 && c <= 'Z')
		c -= 13;
	else
		return (c);
	return (c);
}

int	main(int argc, char *argv[])
{
	int i = 0;
	if (argc < 2 || !argv[1][0])
		return (write(1, "\n", 1));
	while (argv[1][i])
	{
		char c = change(argv[1][i]);
		write(1, &c, 1);
		i++;
	}
	return (0);
}

#include <unistd.h>

int	ft_strchr(char *str, char c)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[]) {

	if (argc != 3)
		return (write(1, "\n", 1));
	int i = 0;
	int	flag[26] = {0};
	for (int i = 0; argv[1][i]; i++) {
		flag[argv[1][i] - 'a'] = 1;
	}
	for (int i = 0; argv[2][i]; i++) {
		flag[argv[2][i] - 'a'] = 1;
	}
	while (argv[1][i])
	{
		if (flag[argv[1][i] - 'a'])
		{
			write(1, &argv[1][i], 1);
			flag[argv[1][i] - 'a'] = 0;
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (flag[argv[2][i] - 'a'])
		{
			write(1, &argv[2][i], 1);
			flag[argv[2][i] - 'a'] = 0;
		}
		i++;
	}
	return (0);
}

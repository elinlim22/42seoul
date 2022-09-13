#include <unistd.h>
#include "libft.h"

int	main()
{
	char *str = "%\n";

	write(1, str, ft_strlen(str));
	return 0;
}

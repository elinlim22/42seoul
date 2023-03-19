#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

# define SUCCESS 0
# define ERROR 1

int opener(FILE *file) {

	return (SUCCESS);
}

int main(int argc, char *argv[]) {
	if (argc == 2) {
		if (!opener(argv[1]))
			return ((void)write(1, "Error: Operation file corrupted\n", 32), ERROR);
		return (SUCCESS);
	}
	else
		return ((void)write(1, "Error: argument\n", 16), ERROR);
}

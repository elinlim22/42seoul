#include <unistd.h>

char search(char *str, char c) {
	for (int i = 0; str[i]; i++) {
		if (str[i] == c)
			return (str[i]);
	}
	return ('\0');
}

int main(int argc, char *argv[]) {
	if (argc == 3) {
		int apb[127];
		for (int i = 0; i < 127; i++) {
			apb[i] = 0;
		}
		for (int i = 0; argv[1][i]; i++) {
			for (int j = 0; argv[2][j]; j++) {
				if (argv[1][i] == argv[2][j] && !apb[(int)argv[1][i]]) {
					write(1, &argv[1][i], 1);
					apb[(int)argv[1][i]] = 1;
					break ;
				}
			}
		}
	}
	return (write(1, "\n", 1));
}

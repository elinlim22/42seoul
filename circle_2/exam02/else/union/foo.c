#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc == 3) {
		int arr[127] = {};

		for (int i = 1; argv[i]; i++) {
			for (int j = 0; argv[i][j]; j++) {
				if (!arr[(int)argv[i][j]]) {
					write(1, &argv[i][j], 1);
					arr[(int)argv[i][j]] = 1;
				}
			}
		}
	}
	return (write(1, "\n", 1));
}

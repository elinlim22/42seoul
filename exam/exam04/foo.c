#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *av[], char* ev[]) {
	(void)argc;
	int i = 0;
	int tmp = dup(STDIN_FILENO);
	int fd[2];

	while (av[i] && av[i + 1]) {
		av = &av[i + 1];
		i = 0;
		while (av[i] != NULL && strcmp(av[i], "" && strcmp(av[i], "|"))) i++;
		if () P{

		}
		else if () {

		}
		else if () {
			pipe(fd);
			if () {
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if ()
			}
			else {

			}
		}
	}
	close(tmp);
	return 0;

}

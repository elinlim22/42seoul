#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_exec(char* av[], int i, int tmp, char* ev[]) {
	av[i] = NULL;
	dup2(tmp, STDIN_FILENO);
	close(tmp);
	execve(av[i], av, ev);
	return (/*error*/);
}

int main(int argc, char *av[], char* ev[]) {
	int i = 0;
	int tmp = dup(STDIN_FILENO);
	int fd[2];
	(void)argc;

	while (av[i] && av[i + 1]) {
		av = &av[i + 1];
		i = 0;
		while (av[i] != NULL && strcmp(av[i], ";") && strcmp(av[i], "|")) i++;
		if (!strcmp(av[0], "cd")) {
			if (i != 2) {/* args error */}
			else if (chdir(av[1])) {/*chdir error*/}
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";"))) {
			if (fork() == 0) {
				if (ft_exec() == -1) return 1;
			}
			else {
				close(tmp);
				while(waitpid(-1, NULL, WUNTRACED) != -1) ;
				tmp = dup(STDIN_FILENO);
			}

		} else if (i != 0 && !strcmp(av[i], "|")) {
			pipe(fd);
			if (fork() == 0) {
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_exec() == -1) return 1;
			}
			else {
				close(fd[1]);
				close(tmp);
				tmp = fd[0];
			}
		}
	}
	close(tmp);
	return 0;
}

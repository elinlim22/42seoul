#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[]) {
	(void)argc;
	int tmp = dup(STDIN_FILENO);
	int fd[2];
	int i = 0;

	while (argv[i] && argv[i + 1]) {
		argv = &argv[i + 1];
		i = 0;

		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++; // -> increase i until the end of the command block, argv stays at the start of the command line

		/* CASE cd */
		if (strcmp(argv[0], "cd") == 0) {
			if (i != 2) { //if the number of cd argument is not 1
				//bad arguments ERROR
			} else if (chdir(argv [1]) != 0) { //execute chdir and error handling
				//chdir ERROR
			}
		}
		/* CASE ; -> exec */
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) { // i should not be 0 b/c ; or | don't come first
			/* subCASE child */
			if (fork() == 0) {
				if (ft_exec())
					return 1;
			}
			/* subCASE parent */
			else {
				close(tmp);
				while(waitpid(-1, NULL, WUNTRACED) != -1) ;
				tmp = dup(STDIN_FILENO);
			}
		}
		/* CASE | -> fork */
		else if (i != 0 && strcmp(argv[i], "|") == 0) { // argv[i] should not be the end to execute pipe
			pipe(fd); //pipe usage
			/* subCASE child */
			if (fork() == 0) {
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if (ft_exec())
					return 1;
			}
			/* subCASE parent */
			else {
				close(fd[1]);
				close(tmp);
				tmp = fd[0];
			}
		}
	}
	return 0;
}

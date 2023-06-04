#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_exec(char* argv[], int i, int tmp, char* envp[]) {
	argv[i] = NULL;
	dup2(tmp, STDIN_FILENO);
	close(tmp);
	execve(argv[0], argv, envp);
	return (/*Error*/);
}

int main(int argc, char *av[], char* ev[]) {
	(void)argc;
	int i = 0;
	int tmp = dup(STDIN_FILENO);
	int fd[2];

	while (av[i] && av[i + 1]) {
		av = &av[i + 1];
		i = 0;
		while (av[i] != NULL && strcmp(av[i], ";") && strcmp(av[i], "|")) i++;
		if (!strcmp(av[0], "cd")) {
			if (i != 2) {/* args error */}
			else if (chdir(av[0])) {/* chdir error */}
		}
		else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";"))) {
			if (fork() == 0) {
				if (ft_exec(av, i, tmp, ev)) return 1;
			}
			else {
				close(tmp);
				while (waitpid(-1, NULL, WUNTRACED) != -1) ;
				tmp = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && !strcmp(av[i], "|")) {
			pipe(fd);
			if (fork() == 0) {
				dup2(fd[1], STDOUT_FILENO); // fd[1]에 OUT 보내야지 바보야..
				close(fd[0]);
				close(fd[1]); //보냈으면 닫아야지..
				// close(tmp); 이건뭐야.. 건들지마
				if (ft_exec(av, i, tmp, ev)) return 1;
			}
			else {
				close(fd[1]);
				close(tmp);
				// close(fd[0]);
				// tmp = dup(STDIN_FILENO);
				tmp = fd[0]; //fd[0]으로 받은거 standard input으로 받아야지...
			}
		}
	}
	close(tmp);
	return 0;
}







// #include <string.h>
// #include <unistd.h>
// #include <sys/wait.h>

// int main(int argc, char *argv[], char *envp[]) {
// 	(void)argc;
// 	int tmp = dup(STDIN_FILENO);
// 	int fd[2];
// 	int i = 0;

// 	while (argv[i] && argv[i + 1]) {
// 		argv = &argv[i + 1];
// 		i = 0;

// 		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
// 			i++; // -> increase i until the end of the command block, argv stays at the start of the command line

// 		/* CASE cd */
// 		if (strcmp(argv[0], "cd") == 0) {
// 			if (i != 2) { //if the number of cd argument is not 1
// 				//bad arguments ERROR
// 			} else if (chdir(argv [1]) != 0) { //execute chdir and error handling
// 				//chdir ERROR
// 			}
// 		}
// 		/* CASE ; -> exec */
// 		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0)) { // i should not be 0 b/c ; or | don't come first
// 			/* subCASE child */
// 			if (fork() == 0) {
// 				if (ft_exec())
// 					return 1;
// 			}
// 			/* subCASE parent */
// 			else {
// 				close(tmp);
// 				while(waitpid(-1, NULL, WUNTRACED) != -1) ; // -1 :
// 				tmp = dup(STDIN_FILENO);
// 			}
// 		}
// 		/* CASE | -> fork */
// 		else if (i != 0 && strcmp(argv[i], "|") == 0) { // argv[i] should not be the end to execute pipe
// 			pipe(fd); //pipe usage
// 			/* subCASE child */
// 			if (fork() == 0) {
// 				dup2(fd[1], STDOUT_FILENO);
// 				close(fd[0]);
// 				close(fd[1]);
// 				if (ft_exec())
// 					return 1;
// 			}
// 			/* subCASE parent */
// 			else {
// 				close(fd[1]);
// 				close(tmp);
// 				tmp = fd[0];
// 			}
// 		}
// 	}
// 	close(tmp);
// 	return 0;
// }



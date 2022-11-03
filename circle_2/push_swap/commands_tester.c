#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[]) {

	char	**res;
	int		count;
	t_stack	*stacks;
	int		*arr;

	res = set_str(argc, argv);
	if (!res)
		return (0);
	count = count_args(res);
	if (check_first(res))
	{
		arr = do_atoi(res, count);
		stacks = (t_stack *)malloc(sizeof(t_stack));
		init_stacks(arr, count, stacks);
		if (!check_second(arr, count) || !check_sorted(arr, count))
			exit(write(1, "Error\n", 6));
		else
		{

			/* before */
			printf("< < < < < < < < BEFORE > > > > > > > > >\n");
			t_node	*curr = NULL;
			printf("Stack A ::: ");
			for (curr = stacks->stack_a->next; curr->next; curr = curr->next) {
				printf("%d -> ", curr->data);
			}
			printf("\n\n");

			printf("Stack B ::: ");
			for (curr = stacks->stack_b->next; curr->next; curr = curr->next) {
				printf("%d -> ", curr->data);
			}
			printf("\n\n\n\n");

			/* scanning... */
			printf("< < < < < < < < SCANNING > > > > > > > > >\n");
			char	commands[4];
			scanf("%s", commands);

	while (commands[0] != 'x')
	{
			if (commands[0] == 'p')
			{
				char *tmp = stacks->commands;
				stacks->commands = ft_strjoin(tmp, pusher(stacks, commands[1]));
				free(tmp);
			}
			else if (commands[0] == 's')
			{
				char *tmp = stacks->commands;
				stacks->commands = ft_strjoin(tmp, swaper(stacks, commands[1]));
				free(tmp);
			}
			else if (commands[0] == 'r' && commands[1] != 'r')
			{
				char *tmp = stacks->commands;
				stacks->commands = ft_strjoin(tmp, rotater(stacks, commands[1]));
				free(tmp);
			}
			else if (commands[0] == 'r' && commands[1] == 'r')
			{
				char *tmp = stacks->commands;
				stacks->commands = ft_strjoin(tmp, rev_rotater(stacks, commands[2]));
				free(tmp);
			}
			printf("\n\n\n\n");

			/* after */
			printf("< < < < < < < < AFTER > > > > > > > > >\n");
			curr = stacks->stack_a;
			printf("Stack A ::: ");
			for (curr = stacks->stack_a->next; curr->next; curr = curr->next) {
				printf("%d -> ", curr->data);
			}
			printf("\n\n");

			printf("Stack B ::: ");
			for (curr = stacks->stack_b->next; curr->next; curr = curr->next) {
				printf("%d -> ", curr->data);
			}
			printf("\n\n\n\n");

			scanf("%s", commands);
	}
			// sorting(모래시계 정렬 함수);
			printf("< < < < < < < < COMMANDS > > > > > > > >\n");
			ft_putstr_fd(stacks->commands, 1);
			printf("\n\n\n\n");
			free_all(res, count, stacks);
			free(arr);
		}
	}
	else
		free_all(res, count, NULL);
	return (0);
}

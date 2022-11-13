#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**res = set_str(argc, argv);
	int		count = count_args(res);
	// t_node	*curr = NULL;

	if (check_first(res))
	{
		int *arr = do_atoi(res, count);
		t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
		init_stacks(arr, count, stack);
		if (!check_second(arr, count) || !check_sorted(arr, count))
			exit(write(1, "Error\n", 6));
		// else
		// {
		// 	// sort_five(stacks, count);
		// 	// sort_three(stacks);
		// 	// for (int i = 0; i < count - 3; i++) {
		// 	// 	pusher(stacks, 'a');
		// 	// }
		// 	printf(" < < < init > > >\n\n\n");
		// 	printf("Stack A -------\n");
		// 	for (curr = stack->stack_a->next; curr->next; curr = curr->next) {
		// 		printf("%d(%d) -> ", curr->data, curr->index);
		// 	}
		// 	printf("\n\n");

		// 	printf("Stack B -------\n");
		// 	for (curr = stack->stack_b->next; curr->next; curr = curr->next) {
		// 		printf("%d(%d) -> ", curr->data, curr->index);
		// 	}
		// 	printf("\n\n\n\n");
		// }

		// ps_b(stack, count);
		// printf(" < < < after > > >\n\n\n");
		// curr = NULL;
		// printf("Stack A -------\n");
		// for (curr = stack->stack_a->next; curr->type == 1; curr = curr->next) {
		// 	printf("%d(%d) -> ", curr->data, curr->index);
		// }
		// printf("\n\n");

		// printf("Stack B -------\n");
		// for (curr = stack->stack_b->next; curr->type == 1; curr = curr->next) {
		// 	printf("%d(%d) -> ", curr->data, curr->index);
		// }
		// printf("\n\n\n\n");
		if (count > 5)
		{
			ps_b(stack, count, 0);
			ps_a(stack, count);
		}
		else
		{
			sort_five(stack, count);
			sort_three(stack);
			for (int i = 0; i < count - 3; i++) {
				stack->commands = ft_strjoin(stack->commands, pusher(stack, 'a'));
			}
		}
		printf("%s\n", stack->commands);
	}
	else
		free_all(res, count, NULL);
	return (0);
}

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**res = set_str(argc, argv);
	int count = count_args(res);
	if (check_first(res))
	{
		int *arr = do_atoi(res, count);
		t_stack *stacks = (t_stack *)malloc(sizeof(t_stack));
		init_stacks(arr, count, stacks);
		if (!check_second(arr, count) || !check_sorted(arr, count))
			exit(write(1, "Error\n", 6));
		else
		{
			sort_five(stacks, count);
			sort_three(stacks);
			for (int i = 0; i < count - 3; i++) {
				pusher(stacks, 'a');
			}
			printf(" < < < result > > >\n\n\n");
			t_node *curr = NULL;
			printf("Stack A -------\n");
			for (curr = stacks->stack_a->next; curr->next; curr = curr->next) {
				printf("%d -> ", curr->data);
			}
			printf("\n\n");

			printf("Stack B -------\n");
			for (curr = stacks->stack_b->next; curr->next; curr = curr->next) {
				printf("%d -> ", curr->data);
			}
			printf("\n\n\n\n");
		}
	}
	else
		free_all(res, count, NULL);
	return (0);
}

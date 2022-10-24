#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_node	*head;
	head = ft_db_lstnew(0);
	ft_db_lstadd_back(&head, ft_db_lstnew(10));
	ft_db_lstadd_back(&head, ft_db_lstnew(20));
	ft_db_lstadd_back(&head, ft_db_lstnew(30));
	t_node	*curr = head;
	for (int i = 0; i < 4; i++)
	{
		printf("%4d", curr->data);
		curr = curr->next;
	}
	printf("\n===================================\n");

	ft_db_lstadd_front(&head, ft_db_lstnew(-10));
	ft_db_lstadd_front(&head, ft_db_lstnew(-20));
	curr = head;
	for (int i = 0; i < 6; i++)
	{
		printf("%4d", curr->data);
		curr = curr->next;
	}
	printf("\n===================================\n");

	curr = head->next->next->next;
	ft_db_lstdelone(curr);
	curr = head;
	for (int i = 0; i < 5; i++)
	{
		printf("%4d", curr->data);
		curr = curr->next;
	}
	printf("\n");

	ft_db_lstclear(&head);
	free(head);

	system("leaks a.out");
	return (0);
}

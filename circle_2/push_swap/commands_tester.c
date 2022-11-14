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
			printf("< < < BEFORE > > >\n");
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
			printf("< < < SCANNING > > >\n");
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
					printf("< < < AFTER > > > \n");
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

			printf("< < < COMMANDS > > >\n");
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


// /* 전처리 ::: 끝!
// 	1. 인자값이 정수가 아닐때
// 	2. 인자값이 정수보다 클때
// 	3. 중복된 인자가 있을때
// 	4. 인자가 없을때
// 	5. 인자가 1개이거나 이미 정렬되었을때는 종료
// */

// /* 인자 받아와서 인덱싱 처리 */

// /* 양방향 연결리스트 사용
// 	스택 A와 스택 B를 각각 구조체로 만들어서 left/right 이동이 가능하도록 설계()
// 	각 스택에서 up/down으로 이동이 가능하도록 설계
// 	각 인자마다 인덱스값을 넣을 int
// */

// /* 함수 리스트
// 	1. 명령어 함수
// */

// 	인자 전처리&인덱싱하기
// 		복사본을 만들고 원본과 대조하면서 원본에 인덱싱 처리를 한다
// 	5개 미만일때 정렬
// 		5개일 때 -> 4개 솔팅 함수로 빠진다
// 		4개일때 -> 3개 솔팅함수로 빠진다
// 		3개일때 하드코딩
// 		재귀로 복귀하면서
// 	make b
// 		모래시계 모양으로 만든다
// 			가장 작은값을 먼저 넘긴다
// 	find max
// 		가장 큰 값을 찾아서 에이로 넘긴다
// 		i++;
// 	move to a
// 	명령어 출력

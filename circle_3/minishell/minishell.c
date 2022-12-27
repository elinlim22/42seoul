/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:41:13 by hyeslim           #+#    #+#             */
/*   Updated: 2022/12/27 20:47:16 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *str;
	while (1)
	{
		str = readline("waiting : ");
		if (ft_strncmp(str, "exit", 4) == 0)
		{
			printf("exit!!\n");
			break ;
		}
		else
			printf("res : %s\n\n", str);
		add_history(str);
		free(str);
	}
	return (0);
}

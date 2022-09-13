/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:21:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/07 14:21:25 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
// # include "libft.h"

int		c(char c);
int		s(char *str);
int		p(void *pt);
int		diu(int i);
int		xX(int i, int ul);
void	hex_print(char c, int ul);
void	ft_strupcase(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:21:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/18 17:18:05 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int		print_c(char c);
int		print_s(char *str);
// int		print_p(void *pt);
int		print_diu(int i);
int		print_xX(unsigned int i, int ul);
void	hex_print(char c, int ul);
void	ft_strupcase(char *str);

#endif

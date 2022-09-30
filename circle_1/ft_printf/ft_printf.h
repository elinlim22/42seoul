/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:21:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/09/30 15:45:28 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_p(void *pt, int flag);
int		print_di(int i);
int		print_u(unsigned int i, int fd);
int		print_x(unsigned int i, int ul, int flag);
void	hex_print(char c, int ul);

#endif

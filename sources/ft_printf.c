/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:29:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/25 19:08:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	size_t	i;
	int		print_count;
	int		return_val;

	if (s == NULL)
		return (1);
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			return_val = ft_print_arg(s, &i, &ap);
			if (return_val < 0)
				return (return_val);
			else
				print_count += return_val;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			print_count++;
			i++;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:44:23 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 19:54:33 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_printf(const char *format, ...)
{
	t_arg_list	args;
	size_t		i;
	size_t		print_count;

	va_start(args.ap_start, format);
	arg_list_start(&args);
	print_count = 0;
	i = 0;
	while (format != NULL && format[i])
	{
		if (format[i] != '%')
			print_count += extended_ft_putchar(format[i++]);
		else if (format[i++] == '%')
		{
			if (print_converted(format, &i, &args, &print_count) != 0)
				return (-1);
			i++;
		}
	}
	return (print_count);
}
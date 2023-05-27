/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:29:19 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 14:37:15 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_printf(const char *format, ...)
{
	va_list			ap_start;
	va_list			ap;
	size_t			i;
	size_t			print_count;

	va_start(ap_start, format);
	va_copy(ap, ap_start);
	i = 0;
	print_count = 0;
	while (format != NULL && format[i])
	{
		if (format[i] != '%')
			print_count += extended_ft_putchar(format[i++]);
		else if (format[i++] == '%')
			print_count += ft_print_converted(format, &i, &ap, &ap_start);
	}
	va_end(ap);
	va_end(ap_start);
	return (print_count);
}

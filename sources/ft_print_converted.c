/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_converted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:43:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 20:42:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void	move_ap(unsigned int n, va_list *ap, va_list *ap_start);
static char	*(*get_tostr_func(char type))(va_list *ap, t_conversion conv);

int	ft_print_converted(const char *format, size_t *i,
						va_list *ap, va_list *ap_start)
{
	t_conversion	*conversion;
	char			*(*tostr_func)(t_conversion *conv, va_list *ap);
	char			*str;
	size_t			str_len;

	conversion = ft_parse_conversion(format, i);
	if (conversion == NULL)
		return (0);
	move_ap(conversion->arg_index, ap, ap_start);
	tostr_func = get_tostr_func(conversion->conversion_type);
	if (tostr_func == NULL)
		return (0);
	str = tostr_func(conversion, ap);
	ft_putstr_fd(str, 1);
	str_len = ft_strlen(str);
	free(str);
	ft_free_conv(conversion);
	return (str_len);
}

static void	move_ap(unsigned int n, va_list *ap, va_list *ap_start)
{
	unsigned int	i;

	if (n == 0)
		return ;
	va_end(*ap);
	va_copy(*ap, *ap_start);
	i = 0;
	while (i++ < (n - 1))
		va_arg(*ap, int);
}

static char	*(*get_tostr_func(char type))(va_list *ap, t_conversion conv)
{
	if (type == 'c')
		return (&tostr_c);
	// if (type == 's')
	// 	return (&tostr_s);
	// if (type == 'p')
	// 	return (&tostr_p);
	// if (type == 'd' || type == 'i')
	// 	return (&tostr_di);
	// if (type == 'u')
	// 	return (&tostr_u);
	// if (type == 'x')
	// 	return (&tostr_x);
	// if (type == 'X')
	// 	return (&tostr_upx);
	// if (type == '%')
	// 	return (&tostr_perc);
	return (NULL);
}

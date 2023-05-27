/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_converted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:43:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 00:08:42 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	(*get_putfunc(char c))(va_list *ap, t_conversion conv);
static void	move_ap(unsigned int n, va_list *ap, va_list *ap_start);

int	ft_print_converted(const char *format, size_t *i,
						va_list *ap, va_list *ap_start)
{
	t_conversion	*conversion;
	int				retval;

	conversion = ft_parse_conversion(format, i);
	if (conversion == NULL)
		return (0);
	move_ap(conversion->arg_index, ap, ap_start);
	retval = get_putfunc(conversion->conversion_type)(ap, *conversion);
	ft_free_conv(conversion);
	return (retval);
}

static int	(*get_putfunc(char c))(va_list *ap, t_conversion conv)
{
	if (c == 'c')
		return (&ft_put_c);
	return (NULL);
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

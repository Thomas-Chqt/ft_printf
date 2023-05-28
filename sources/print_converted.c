/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_converted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:42:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 19:45:39 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static char	*(*get_tostr_func(char type))(t_conv_specs conv_specs, t_arg_list *args);

int	print_converted(const char *str, size_t *i, t_arg_list *args, size_t *print_count)
{
	t_conv_specs	conv_specs;
	char			*(*tostr_func)(t_conv_specs conv_specs, t_arg_list *args);
	char			*printed_str;


	if (parse_conv_specs(str, i, args, &conv_specs) != 0)
		return (-1);
	tostr_func = get_tostr_func(conv_specs.conversion_type);
	if (tostr_func == NULL)
		return (-1);
	printed_str = tostr_func(conv_specs, args);
	if (printed_str == NULL)
		return (-1);
	ft_putstr_fd(printed_str, 1);
	(*print_count) += ft_strlen(printed_str);
	free(printed_str);
	return (0);
}

static char	*(*get_tostr_func(char type))(t_conv_specs conv_specs, t_arg_list *args)
{
	if (type == 'c')
		return (&tostr_c);
	if (type == 's')
		return (&tostr_s);
	if (type == 'd' || type == 'i')
		return (&tostr_di);
	if (type == 'u')
		return (&tostr_u);
	if (type == 'x')
		return (&tostr_x);
	if (type == 'X')
		return (&tostr_upx);
	// if (type == '%')
	// 	return (&tostr_perc);
	return (NULL);
}

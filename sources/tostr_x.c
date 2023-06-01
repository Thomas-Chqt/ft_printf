/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:33:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 17:18:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_x(t_conv_specs conv_specs, t_arg_list *args)
{
	unsigned long long	nbr;

	if (conv_specs.length_mod == hh)
		nbr = (unsigned char)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == h)
		nbr = (unsigned short)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == 0)
		nbr = n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		nbr = n_arg_ulong(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		nbr = n_arg_ullong(conv_specs.arg_index, args);
	else
		return (NULL);
	return (ft_itoa_ullong_base(nbr, "0123456789abcdef"));
}

char	*tostr_upx(t_conv_specs conv_specs, t_arg_list *args)
{
	unsigned long long	nbr;

	if (conv_specs.length_mod == hh)
		nbr = (unsigned char)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == h)
		nbr = (unsigned short)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == 0)
		nbr = n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		nbr = n_arg_ulong(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		nbr = n_arg_ullong(conv_specs.arg_index, args);
	else
		return (NULL);
	return (ft_itoa_ullong_base(nbr, "0123456789ABCDEF"));
}
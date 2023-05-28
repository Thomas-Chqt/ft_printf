/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:33:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 20:02:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_x(t_conv_specs conv_specs, t_arg_list *args)
{
	unsigned long long	nbr;
	char				*nbr_str;
	char				*out_str;

	if (conv_specs.length_mod == hh)
		nbr = (unsigned char)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == h)
		nbr = (unsigned short)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == 0)
		nbr = n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j || conv_specs.length_mod == t || conv_specs.length_mod == z)
		nbr = n_arg_ulong(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		nbr = n_arg_ullong(conv_specs.arg_index, args);
	else
		return (NULL);
	nbr_str = ft_itoa_ullong_base(nbr, "0123456789abcdef");
	if ((conv_specs.flags & hash) > 0)
		out_str = ft_strjoin("0x", nbr_str);
	else
		out_str = ft_strdup(nbr_str);
	free(nbr_str);
	return (out_str);
}

char	*tostr_upx(t_conv_specs conv_specs, t_arg_list *args)
{
	unsigned long long	nbr;
	char				*nbr_str;
	char				*out_str;

	if (conv_specs.length_mod == hh)
		nbr = (unsigned char)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == h)
		nbr = (unsigned short)n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == 0)
		nbr = n_arg_uint(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j || conv_specs.length_mod == t || conv_specs.length_mod == z)
		nbr = n_arg_ulong(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		nbr = n_arg_ullong(conv_specs.arg_index, args);
	else
		return (NULL);
	nbr_str = ft_itoa_ullong_base(nbr, "0123456789ABCDEF");
	if ((conv_specs.flags & hash) > 0)
		out_str = ft_strjoin("0X", nbr_str);
	else
		out_str = ft_strdup(nbr_str);
	free(nbr_str);
	return (out_str);
}
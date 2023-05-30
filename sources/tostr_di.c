/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:45:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 16:18:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_di(t_conv_specs conv_specs, t_arg_list *args)
{
	long long	nbr;

	if (conv_specs.length_mod == hh)
		nbr = (char)n_arg_int(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == h)
		nbr = (short)n_arg_int(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == 0)
		nbr = n_arg_int(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == l || conv_specs.length_mod == j
		|| conv_specs.length_mod == t || conv_specs.length_mod == z)
		nbr = n_arg_long(conv_specs.arg_index, args);
	else if (conv_specs.length_mod == ll || conv_specs.length_mod == q)
		nbr = n_arg_llong(conv_specs.arg_index, args);
	else
		return (NULL);
	return (ft_itoa_llong(nbr));
}

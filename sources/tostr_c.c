/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:20:49 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 16:15:45 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_c(t_conv_specs conv_specs, t_arg_list *args)
{
	char	c;

	c = n_arg_int((long)conv_specs.arg_index, args);
	if (!ft_isprint(c) && conv_specs.length_mod == l)
		return (NULL);
	return (ft_substr(&c, 0, 1));
}

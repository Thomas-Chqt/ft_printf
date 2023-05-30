/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:23:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 20:07:18 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_perc(t_conv_specs conv_specs, t_arg_list *args)
{
	char	c;

	if (args == 0)
	{
	}
	c = '%';
	if (!ft_isprint(c) && conv_specs.length_mod == l)
		return (NULL);
	return (ft_substr(&c, 0, 1));
}

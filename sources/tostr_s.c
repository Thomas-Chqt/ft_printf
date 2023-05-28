/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:42:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 19:00:32 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_s(t_conv_specs conv_specs, t_arg_list *args)
{
	char	*str;

	str = n_arg_str(conv_specs.arg_index, args);
	if (conv_specs.length_mod == l)
		return (NULL);
	if (conv_specs.precision >= 0)
		return (ft_substr(str, 0, conv_specs.precision));
	return (ft_strdup(str));
}
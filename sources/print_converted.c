/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_converted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:42:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/01 00:17:44 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	print_converted(const char *str, size_t *i, t_arg_list *args,
		size_t *print_count)
{
	t_conv_specs	conv_specs;

	if (parse_conv_specs(str, i, args, &conv_specs) != 0)
		return (0);
	return (0);
}

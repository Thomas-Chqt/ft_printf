/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:22:55 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 17:28:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_stdarg.h"

static int	next_arg_int(t_arg_list *list);
static unsigned int	next_arg_uint(t_arg_list *list);

int	n_arg_int(long n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_int(list));
}

unsigned int	n_arg_uint(long n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_uint(list));
}

unsigned int	n_arg_uint_no_move(long n, t_arg_list *list)
{
	va_list			save;
	unsigned int	value;

	va_copy(save, list->ap_current);
	value = n_arg_uint(n, list);
	va_end(list->ap_current);
	va_copy(list->ap_current, save);
	va_end(save);
	return (value);
}

static int	next_arg_int(t_arg_list *list)
{
	return (va_arg(list->ap_current, int));
}

static unsigned int	next_arg_uint(t_arg_list *list)
{
	return (va_arg(list->ap_current, unsigned int));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arg_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:15:22 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 16:16:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_stdarg.h"

static long				next_arg_long(t_arg_list *list);
static unsigned long	next_arg_ulong(t_arg_list *list);

long	n_arg_long(unsigned int n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_long(list));
}

unsigned long	n_arg_ulong(unsigned int n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_ulong(list));
}

static long	next_arg_long(t_arg_list *list)
{
	return (va_arg(list->ap_current, long));
}

static unsigned long	next_arg_ulong(t_arg_list *list)
{
	return (va_arg(list->ap_current, unsigned long));
}

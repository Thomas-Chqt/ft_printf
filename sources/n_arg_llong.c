/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arg_llong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:10:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 16:16:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_stdarg.h"

static long long			next_arg_llong(t_arg_list *list);
static unsigned long long	next_arg_ullong(t_arg_list *list);

long long	n_arg_llong(unsigned int n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_llong(list));
}

unsigned long long	n_arg_ullong(unsigned int n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_ullong(list));
}

static long long	next_arg_llong(t_arg_list *list)
{
	return (va_arg(list->ap_current, long long));
}

static unsigned long long	next_arg_ullong(t_arg_list *list)
{
	return (va_arg(list->ap_current, unsigned long long));
}

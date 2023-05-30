/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:19:28 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 14:44:36 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_stdarg.h"

void	arg_list_start(t_arg_list *list)
{
	va_copy(list->ap_current, list->ap_start);
}

void	arg_list_end(t_arg_list *list)
{
	va_end(list->ap_current);
	va_end(list->ap_start);
}

void	move_ap(unsigned int n, t_arg_list *list)
{
	unsigned int	i;

	if (n == 0)
		return ;
	va_end(list->ap_current);
	va_copy(list->ap_current, list->ap_start);
	i = 0;
	while (i++ < (n - 1))
		va_arg(list->ap_current, int);
}

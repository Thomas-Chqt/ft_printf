/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arg_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:16:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 18:20:22 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_stdarg.h"

static char	*next_arg_str(t_arg_list *list);

char	*n_arg_str(long n, t_arg_list *list)
{
	move_ap(n, list);
	return (next_arg_str(list));
}

static char	*next_arg_str(t_arg_list *list)
{
	return (va_arg(list->ap_current, char *));
}

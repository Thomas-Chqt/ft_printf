/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_stdarg.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:04:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/31 23:45:48 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDED_STDARG_H
# define EXTENDED_STDARG_H

# include <stdarg.h>

typedef struct s_arg_list
{
	va_list	ap_start;
	va_list	ap_current;
}	t_arg_list;

void				arg_list_start(t_arg_list *list);
void				move_ap(unsigned int n, t_arg_list *list);

long long			get_arg(unsigned int n, t_arg_list *list);
unsigned int		get_arg_no_move(unsigned int n, t_arg_list *list);

void				arg_list_end(t_arg_list *list);

#endif
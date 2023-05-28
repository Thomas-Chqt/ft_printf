/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_stdarg.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:04:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 18:21:21 by tchoquet         ###   ########.fr       */
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
void				move_ap(long n, t_arg_list *list);

unsigned long long	n_arg_ullong(long n, t_arg_list *list);
long long			n_arg_llong(long n, t_arg_list *list);

unsigned long		n_arg_ulong(long n, t_arg_list *list);
long				n_arg_long(long n, t_arg_list *list);

unsigned int		n_arg_uint(long n, t_arg_list *list);
unsigned int		n_arg_uint_no_move(long n, t_arg_list *list);
int					n_arg_int(long n, t_arg_list *list);

char				*n_arg_str(long n, t_arg_list *list);

void				arg_list_end(t_arg_list *list);

#endif
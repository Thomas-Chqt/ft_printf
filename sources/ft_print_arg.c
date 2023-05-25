/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:34:53 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/25 18:57:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_print_arg(const char *str, size_t *i, va_list *ap)
{
	t_converter	*converter;
	
	(*i)++;
	converter = converter_from_key(str + *i);
	if (converter == NULL)
		return (-1);
	(*i) += converter->key_len;
	return (converter->put_func(ap));
}
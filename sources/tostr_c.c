/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostr_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:44:12 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 20:47:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

char	*tostr_c(t_conversion *conv, va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);

	return (ft_substr(&c, 0, 1));
}
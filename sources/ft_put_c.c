/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:53:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 00:10:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_put_c(va_list *ap, t_conversion conv)
{
	char	c;

	if (conv.conversion_type == 'c')
	{
		c = va_arg(*ap, int);
		return (ft_print_char(c));
	}
	return (0);
}
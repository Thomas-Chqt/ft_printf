/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:59:39 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/25 18:34:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

int	ft_put_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
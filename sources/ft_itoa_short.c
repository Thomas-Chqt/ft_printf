/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:49:47 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 19:50:43 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

char	*ft_itoa_short(short nbr)
{
	return (ft_itoa_llong(((long long)nbr)));
}

char	*ft_itoa_ushort(unsigned short nbr)
{
	return (ft_itoa_ullong((unsigned long long)nbr));
}

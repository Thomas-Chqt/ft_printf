/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:35:58 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 19:52:06 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

char	*ft_itoa_long(long nbr)
{
	return (ft_itoa_llong((long long)nbr));
}

char	*ft_itoa_ulong(unsigned long nbr)
{
	return (ft_itoa_ullong((unsigned long long)nbr));
}

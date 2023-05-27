/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:46:07 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 19:49:35 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

char	*ft_itoa_int(int nbr)
{
	return (ft_itoa_llong(((long long)nbr)));
}

char	*ft_itoa_uint(unsigned int nbr)
{
	return (ft_itoa_ullong((unsigned long long)nbr));
}

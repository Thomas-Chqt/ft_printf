/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:50:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 19:51:52 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

char	*ft_itoa_char(char nbr)
{
	return (ft_itoa_llong(((long long)nbr)));
}

char	*ft_itoa_uchar(unsigned char nbr)
{
	return (ft_itoa_ullong((unsigned long long)nbr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:08:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/03 13:33:09 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned short	intlen(int n);

char	*ft_itoa(int n)
{	
	unsigned int	nbr;
	unsigned short	n_len;
	char			*str;
	unsigned short	i;

	n_len = intlen(n);
	str = ft_calloc((n_len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = n * -1;
	}
	else
		nbr = n;
	i = n_len - 1;
	while ((nbr / 10) > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[i] = (nbr % 10) + '0';
	return (str);
}

static unsigned short	intlen(int n)
{
	unsigned int	nbr;
	unsigned short	len;

	len = 1;
	if (n < 0)
	{
		len++;
		nbr = n * -1;
	}
	else
		nbr = n;
	while ((nbr / 10) > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:20:41 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 19:22:07 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

static void	ullonglen(unsigned long long nbr, unsigned int *len);
static void	itoa_ullong(unsigned long long nbr, unsigned int *i, char *buffer);

char	*ft_itoa_llong(long long nbr)
{
	char	*u_buffer;
	char	*s_buffer;

	if (nbr < 0)
	{
		u_buffer = ft_itoa_ullong(nbr * -1);
		s_buffer = ft_strjoin("-", u_buffer);
		free(u_buffer);
		return (s_buffer);
	}
	return (ft_itoa_ullong(nbr));
}

char	*ft_itoa_ullong(unsigned long long nbr)
{
	unsigned int	len;
	char			*buffer;
	unsigned int	i;

	i = 0;
	len = 0;
	ullonglen(nbr, &len);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	itoa_ullong(nbr, &i, buffer);
	buffer[i] = '\0';
	return (buffer);
}

static void	ullonglen(unsigned long long nbr, unsigned int *len)
{
	if ((nbr / 10) > 0)
	{
		ullonglen(nbr / 10, len);
	}
	(*len)++;
}

static void	itoa_ullong(unsigned long long nbr, unsigned int *i, char *buffer)
{
	if ((nbr / 10) > 0)
	{
		itoa_ullong(nbr / 10, i, buffer);
	}
	buffer[*i] = (nbr % 10) + '0';
	(*i)++;
}

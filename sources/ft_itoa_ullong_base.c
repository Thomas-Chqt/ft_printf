/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ullong_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:07:31 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 16:17:46 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extended_libft.h"

static void	ullong_base_len(unsigned long long nbr,
				unsigned int *len, char *base);
static void	itoa_ullong_len(unsigned long long nbr,
				unsigned int *i, char *buffer, char *base);

char	*ft_itoa_ullong_base(unsigned long long nbr, char *base)
{
	unsigned int	len;
	char			*buffer;
	unsigned int	i;

	i = 0;
	len = 0;
	ullong_base_len(nbr, &len, base);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	itoa_ullong_len(nbr, &i, buffer, base);
	buffer[i] = '\0';
	return (buffer);
}

static void	ullong_base_len(unsigned long long nbr,
				unsigned int *len, char *base)
{
	if ((nbr / ft_strlen(base)) > 0)
	{
		ullong_base_len(nbr / ft_strlen(base), len, base);
	}
	(*len)++;
}

static void	itoa_ullong_len(unsigned long long nbr,
				unsigned int *i, char *buffer, char *base)
{
	if ((nbr / ft_strlen(base)) > 0)
	{
		itoa_ullong_len(nbr / ft_strlen(base), i, buffer, base);
	}
	buffer[*i] = base[nbr % ft_strlen(base)];
	(*i)++;
}

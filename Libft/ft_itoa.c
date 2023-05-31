/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:08:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/24 16:37:55 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				absintlen(long nb, unsigned short *len);
static unsigned short	intlen(int n);
static void				itoa(int n, char *buffer);
static void				abs_itoa(long n, unsigned short *i, char *buffer);

char	*ft_itoa(int n)
{
	char			*str;	

	str = malloc((intlen(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	itoa(n, str);
	return (str);
}

static unsigned short	intlen(int n)
{
	unsigned short	len;
	long			l_n;

	len = 0;
	l_n = (long)n;
	if (l_n < 0)
	{
		len++;
		l_n *= -1;
	}
	absintlen(l_n, &len);
	return (len);
}

static void	absintlen(long nb, unsigned short *len)
{
	if ((nb / 10) > 0)
	{
		absintlen(nb / 10, len);
	}
	(*len)++;
}

static void	itoa(int n, char *buffer)
{
	unsigned short	i;
	long			l_n;

	i = 0;
	l_n = (long)n;
	if (l_n < 0)
	{
		buffer[i] = '-';
		i++;
		l_n *= -1;
	}
	abs_itoa(l_n, &i, buffer);
	buffer[i] = 0;
}

static void	abs_itoa(long n, unsigned short *i, char *buffer)
{
	if ((n / 10) > 0)
	{
		abs_itoa(n / 10, i, buffer);
	}
	buffer[*i] = (n % 10) + '0';
	(*i)++;
}

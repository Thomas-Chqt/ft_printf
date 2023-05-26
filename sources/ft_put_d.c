/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:00:45 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/26 15:27:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void				absintlen(long nb, unsigned short *len);
static unsigned short	intlen(int n);

int	ft_put_d(va_list *ap)
{
	int				nbr;
	unsigned short	len;

	nbr = va_arg(*ap, int);
	len = intlen(nbr);
	ft_putnbr_fd(nbr, 1);
	return (len);
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
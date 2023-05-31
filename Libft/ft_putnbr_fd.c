/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:48:46 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/22 18:22:02 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putabnbr_fd(long nb, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	l_n;

	l_n = (long)n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n *= -1;
	}
	ft_putabnbr_fd(l_n, fd);
}

static void	ft_putabnbr_fd(long nb, int fd)
{
	if ((nb / 10) > 0)
		ft_putabnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

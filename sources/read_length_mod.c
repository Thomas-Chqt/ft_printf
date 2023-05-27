/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_length_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:04:57 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 18:05:40 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_length_mod	read_length_mod(const char *format, size_t *i)
{
	static char		*length_mod_str[9]
		= {"", "hh", "h", "l", "j", "t", "z", "q", "ll"};
	unsigned int	y;

	y = 1;
	while (y <= 8)
	{
		if (ft_strncmp(format + (*i),
				length_mod_str[y],
				ft_strlen(length_mod_str[y])) == 0)
		{
			(*i) += ft_strlen(length_mod_str[y]);
			return ((t_length_mod)((unsigned char)1 << (y - 1)));
		}
		if (y == 2)
			y = 8;
		else if (y == 8)
			y = 3;
		else if (y == 7)
			break ;
		else
			y++;
	}
	return (none);
}

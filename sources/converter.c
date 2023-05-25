/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:14:51 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/25 19:10:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static void			init_converters(t_converter converters[]);
static t_converter	create_t_convet(const char *key, unsigned int key_len,
						int (*put_func)(va_list *));

t_converter	*converter_from_key(const char *key)
{
	static t_converter	converters[3];
	unsigned int		i;

	init_converters(converters);
	i = 0;
	while (i < 3)
	{
		if (ft_strncmp(key, converters[i].key, converters[i].key_len) == 0)
			return (&(converters[i]));
		i++;
	}
	return (NULL);
}

static void	init_converters(t_converter converters[])
{
	converters[0] = create_t_convet("c", 1, &ft_put_c);
	converters[1] = create_t_convet("s", 1, &ft_put_s);
	converters[2] = create_t_convet("d", 1, &ft_put_d);
}

static t_converter	create_t_convet(const char *key, unsigned int key_len,
						int (*put_func)(va_list *))
{
	t_converter	new_convert;

	new_convert.key = key;
	new_convert.key_len = key_len;
	new_convert.put_func = put_func;
	return (new_convert);
}

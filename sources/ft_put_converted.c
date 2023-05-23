/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_converted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:29:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/23 13:18:16 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static t_convert	create_t_convet(char *key, unsigned int key_len,
						void (*put_func)(void *));
static unsigned int	init_key_array(t_convert **keys);

unsigned int	ft_put_converted(char *key, void *value)
{
	t_convert		keys[1];
	unsigned int	keys_count;

	keys_count = init_key_array(&keys);
}

static unsigned int	init_key_array(t_convert **keys)
{
	(*keys)[0] = create_t_convet("c", 1, &ft_put_c);
	return (1);
}

static t_convert	create_t_convet(char *key, unsigned int key_len,
						void (*put_func)(void *))
{
	t_convert	new_convert;

	new_convert.key = key;
	new_convert.key_len = key_len;
	new_convert.put_func = put_func;
	return (new_convert);
}

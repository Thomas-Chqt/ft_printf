/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_converted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:29:16 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/23 16:59:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static t_convert	create_t_convet(char *key, unsigned int key_len,
						void (*put_func)(void *));
static unsigned int	init_key_array(t_convert **keys);
int					index_for_key(char *key, t_convert *array,
						unsigned int array_len);

unsigned int	ft_put_converted(char *key, void *value)
{
	t_convert		*keys;
	unsigned int	keys_count;
	unsigned int	key_len;

	keys_count = init_key_array(&keys);
	keys[index_for_key(key, keys, keys_count)].put_func(value);
	key_len = keys[index_for_key(key, keys, keys_count)].key_len;
	free(keys);
	return (key_len);
}

static unsigned int	init_key_array(t_convert **keys)
{
	*keys = malloc(sizeof(t_convert) * 1);
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

int	index_for_key(char *key, t_convert *array, unsigned int array_len)
{
	int	i;

	i = 0;
	while (i < array_len)
	{
		if (ft_strncmp(key, array[i].key, array[i].key_len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

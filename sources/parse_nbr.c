/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:27:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 16:31:20 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specifier.h"

static int	parse_uint(const char *str, size_t *i, t_arg_list *args, long *parsed_uint);
static int	parse_arg_index(const char *str, size_t *i, unsigned int *parsed_arg_index);

int	parse_arg_index_comp(const char *str, size_t *i, t_arg_index_comp *parsed_arg_index_comp)
{
	size_t	y;

	if (!ft_isdigit(str[*i]) || str[*i] == '0')
		return (-1);
	y = *i;
	while (str[y] && ft_isdigit(str[y]))
		y++;
	if (str[y] == '$')
	{
		(*parsed_arg_index_comp) = ft_atoi_uint(str + (*i));
		(*i) = y;
		return (0);
	}
	return (-1);
}

int	parse_width_comp(const char *str, size_t *i, t_arg_list *args, t_width_comp *parsed_width_comp)
{
	return (parse_uint(str, i, args, (long *)parsed_width_comp));
}

int	parse_precision_comp(const char *str, size_t *i, t_arg_list *args, t_precision_comp *parsed_precision_comp)
{
	if (str[*i] != '.')
		return (-1);
	(*i)++;
	return (parse_uint(str, i, args, (long *)parsed_precision_comp));
}

static int	parse_uint(const char *str, size_t *i, t_arg_list *args, long *parsed_uint)
{
	unsigned int	arg_index;

	if (str[*i] == '*')
	{
		(*i)++;
		if (parse_arg_index(str, i, &arg_index) == 0)
		{
			(*parsed_uint) = (long)n_arg_uint_no_move(arg_index, args);
			return (0);
		}
		else
			return (-1);
	}
	if (str[*i] == '0' || !ft_isdigit(str[*i]))
		return (-1);
	(*parsed_uint) = ft_atoi_uint(str + (*i));
	while (ft_isdigit(str[*i]))
		(*i)++;
	(*i)--;
	return (0);
}

static int	parse_arg_index(const char *str, size_t *i, unsigned int *parsed_arg_index)
{
	t_arg_index_comp	arg_index;

	if (parse_arg_index_comp(str, i, &arg_index) == 0)
	{
		(*parsed_arg_index) = (unsigned int)arg_index;
		return (0);
	}
	else
		return (-1);
}

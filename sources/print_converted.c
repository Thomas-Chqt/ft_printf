/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_converted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:42:21 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 20:09:29 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static char	*(*get_tostr_func(char type))(t_conv_specs conv_specs,
				t_arg_list *args);
static char	*creat_print_str(t_conv_specs conv_specs, t_arg_list *args,
				char *(*tostr_func)(t_conv_specs conv_specs, t_arg_list *args));
char		*get_pre_str(char **data_str, t_conv_specs conv_specs);

int	print_converted(const char *str, size_t *i,
		t_arg_list *args, size_t *print_count)
{
	t_conv_specs	conv_specs;
	char			*(*tostr_func)(t_conv_specs conv_specs, t_arg_list *args);
	char			*printed_str;

	if (parse_conv_specs(str, i, args, &conv_specs) != 0)
		return (0);
	tostr_func = get_tostr_func(conv_specs.conversion_type);
	printed_str = creat_print_str(conv_specs, args, tostr_func);
	ft_putstr_fd(printed_str, 1);
	(*print_count) += ft_strlen(printed_str);
	if (printed_str == NULL)
	{
		free_conv_specs(conv_specs);
		return (-1);
	}
	free(printed_str);
	free_conv_specs(conv_specs);
	return (0);
}

static char	*(*get_tostr_func(char type))(t_conv_specs conv_specs,
				t_arg_list *args)
{
	if (type == 'c')
		return (&tostr_c);
	if (type == 's')
		return (&tostr_s);
	if (type == 'd' || type == 'i')
		return (&tostr_di);
	if (type == 'u')
		return (&tostr_u);
	if (type == 'x')
		return (&tostr_x);
	if (type == 'X')
		return (&tostr_upx);
	if (type == '%')
		return (&tostr_perc);
	return (NULL);
}

static char	*creat_print_str(t_conv_specs conv_specs, t_arg_list *args,
				char *(*tostr_func)(t_conv_specs conv_specs, t_arg_list *args))
{
	char	*pre_str;
	char	*data_str;
	char	c;

	c = ' ';
	if (tostr_func == NULL)
		return (NULL);
	data_str = tostr_func(conv_specs, args);
	pre_str = get_pre_str(&data_str, conv_specs);
	if (conv_specs.precision && conv_specs.conversion_type
		!= s && conv_specs.conversion_type != (t_type_comp)c)
		data_str = ex_strjoin(create_str('0', *(conv_specs.precision)
					- ft_strlen(data_str)), data_str);
	data_str = ex_strjoin(pre_str, data_str);
	if ((conv_specs.flags & zero) == zero)
		c = '0';
	if ((conv_specs.flags & minus) == minus)
		data_str = ex_strjoin(data_str, create_str(c, conv_specs.width
					- ft_strlen(data_str)));
	else
		data_str = ex_strjoin(create_str(c, conv_specs.width
					- ft_strlen(data_str)), data_str);
	return (data_str);
}

char	*get_pre_str(char **data_str, t_conv_specs conv_specs)
{
	if (conv_specs.conversion_type == c || conv_specs.conversion_type == s)
		return (ft_strdup(""));
	if ((conv_specs.flags & hash) == hash
		&& (conv_specs.conversion_type == x
			|| conv_specs.conversion_type == upx))
	{
		if (conv_specs.conversion_type == x)
			return (ft_strdup("0x"));
		if (conv_specs.conversion_type == upx)
			return (ft_strdup("0X"));
	}
	if ((*data_str)[0] == '-')
	{
		if (*data_str)
			*data_str = ex_substr(*data_str, 1, ft_strlen(*data_str) - 1);
		return (ft_strdup("-"));
	}
	if ((conv_specs.flags & plus) == plus)
		return (ft_strdup("+"));
	if ((conv_specs.flags & space) == space)
		return (ft_strdup(" "));
	return (NULL);
}

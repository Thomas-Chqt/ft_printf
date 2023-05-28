/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:10:33 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 19:45:34 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_specifier.h"

static t_conv_specs		empty_spec(void);
static int				parse_next(const char *str, size_t *i, t_arg_list *args, t_conv_specs *parsed_conv_specs);
static t_length_comp	final_length_mod(t_conv_specs *conv_specs);
static void				simplify_conv_spec(t_conv_specs *conv_specs);

int	parse_conv_specs(const char *str, size_t *i, t_arg_list *args, t_conv_specs *parsed_conv_specs)
{
	(*parsed_conv_specs) = empty_spec();
	while (str[*i] && parse_type_comp(str, i, &(parsed_conv_specs->conversion_type)) != 0)
	{
		if (parse_next(str, i, args, parsed_conv_specs) != 0)
			return (-1);
		(*i)++;
	}
	if (str[*i] == '\0')
		return (-1);
	parsed_conv_specs->length_mod = final_length_mod(parsed_conv_specs);
	simplify_conv_spec(parsed_conv_specs);
	return (0);
}

static int	parse_next(const char *str, size_t *i, t_arg_list *args, t_conv_specs *parsed_conv_specs)
{
	t_flag			new_flag;
	t_length_comp	new_length_comp;

	if (parse_arg_index_comp(str, i, &(parsed_conv_specs->arg_index)) == 0)
		return (0);
	if (parse_flag(str, i, &new_flag) == 0)
	{
		parsed_conv_specs->flags = (parsed_conv_specs->flags | (t_flags_comp)new_flag);
		return (0);
	}
	if (parse_width_comp(str, i, args, &(parsed_conv_specs->width)) == 0)
		return (0);
	if (parse_precision_comp(str, i, args, &(parsed_conv_specs->precision)) == 0)
		return (0);
	if (parse_length_comp(str, i, &new_length_comp) == 0)
	{
		parsed_conv_specs->length_mod = (parsed_conv_specs->length_mod | (t_length_comp)new_length_comp);
		return (0);
	}
	return (-1);
}

static t_conv_specs	empty_spec(void)
{
	t_conv_specs	specs;

	specs.arg_index = -1;
	specs.flags = 0;
	specs.width = -1;
	specs.precision = -1;
	specs.length_mod = 0;
	specs.conversion_type = 0;
	return (specs);
}

static t_length_comp	final_length_mod(t_conv_specs *conv_specs)
{
	short	i;

	if (ft_strchr("cs", conv_specs->conversion_type) != NULL)
		return (conv_specs->length_mod & (t_length_comp)l);
	else
	{
		i = 8;
		while (i >= 0)
		{
			if ((conv_specs->length_mod & (1 << i)) != 0)
				return (conv_specs->length_mod & (1 << i));
			i--;
		}
		return (0);
	}
}

static void	simplify_conv_spec(t_conv_specs *conv_specs)
{
	if (conv_specs->conversion_type == p)
	{
		conv_specs->conversion_type = x;
		conv_specs->length_mod = l;
		conv_specs->flags = (conv_specs->flags | hash);
	}
}
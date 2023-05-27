/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:44:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 00:53:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int	is_conv_type(char c);
static int	update_conv(const char *format, size_t *i, t_conversion *conv);

t_conversion *ft_parse_conversion(const char *format, size_t *i)
{
	t_conversion	*conversion;

	(*i)++;
	conversion = (t_conversion *)malloc(sizeof(t_conversion));
	if (conversion == NULL)
		return (NULL);
	while (format[*i] && !is_conv_type(format[*i]))
	{
		if (update_conv(format, i, conversion) < 0)
		{
			ft_free_conv(conversion);
			return (NULL);
		}
	}
	if (format[*i] == 0)
	{
		ft_free_conv(conversion);
		return (NULL);
	}
	conversion->conversion_type = format[*i];
	(*i)++;
	return (conversion);
}

void	ft_free_conv(t_conversion *conv)
{
	if (conv->flags)
		free(conv->flags);
	if (conv->length_mod)
		free(conv->length_mod);
	free(conv);
}

static int	is_conv_type(char c)
{
	static char *types = "cspdiuxX%";

	if (ft_strchr(types, c) != NULL)
		return (1);
	else
		return (0);
}

static int	update_conv(const char *format, size_t *i, t_conversion *conv)
{
	unsigned int	nbr;

	if (format[(*i)++] == '.')
	{
		conv->precision = atoi(format + (*i));
		while (ft_isdigit(format[*i]))
			(*i)++;
		return (0);
	}
	if (ft_isdigit(format[*i]))
	{
		nbr = atoi(format + (*i));
		while (ft_isdigit(format[*i]))
			(*i)++;
		if (format[*i] == '$')
		{
			conv->arg_index = nbr;
		}
		else
			conv->min_width = nbr;

	}
	return (-1);
}


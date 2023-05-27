/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:44:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 18:48:00 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

static int				update_conv(const char *format, size_t *i,
							t_conversion *conv);
static int				update_conv_pt2(const char *format, size_t *i,
							t_conversion *conv);
static unsigned char	new_length_mod(unsigned char current, t_length_mod new);
t_length_mod			final_length_mod(t_conversion *conv);

t_conversion	*ft_parse_conversion(const char *format, size_t *i)
{
	t_conversion	*conversion;

	conversion = (t_conversion *)ft_calloc(1, sizeof(t_conversion));
	if (conversion == NULL)
		return (NULL);
	while (format[*i] && !(ft_strchr("cspdiuxX%", format[*i]) != NULL))
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
	conversion->length_mod = final_length_mod(conversion);
	(*i)++;
	return (conversion);
}

static int	update_conv(const char *format, size_t *i, t_conversion *conv)
{
	if (ft_strchr(",;:_", format[*i]) != NULL)
		(*i)++;
	if (ft_strchr("#0- +'", format[*i]) != NULL)
	{
		conv->flags
			= extended_ft_strjoin(conv->flags, ft_substr(format, (*i), 1));
		(*i)++;
		return (0);
	}
	if (format[*i] == '.')
	{
		conv->precision = atoi(format + (++(*i)));
		while (ft_isdigit(format[*i]))
			(*i)++;
		return (0);
	}
	return (update_conv_pt2(format, i, conv));
}

static int	update_conv_pt2(const char *format, size_t *i, t_conversion *conv)
{
	unsigned int	nbr;

	if (ft_isdigit(format[*i]))
	{
		nbr = atoi(format + (*i));
		while (ft_isdigit(format[*i]))
			(*i)++;
		if (format[*i] == '$')
		{
			conv->arg_index = nbr;
			(*i)++;
		}
		else
			conv->min_width = nbr;
		return (0);
	}
	conv->length_mod
		= new_length_mod((unsigned char)conv->length_mod,
			read_length_mod(format, i));
	if (conv->length_mod == 0)
		return (-1);
	return (0);
}

static unsigned char	new_length_mod(unsigned char current, t_length_mod new)
{
	if (new == none)
		return (0);
	return (current | (unsigned char)new);
}

t_length_mod	final_length_mod(t_conversion *conv)
{
	unsigned short	i;

	if (ft_strchr("cs", conv->conversion_type) != NULL)
		return (conv->length_mod & (t_length_mod)l);
	else
	{
		i = 8;
		while (i >= 0)
		{
			if ((conv->length_mod & (1 << i)) != 0)
				return (conv->length_mod & (1 << i));
			i--;
		}
		return (none);
	}
}

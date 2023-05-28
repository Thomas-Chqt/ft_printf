/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifier.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:32:29 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/28 16:13:05 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_SPECIFIER_H
# define CONVERSION_SPECIFIER_H

# include <libc.h>
# include "extended_stdarg.h"
# include "extended_libft.h"

typedef long			t_arg_index_comp;
typedef unsigned char	t_flags_comp;
typedef long			t_width_comp;
typedef long			t_precision_comp;

typedef enum flag
{
	hash	= 0b00000001,
	zero	= 0b00000010,
	minus	= 0b00000100,
	space	= 0b00001000,
	plus	= 0b00010000,
	apos	= 0b00100000,
}	t_flag;

int	parse_flag(const char *str, size_t *i, t_flag *parsed_flag);

typedef enum length_comp
{
	hh		= 0b00000001,
	h		= 0b00000010,
	l		= 0b00000100,
	j		= 0b00001000,
	t		= 0b00010000,
	z		= 0b00100000,
	q		= 0b01000000,
	ll		= 0b10000000
}	t_length_comp;

int	parse_length_comp(const char *str, size_t *i,
		t_length_comp *parsed_length_comp);

typedef enum conv_type
{
	c		= 'c',
	s		= 's',
	p		= 'p',
	d		= 'd',
	i		= 'i',
	u		= 'u',
	x		= 'x',
	upx		= 'X',
	perc	= '%'
}	t_type_comp;

int	parse_type_comp(const char *str, size_t *i, t_type_comp *parsed_type_comp);

typedef struct s_conv_specs
{
	t_arg_index_comp	arg_index;
	t_flags_comp		flags;
	t_width_comp		width;
	t_precision_comp	precision;
	t_length_comp		length_mod;
	t_type_comp			conversion_type;
}	t_conv_specs;

int	parse_arg_index_comp(const char *str, size_t *i,
		t_arg_index_comp *parsed_arg_index_comp);

int	parse_width_comp(const char *str, size_t *i, t_arg_list *args,
		t_width_comp *parsed_width_comp);

int	parse_precision_comp(const char *str, size_t *i, t_arg_list *args,
		t_precision_comp *parsed_precision_comp);

int	parse_conv_specs(const char *str, size_t *i, t_arg_list *args,
		t_conv_specs *parsed_conv_specs);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 20:27:47 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ftprintf.h"
# include "extended_libft.h"

# include <stdarg.h>

typedef enum length_mod
{
	none	= 0b00000000,
	hh		= 0b00000001,
	h		= 0b00000010,
	l		= 0b00000100,
	j		= 0b00001000,
	t		= 0b00010000,
	z		= 0b00100000,
	q		= 0b01000000,
	ll		= 0b10000000
}	t_length_mod;

t_length_mod	read_length_mod(const char *format, size_t *i);

typedef struct s_conversion
{
	unsigned int	arg_index;
	char			*flags;
	unsigned int	min_width;
	unsigned int	precision;
	t_length_mod	length_mod;
	char			conversion_type;
}	t_conversion;

t_conversion	*ft_parse_conversion(const char *format, size_t *i);
void			ft_free_conv(t_conversion *conv);

char			*tostr_c(t_conversion *conv, va_list *ap);
char			*tostr_s(t_conversion *conv, va_list *ap);
char			*tostr_p(t_conversion *conv, va_list *ap);
char			*tostr_di(t_conversion *conv, va_list *ap);
char			*tostr_u(t_conversion *conv, va_list *ap);
char			*tostr_x(t_conversion *conv, va_list *ap);
char			*tostr_upx(t_conversion *conv, va_list *ap);
char			*tostr_perc(t_conversion *conv, va_list *ap);

int				ft_print_converted(const char *format, size_t *i,
					va_list *ap, va_list *ap_start);

#endif
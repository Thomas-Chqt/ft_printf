/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/27 00:07:51 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ftprintf.h"
# include "libft.h"

# include <stdarg.h>

typedef struct s_conversion
{
	unsigned int	arg_index;
	char			*flags;
	unsigned int	min_width;
	unsigned int	precision;
	char			*length_mod;
	char			conversion_type;
}	t_conversion;

t_conversion	*ft_parse_conversion(const char *format, size_t *i);
void			ft_free_conv(t_conversion *conv);

int				ft_print_char(char c);

int				ft_put_c(va_list *ap, t_conversion conv);

int				ft_print_converted(const char *format, size_t *i,
					va_list *ap, va_list *ap_start);

#endif
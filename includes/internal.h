/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/25 18:40:27 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ftprintf.h"
# include "libft.h"

# include <stdarg.h>

typedef struct t_converter
{
	const char		*key;
	unsigned int	key_len;
	int				(*put_func)(va_list *);
}	t_converter;

t_converter	*converter_from_key(const char *key);

int	ft_put_c(va_list *ap);
int	ft_put_s(va_list *ap);
int	ft_put_p(va_list *ap);
int	ft_put_d(va_list *ap);
int	ft_put_i(va_list *ap);
int	ft_put_u(va_list *ap);
int	ft_put_x(va_list *ap);
int	ft_put_upx(va_list *ap);
int	ft_put_percent(va_list *ap);

int	ft_print_arg(const char *str, size_t *i, va_list *ap);

#endif
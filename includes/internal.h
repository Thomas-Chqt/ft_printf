/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/01 19:11:24 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft_printf.h"
# include "conversion_specifier.h"

int	put_c(t_conv_specs conv_specs, t_arg_list *args);
int	put_s(t_conv_specs conv_specs, t_arg_list *args);
int	put_di(t_conv_specs conv_specs, t_arg_list *args);
int	put_u(t_conv_specs conv_specs, t_arg_list *args);
int	put_x(t_conv_specs conv_specs, t_arg_list *args);
int	put_upx(t_conv_specs conv_specs, t_arg_list *args);
int	put_per(t_conv_specs conv_specs, t_arg_list *args);

int	print_converted(const char *str, size_t *i, t_arg_list *args,
		size_t *print_count);

#endif
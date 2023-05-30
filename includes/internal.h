/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:27:50 by tchoquet          #+#    #+#             */
/*   Updated: 2023/05/30 20:13:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft_printf.h"
# include "conversion_specifier.h"

char	*tostr_c(t_conv_specs conv_specs, t_arg_list *args);
char	*tostr_s(t_conv_specs conv_specs, t_arg_list *args);
char	*tostr_di(t_conv_specs conv_specs, t_arg_list *args);
char	*tostr_u(t_conv_specs conv_specs, t_arg_list *args);
char	*tostr_x(t_conv_specs conv_specs, t_arg_list *args);
char	*tostr_upx(t_conv_specs conv_specs, t_arg_list *args);
char	*tostr_perc(t_conv_specs conv_specs, t_arg_list *args);

int		print_converted(const char *str, size_t *i,
			t_arg_list *args, size_t *print_count);

#endif